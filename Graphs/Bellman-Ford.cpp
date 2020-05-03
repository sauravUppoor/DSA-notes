//TC = O(N*M) 
//No need to sort the edges by weight
//bool compare(tuple<int,int,int> a, tuple<int,int,int> b) {
	//int u1 ,v1 ,w1, u2, v2, w2;
	//tie(u1,v1,w1) = a;
	//tie(u2,v2,w2) = b;

	//return w1 > w2;
//}

void solve() {
	int n,m;
	cin >> n >> m;

	ll dist[n+1];
	tuple<int, int, int> edges[m];

	F0R(i, m) {
		int a,b,w;
		cin >> a >> b >> w;
		edges[i] = tie(a,b,w);
	}

	//sort(ALLn(edges, m), compare);

	FOR(i, 1, n) dist[i] = INF;

	int source,destination;
	cin >> source >> destination;
	dist[source] = 0;
	
	FOR(i, 1, n) {
		for(auto e: edges) {
			int a,b,w;
			tie(a,b,w) = e;
			dist[b] = min(dist[b], dist[a] + w);
		}
	}
	
	cout << dist[destination]; 
	
}

//https://www.spoj.com/problems/UCV2013B/
