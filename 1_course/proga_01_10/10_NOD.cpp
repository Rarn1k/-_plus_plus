#include<iostream>
using namespace std;
int main()
{
	int n, m, x;
	x = 0;
	cout << "Enter n ";
	cin >> n;
	cout << "Enter m ";
	cin >> m;
	for (int i = 2; i <= n; i++)
	{
		if ((n % i == 0) && (m % i == 0))
		{
			x = i;
		}
	}
    if (x == 0 )
	{
		cout << "No dividers";
	}
	else
	{
		cout << "NOD = " << x;

	}
	return 0;
}