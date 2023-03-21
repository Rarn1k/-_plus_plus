/*Багаж пассажира характеризуется номером, количеством вещей и общим весом.
Ввести информацию об N пассажирах и определить есть ли среди пассажиров такой, у которого самый маленький багаж по числу и по весу.*/



#include<iostream>
#include<cstring>
using namespace std;

struct Bagage
{
	int num; //номер багажа
	int x; //кол-во вещей
	int y; //общий вес
};

void input(Bagage* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].num >> a[i].x >> a[i].y;
	}
}

void SortX(Bagage* a, int n)
{
	Bagage g;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= (i+1); j--)
			if (a[j].x < a[j-1].x)
			{
				g = a[j];
				a[j] = a[j -1];
				a[j - 1] = g;
			}
	}
}

void SortY(Bagage* a, int n)
{
	Bagage g;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= (i+1) ; j--)
			if (a[j].y < a[j-1].y)
			{
				g = a[j];
				a[j] = a[j - 1];
				a[j - 1] = g;
			}
	}
}

void output(Bagage* a, int n) //вывод структуры
{
	for (int i = 0; i < n; i++)
	{

		cout << a[i].num << " " << a[i].x << " " << a[i].y << endl;
	}
}

int main()
{
	int n;
	int X = 0, Y = 0;
	cout << "Enter n = ";
	cin >> n;
	Bagage* a = new Bagage[n];
	input(a, n);
	SortX(a, n);
	X = a[0].num;
	cout << "SortX" << endl;
	output(a, n);
	SortY(a, n);
	Y = a[0].num;
	cout << "SortY" << endl;
	output(a, n);
	if (X == Y) cout << "Yes: " << a[0].num << " " << a[0].x << " " << a[0].y;
	else cout << "No";
	return 0;
}