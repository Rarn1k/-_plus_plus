#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus"); //функция, отвечающая за вывод русских символов в консоль
	int Var, Var2;

	cout << "Введите два числа: ";
	cin >> Var >> Var2;

	cout << "Вы ввели число 1 = " << Var << endl << "Вы ввели число 2 = " << Var2 << endl;
	const int n = 5;
	int k[n]{ 5, 1, 2, 4, 6 };
	int x;
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j >= i + 1; j--)
			if (k[j] <= k[j - 1])
			{
				x = k[j];
				k[j] = k[j - 1];
				k[j - 1] = x;
			}
	for (int i = 0; i < n; i++)
		cout << k[i];
	return 0;
}