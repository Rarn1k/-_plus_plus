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

bool number_several_times(int a[n][n], int k, int l)
{
	int j, x = 0;
	bool p = true;
	for (j = 0; j < n; j++)
		if (a[l][j] == k)
			x++;
	if (x < 3) p = false;
	return p;
}

void matrix_rows_with_the_same_number(int a[n][n], int k)
{
	int i;
	bool g;
	cout << "Matrix rows with number " << k << ": " << endl;
	for (i = 0; i < n; i++)
	{
		g = number_several_times(a, k, i);
		if (g) cout << i << " ";
	}

}

int main()
{
	int a[n][n];
	int k;
	create(a);
	show(a);
	cout << endl;
	cout << "Enter k = ";
	cin >> k;
	matrix_rows_with_the_same_number(a, k);
	return 0;
}