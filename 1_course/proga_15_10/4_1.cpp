p#include<iostream>
using namespace std;
int main()

{
	const int n = 10;
	int a[n], i;
	bool t = 1, b = 1;
	cout << "Enter array a" << endl;

	for (i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	
	for (i = 0; i < n && t; i++)
	{
		if (a[i] < 2) t = 0;
		for (int j = 2; j <= sqrt(a[i]) && t; j++)
		{
			if (a[i] % j == 0)
				t = 0;
		}
	}
     
	for (i = 0; i < n-1 && b; i++)
	{
		if (a[i] >= a[i+1])
			b = 0;
	}

	cout << endl;
	if (t && b)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
