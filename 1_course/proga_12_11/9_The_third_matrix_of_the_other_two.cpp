#include <iostream>
#include <iomanip>
using namespace std;
const int n = 4;

void create(int a[n][n])
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Enter " << "[" << i << "][" << j << "] = ";
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

void third_matrix_of_the_other_two(int a[n][n], int b[n][n])
{
	int c[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > b[i][j])
				c[i][j] = a[i][j];
			else
				c[i][j] = b[i][j];
		}
	show(c);
}

int main()
{
	int a[n][n];
	cout << "Enter array a:" << endl;
	create(a);
	int b[n][n];
	cout << "Enter array b:" << endl;
	create(b);
	cout << "Matrix a:" << endl;
	show(a);
	cout << "Matrix b:" << endl;
	show(b);
	cout << "Matrix c:" << endl;
	third_matrix_of_the_other_two(a, b);
	return 0;
}