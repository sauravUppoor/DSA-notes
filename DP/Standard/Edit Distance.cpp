//Edit Distance 
//PS - Given 2 strings s1 and s2. Convert s1 to s2 with minimum possible edits. 
//3 edits possible - Insertion, Deletion, Replace.
// TC = O(n * m)

//Recursive Version - n * m function calls <-- Worst Case

int t[1000][1000];
string s1,s2;

int edit(int i,int j) {
	//D1(i); D1(j);
	if(i == 0) return j;
	else if(j == 0) return i;

	if(t[i][j] != -1) return t[i][j];

	if(s1[i - 1] == s2[j - 1]) return t[i][j] = edit(i-1, j-1); //if the current position elements matches then check substring of cur - 1 length in both and no eddits made so previous one is maintained
	else return t[i][j] = 1 + min({edit(i, j -1), edit(i - 1,j), edit(i -1, j - 1)});
  //current position needs to be edited so add 1 to minimum previous edit. Each recursive call signifies insert, delete and replace respectively
}

void solve() {
	cin >> s1 >> s2;

	int n = s1.length();
	int m = s2.length();

	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			t[i][j] = -1;
		}
	}
	
	cout << edit(n, m) << "\n";
}

__________________________________________________________________________

//Iterative
void solve() {
	cin >> s1 >> s2;

	int n = s1.length();
	int m = s2.length();
	F0R(i, n + 1) t[i][0] = i;
	F0R(j, m + 1) t[0][j] = j;

	FOR(i, 1, n + 1) {
		FOR(j, 1, m + 1) {
			if(s1[i - 1] == s2[j - 1]) t[i][j] = t[i -1][j - 1];
			else t[i][j] = 1 + min({t[i - 1][j], t[i][j - 1], t[i - 1][j - 1]});
		}
	}

	cout << t[n][m] << "\n";
	
}

