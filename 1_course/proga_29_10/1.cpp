#include <iostream>
using namespace std;
int main()
{
	const int n = 4;
	int A[n];
	bool t = true, p = true;
	int sum = 0, i, j;
	for (i = 0; i < n; i++)
		cin >> A[i];
	for (i = n - 1; i >= 0; i--)
	{
		if ((A[i] == 0) && (A[i - 1] == 0))
		{
			cout << "0";
			p = false;
		}
		
	}
	for (i = n - 1; i >= 0 && p; i--)
	{
		if (A[i] == 0 && t)
		{
			j = i-1;
			for (i = j; A[i] != 0; i--)
				sum += A[i];
			t = false;
		}
	}
	
	cout << "sum=" << sum;
	return 0;
}
