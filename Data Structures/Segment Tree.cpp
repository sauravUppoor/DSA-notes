// Segment Tree

// Operations:
// Increment / Range update: Change the value of a range [l...r] of an array- O(logN)
// RMQ: Find the minimum or maximum of a range - O(logN)

// Lazy propagation: We store the value of deltas of each and node and only propagate them to their children when we explore the children when need be.

struct segTree {
	int n;
	vi lo, hi, minn, delta;

	segTree(int N) : n(N), lo(4*n+5), hi(4*n+5), minn(4*n+5), delta(4*n+5) {init(1,0,n-1);}

	void init(int i, int a, int b) {
		lo[i]=a;
		hi[i]=b;

		int m = (a+b)/2;

		if(a==b) return;
		init(2*i,a,m);
		init(2*i+1, m+1,b);
	}

	void prop(int i) { 
		//Propagate the lazy delta down to its left and right nodes
		delta[2*i] += delta[i];
		delta[2*i+1] += delta[i];
		delta[i] = 0;
	}

	void update(int i) {
		// Updating the minimum value of the segments
		minn[i] = max(minn[2*i]+delta[2*i], minn[2*i+1]+delta[2*i+1]);
	}

	// Query 1
	void increment(int i, int a, int b, int val) {
		if(b < lo[i] || a > hi[i]) // Node completely out of the range we need
			return;

		if(a <= lo[i] && b >= hi[i]) {
			// Node completely in the range we need
			delta[i] += val;
			return;
		}

		// Partially covered case, need to dive inside
		prop(i);

		increment(2*i, a, b, val);''
		increment(2*i+1, a, b, val);

		update(i);
	}

	// Query 2
	int minimum(int i, int a, int b) {
		if(b < lo[i] || a > hi[i]) 
			// Node completely out of our range so while finding the minimum we return a large value
			return 0;

		if(a >= lo[i] && b <= hi[i]) 
			// Node completely in the range we need, so we return the min value and the delta at that position in case there is some
			return minn[i] + delta[i];

		//partially covered case, we need to dive more inside
		prop(i);

		int minleft = minimum(2*i, a, b);
		int minright = minimum(2*i+1, a, b);

		update(i);

		return max(minleft, minright);
	}
};

//https://codeforces.com/problemset/problem/52/C
//https://codeforces.com/contest/356/problem/A