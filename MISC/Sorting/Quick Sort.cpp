#include <iostream>
using namespace std;

// Quick Sort
// TC
// Best Case - O(nlogn)
// Avg Case - O(nlogn)
// Worst Case - O(n*n)
// SC = O(logn)

const int N = 100;
int a[N];

int Partition(int a[], int p, int r)
{
	int x = a[r];
	int i = p-1;
	for(int j = p; j <= r-1; j++)
	{
		if(a[j] <= x)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	i++;
	swap(a[i],a[r]);
	return i;
}

void Quick_Sort(int a[], int p, int r)
{
	if(p < r)
	{
		int q = Partition(a,p,r);
		Quick_Sort(a,p,q-1);
		Quick_Sort(a,q+1,r);
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
	Quick_Sort(a, 0, n-1);
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
}