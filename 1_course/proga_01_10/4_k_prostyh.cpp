#include<iostream>
using namespace std;
int main()
{
	int n;
	int k, b, a;
	k = 0;
	cout << "Enter n ";
	cin >> n;
	while (n >= 2)
	{
		b = 0;
		a = 2;
		while (n > a)
		{
			if (n % a == 0)
			{
				b = 7 ;
			}		
				a++;
		}
		if ((n % n == 0) && (b == 0))
		{
	      k = k + 1;
	    }
		cout << "Enter n ";
		cin >> n;
	}
	cout << k << endl;
	return 0;
}

