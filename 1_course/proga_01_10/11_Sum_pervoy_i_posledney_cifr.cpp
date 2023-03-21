#include<iostream>
using namespace std;
int main()
{
	int a, b, c, sum;
	cout << "Enter a ";
	cin >> a;
	c = a / 10;
	b = a % 10;
	for (int i = 10; a / i > 10; i *= 10)
	{
		c = a / i / 10;
	}
	sum = b + c;
	cout << "Sum = " << c << " + " << b << " = " << sum;
	return 0;
}