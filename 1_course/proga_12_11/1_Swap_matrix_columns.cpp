#include <iostream>
#include <iomanip>
using namespace std;
const int n = 4;
void create(int a[n][n])
{
	int i, j;
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
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw(5) << a[i][j];
	cout << endl;
    }
}


void swap_columns(int a[n][n])
{
	int i, j, x, y;
	cout << "Enter 1st column: x = ";
	cin >> x;
	cout << "Enter 2nd column: y = ";
	cin >> y;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (j == x)
				swap(a[i][j], a[i][y]);
	show(a);
}

int main()
{
	int a[n][n];
	cout << "Enter array a: " << endl;
    create(a);
	cout << "Array a: " << endl;
	show(a);
	
	cout << "Array a with swapped colums: " << endl;
	swap_columns(a);


	return 0;
}
