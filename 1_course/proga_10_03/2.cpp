/*Информация по N рабочим завода задается строкой следующего вида: фамилия, средний возраст, специальность, средний оклад. 
Ввести информацию по рабочим, посчитать средний оклад всех рабочих. Отсортировать рабочих по возрасту. */

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

int sum(Zavod* a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i].salary;
	return sum;
}

void sort(Zavod* a, int n)
{
	Zavod g;
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j].age < a[j - 1].age)
			{
				g = a[j];
				a[j] = a[j - 1];
				a[j - 1] = g;
			}
}

int main()
{
	int n;
	int x;
	cout << "Enter n = ";
	cin >> n;
	Zavod* a = new Zavod[n];
	input(a, n);
	cout << endl;
	output(a, n);
	cout << endl;
	x = sum(a, n);
	cout << "Sum of salaries: " << x << endl << endl;
	sort(a, n);
	cout << "Sort by age:" << endl;
	output(a, n);
	return 0;
}