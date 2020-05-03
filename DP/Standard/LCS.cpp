//Longest Common Subsequence
// Naive - O(2^n) generating all subsequences
// DP - O(n^2)

//Recursive

int t[1000][1000];
string x,y;

int LCS(int n,int m) {
	if(n == 0 || m == 0) return t[n][m] = 0;
	else {
		if(t[n][m] != -1) return t[n][m];
		if(x[n - 1] == y[m - 1]) return t[n][m] = 1 + LCS(n-1, m-1); //If the cur elements at n and m position is equal we cant consider them again in the final subsequence
		else return t[n][m] = max(LCS(n-1,m), LCS(n,m-1)); //Else check the other two possibilites of matching one of the current elements at position n or m with elements behind
	}
}

void solve() {
	cin >> x >> y;
	
	int n = x.length();
	int m = y.length();

	F0R(i, n + 1) F0R(j, m + 1) t[i][j] = -1;

	cout << LCS(n,m);
}

_______________________________________________________________________

//Iterative

void solve() {
	cin >> x >> y;
	
	int n = x.length();
	int m = y.length();

	F0R(i, n + 1) F0R(j, m + 1) t[i][j] = 0;
	F0R(i, n + 1) t[i][0] = 0;
	F0R(j, m + 1) t[0][j] = 0;
	
	FOR(i, 1, n + 1) {
		FOR(j, 1, m + 1) {
			//cout << x[i] << " " << y[j] << "\n";
			if(x[i - 1] == y[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
			else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}

	cout << t[n][m];
}
