#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
	const int m = 100;
	char str[m];
	int n = 0;
	int k = 0;
	int count = 0;
	bool f = true;
	cout << "Enter string: ";
	cin.getline(str, m);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if ((!(isalpha(str[i]))) && f)
				f = false;
			k++;
		}
		else
		{
			if (f && (k != 0))
				count++;
			n = 0;
			k = 0;
			f = true;
		}
	}
	if (f && (k != 0))
		count++;
	cout << count << endl;
	return 0;
}
