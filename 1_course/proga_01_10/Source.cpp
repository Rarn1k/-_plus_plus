#include<iostream>
using namespace std;
int main()
{
	long int n;
	int k1, k2;
	setlocale(LC_ALL, "Rus");
	cout << "Введите n ";
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
	cout << "Чётных чисел " << k1 << endl;
	cout << "Нечётных чисел " << k2 << endl;
	return 0;
}