int par[MAXN], ans; //par initially -1
 
int find(int a) { //Path compression
	if(par[a] < 0) return a;
	else return par[a] = find(par[a]);
}
 
// Variation 1: Keeping count of children of a node in a set
void _union(int a, int b) {
	par[a] += par[b]; // Keeps track of all the children of a par node, negative in value
	par[b] = a;
}

//Variation 2: Minimum node value in a set
void _union(ll a, ll b) {
	par[a] = min(par[a], par[b]);
	par[b] = a;
}

