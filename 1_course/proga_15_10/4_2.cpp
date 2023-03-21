#include<iostream>
using namespace std;
const int n = 10;
int main()
{
	double c[n], sr_pol, sum_pol, sum_otric, sr_otric, pr;
	int p = 0, b = 0;
	sum_pol = 0;
	sum_otric = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter c[" << i << "] = ";
		cin >> c[i];
	}
	for (int i = 0; i < n; i++)
		cout << c[i] << " ";
	cout << endl;

	for (int i = 0; i < n; i++)
	{
	
		if (c[i] >= 0)
		{
			sum_pol += c[i];
			p++;
		}
		else
		{
			sum_otric += c[i];
			b++;
		}
	}
	sr_pol = sum_pol / p;
	sr_otric = sum_otric / b;
	pr = sr_pol * sr_otric;
	cout << pr;
	return 0;
}