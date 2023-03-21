//Задан текстовый файл
/*
1)ФИО
2)Год рождения
3)Пол
4)Семейное положение
5)Дути
6)Обрзование
7)Зарплата*/
//Иванов.И.И. 2000 m y 2 y
/*   
m             | w
30-60         |20-50
дети >=2      | -
семья Y       | -

*/




#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
struct person
{
	char fio[40];
	int year;
	char sex;
	int ms;
	int child;
	char edu;
	int salary;
};

int main()
{
	ifstream in("TextFile1.txt");
	ofstream mout("outman.bin", ios::binary);
	ofstream fout("outfemale.bin", ios::binary);
	person x;
	int k1 = 0, k2 = 0;
	if (!in)
	{
		cout << "File not found" << endl;
		system("pause");
		exit(-1);
	}
	while (in >> x.fio >> x.year >> x.sex >> x.ms >> x.child >> x.edu >> x.edu >> x.salary)
	{
		if (((x.sex == 'm')) && (((2020 - x.year) <= 60) && ((2020 - x.year) >= 40)) && (x.ms == 1) && (x.child >= 2) && (x.edu == 'v') && (x.salary >= 75000))
		{
			mout.write((char*)&x, sizeof(struct person));
			k1++;
		}
		if (((x.sex == 'f')) && (((2020 - x.year) <= 40) && ((2020 - x.year) >= 20)) && (x.child >= 2) && (x.edu == 'v'))
		{
			fout.write((char*)&x, sizeof(struct person));
			k2++;
		}
	}
	in. close();
	fout.close();
	mout.close();
	ifstream manbin("outman.bin", ios::binary);
	ifstream fembin("outfemale.bin", ios::binary);
	if (!manbin )
	{
		cout << "File (men) not found;" << endl;
		system("pause");
		exit(-1);
	}
	if (!fembin)
	{
		cout << "File (fem) not found;" << endl;
		system("pause");
		exit(-1);
	}
	cout << "Man list" << endl;
	while(manbin.read((char*)&x, sizeof(struct person)));
	{
		cout << x.fio << ' ' << x.year << ' ' << x.child << endl;
	}
	cout << "Women list" << endl;
	while (fembin.read((char*)&x, sizeof(struct person)));
	{
		cout << x.fio << ' ' << x.year << ' ' << x.child << endl;
	}
	manbin.close();
	fembin.close();
	system("pause");
	return 0;
}