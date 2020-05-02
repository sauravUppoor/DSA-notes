// Recursive Version

int a[MAXN], L[MAXN];
bool vis[MAXN];

int LIS(int n) {
  vis[n] = 1;
	if(n == 0) return L[n] = 1; 
	else {
		int ans = 0;
    
    //Checking past positions till i-1
    //If no LIS call made from that index call LIS on it
    //Count if a[n] > a[i] and use subproblem property
    
		F0R(i, n) {
			if(!vis[i]) LIS(i);
			if(a[n] > a[i]) L[n] = 1 + L[i];
			ans = max(ans, L[i]);
		}
    
    //return the max value of L arr till n
		return max(ans, L[n]);
	}
}

void solve() {
	
	int n;
	cin >> n;
  
	F0R(i, n) L[i] = 1;
  memset(vis, 0, sizeof(vis));
	F0R(i, n) cin >> a[i];

	
	cout << LIS(n-1) << "\n";
	F0R(i, n) cout << L[i] << " ";
}

_______________________________________________________

//Iterative Version

int a[MAXN], L[MAXN];


void solve() {
	int n;
	cin >> n;
	F0R(i, n) cin >> a[i];
	int ans = 0;
	
	F0R(i, n) L[i] = 1; //Initialisation
	F0R(i, n) {
		F0R(j, i) if(a[i] > a[j]) L[i] = 1 + L[j]; 
		ans = max(ans, L[i]);
	}

	cout << ans << "\n";

}
