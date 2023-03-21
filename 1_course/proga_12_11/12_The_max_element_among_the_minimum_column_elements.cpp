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

void show(int a[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
}

int min_elemet_of_column(int a[n][n], int l)
{
	int min;
	min = a[0][l];
	for (int i = 1; i < n; i++)
		if (a[i][l] < min)
			min = a[i][l];
	return min;
}

int max_element(int a[n][n])
{
	int max, x;
	max = min_elemet_of_column(a, 0);
	for (int j = 1; j < n; j++)
	{
		x = min_elemet_of_column(a, j);
		if (x > max) max = x;
	}
	return max;
}

int main()
{
	int a[n][n];
	int max;
	cout << "Enter array a:" << endl;
	create(a);
	cout << "Array a:" << endl;
	show(a);
	max = max_element(a);
	cout << "The max element amoung the min column elements : " << max;
	return 0;
	
}