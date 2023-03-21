#include<iostream>
using namespace std;
int main()
{
	long int n;
	int k1, k2;
	setlocale(LC_ALL, "Rus");
	cout << "Ââåäèòå n ";
	cin >> n;
	k1 = 0;
	k2 = 0;
	while (n > 0)
	{
		int digit;
		digit = n % 10;
		if (digit % 2 == 0)
		{
			k1 += 1;
		}
		else
		{
			k2 += 1;
		}
		n /= 10;
	}
	cout << "×¸òíûõ ÷èñåë " << k1 << endl;
	cout << "Íå÷¸òíûõ ÷èñåë " << k2 << endl;
	return 0;
}
