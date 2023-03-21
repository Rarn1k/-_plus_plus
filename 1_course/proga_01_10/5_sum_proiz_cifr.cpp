#include<iostream>
using namespace std;
int main()
{
	long int n;
	int sum, pr;
	sum = 0;
	pr = 1;
	cout << "Enter n ";
	cin >> n;
	while (n > 0)
	{
		int digit;
		digit = n % 10;
		sum += digit;
		pr *= digit;
		n /= 10;
	}
	cout << "Sum = " << sum << endl << "Pr = " << pr << endl;
	return 0;
}