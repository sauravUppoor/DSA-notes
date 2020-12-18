/* Finding all subsets of a given array/string
   Complexity - O(2^n * n)
*/

for(int i = 0; i < (1<<n); i++) {
	vector<int> subset;
	for(int j = 0; j < n; j++) {
		if(i&(1<<j)) subset.pb(a[j]);
	}
	// Evaluate this subset
}
