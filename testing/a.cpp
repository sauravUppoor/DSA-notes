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
const ll MAX_N = 1e6 + 5;
int arr[MAX_N];

int main() {
	int n,data;
	cin >> n;
	si S;
	
	for(int i = 0; i <n; ++i) {
		cin >> data;
		S.insert(data);
		
	}
	si::iterator itr = S.begin();
	itr++;
	cout << *itr;
}
