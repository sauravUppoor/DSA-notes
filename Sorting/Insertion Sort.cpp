#include <iostream>
using namespace std;

// Insertion Sort
// TC = O(n*n)
// SC = O(1)
void Insertion_Sort(int a[], int n)
{
	for(int j = 1; j < n; ++j)
	{
		int key = a[j];
		int i = j-1;
		while(i >= 0 && a[i] > key)
		{
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
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
	Insertion_Sort(a, n);
}