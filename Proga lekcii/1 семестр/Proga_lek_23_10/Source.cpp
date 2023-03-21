//#include<iostream> // Указатели
//#include<iomanip>
//using namespace std;
//int main()
//{
//	int x=5;
//	cout << "x = " << x << endl;
//	int* ptr = &x;
//	cout << "ptr" << ptr << endl;
//	*ptr = 20;
//	int* ptr1 = new int;
//	cout << "ptr1=" << ptr1 << endl;
//	*ptr1 = 100;
//	cout << "ptr1=" << *ptr1 << endl;
//
//	cout << "x = " << x << endl;
//	int& a = x;                     //ссылка
//	cout << "a = " << a << endl;
//	a = a + 2;
//	cout << "a = " << a << endl;
//	cout << "x = " << x << endl;
//
//	return 0;
//}



# include <iostream>
using namespace std;
void plus(int, int, int); // прототип функции plus, параметры переданы по значению
void plus1(int, int, int&); // прототип функции plus1, последний параметр передан по ссылке
int plus2(int, int); //результат функции число типа int

void main()
{
	int a = 4; int b = 5; int c = 10;
	cout << "plus()" << endl;
	plus(a, b, c);
	cout << "c = " << c << endl; //9
	plus1(a, b, c);
	cout << "c = " << c << endl; //10
	int c2 = plus2(a, b);
	cout << "c2 = " << c2 << endl; //9
	// Возможен вариант
	cout << "plus2() = " << plus2(a, b) << endl; //9
}



void plus(int x, int y, int z)
{
	cout << "x = " << x << endl; //4
	cout << "y = " << y << endl; // 5
	cout << "z = " << z << endl; // 10
	z = x + y;
	cout << "z = " << z << endl; // 9
}

void plus1(int x, int y, int& z)
{
	cout << "x = " << x << endl; //4
	cout << "y = " << y << endl; // 5
	cout << "z = " << z << endl; // 10
	z = x + y;
	cout << "z = " << z << endl; // 9
}

int plus2(int x, int y)
{
	cout << "x = " << x << endl; //4
	cout << "y = " << y << endl; // 5
	cout << "x + y" << x + y << endl; // 9
	return x + y;
}







