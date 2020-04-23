int distance[MAXN]; //Dsitance of node i from source node
bool vis[MAXN];
priority_queue<pair<int, int>> q; // pair of -distance and node. Used negative of distance so as to get smallest value from max heap first.

for (int i = 1; i <= n; i++) distance[i] = INF;

distance[s] = 0; // starting node s
q.push({0, s});
while (!q.empty()) {
    int a = q.top().second; q.pop();
    
    if (vis[a]) continue;
    vis[a] = 1;
    
    for (auto u : adj[a]) {
        int b = u.first, w = u.second;
        
        if (distance[a] + w < distance[b]) {
            distance[b] = distance[a] + w;
            q.push({-distance[b], b});
        }
    }
}

// https://www.spoj.com/problems/HIGHWAYS/
