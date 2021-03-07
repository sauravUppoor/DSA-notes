struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a,b); } // any associative function
	vector<T> s; int n;
	Tree (int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val)
	{
		for(s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos*2], s[pos*2 + 1]);
	}
	T query(int b, int e) // query [b,e)
	{
		T ra = unit; T rb = unit;
		for(b += n, e += n; b < e; b /= 2, e /= 2)
		{
			if(b%2) ra = f(ra, s[b++]);
			if(e%2) rb = f(s[--e], rb);
		}
		return f(ra,rb);
	}
};

void solve() {
	int n;
	cin >> n;
	Tree st(n,0);
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		st.update(i,x);
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; ++i)
	{
		int l,r; cin >> l >> r;
		cout << st.query(--l,r) << '\n';
	}
}
