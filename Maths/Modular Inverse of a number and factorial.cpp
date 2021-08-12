/*  Finding Inverse of a number and factorial under some prime p
	Used to compute (1/x!) %p = inverse(x!) % p
	Now,
	fact(x) = x * fact(x-1)
	factInverse(x) = numInverse(x) * factInverse(x-1)

	Time complexity -
	Precompute - O(N)
	Queries - O(1)

	Applications - nCr, nPr etc
*/

#include<bits/stdc++.h>
using namespace std;

const ll M = 1e9 + 7;
const ll N = 500000;

int factInv[N + 1], numInv[N + 1], fact[N + 1];

// Finding inverse of a number from 1 to N
void numInverse(int p) {
	numInv[0] = numInv[1] = 1;
	for (int i = 2; i <= N; i++) {
		numInv[i] = (numInv[p % i] * (p - p / i)) % p;
	}
}

// Finding inverse of a factorial from 1! to N!
void factInverse(int p) {
	factInv[0] = factInv[1] = 1;
	for (int i = 2; i <= N; i++) {
		factInv[i] = (numInv[i] * factInv[i - 1]) % p;
	}
}

// Finding normal factorial (for nCr/nPr)
void factorial(int p) {
	fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}

void solve() {
	int n, r;
	n = 20;
	r = 3;

	/*  Calculating nCr
		nCr = n! / (r! * (n - r)!)
			= (n! * factInv(r) % p * factInv(n - r) % p) % p
	*/
	cout << (fact[n] * factInv[r] % M * factInv[n - r] % M) % M << '\n';

	/*  Calculating nPr
		nPr = n! / (n - r)!
			= (n! * factInv(n - r) % p) % p
	*/
	cout << (fact[n] * factInv[n - r] % M) % M << '\n';
}

int32_t main() {
	_

#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	numInverse(M);
	factInverse(M);
	factorial(M);
	// tc(t)
	solve();
	// cerr << "[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
}
