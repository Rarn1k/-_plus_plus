#include<iostream>//Вывести в обратном порядке
#include<cstring>
using namespace std;
int main()
{
	const int m = 50;
	char a[m];
	int k = 0;
	cout << "Enter string: ";
	cin.getline(a, m);
	cout << "Str is " << a << endl << endl;
	for (int i = 0; a[i] != '\0'; i++)
		k++;
	for (int i = k - 1; i >= 0; i--)
		cout << a[i];
	cout << endl;
	return(0);
}