#include<iostream>
using namespace std;
int main()
{
	long int n;
	int sum;
	cout << "Enter n ";
	cin >> n;
	sum = 0;
	while (n > 0)
	{
		int digit;
		digit = n % 10;
		if (digit % 2 == 0)
		{
			sum = sum + digit;
		}
		n /= 10;
	}
	cout << sum << endl;
	return 0;
}
