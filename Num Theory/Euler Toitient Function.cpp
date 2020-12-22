/*  Euler Toitient Function
    phi(x) - gives the count of numbers which are coprime with x in the range [1,x]
    phi(x) is multiplicative i.e. phi(x*y) = phi(x) * phi(y)
    
    General formula for phi(n)
    phi(n) = n * (P1 - 1)/P1 * (P2 - 1)/P2 * ... * (Pk - 1)/Pk
    where Pi are prime factors of number n
*/

/*  Finding ETF of a particular number
    Complexity - O(sqrt(n))
*/

int phi(int n) {
	int res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res /= i;
			res *= (i - 1);
			while (n % i == 0)
				n /= i;
		}
	}

	if (n > 1)
		res /= n, res *= (n - 1);
	return res;
}

// -------------------------------------------------------------

/* For finding ETF of numbers from 1 to N, above method will take N*sqrt(N) time.
   We can use sieve and precompute ETF for all the numbers.
   Complexity -
   Precompute - O(NloglogN)
   Query - O(1)
*/

const ll N = 1000000;
int phi[N];

void sieve() {
	for (int i = 1; i <= N; i++)
		phi[i] = i;

	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i) {
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
	}
}
    
// -------------------------------------------------------------

/* Modified ETF
   f(p,r) - gives count of numbers which are coprime with p in the range [1,r]
   f(p,r) = r - g(p,r)
   where g(p,r) is the count of numbers which are not coprime with p
   
   We can find g(p,r) using phi_2(p,r,v) where v is a vector containing prime factors of p.
   We use the principle of Inclusion and Exclusion to find the value.
   
   Eg - v = {p1,p2,p3}
   Then g(p,r) = (r/p1) + (r/p2) + (r/p3) - (r/p1p2) - (r/p2p3) - (r/p3p1) + (r/p1p2p3)
   Complexity -
   For a given number p, there are log10(p) primes possible at max,
   Thus generating subsets take O(N*2^N) = O(2^N) where N = log10(p)
*/

int phi_2(int p, int r, vi v) {
	int sz = v.size();
	int phi = 0;
	for (int ii = 1; ii < (1 << sz); ii++) {
		vi select;
		int p = 1;
		for (int j = 0; j < sz; j++) {
			if (ii & (1 << j)) select.pb(v[j]), p *= v[j];
		}
		// D1(select.size());
		if (select.size() % 2 == 0 && select.size() > 0) {
			phi -= (r / p);
		}
		else phi += (r / p);
	}
	return phi;
}
