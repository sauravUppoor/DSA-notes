// Sparse Table
// Range Min Queries
// Time - O(1)
// Space - O(N*32)

template <typename T>
class SparseTable {
public:
    using F = function<T(const T&, const T&)>;
 
    int n;
    vector<vector<T>> mat;
    F f;
    SparseTable(): n(), mat(), f() {}
 
    template <typename U>
    SparseTable(const U& arr, int n, F f): n(n), f(f), mat((int)log2(n) + 1) {
        mat[0].resize(n);
        for (int i = 0; i < n; i++)
            mat[0][i] = T(arr[i]);
        for (int j = 1; j < mat.size(); j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i + (1 << j) <= n; i++) {
                mat[j][i] = f(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = 32 - __builtin_clz(r - l + 1) - 1;
        return f(mat[j][l], mat[j][r + 1 - (1 << j)]);
    }
};

void solve() {
	int n; cin >> n;
	
	vector<int> a(n);
	for(auto &x : a) cin >> x;
	
	SparseTable<int> gcd(a, n, [&](int a, int b) { return __gcd(a,b); });
	SparseTable<int> mn(a, n, [&](int a, int b) { return min(a,b); });
}
