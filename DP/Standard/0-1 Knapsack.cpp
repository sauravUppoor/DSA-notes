/* 0-1 Knapsack problem
   Given a list of n items and a pair(wli,vi) weight and value pair associated with each pair
   We have to find the maximum value of items that can be choosen with max permissible weight of w.
   [Point to note - We have arrays list and a weight/val limie ==> Knapsack could be applicable]
*/

/* Recursive / Top down
   Time Complexity - O(2^n)
   Space complexity - O(n*w) for memoization
                      O(1) if no memoization
*/

const ll N = 200;
const ll W = 100009;

int n, w;
int dp[N][W];
int wl[N], v[N];

int go(int i, int wt) {
	if (i >= n) return 0;
	if (wt > w) return 0;
	if (dp[i][wt] != -1) return dp[i][wt];

	if (wt + wl[i] <= w) dp[i][wt] = max(go(i + 1, wt), go(i + 1, wt + wl[i]) + v[i]);
	else dp[i][wt] = go(i + 1, wt);
	return dp[i][wt];
}

void solve() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) cin >> wl[i] >> v[i];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			dp[i][j] = -1;
		}
	}
	go(0, 0);
  
	cout << dp[0][0];
}

// ---------------------------------------------------------------------------------

/* Iterative / Bottom up
   Time complexity - O(n*w)
   Space complexity - O(n*w)
*/

const ll N = 200;
const ll W = 100009;

int n, w;
int dp[N][W];
int wl[N], v[N];

void solve() {
	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> wl[i] >> v[i];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (wl[i] <= j)
				dp[i][j] = max(dp[i - 1][j - wl[i]] + v[i], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][w];

}
