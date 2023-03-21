#include <iostream>;
using namespace std;
int main()
{
	int m, n;
	cout << "Enter m ";
	cin >> m;
	cout << "Enter n ";
	cin >> n;
	if (m < n)
	{
		int a, i;
		i = 1;
		a = m + 1;
		while (a < n)
		{
			cout << "Dividers " << a << ": ";
			while (i < a)
			{
				if ((a % i == 0) && (i != 1))
				{
					cout << i << " ";
				} 
				i++;
			}
			i = 1;
			cout << endl;
			a++;
		}

	}
	else
	{
		cout << "You have to enter m < n";
	}
	return 0;
}