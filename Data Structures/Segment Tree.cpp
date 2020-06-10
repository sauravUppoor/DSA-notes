// Rgment Tree

// Operations:
// Increment / Range update: Change the value of a range [l...r] of an array- O(logN)
// RMQ: Find the minimum or maximum of a range - O(logN)

// Lazy propagation: We store the value of deltas of each and node and only propagate them to their children when we explore the children when need be.

int ar[MAXN];

struct RgTree {
	int n;
	vi L, R, st, delta;


	RgTree(int N) : n(N), L(4*n+5), R(4*n+5), st(4*n+5), delta(4*n+5) {buildTree(1,0,n-1);}

	void buildTree(int i, int qs, int qe) {
		L[i]=qs;
		R[i]=qe;

		if(qs == qe) {st[i] = ar[qs]; return;}

		int mid = (qs+qe)/2;

		buildTree(2*i, qs, mid);
		buildTree(2*i+1, mid+1, qe);

		st[i] = min(st[2*i], st[2*i+1]);
	}

	void prop(int i) {
		delta[2*i] += delta[i];
		delta[2*i+1] += delta[i];
		delta[i] = 0;
	}

	void update(int i) {
		st[i] = min(st[2*i]+delta[2*i], st[2*i+1]+delta[2*i+1]);
	}

	int pQuery(int i, int L, int R, int qi) {
		if(L==R) return st[i];

		int mid = (L+R)/2;
		if(qi<=mid) return pQuery(2*i, L, mid, qi);
		else return pQuery(2*i+1, mid+1, R, qi);
	}

	int Query(int i, int L, int R, int qs, int qe) {
		if(qe < L || qs > R) {
			return INT_MAX;
		}

		if(qs <= L && qe >= R) {
			
			return st;
		}

		int mid = (L+R)/2;
		int left = minimum(2*i, L, mid, qs, qe);
		int right = minimum(2*i+1, mid+1, R, qs, qe);

		return min(left, right);
	}

	void pUpdate(int i, int L, int R, int qi) {
		if(L == R) {
			st[i] = ar[L];
			return;
		}

		int mid = (L+R)/2;
		if(qi <= mid) ptupdate(2*i, L, mid, qi);
		else ptupdate(2*i+1, mid+1, R, qi);

		st[i] = min(st[2*i], st[2*i+1]);
	}

	void Update(int i, int L, int R, int qs, int qe, int val) {
		if(qe < L || qs > R) 
			return;

		if(qs <= L && qe >= R) {
			delta[i] += val;
			return;
		}

		prop(i);

		int mid = (L + R)/2;
		increment(2*i, L, mid, qs, qe, val);
		increment(2*i+1, mid+1, R, qs, qe, val);

		update(i);
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