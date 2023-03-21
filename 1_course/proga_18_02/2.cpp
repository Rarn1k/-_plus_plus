#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[50];
	cout << "Enter string: ";
	cin >> str;
	int Sum_Big = 0;
	int Sum_Small = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			Sum_Small++;
		if (str[i] >= 'A' && str[i] <= 'Z')
			Sum_Big++;
	}
	cout << "Kolichestvo zaglavnyh: " << Sum_Big << endl;
	cout << "Kolichestvo strochnyh: " << Sum_Small << endl;
	return 0;
}