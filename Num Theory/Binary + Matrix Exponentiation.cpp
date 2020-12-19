// Binary Exponentiation - to find x^n
// TC = O(logN)
// Whenever the power is even we divide n to n/2 and the exponent to be multiplied (x) is squared (x*x).
// Incase odd power is encounteredwe multiply the current

//2^13 = (2) * 2^12 = (2) * (4)^6 = (2) * (16)^3 = (32) * 16^2 = (32) * (256)^1
//= (32*256) = 8192

int mpow(int x, int n) {
	int ans = 1;
	while (n > 0) {
		if (n % 2 == 1) {
			(ans *= x) %= M;
			n--;
		}
		else {
			(x *= x) %= M;
			n /= 2;
		}
	}
	return ans;
}

_________________________________________________________________________
// Matrix Exponentiation - 
int a[N][N], I[N][N];

void matMul(int ar[][N], int b[][N], int n) {
	int res[n][n];
	F0R(i, n) {
		F0R(j, n) {
			res[i][j] = 0;
			F0R(k, n) {
				(res[i][j] += ar[i][k]*b[k][j]) %= MOD;
			}
		}
	}

	F0R(i, n) F0R(j, n) ar[i][j] = res[i][j];
}

void matExpo(int ar[][N], int n, int size) {
	F0R(i, n) F0R(j, n) {
		if(i == j) I[i][j] = 1;
		else  	   I[i][j] = 0;
	}

	//F0R(i, n) {
		//matMul(I, ar, n);
	//}
	while(n > 0) {
		if(n%2 == 1) {
			matMul(I, a, size);
			n--;
		}
		else {
			matMul(a, a, size);
			n /= 2;
		}
	}
}

void solve() {
	int n, pow;
	cin >> n >> pow;
	
	
	
	F0R(i, n) F0R(j, n) cin >> a[i][j];

	//int pow; cin >> pow;

	matExpo(a, pow, n);

	F0R(i, n) {
		F0R(j, n) {
			cout << I[i][j] << " ";
		}
		cout << "\n";
	}
	
}

//https://www.spoj.com/problems/MPOW/ (EASY)
