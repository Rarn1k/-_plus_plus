#include<iostream>
using namespace std;
int main()
{
	long int n;
	int i = 1, f = 1;
	cout << "Enter n ";
	cin >> n;
	while (i <=n)
	{
		f *= i;
		i++;
	}
	cout << f << endl;
	return 0;
}
