/*������� ���������� �� ������ ��������� � ��������� ����� � ������ N �������. 
�� ������� �� ��������� ������� ��������� ��������: �������, ������ �� ����������, ������ �� ����������� � ������ �� ������. 
������ ���������� �� ��������� ��������� � ���������� ������� ���� �� ������ ����������.*/

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
		cout << a[i].surname << " " << a[i].math << " " << a[i].inf << " " << a[i].fiz << endl;
}

double math(ekz* a, int n)
{
	double x = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i].math;
	x = (double)sum / n;
	return x;
}

double fiz(ekz* a, int n)
{
	double x = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i].fiz;
	x = (double)sum / n;
	return x;
}

double inf(ekz* a, int n)
{
	double x = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i].inf;
	x = (double)sum / n;
	return x;
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
	cout << "Math: " << math(a, n) << endl;
	cout << "Inf: " << inf(a, n) << endl;
	cout << "Fiz: " << fiz(a, n) << endl;
	return 0;
}