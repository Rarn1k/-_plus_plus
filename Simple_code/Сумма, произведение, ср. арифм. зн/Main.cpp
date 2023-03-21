#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "Enter 1st number ";
	cin >> a;
	cout << "Enter 2nd number ";
	cin >> b;
	cout << "Enter 3rd number ";
	cin >> c;
	cout << "Amount=" << a + b + c << endl << "1*2*3=" << a * b * c << endl << "avarage=" << (a + b + c) / 3;
	return 0;
}