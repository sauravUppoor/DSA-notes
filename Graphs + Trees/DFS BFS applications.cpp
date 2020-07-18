In Out Time of Nodes 


________________________________________________________________

Size of Subtree - O(n)

int dfs(int u) {
	vis[u] = 1;

	int cur = 1;

	for(auto v:adj[u]) {
		if(!vis[v]) cur += dfs(v);
	}

	subsz[u] = cur;
	return cur;
}

___________________________________________________________________

Kahn's algorithm for Topological Sort - O(V + E)

vi adj[MAXN];
vi res;
int in[MAXN];

void kahn(int n) {
	queue<int> q;
	// priority_queue<int, vi, greater<int>> q; For lexicographically odered res
	F0R(i,n) if(in[i] == 0) q.push(i);

	while(!q.empty()) {
		int node = q.front();
		q.pop();
		res.pb(node+1);
		for(auto x: adj[node]) {
			in[x]--;
			if(in[x] == 0) q.push(x);
		}
	}

	if(res.size() == n) for(auto x: res) cout << x << ' ';
	else cout << "Sandro fails.";
}

void solve() {
	int n, m;
	cin >> n >> m;

	F0R(i,m) {
		int u,v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		in[v]++;
	}

	kahn(n);
}

___________________________________________________________________