#include <iostream>
#include <iomanip>
using namespace std;
const int n = 4;

void create(int a[n][n])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			cout << "Enter [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	for (int i = 0; i < n; i++)
		a[i][n - 1] = 0;
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

int sum_of_the_row_elements(int a[n][n], int l)
{
	int sum = 0;
	for (int j = 0; j < n - 1; j++)
		sum += a[l][j];
	return sum;
}

void lest_element_of_rows(int a[n][n])
{
	for (int i = 0; i < n; i++)
		a[i][n - 1] = sum_of_the_row_elements(a, i);
	cout << "Changed arra a:" << endl;
	show(a);
}

int main()
{
	int a[n][n];
	cout << "Enter array a:" << endl;
	create(a);
	cout << "Array a:" << endl;
	show(a);
	lest_element_of_rows(a);
	return 0;
}