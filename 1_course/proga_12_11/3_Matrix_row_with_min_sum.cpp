#include <iostream>
#include <iomanip>
using namespace std;
const int n = 4;
void create(int a[n][n]) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void show(int a[n][n]) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
}

void show_row(int a[n]) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int sum_row(int a[n][n], int i, int j)
{
	int sum_row = 0;
		for (j = 0; j < n; j++)
		sum_row += a[i][j];
	return sum_row;
}

void row_with_min_sum(int a[n][n])
{
	int i, j, sum = 0;
	int g[n], summ[n];
	/*for (j = 0; j < n; j++) {
		g[j] = a[0][j];
		sum += a[0][j];
	}*/
	for (j = 0; j < n; j++) 
		g[j] = a[0][j];
	sum = sum_row(a, 0, j);
	summ[0] = sum;
	cout << "sum [0] = " << summ[0] << endl;
	sum = 0;

	for (i = 1; i < n; i++) {
		/*for (j = 0; j < n; j++)
			sum += a[i][j];*/
		sum = sum_row(a, i, j);
		summ[i] = sum;
		cout << "sum [" << i << "] = " << summ[i] << endl;
		if ((summ[i] < summ[i - 1]) && (summ[i] < summ[0]))
			for (j = 0; j < n; j++)
				g[j] = a[i][j];
		sum = 0;
	}
	cout << endl << "Matrix row with minimum sum of elements : " << endl;
	show_row(g);
}

////void row_with_min_summ(int a[n][n])
////{
////	int i, j, sum, sum_one;
////	int g[n];
////	for (i = 0; i < n; i++)
////	{
////		sum_one = sum_row(a);
////	}
////}

int main() {
	int a[n][n];
	cout << "Enter array a: " << endl;
	create(a);
	cout << "Array a: " << endl;
	show(a);
	cout << endl;
	row_with_min_sum(a);
	return 0;
}