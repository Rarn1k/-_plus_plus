#include<iostream>
using namespace std;
int main()
{
	int a, b, n, sum;
	cout << "Enter a ";
	cin >> a;
	cout << "Enter b ";
	cin >> b;
	n = a;
	sum = 0;
	if (b >= a)
	{
		for (n; n <= b; n++)
		{
			sum += n;
		}
		cout << "Sum = " << sum;
	}
	else
	{
		cout << "Enter a <= b";
	}
	return 0;
}