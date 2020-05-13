//Coin Change / Change Making Problem
// Given a number N the value of current amount we have, and array S - the denominations of changes, we need to count the total number of
// ways to convert N in terms of elements in S.

// Recursive - 

int ways[1000][1000];
int s[1000];

int count(int m, int n) {
	if(n == 0) return 1;
	if((m <= 0 && n > 0) || n < 0) return 0;
	if(ways[m][n] != -1) return ways[m][n];
	return ways[m][n] = count(m-1, n) + count(m, n - s[m-1]);
}

void solve() {
	memset(ways, -1, sizeof(ways));
	
	int n, m;
	cin >> n >> m;
	F0R(i, m) cin >> s[i];

	cout << count(m, n) << "\n";
}

_________________________________________________________________

// Iterative - with space optimisation

void solve() {
	//memset(ways, -1, sizeof(ways));
	
	int n, m;
	cin >> n >> m;
	int ways[n+1];
	int s[m];

	memset(ways, 0, sizeof(ways));
	F0R(i, m) cin >> s[i];


	
	ways[0] = 1;

	F0R(i, m) {
		FOR(j, s[i], n+1) {
			ways[j] += ways[j-s[i]];
		}
	}
	D2(ways);
	
	cout << ways[n] << "\n";
}
