#include<bits/stdc++.h>
using namespace std;
 
/* DEBUG */
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

/* MACROS */
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
#define int ll
 
#define ALL(s) 		(s).begin(),(s).end()
#define ALLn(s,n) 	s,s+n
#define F 			first
#define S 			second
#define pb 			push_back
#define lcm(x, y)   ((x) * (y) / __gcd(x, y))
#define setbit(x)   __builtin_popcountll(x)
#define _ 			ios_base::sync_with_stdio(false); cin.tie(NULL);
 
/* CONSTRAINTS */ 
const ll M = 1e9 + 7;
const ll MM = 998244353;
const ll INF = 1e18;
const ll MXN = 2e5 + 1;
 
void solve(string s) {
	while(next_permutation(ALL(s))) {
		cout << s << '\n';
		return;
	}
	cout << "No Successor\n";
}
 
int32_t main() {
    _
 
    while(1) {
    	string s; cin >> s;
    	if(s == "#") break;
    	solve(s);
    }
}









