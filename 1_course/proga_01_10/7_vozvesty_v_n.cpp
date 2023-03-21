#include<iostream>
using namespace std;
int main()
{
	int n, a, b, i = 0;
	cout << "Enter number " ;
	cin >> a;
	cout << "n = ";
	cin >> n;
	b = 1;
	while (i < n)
	{
        b *= a;
		i++;
	}
	cout << "a^n="<< b;
	return 0;
}