/*������� ���������� �� ������ ��������� � ��������� ����� � ������ N �������. 
�� ������� �� ��������� ������� ��������� ��������: �������, ������ �� ����������, ������ �� ����������� � ������ �� ������. 
������ ���������� �� ��������� � ���������� ���������� � ������� ���������, ������� ���� �� ���� ������.*/

#include<iostream>
#include<cstring>
using namespace std;

struct ekz
{
	char surname[50];
	int math;
	int inf;
	int fiz;
};

void input(ekz* a, int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i].surname >> a[i].math >> a[i].inf >> a[i].fiz;
}

void output(ekz* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i].surname << " " << a[i].math << " " << a[i].inf << " " << a[i].fiz<<endl;
}

void bad(ekz* a, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if ((a[i].math == 2) || (a[i].inf == 2) || (a[i].fiz == 2))
		{
			k++;
			cout << k << " " << a[i].surname << " " << a[i].math << " " << a[i].inf << " " << a[i].fiz << endl;
		}
	cout << "Number of students k = " << k << endl;
}

int main()
{
	int n;
	cout << "Enter n = ";
	cin >> n;
	ekz* a = new ekz[n];
	input(a, n);
	cout << endl;
	output(a, n);
	cout << endl;
	cout << "Students with 2: " << endl;
	bad(a, n);
	return 0;
}