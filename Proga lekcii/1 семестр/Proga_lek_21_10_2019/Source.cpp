//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cout << "Enter n ";
//	cin >> n;
//	int **a=new int *[n];
//	int i, j;
//	
//	for (i = 0; i < n; i++)
//		a[i] = new int[n];
//	cout << "Enter array a:" << endl;
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//		{
//			cout << "a[" << i << "][" << i << "]=";
//			cin >> a[i][j];
//		}
//	cout << "Array a:" << endl;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//			cout << set(5) <<  a[i][j] << " ";
//		cout << endl;
//	}
//
//
//	bool p = false;
//	for (i = 0; i < n && !p; i++)
//	{
//		bool q = true;
//		for (j = 0; j < n && q; j++)
//			if (a[i][j] <= 0) q = false;
//		p = q;
//	}
//	cout << "p = " << p;
//	
//	
//	return 0;
//}


// Умножение матриц
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n, i, j, k;
	cout << "Enter n ";
	cin >> n;
	int** a = new int* [n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	int** b = new int* [n];
	for (i = 0; i < n; i++)
		b[i] = new int[n];
	int** c = new int* [n];
	for (i = 0; i < n; i++)
		c[i] = new int[n];
	cout << "Enter array a:" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	cout << "Enter array b:" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "b[" << i << "][" << j << "]=";
			cin >> b[i][j];
		}

	cout << "Array a:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)

			cout << setw(5)<< a[i][j] << " ";
		cout << endl;
	}

	cout << "Array b:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)

			cout << setw(5) << b[i][j] << " ";
		cout << endl;
	}

	bool p = false;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
	{
			c[i][j] = 0;
			for (k = 0; k < n; k++)
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
	}
	 

	cout << "Array c:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)

			cout << setw(5) << c[i][j] << " ";
		cout << endl;
	}


	return 0;
}
