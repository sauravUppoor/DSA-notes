/*  Get all the divisors of a number
    Complexity - O(sqrt(n))
*/

vi divisors(int n) {
	vi res;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.pb(i);
			res.pb(n / i);
		}
	}
	sort(ALL(res));
	return {res.begin(), unique(ALL(res))};
}
