//Min Cost Path - TC = O(n*m)
// PS - Given a cost matrix find minimum cost to reach from (0,0) to (m,n)

//Recusrive - n * m calls
int mc[1000][1000], cost[1000][1000];

int MinCost(int i, int j) {
	if(i == 0 && j == 0) return cost[0][0];
	if(mc[i][j] != -1) return mc[i][j];
	
	if(i == 0) return mc[i][j] = MinCost(i, j - 1) + cost[i][j];
	if(j == 0) return mc[i][j] = MinCost(i - 1, j) + cost[i][j];
	return mc[i][j] = min({MinCost(i-1, j), MinCost(i-1, j-1), MinCost(i, j-1)}) + cost[i][j];
}

void solve() {
	memset(mc, -1, sizeof(mc));
	int m, n;
	cin >> m >> n;

	F0R(i, m) {
		F0R(j, n) {
			cin >> cost[i][j];
		}
	}

	cout << MinCost(m-1, n-1);
}

____________________________________________________________

//Iterative -
//Space optimisation - using the same cost array to store the mincost path

int cost[1000][1000];
void solve() {
	//memset(cost, -1, sizeof(cost));
	int m, n;
	cin >> m >> n;

	F0R(i, m) {
		F0R(j, n) {
			cin >> cost[i][j];
		}
	}

	FOR(i, 1, m) 
		cost[i][0] += cost[i-1][0];

	FOR(i, 1, n) 
		cost[0][i] += cost[0][i-1];

	FOR(i, 1, m) {
		FOR(j, 1, n) {
			cost[i][j] = min({cost[i-1][j], cost[i-1][j-1], cost[i][j-1]}) + cost[i][j];
		}
	}

	cout << cost[m-1][n-1] << "\n";
}
