// Binary Indexed Tree
// TC - 
// 1. Query / Prefix Sums [L,R] : O(logN) Sum up values by staircasing down last set bit number of times
// 2. Update : O(logN) Update bit values of all those above who "own" us. Unset bits of current index

struct BIT {
	int size;
	vi bit;

	BIT(int n) {
		size = n;
		bit.assign(0, size);
	}

	void update(int i, int delta) { 
		while(i < size) {
			bit[i] += delta;
			i += i&-i;
		}
	}
	
	int pref(int i) {
		int sum = 0;
		while(i > 0) {
			sum += bit[i];
			i -= i&-i;
		}
	}
};
