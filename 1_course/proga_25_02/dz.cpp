#include<iostream>//Сортировка слова методом пузырька
#include<cstring>
using namespace std;
int main()
{
	const int m = 50;
	char a[m], x;
	int b, i, j;
	cout << "Enter str: ";
	cin.getline(a, m);
	b = strlen(a);
	for(i = 0; a[i] != '\0'; i++)
		for (j = b - 1; j > i; j--)
			if (a[j] < a[j - 1])
			{
				x = a[j];
				a[j] = a[j - 1];
				a[j - 1] = x;
			}
	cout << a;
	return(0);
}