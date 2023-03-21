#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//int num_c(int x) // количество цифр в числе
//{
//	if (x == 0) return 1;
//	int num = 0;
//	while (x != 0)
//	{
//		x = x / 10;
//		num++;
//	}
//	return num;
//}
//
//int sum_c(int x) // сумма цифр в числе
//{
//	
//	int sum = 0;
//	while (x != 0)
//	{
//		sum += abs( x % 10);
//		x = x / 10;
//
//	}
//	return sum;
//}
//
//int max_c(int x) // наибольшая цифра в числе
//{
//	int max = 0;
//	while (x != 0)
//	{
//		if (max < abs(x % 10))
//			max = abs(x % 10);
//		x = x / 10;
//
//	}
//	return max;
//}
//
//
//int main()
//{
//	int n;
//	cout << "Enter n = ";
//	cin >> n;
//	cout << "Num = " << num_c(n) << endl;
//	cout << "Sum = " << sum_c(n) << endl;
//	cout << "Max = " << max_c(n) << endl;
//
//
//	return 0;
//}

int** create(int n)
{
	int** x = new int* [n];
	int i;
	for (i = 0; i < n; i++)
		x[i] = new int[n];
	int j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "x[" << i << "][" << j << "] = ";
			cin >> x[i][j];
		}
	return x;
}

void show(int** x, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw(5) << x[i][j] ;
		cout << endl;
	}
}

bool prime(int x) // простое ли число
{
	if (x <= 1) return false;
	if (x == 2) return true;
	int i;
	bool p = true;
	for (i = 2; (i * i <= x) && p; i++)
		if (x % i == 0) p = false;
	return p;
}

int** mult(int** x, int** y, int n)
{
	int i, j, k;
	int** z = new int* [n];
	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			z[i][j] = 0;
			for (k = 0; k < n; k++)
				z[i][j] = z[i][j] + x[i][k] * y[k][j];
		}
	return z;
}

int** add(int** x, int** y, int n)
{
	int i, j, k;
	int** z = new int* [n];
	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			z[i][j] = x[i][j] + y[i][j];
	return z;
}

bool EA(int** x, int n)
{
	int i, j;
	bool p, q;
	p = false;
	for (i = 0; (i < n) && !p; i++)
	{
		q = true;
		for (j = 0; (j < n) && q; j++)
			if (!prime(x[i][j])) q = false;
		p = q;
	}
	return p;
}


void interval_prime(int n, int m) // Выписать все простые числа на отрезке (n;m)
{
	int i;
	for (i = n; i <= m; i++)
		if (prime(i)) cout << i << " ";
	cout << endl;
}

int main()
{
	/*int n, m;
	cout << "Enter n = ";
	cin >> n;
	cout << "Enter m = ";
	cin >> m;*/


	/*interval_prime(n, m);*/

	/*if (prime(n)) cout << "Prime number";
	else cout << "Not prime number";
	cout << endl;*/

	//cout << "Prime n = " << prime(n) << endl;
	int n;
	cout << "Enter n = ";
	cin >> n;
	cout << "Enter array a: " << endl;
	int** a = create(n);
	cout << "Enter array b: " << endl;
	int** b = create(n);
	cout << " Array a: " << endl;
	show(a, n);
	cout << " Array b: " << endl;
	show(b, n);
	int** c;
	if (EA(a, n)) c = mult(a, b, n);
	else c = add(a, b, n);
	cout << "Array c: " << endl;
	show(c, n);
	return 0;
}