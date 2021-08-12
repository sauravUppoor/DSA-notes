#include <iostream>
using namespace std;

/*
Induction
go(7) --> go(6) --> go(5) --> ...
 (7)		(6)		  (5) 	...

Base
go(1)
*/

void go(int n)
{
	if(n == 1) {cout << 1 << ' '; return;}
	cout << n << ' ';
	go(n-1);
}

int main()
{
	int n;
	cin >> n;
	go(n); // n to 1 print - Hypothesis
}