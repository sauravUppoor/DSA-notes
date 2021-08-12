/* Finding prime factors with count of a number
   Complexity - O(sqrt(n))
*/

vector<pii> factorize(int n) {
	vector<pii> f;
	// finding smallest prime dividing n
	for (int i = 2; i * i <= n; i++) {
		// cnt be the number of time this prime i divides n
		int cnt = 0;
		int val = 1;
		while (n % i == 0) {
			val = i;
			cnt++;
			n /= i;
		}
		if (val != 1) f.pb({val, cnt});
	}
	if (n > 1) f.pb({n, 1});
	return f;
}
// -------------------------------------------------------------------------------------------------
/* To answer queries and get prime factors -
   1. Precompute spf (smallest prime factor) in O(NloglogN)
   2. Get prime factors in O(logN)
*/
const ll N = 1000000;
int spf[N];

// computing spf for 1 to N in O(NloglogN)
void sieve() {
	for (int i = 2; i * i <= N; i++) {
		if (spf[i] == 0) { // i is a prime
			spf[i] = i;
			for (int j = i * i; j <= N; j += i) {
				if (spf[j] == 0)
					spf[j] = i;
			}
		}
	}
	for (int i = 0; i <= N; i++)
		if (spf[i] == 0) spf[i] = i;
}

// factorize in O(logN)
vector<pii> factorize(int n) {
	vector<pii> f;
	map<int, int> mp;
	// finding smallest prime dividing n in O(1)
	while (n != 1) {
		mp[spf[n]]++;
		n /= spf[n];
	}
	for (auto x : mp)
		f.pb({x.F, x.S});
	return f;
}

// -------------------------------------------------------------------------------------------------

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

