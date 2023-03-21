#include<iostream>// Подсчитать сколько слов содержит ровно две буквы а
#include<cstring>
using namespace std;
int main()
{
	const int m = 50;
	char a[m];
	int i = 0, k = 0, s = 0, num = 0, ans = 0, space = 0;
	char g;
	bool t = true;
	cout << "Enter str: ";
	cin.getline(a, m);
	cout << "Enter a = ";
	cin >> g;
	
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != ' ')
		{
			k++;
		}
		else
		{
			if (k != 0)
				s++;
			k = 0;
		}
	}
	if (k != 0)
		s++;
	k = 0;
	for (int j = 0; j != s; j++)
	{
		for (i = k; a[i] != ' ' && a[i] != '\0'; i++)
		{
			if (!(isalpha(a[i])))
				t = false;
			if (a[i] == g && t)
				num++;
			space++;
		}
		if (space == 0)
			j--;
		if (num == 2)
			ans++;
		k = i + 1;
		num = 0;
		space = 0;
		t = true;
	}
	cout << ans << endl;

	return(0);
}