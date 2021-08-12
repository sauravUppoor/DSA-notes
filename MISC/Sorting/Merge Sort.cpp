void merge(int n, int start, int mid, int end) {
	int t[end-start+1], k = 0;
	int p = start, q = mid+1;
	int inv = 0;

	for(int i = start; i <= end; i++) {
		if(p > mid) t[k++] = a[q++];
		else if(q > end) t[k++] = a[p++];
		else if(a[p] <= a[q]) t[k++] = a[p++];
		else t[k++] = a[q++];
	}

	F0R(i,k) {
		a[start++] = t[i];
	}
}

void mergesort(int n, int start, int end) {
	int inv = 0;
	if(start < end) {
		int mid = (start+end)/2;

		memrgesort(n, start, mid);
		mergesort(n, mid+1, end);
		merge(n, start, mid, end);
	}
		
}

void solve() {
	int n;
	cin >> n;

	memset(a,0,sizeof(a));
	F0R(i,n) cin >> a[i];
	mergesort(n,0,n-1)
	// cout <<  << "\n";

}