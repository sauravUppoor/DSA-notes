// Bridges - Nodes which if removed makes the graph disconnected.
// TC = O(N + M) 

// Solution uses DFS Tree. In DFS Tree there are 2 types of nodes (atleast for this problem) - Forward edge and Back edge.
// Forward Edge - Edge that gets traversed during DFS Search
// Back Edge - Edge that doesnt get traversed during DFS Search

// Now we can prove that a backward edge cannot be a Bridge since that edge isnt traversed in the DFS Search yet that graph was connected 
// ie we were able to reach the node node from where this back edge is connected to its ancestor.
// We maintain 2 values for each node - in and low. 
// The in[] stores the in time of each node during DFS.
// The low[] stores the minimum value of in time of all the nodes that the is connected to the current node except the parent node.

// At each stage we try to minimise the low time. There are 2 ways for this :
// 1. For back edge - low(cur node) = min(low(cur node), in(adj node))
// 2. For forward edge - low(cur node) = min(low(cur node),  low(adj node)) Since the current node can reach the low of its adjacent node.

// We then check for an edge, if its not a back edge, if it is a bridge by checking for the following condition:
// low(adjacent node) > in(current node) 
// NOTE: We dont do put equal in the above expression since low of adjacent node keeps updating at each search. Thus, if a node was
// was connected to previous ancestor and then while backtracking from the dfs calls, that ancestor becomes the adjacent node then the
// values become equal. However that doesnt mean its a bridge.

vi adj[MAXN];
vector<pii> bridges;
int vis[MAXN], in[MAXN], low[MAXN];
int timer;

void dfs(int n, int par = -1) {
	vis[n] = 1;
	in[n] = timer;
	low[n] = timer;
	++timer;

	for(auto x: adj[n]) {
		if(x == par) continue;
		else if(vis[x]) {
			low[n] = min(low[n], in[x]);
		}
		else {
			dfs(x, n);
			if(low[x] > in[n]) bridges.pb({n,x});
			low[n] = min(low[n], low[x]);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	F0R(i, n) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);

	for(auto x: bridges) cout << x.F << " --> " << x.S << "\n";
	
}


//Example - 
//1 --- 2
//     / \
//    3 - 4

//Output -
//1 --> 2

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737 (EASY)
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=551
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3785
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251
// https://www.spoj.com/problems/GRAFFDEF/
// https://www.spoj.com/problems/EC_P/
// https://codeforces.com/contest/700/problem/C
// https://codeforces.com/contest/732/problem/F
    
  


