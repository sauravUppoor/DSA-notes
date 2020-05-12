//Brute force:

void factorize(int n) {
	for(int p = 2; p <= n; ++p) {
		int e = 0;
		while(n%p == 0) {
			n /= p;
			++e;
		}

		if(e > 0) {
			printf("%d^%d\n", p, e);
		}
	}
	
	assert(n == 1);
}

//________________________________________________________________
//LogN approach:
//Better if you want to keep count of particular prime factors occuring in factorization
//Less memory space

void factorize_efficient(int n) {
	for(int p = 2; p*p < n; ++p) {
		int e = 0;
		while(n%p == 0) {
			n /= p;
			++e;
		}

		if(e > 0) {
			printf("%d^%d\n", p, e);
		}
	}
	if(n > 1) {
		printf("%d^%d", n, 1);
		
		n /= n;
	}
	assert(n == 1);
}
	
int main() {_
	factorize(30);
	factorize_efficient(90);
}

//________________________________________________________

//Sieve approach:
void sieve() {
	memset(primes, -1, sizeof(primes));

	for(int i = 2; i*i <= MAXN; ++i) {
		if(primes[i] == -1) {
			for(int j = i*i; j <= MAXN; j += i)
				primes[j] = i;

		}
	}
}

void factorize_sieve(int n) {
	vi factors;
	
	while(n > 1) {
		if(primes[n] == -1) {
			factors.pb(n);
			n = 1;
		}
		else {
			factors.pb(primes[n]);
			n /= primes[n];
		}
	}
	for(auto x: factors) cout << x << " ";
	cout << "\n";
}

void solve() {
	int n;
	cin >> n;

	factorize_sieve(n);
}
