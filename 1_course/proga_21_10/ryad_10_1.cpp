#include<iostream>
using namespace std;
int main()
{
	int Sum, n, p;
	double t, x, k;
	cout << "Enter n " << endl;
	cin >> n;
	cout << "Enter number of x " << endl;
	cin >> p;
	for (int i = 0; i < p; i++)
	{
		cout << "Enter x[" << i << "] = ";
		cin >> x;
		Sum = 0;
		k = 0;
		t = x;
			for (k = 1; k < n; k++)
			{
				t = - t * (x * x * (2 * k - 1)) / (k * (2 * k + 1));
				Sum += t;
			}
		cout << "Sum = " << Sum << endl;
	}
	return 0;
}
