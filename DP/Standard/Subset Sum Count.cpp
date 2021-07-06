// Count of subset sum
// arr = [a0, a1, a2, …, an-1], a[i] > 0
// S

#include <bits/stdc++.h>

const int MX = 1e3;
// cache[i][j] is count of subsets of first i elements of arr and j as target sum
int cache[MX][MX];

int countSubsetSum(vector<int> a, int n, int s) {
	if(cache[n][s] != -1) return cache[i][j];
	if(s == 0) return 1;
	if(n == 0) return 0;
	if(s >= a[n-1]) return cache[i][j] = countSubsetSum(a, n-1, s - a[n-1]) + countSubsetSum(a,n-1,s);	
	else return cache[i][j] = countSubsetSum(a,n-1,s);
}

void main() {
	int N; cin >> N;
	vector<int> a(N); 
	for(int i = 0; i < N; ++i) cin >> a[i];
	int S; cin >> S;
	for(int i = 0; i <= N; ++i)
		for(int j = 0; j <= S; ++j) 
			cache[i][j] = -1;

	for(int i = 1; i <= S; ++i) cache[0][i] = 0; // no elements and target sum != 0
	for(int i = 0; i <= N; ++i) cache[i][0] = 1; // target sum = 0;
	
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= S; ++j) {
			if(j >= a[i-1]) cache[i][j] =cache[i-1][j - a[i-1]] + cache[i-1][j];
			else cache[i][j] = cache[i-1][j];
		}
	}
	int ans = countSubsetSum(a, N, S);
	cout << ans;
}


