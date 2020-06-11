// segment Tree

// Operations:
// 1. pUpdate - update just a position in the array
// 2. Update - update a range in the array
// 3. pQuery - get the min/max or other details of a particular postion in the array
// 4. Query - get the information about a particular range in the array

// Lazy propagation: We store the value of deltas of each and node and only propagate them to their children when we explore the children when need be.

int ar[MAXN];

struct segTree {
	int n;
	vi st, lazy;

	segTree(int N) : n(N) st(4*n+5), lazy(4*n+5) {buildTree(1,0,n-1);}

	void buildTree(int i, int qs, int qe) {

		if(qs == qe) {st[i] = ar[qs]; return;}

		int mid = (qs+qe)/2;

		buildTree(2*i, qs, mid);
		buildTree(2*i+1, mid+1, qe);

		st[i] = (st[2*i] + st[2*i+1]);
	}


	int pQuery(int i, int L, int R, int qi) {
		if(L==R) return st[i];

		int mid = (L+R)/2;
		if(qi<=mid) return pQuery(2*i, L, mid, qi);
		else return pQuery(2*i+1, mid+1, R, qi);
	}

	int Query(int i, int L, int R, int qs, int qe) {

		if(lazy[i]) {
			st[i] = lazy[i] * (R-L+1);
			if(L!=R) lazy[2*i] += lazy[i], lazy[2*i+1] = lazy[i];
			lazy[i] = 0;
		}

		if(qe < L || qs > R) {
			return INT_MAX;
		}

		if(qs <= L && qe >= R) {
			
			return st;
		}

		int mid = (L+R)/2;
		int left = Query(2*i, L, mid, qs, qe);
		int right = Query(2*i+1, mid+1, R, qs, qe);

		return left + right;
	}

	void pUpdate(int i, int L, int R, int qi) {
		if(L == R) {
			st[i] = ar[L];
			return;
		}

		int mid = (L+R)/2;
		if(qi <= mid) ptupdate(2*i, L, mid, qi);
		else ptupdate(2*i+1, mid+1, R, qi);

		st[i] = (st[2*i] + st[2*i+1]);
	}

	void Update(int i, int L, int R, int qs, int qe, int val) {

		if(lazy[i]) {
			st[i] = lazy[i] * (R-L+1); //Range sum
			if(L!=R) lazy[2*i] += lazy[i], lazy[2*i+1] = lazy[i];
			lazy[i] = 0;
		}

		if(qe < L || qs > R) 
			return;

		if(qs <= L && qe >= R) {
			st[i] += (R-L+1) * val;
			if(L != R) lazy[2*i] += val, lazy[2*i+1] += val;
			return;
		}

		int mid = (L + R)/2;
		increment(2*i, L, mid, qs, qe, val);
		increment(2*i+1, mid+1, R, qs, qe, val);

		st[i] = (st[2*i] + st[2*i+1]);

	}

	void update(int pos, int val) {
		pUpdate(1, 1, n, pos, val);
	}

	void update(int l, int r, int val) {
		Update(1, 1, n, l, r, val)
	}

	int query(int pos) {
		return pQuery(1, 1, n, pos);
	}
	int query(int l, int r) {
		return Query(1, 1, n, l, r);
	}


};

//https://codeforces.com/problemRt/problem/52/C
//https://codeforces.com/contest/356/problem/A