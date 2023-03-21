/*���������� �� N ������� ������ �������� ������� ���������� ����: �������, ������� �������, �������������, ������� �����. 
������ ���������� �� �������. 
���������� ����� �������, ��� ������� ������� ���� 35 ���.*/


#include<iostream>
#include<cstring>
using namespace std;

struct Zavod
{
	char surname[55];
	int age;
	char spec[50];
	int salary;
};

void input(Zavod* a, int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i].surname >> a[i].age >> a[i].spec >> a[i].salary;
}

void output(Zavod* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i].surname << " " << a[i].age << " " << a[i].spec << " " << a[i].salary << endl;
}

void bam(Zavod* a, int n)
{
	for (int i = 0; i < n; i++)
		if (a[i].age > 35)
			cout << a[i].surname << " " << a[i].age << " " << a[i].spec << " " << a[i].salary << endl;
}

int main()
{
	int n;
	int X = 0, Y = 0;
	cout << "Enter n = ";
	cin >> n;
	Zavod* a = new Zavod[n];
	input(a, n);
	cout << endl;
	output(a, n);
	cout << "Age > 35" << endl;
	bam(a, n);
	return 0;
}
