#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	int *A=new int [n];
	bool t = true, p = true;
	int sum = 0, i = 0, j = 0, g = 0;
	for (i = 0; i < n; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}
	for (i = 0; i < n && t; i++)
	{
		if (A[i] == 0)
		{
			j = i + 1;
			t = false;
		}
	}
	for (i = n-1; i >= 0 && p; i--)
	{
		if (A[i] == 0)
		{
			g = i - 1;
			p = false;
		}
	}
	for (i = j; i<= g; i++)
	{
		sum += A[i];
	}
	

	cout << "sum=" << sum;
	return 0;
}