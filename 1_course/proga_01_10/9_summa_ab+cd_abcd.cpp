#include <iostream>
using namespace std;
int main()
{
	int abcd, ab, cd, x;
	cout << "Enter abcd ";
	cin >> abcd;
	ab = abcd / 100;
	cd = abcd % 100;
	x = ab + cd;
	cout << "ab+cd=" << ab << '+' << cd << '=' << x;
	return 0;
}