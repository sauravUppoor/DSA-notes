vector<int> adj[MAX_N], radj[MAX_N];
bool vis[MAX_N];
vector<int> order;
vector<vector<int> > comp;

void search1(int u) {
	if(vis[u]) return;
	vis[u] = 1;
	order.pb(u);

	for(auto v:adj[u]) {
		search1(v);
	}
}

void search2(int u) {
	if(vis[u]) return;
	vis[u] = 1;
	for(auto v:radj[u]) 
		search2(v);
	comp[comp.size() - 1].pb(u);
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		radj[v].pb(u);
	}

	for(int i = 0; i < n; ++i) {
		if(!vis[i]) search1(i);
	}
	reverse(ALL(order));

	memset(vis, 0, sizeof(vis));
	for(auto x:order) {
		if(!vis[x]) {
			comp.pb(vector<int>());
			search2(x);
		}
	}

	//for(auto x:comp) {
		//for(auto y:x) {
			//cout << y << " ";
		//}
		//cout << "\n";
	//}
}
