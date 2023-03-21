#include <iostream>
#include <iomanip>
using namespace std;
const int n = 4;

void create(int a[n][n])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Enter [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void show(int a[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
}

void exchange_of_values(int a[n][n])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				swap(a[i][j], a[i][n - 1 - i]);
	show(a);
}
int main()
{
	int a[n][n];
	cout << "Enter array a:" << endl;
	create(a);
	cout << "Array a:" << endl;
	show(a);
	cout << "Changed Array a:" << endl;
	exchange_of_values(a);
	return 0;
}