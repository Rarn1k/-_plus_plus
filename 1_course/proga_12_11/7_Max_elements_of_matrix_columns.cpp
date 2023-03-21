#include <iostream>
#include <iomanip>
using namespace std;
const int n = 4;
void create(int a[n][n]) 
{
	int i, j;
	cout << "Enter array a: " << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) 
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void show(int a[n][n]) 
{
	int i, j;
	cout << "Array a: " << endl;
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
}

void max_elements_of_matrix_columns(int a[n][n]) 
{
	int i, j, max, k = 0, q = 0;
	int* g = new int[n];
	for (j = 0; j < n; j++) 
	{
		max = a[0][j];
		for (i = 0; i < n; i++)
			if (a[i][j] > max)
				max = a[i][j];
		g[q] = max;
		q++;
	}
	cout << "Maximum elements of matrix columns : " << endl;

	for (q = 0; q < n; q++)
		cout << g[q] << " ";
}

int main() 
{
	int a[n][n];
	create(a);
	show(a);
	cout << endl;
	max_elements_of_matrix_columns(a);
	return 0;
}