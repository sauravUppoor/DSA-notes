// Segment Tree

// Operations:
// Increment / Range update: Change the value of a range [l...r] of an array- O(logN)
// RMQ: Find the minimum or maximum of a range - O(logN)

// Lazy propagation: We store the value of deltas of each and node and only propagate them to their children when we explore the children when need be.

int ar[MAXN];

struct segTree {
	int n;
	vi ss, se, minn, delta;


	segTree(int N) : n(N), ss(4*n+5), se(4*n+5), minn(4*n+5), delta(4*n+5) {buildTree(1,0,n-1);}

	void buildTree(int i, int qs, int qe) {
		ss[i]=qs;
		se[i]=qe;

		if(qs == qe) {minn[i] = ar[qs]; return;}

		int mid = (qs+qe)/2;

		buildTree(2*i, qs, mid);
		buildTree(2*i+1, mid+1, qe);

		minn[i] = min(minn[2*i], minn[2*i+1]);
	}

	void prop(int i) { 
		//Propagate the lazy delta down to its left and right nodes
		delta[2*i] += delta[i];
		delta[2*i+1] += delta[i];
		delta[i] = 0;
	}

	void update(int i) {
		// Updating the minimum value of the segments
		minn[i] = min(minn[2*i]+delta[2*i], minn[2*i+1]+delta[2*i+1]);
	}

	// Query 1 - update a range
	void increment(int i, int qs, int qe, int val) {
		if(qe < ss[i] || qs > se[i]) // Node completely out of the range we need
			return;

		if(qs <= ss[i] && qe >= se[i]) {
			// Node completely in the range we need
			delta[i] += val;
			return;
		}

		// Partially covered case, need to dive inside
		prop(i);

		increment(2*i, qs, qe, val);
		increment(2*i+1, qs, qe, val);

		update(i);
	}

	// Query 2 - Find minimum in a range
	int minimum(int i, int qs, int qe) {
		if(qe < ss[i] || qs > se[i]) {

			// Node completely out of our range so wsele finding the minimum we return a large value
			return INT_MAX;
		}

		if(qs <= ss[i] && qe >= se[i]) {
			// Node completely in the range we need, so we return the min value and the delta at that position in case there is some
			return minn[i];
		}

		//partially covered case, we need to dive more inside
		prop(i);

		int minleft = minimum(2*i, qs, qe);
		int minright = minimum(2*i+1, qs, qe);

		update(i);

		return min(minleft, minright);
	}
};

//https://codeforces.com/problemset/problem/52/C
//https://codeforces.com/contest/356/problem/A