// Binary Search templates

// 1. Finding lower/upper bounds in a range [l..r]

int bs(int l, in r) {
	// l, r are the values in range answer exists [l...r]
	while(l < r) {
		int mid = (l+r)/2;

		// for upper bound
		if(good(mid)) l = mid;
		else r = mid - 1;

		//for lower bound
		if(good(mid)) r = mid;
		else l = mid + 1
	}
	return l;
}