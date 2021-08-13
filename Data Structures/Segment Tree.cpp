// SegTree
// DYNAMIC Range queries of any associative operation
// Build: O(n)
// Query: O(logn)

// for STATIC Range queries - Use DP
// Build: O(nlogn)
// Query: O(1)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const ll N = 3e5 + 5;
const ll INF = 1e18;

class SegmentTree {
private: 
	vector<int> t;
	int n;
	int INIT_VAL = INF;
	
	int operation(int a, int b) {
		return min(a,b);	
	}
	
	// v is the current node - 1,2,3,4,...
	// tl,tr is the tree range - 0,1,2,...,N-1
	// idx is the idx to be updated
	// val is the new value
	void update(int node, int tl, int tr, int idx, int val) {
		if(tl == idx && tr == idx) {
			t[node] = min(t[node], val);
			return;
		}
		
		if(tl > val || tr < val) { return; }
		
		int tm = (tl + tr)/2;
		update(2*node, tl, tm, idx, val);
		update(2*node, tm+1, tr, idx, val);
		
		t[node] = operation(t[2*node], t[2*node+1]);
		return;
	}
	
	// l,r is the range query
	int query(int node, int tl, int tr, int l, int r) {
		// no overlap
		if(tl > r || tr < l ) { return 0; }
		
		// fully within
		if(tl >= l && tr <= r) {
			return t[node];
		}
		
		// partially
		int tm = (tl + tr)/2;
		int ql = query(2*node, tl, tm, l, r);
		int qr = query(2*node+1, tm+1, tr, l, r);
		int ans = operation(ql, qr);
		return ans;
	}
	
public:
	SegmentTree(const vector<int> &A) {
		n = A.size();
		t.assign(n, INIT_VAL);
		for(int i = 0; i < n; ++i) {
			update(1, 0, n-1, i+1, A[i]);
		}
	}
	
	void update(int idx, int val) { return update(1, 0, n-1, idx, val); }
	
	int query(int i, int j) { return query(1, 0, n-1, i, j); }
	
	void displayTree() {
		for(int i = 0; i < 14; ++i) {
			cout << t[i] << ' ';
		}
		cout << '\n';
	}
};

// int t[4*N]; // segtree
// int n;
// 
// void update(int v, int tl, int tr, int idx, int val) {
	// if(tl == idx && tr == idx) {
		// t[v] = t[v]^val;
		// return;
	// }
// 	
	// if(tl > idx || tr < idx) {
		// return;
	// }
// 	
	// int tm = (tr + tl)/2;
	// update(2*v, tl, tm, idx, val);
	// update(2*v+1, tm+1, tr, idx, val);
	// t[v] = t[2*v] ^ t[2*v+1];
	// return;
// }
// 
// 
// int query(int v, int tl, int tr, int l, int r) {
	// // no overlap
	// if(tl > r || tr < l) {
		// return 0;
	// }
// 	
	// // fully within
	// if(l <= tl && tr <= r) { //l...tl...tr....r
		// return t[v];
	// }
// 	
	// // partial overlap - go deeper
	// int tm = (tr + tl)/2;
	// int ans = 0;
	// ans = query(2*v, tl, tm, l, r);
	// ans ^= query(2*v+1, tm+1, tr, l , r);
	// return ans;
// }
int32_t main() {
	 // update(1,0,N-1,2,5);
	 // update(1,0,N-1,3,6);
	 // cout << query(1,0,N-1,2,3);
	 // int q;
	 // cin >> n >> q;
	 // for(int i = 0; i < n; i++) {
	 	// int x; cin >> x;
	 	// update(1,0,N-1,i+1,x);
	 // }
// 	 
	 // for(int i = 0; i < q; i++) {
	 	// int t, x, y;
	 	// cin >> t >> x >> y;
	 	// if(t == 1) {
	 		// update(1,0,N-1,x,y);
	 	// }
	 	// else {
	 		// cout << query(1,0,N-1,x,y) << '\n';
	 	// }
	 // }
	 
	vector<int> A = { 18, 17, 13, 19, 15, 11, 20 }; // the original array
	// vector<int> A(arr, arr + 7);
	SegmentTree st(A);
	printf("RMQ(1, 3) = %d\n", st.query(1, 3)); // answer = index 2
	printf("RMQ(4, 6) = %d\n", st.query(4, 6));
	st.displayTree();
}
