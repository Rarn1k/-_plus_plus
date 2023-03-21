#include<iostream>
#include<iomanip>
using namespace std;

double** create(int n)
{
	int i, j;
	double** a = new double*[n];
	for (i = 0; i < n; i++)
		a[i] = new double[n + 1];
	for (i = 0; i < n; i++)
		for (j = 0; j < n + 1; j++)
		{
			cout << "Enter [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	return a;
}

void show(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(10) << a[i][j];
		cout << "|" << setw(10) << a[i][n];
		cout << endl;
	}
	cout << endl;
}

double** zeroing_1(double** a, int n, int x)
{
	int i, j;
	double g;
	for (i = x + 1; i < n; i++)
	{
		g = a[i][x] / a[x][x];
		for (j = x; j < n + 1; j++)
			a[i][j] = a[i][j] - (a[x][j] * g);
	}
	return a;
}

double** zeroing_down(double** a, int n)
{
	int q;
	for (q = 0; q < n - 1; q++)
		a = zeroing_1(a, n, q);
	return a;
}

double** zeroing_2(double** a, int n, int x)
{
	int i, j;
	double g;
	for (i = x - 1; i >= 0; i--)
	{
		g = a[i][x] / a[x][x];
		for (j = n; j >= 0; j--)
			a[i][j] = a[i][j] - (a[x][j] * g);
	}
	return a;
}

double** zeroing_top(double** a, int n)
{
	int q;
	for (q = n - 1; q > 0; q--)
		a = zeroing_2(a, n, q);
	return a;
}

void answer(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i][i] = a[i][n] / a[i][i];
		cout << "x" << i << " = " << setw(5) << a[i][i] << endl;
	}
}

int main()
{
	int n;
	cout << "Enter n = ";
	cin >> n;

	cout << "Enter matrix : " << endl;
	double** a = create(n);
	cout << "Matrix : " << endl;
	show(a, n);

	a = zeroing_1(a, n, 0);
	cout << "Matrix with 0 in first column : " << endl;
	show(a, n);

	a = zeroing_down(a, n);
	cout << "Step matrix : " << endl;
	show(a, n);

	a = zeroing_2(a, n, n - 1);
	cout << "Matrix with 0 in last column : " << endl;
	show(a, n);

	a = zeroing_top(a, n);
	cout << "Step matrix : " << endl;
	show(a, n);

	answer(a, n);

	return 0;
}