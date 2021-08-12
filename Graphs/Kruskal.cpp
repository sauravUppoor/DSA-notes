#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define F0R(i, a, b) for (int i=a; i<(b); i++)
#define F0Rd(i,a,b) for (int i = (b)-1; i >= a; i--)

#define ALL(s) (s).begin(),(s).end()
#define ALLn(s,n) s,s+n
#define F first
#define S second
#define pb push_back
#define tc(t) int t; cin >> t; while(t--)
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n"; }

const ll M = 1e9 + 7;
const ll MM = 998244353;
const ll INF = 1e18;

const ll N = 1e5+7;
const ll Mm = 1e7+7;

// Kruskal MST 
// TC = O(ElogV) using DSU
struct edge
{
	int u, v, w;
};

edge e[Mm];
int par[N];

bool cmp(edge e1, edge e2)
{
	return e1.w < e2.w;
}

// Find - Path comp
int find(int a)
{
	// D1(par[a]);
	// D1(a);
	if(par[a]==-1) return a;
	else return par[a] = find(par[a]);
}

// Union
void un(int a, int b)
{
	par[a] = b;
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for(int i = 0; i <= n; ++i) par[i] = -1;
	sort(e,e+m,cmp);
	int ans = 0;
	for(int i = 0; i < m; ++i)
	{
		int a = find(e[i].u);
		int b = find(e[i].v);
		if(a != b) un(a, b),ans+=e[i].w;
	}
	cout << ans << '\n';
}
