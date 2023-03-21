#include <iostream>
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

bool twodigit_number(int x)
{
	if ((fabs(x) > 9) && (fabs(x) < 100)) return true;
	return false;
}

int number_of_two_digit_numbers(int a[n][n])
{
	bool p;
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			p = twodigit_number(a[i][j]);
			if (p == true) k++;
		}
	return k;
}

int main()
{
	int a[n][n];
	cout << "Enter array a:" << endl;
	create(a);
	cout << "Array a:" << endl;
	show(a);
	cout << "Number of two-digit numbers in the matrix: " << number_of_two_digit_numbers(a);
	return 0;
}