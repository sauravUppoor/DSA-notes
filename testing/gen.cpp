//generating random sequence of distinct elements
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


int rand(int a,int b){
	return a + rand() % (b -a + 1);
}

int main(int argc,char* argv[]) {_
	srand(atoi(argv[1]));
	int n = rand(2,1000);
	printf("%d\n",n);
	si used;
	for(int i = 0; i <n; ++i) {
		int x;
		do {
			x = rand(1,10 );
		} while(used.count(x));
		printf("%d ",x);
		used.insert(x);
	}
	puts("");
}














