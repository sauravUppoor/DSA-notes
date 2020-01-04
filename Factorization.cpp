#include<bits/stdc++.h>

using namespace std;

#define ll					long long
#define vi					vector<int>
#define vii					vector<vi>
#define ALL(s)			(s).begin(),(s).end()
#define pii					pair<int, int> pii;
#define pll					pair<ll, ll>
#define si					set<int>
#define F						first
#define S						second
#define pb					push_back
#define tc(t)				int t; cin >> t; while(t--)
#define _						ios_base::sync_with_stdio(false); cin.tie(NULL); 
const ll MOD = 1e9 + 7;
const ll INF = 1<<29;
const ll MAX_N = 1e6 + 7;

void factorize(int n) {
	for(int p = 2; p <= n; ++p) {
		int e = 0;
		while(n%p == 0) {
			n /= p;
			++e;
		}

		if(e > 0) {
			printf("%d^%d\n", p, e);
		}
	}
	
	assert(n == 1);
}

void factorize_efficient(int n) {
	for(int p = 2; p*p < n; ++p) {
		int e = 0;
		while(n%p == 0) {
			n /= p;
			++e;
		}

		if(e > 0) {
			printf("%d^%d\n", p, e);
		}
	}
	if(n > 1) {
		printf("%d^%d", n, 1);
		
		n /= n;
	}
	assert(n == 1);
}
	
int main() {_
	factorize(30);
	factorize_efficient(90);
}
