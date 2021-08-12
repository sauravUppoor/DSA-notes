int distance[MAXN], pred[MAXN]; //Dsitance of node i from source node and predecessor of node i.
bool vis[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq; // pair of distance and node. This pq acta as Min Heap
for (int i = 1; i <= n; i++) distance[i] = INF;

void pathRestore(int s, int t) { // restores path, here s = source t= sink
	vi path;
	map<int,int> m;

	for(int i = s; i != t; i = pred[i]) {
		path.pb(i);
		m[i]++;
		if(m[i] == 2) { // This is to check incase there's no path possible ie we reach same node again.
			cout << "-1";
			return;
		}
	}
	path.pb(1);	
	reverse(ALL(path));
	for(auto x: path) cout << x << " ";
}

int main()
{
	distance[s] = 0; // starting node s
	pq.push({0, s});
	while (!pq.empty()) {
	    int a = pq.top().second; 
	    int val = pq.first();
	    pq.pop();
	    if(val != dist[a]) continue;

	    for (auto u : adj[a]) {
		int b = u.first, w = u.second;

		if (dist[a] + w < dist[b]) {
		    dist[b] = dist[a] + w;
		    pq.push({-dist[b], b});
		}
	    }

	    pathRestore(s, t);
}

// https://www.spoj.com/problems/HIGHWAYS/
// https://codeforces.com/contest/20/problem/C
// https://www.spoj.com/problems/SHPATH/ 
