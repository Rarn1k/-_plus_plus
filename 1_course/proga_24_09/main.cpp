#include<iostream>
using namespace std;
int main()
{
	double x, y, z, u1, u2;
	cout << "Enter x ";
	cin >> x;
	cout << "Enter y ";
	cin >> y;
	cout << "Enter z ";
	cin >> z;

	u1 = 2.3 - x;
	u1 = u1 / y;
	u1 = u1 * z;
	u1 = u1 + 3.15;
	u1 = u1 / x;
	u1 = u1 - y;
	u1 = u1 * z;
	u1 = u1 + x;

	u2 = x + y;
	u2 += 2.1;
	u2 *= z;
	x -= z;
	x -= 5.6;
	u2 /= x;
	u2 += y;
	y = z + 1.0;
	x = z - 2.0;
	z = x / y;
	u2 += z;

	cout << "u1=" << u1 << endl;
	cout << "u2=" << u2 << endl;
	return 0;
}



// Д/З 4
