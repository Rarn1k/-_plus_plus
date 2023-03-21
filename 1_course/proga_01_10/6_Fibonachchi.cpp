#include<iostream>
using namespace std;
int main()
{
	int n, g = 0, a = 0, c = 1, f;
	cout << "Enter n ";
	cin >> n; //число элементов
	while (a < n)
	{

		f = g + c;
		cout << f << endl;
		a++; 
		c = g;
		g = f; 
	}
	return 0;
}