#include<iostream>
#include<iomanip>

using namespace std;
int mult(int**x,int**y, int n)
{
	int** z = new int* [n];
	int i, j, k;
	
	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			z[i][j] = 0;
			for(k=0; k<n;k++)
			z[i][j] = x[i][j] * y[i][j];
		}


	return **z;
}
int add(int** x, int** y, int n)
{
	int** z = new int* [n];
	int i, j;

	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			z[i][j] = x[i][j] + y[i][j];
	return **z;
}
int** create(int n)
{
	
}
void show(int** z, int n)
{
	int i, j;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw(10) << z[i][j];
		cout << endl;
	}
}
void del(int** x, int n)
{
	int i;
	for (i = 0; i < n; i++)
		delete[] x[i];
	delete[] x;
}
int main()
{
	int n;
	cout << "Enter suze of array: n=";
	cin >> n;
	cout << "Enter array a:" << endl;
	int** a = create(n);
	cout << "Enter array b:" << endl;
	int** b = create(n);
	cout << "Array a:" << endl;
	show(a, n);
	cout << "Array b:" << endl;
	show(b, n);
	int** c = add(mult(a, b, n), a, n);
	cout << "Array c:" << endl;
	show(c, n);

}