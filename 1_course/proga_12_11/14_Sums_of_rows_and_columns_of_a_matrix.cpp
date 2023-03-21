#include<iostream>
#include<iomanip>
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

void cout_5_smt(int x)
{
	cout << setw(5) << x;
}


void show(int a[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout_5_smt(a[i][j]);
		cout << endl;
	}
}

int sum_of_row(int a[n][n], int l)
{
	int sum = 0;
	for (int j = 0; j < n; j++)
		sum += a[l][j];
	return sum;
}

int sum_of_column(int a[n][n], int l)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i][l];
	return sum;
}

void sums_of_rows_and_columns(int a[n][n])
{
	int row, column;
	for (int i = 0; i < n; i++)
	{
		row = sum_of_row(a, i);
		for (int j = 0; j < n; j++)
			cout_5_smt(a[i][j]);
		cout_5_smt(row);
		cout << endl;
	}
	for (int j = 0; j < n; j++)
	{
		column = sum_of_column(a, j);
		cout_5_smt(column);
	}
}

int main()
{
	int a[n][n];
	cout << "Enter array a:" << endl;
	create(a);
	cout << "Array a:" << endl;
	show(a);
	cout << "Array a with sums :" << endl;
	sums_of_rows_and_columns(a);
	return 0;
}