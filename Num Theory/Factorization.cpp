
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
