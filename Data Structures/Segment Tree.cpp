// SegTree
// Get Range queries of any associative operation
// eg - Range XOR

const ll N = 3e5 + 5;

int t[4*N]; // segtree
int n;
// v is the current node - 1,2,3,4,...
// tl,tr is the node range (yellow) - 0,1,2,...,N-1
// idx is the idx to be updated
// val is the new value
void update(int v, int tl, int tr, int idx, int val) {
	if(tl == idx && tr == idx) {
		t[v] = t[v]^val;
		return;
	}
	
	if(tl > idx || tr < idx) {
		return;
	}
	
	int tm = (tr + tl)/2;
	update(2*v, tl, tm, idx, val);
	update(2*v+1, tm+1, tr, idx, val);
	t[v] = t[2*v] ^ t[2*v+1];
	return;
}

// l,r is the range query (green)
int query(int v, int tl, int tr, int l, int r) {
	// no overlap
	if(tl > r || tr < l) {
		return 0;
	}
	
	// fully within
	if(l <= tl && tr <= r) { //l...tl...tr....r
		return t[v];
	}
	
	// partial overlap - go deeper
	int tm = (tr + tl)/2;
	int ans = 0;
	ans = query(2*v, tl, tm, l, r);
	ans ^= query(2*v+1, tm+1, tr, l , r);
	return ans;
}
void solve() {
	 // update(1,0,N-1,2,5);
	 // update(1,0,N-1,3,6);
	 // cout << query(1,0,N-1,2,3);
	 int q;
	 cin >> n >> q;
	 for(int i = 0; i < n; i++) {
	 	int x; cin >> x;
	 	update(1,0,N-1,i+1,x);
	 }
	 
	 for(int i = 0; i < q; i++) {
	 	int t, x, y;
	 	cin >> t >> x >> y;
	 	if(t == 1) {
	 		update(1,0,N-1,x,y);
	 	}
	 	else {
	 		cout << query(1,0,N-1,x,y) << '\n';
	 	}
	 }
	 
}
