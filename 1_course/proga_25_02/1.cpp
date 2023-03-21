#include<iostream>//Три строки, содержащие отдельно фамилию, имя и отчество
#include<cstring>
using namespace std;
int main()
{
	const int m = 30;
	char str[m], name[m], surname[m],patronymic[m];
	cout << "Enter string: ";
	cin.getline(str, 50);
	cout << "Str is " << str << endl << endl;
	int i, j = 0;
	for (i = 0; str[i] != ' '; i++)
		name[i] = str[i];
	name[i] = '\0';
	i++;
	while (str[i] != ' ')
	{
		surname[j] = str[i];
		i++;
		j++;
	}
	surname[j] = '\0';
	i++;
	j = 0;
	while (str[i] != '\0')
	{
		patronymic[j] = str[i];
		i++;   j++;
	}
	patronymic[j] = '\0';
	cout << "Name is " << name << endl;
	cout << "Surname is " << surname << endl;
	cout << "Patronymic is " << patronymic << endl;

	/*for (i = 0; str[i] != ' '; i++)
		y++;
	char name[m] = { };
	for (i = 0; i != y; i++)
	{
		name[i] = str[i];
	}
	cout << "Name is " << name << endl;
	for (i = y + 1; str[i] != ' '; i++)
		f++;
	char surname[m] = { };
	for (i = 0, g = y + 1; i != f; i++, g++)
	{
		surname[i] = str[g];
	}
	cout << "Surname is " << surname << endl;
	for (i = y + 1; str[i] != ' '; i++)
		f++;
	char surname[m] = { };
	for (i = 0, g = y + 1; i != f; i++, g++)
	{
		surname[i] = str[g];
	}
	cout << "Surname is " << surname << endl;*/
	return 0;
}


