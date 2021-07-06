// Equal Sum Partition
// arr - [a1, a2, a3, ... , an]
// Return True / False


#include <bits/stdc++.h>

const int MX = 1e3;

// cache[i][j] stores result if we have first i elements of arr and  W = j
int cache[MX][MX]; 

int f(vector<int> a, int N, int W) {
	if(W == 0) return 1;
	if(N == 0) return 0;
	if(cache[N][W] != -1) return cache[N][W]);
	if(W >= a[N]) return t[N][W] = (f(a,N-1,W-a[N]) || f(a,N-1,W));
	else return t[N][W] = f(a,N-1,W);
}

void main() {
	int N; cin >> N; 
	vector<int> a(N);
	a[0] = 0;
	int W, sm = 0;
	for(int i = 1; i <= N; ++i) cin >> a[i], sm += a[i];
	if(sm & 1) {
		cout << false;
		return;
	}
	W = sm/2;
	for(int i = 0; i <= W; ++i) cache[0][i] = 0;
	for(int i = 0; i <= N; ++i) cache[i][0] = 1;

	for(int i = 0; i <= N; ++i) 
		for(int j = 0; j <= W; ++i) {
			if(j >= a[i]) cache[i][j] = cache[i-1][j-a[i]] || cache[i-1][j];
			else cache[i][j] = cache[i-1][j];
		}
			
	bool res = f(a, N, W);
	cout << cache[N][W];
}
