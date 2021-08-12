#include <iostream>
using namespace std;

// Selection Sort
// TC
// Best Case - O(n*n) comparison O(1) swaps
// Avg Case - O(n*n) comparison O(n) swaps
// Worst Case - O(n*n) comparison O(n) swaps
// SC = O(1)

const int N = 100;
int a[N];

void Selection_Sort(int a[], int n)
{
	int imin = -1;
	for(int i = 0; i < n; ++i)
	{
		imin = i;
		for(int j = i+1; j < n; ++j)
		{
			if(a[j] < a[imin])
			{
				imin = j;
			}
		}
		swap(a[imin],a[i]);
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	Selection_Sort(a, n);
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
}