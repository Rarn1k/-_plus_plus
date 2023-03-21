#include<iostream>//первые a символов строки заменить на &
#include<cstring>
using namespace std;
int main()
{
	const int m = 50;
	char a[m];
	cout << "Enter str: ";
	cin.getline(a, m);
	int b, j,  i = 0;
	int g, c = 0;
	cout << "Enter a = ";
	cin >> g;
	b = strlen(a);
	j = a[b - 1] - '0';
	if (g == j)
	{
		for (c = 0; c < g; c++)
		{ 
			if (a[i] == ' ')
				c--;
			else
				a[i] = '&';
			i++;
		}
	}
	else
		cout << "Error" << endl;
	cout << a << endl;
	return (0);
}