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

