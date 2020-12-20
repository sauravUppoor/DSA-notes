/*  Euler Toitient Function
    phi(x) - gives the count of numbers below x which are coprime with x
    phi(x) is multiplicative i.e. phi(x*y) = phi(x) * phi(y)
    
    General formula for phi(n)
    phi(n) = n * (P1 - 1)/P1 * (P2 - 1)/P2 * ... * (Pk - 1)/Pk
    where Pi are prime factors of number n
*/

/*  Finding ETF of a particular number
    Ccomplexity - O(sqrt(n))
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
