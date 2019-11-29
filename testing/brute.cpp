#include<bits/stdc++.h>

using namespace std;

#define ll					long long
#define vi					vector<int>
#define vii					vector<vi>
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

int main() {_
	int n;
	cin >> n;
	vi a(n);
	for(int& x : a) {
		cin >> x;
	}

	for(int x : a) {
		int count_smaller = 0;
		for(int y : a) {
			if(y < x) ++count_smaller;
		}
		if(count_smaller == 1) {
			cout << x<<'\n';
			return 0;
		}
	}
	assert(false);
}
