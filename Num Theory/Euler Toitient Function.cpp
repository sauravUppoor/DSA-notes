/*  Euler Toitient Function
    phi(x) - gives the count of numbers below x which are coprime with x
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
    
