#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void create(int**, int);
void show(int**, int);
bool prime(int);
bool EA(int**, int);
void mult(int**, int**, int**, int);
void add(int**, int**, int**, int);
void op1(int**, int**, int);
void op2(int**, int**, int);
void del(int**, int);
int max_cifra(int);
int sum_div(int);

int main()
{

	int n;
	cout << "enter size of array n=";
	cin >> n;
	int** a, ** b, ** c, ** d, ** e;
	int i;
	a = new int* [n];
	b = new int* [n];
	c = new int* [n];
	d = new int* [n];
	e = new int* [n];
	for (i = 0; i < n; i++)
	{
		a[i] = new int[n];
		b[i] = new int[n];
		c[i] = new int[n];
		d[i] = new int[n];
		e[i] = new int[n];
	}
	cout << "enter array a:" << endl;
	create(a, n);
	cout << "enter array a:" << endl;
	create(b, n);

	cout << "array a:" << endl;
	show(a, n);

	cout << "array b:" << endl;
	show(b, n);

	if (EA(a, n))
	{
		op1(a, d, n);
		op2(b, e, n);
		add(d, e, c, n);
	}
	else
	{
		op1(b, d, n);
		op2(a, e, n);
		mult(d, e, c, n);
	}
	cout << "array c:" << endl;
	show(c, n);

	del(a, n);
	del(b, n);
	del(c, n);
	del(d, n);
	del(e, n);


	system("pause");
	return 0;
}
//////////////////////////////////////////////
void create(int** x, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "x[" << i << "][" << j << "]=";
			cin >> x[i][j];
		}
}
/////////////////////////////////////////
void show(int** x, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw(5) << x[i][j];
		cout << endl;
	}
}
/////////////////////////////////////////////
bool prime(int x)
{
	bool t;
	int i;
	if (x <= 1) return false;
	if (x == 2) return true;
	t = true;
	for (i = 2; i <= sqrt(x) && t; i++)
		if (x % i == 0) t = false;
	return t;
}
////////////////////////////////////////////
bool EA(int** x, int n)
{
	bool p, q;
	int i, j;
	p = false;
	for (i = 0; i < n && !p; i++)
	{
		q = true;
		for (j = 0; j < n - 1 && q; j++)
			if (x[i][j] > x[i][j + 1])q = false;
		p = q;
	}
	return p;
}
//////////////////////////////////////////
void mult(int** x, int** y, int** z, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			z[i][j] = 0;
			for (k = 0; k < n; k++)
				z[i][j] = z[i][j] + x[i][k] * y[k][j];
		}
}
void add(int** x, int** y, int** z, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			z[i][j] = x[i][j] + y[i][j];
}
//////////////////////////////////////////////////////////////
int sum_div(int x)
{
	int i,
		s = 0;
	for (i = 2; i < x; i++)
		if (x % i == 0)
			s = s + i;
	return s;
}
//////////////////////////////////////////////////
void op1(int** x, int** y, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			y[i][j] = sum_div(x[i][j]);
}
//////////////////////////////////////////////////////
int max_cifra(int x)
{
	int max = 0;
	while (x > 0)
	{
		if (max < x % 10)
			max = x % 10;
		x = x / 10;
	}
	return max;
}
void op2(int** x, int** y, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (prime(max_cifra(x[i][j])))
				y[i][j] = x[i][j];
			else
				y[i][j] = x[i][j] * x[i][j];
}
/////////////////////////////////////////
void del(int** x, int n)
{
	int i;
	for (i = 0; i < n; i++)
		delete[] x[i];
	delete[] x;
}