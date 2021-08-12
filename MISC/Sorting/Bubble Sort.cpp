#include <iostream>
using namespace std;

// Bubble Sort
// TC
// Best Case - O(1) comparisons O(n) swaps
// Avg Case - O(n*n) comparisons O(n*n) swaps
// SC = O(1)

void Bubble_Sort(int a[], int n)
{
	for(int i = 0; i < n; ++i)	
	{
		bool swapped = 0;
		for(int j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j],a[j+1]);
				swapped = 1;
			}
		}
		if(!swapped)
		{
			break;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	Bubble_Sort(a, n);
}