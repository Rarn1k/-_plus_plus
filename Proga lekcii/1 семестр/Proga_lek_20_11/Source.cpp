/*#include <iostream>
using namespace std;

void main()
{
	const int n = 30;
	char S[n];
	char T[n];
	char R[n];
	cout << "enter 3 words s=" << endl;
	cin >> S;
	cout << "string S=" << S << endl; ;
	//Ввод строки    Kazan  State   University           
	//На экране будет только слово Kazan

	cin >> T >> R;
	cout << T << ' ' << R << endl;   //Вsвод двух слов   State  University
    //эти два слова остались во входном потоке 
    //они заносятся в переменные Т и R и выводятся
}*/

/*#include <iostream>
using namespace std;
void main()
{
	const int n = 30;
	char S[n];
	cout << " new line ch= " << (int)'\n' << endl;//10
	cout << " 0-symbol ch= " << (int)'\0' << endl;//0

	cout << "enter  S1=" << endl;
	cin.getline(S, n); //Ввод строки Kazan  State  University
	cout << " S1=" << S << endl; //Вывод Kazan  State  University
	char V[] = "abc";
	cout << "V= " << V << endl;//  печатает abc
	cout << V[0] << V[1] << V[2] << (int)V[3] << endl;
	// печатает abc0
	V[3] = 'a';
		cout << "error V= " << V << endl;
		V[3] = '\0';
		cout << "normal V= " << V << endl;
}*/

/*#include <iostream>
using namespace std;
void main()
{
	const int n = 30;
	char S[n];
	cout << "enter string s= ";
	cin.get(S, n);
	cout << " S= " << S << endl;
	cin.get();
	cout << "enter string s= ";
	cin.get(S, n);
	cout << " S= " << S << endl;
}*/

/*#include <iostream>
#include<string.h>
using namespace std;
const int n = 80;
void main()
{
	char a[n], b[n], c[n], d[n];
	cout << " enter fio=";
	cin.getline(a, n);
	cout << "a=" << a << endl;
	int i, j;
	for (i = 0; a[i] != ' '; i++)
		b[i] = a[i];
	b[i] = '\0';
	i++; j = 0;
	while (a[i] != ' ')
	{
		c[j] = a[i];
		i++;
		j++;
	}
	c[j] = '\0';
	i++;
	j = 0;
	while (a[i] != '\0')
	{
		d[j] = a[i];
		i++;   j++;
	}
	d[j] = '\0';
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
}*/

/*#include <iostream>
using namespace std;

void main()
{
	const int m = 20;
	char str[m];
	int i, n;
	bool fl = true;
	cout << "Enter string:";
	cin >> str;         // Можно ввести не более 19 символов.

  // Подсчет количества символов в строке.
  // Символ ‘\0’ – признак конца строки.

	for (n = 0; str[n] != '\0'; n++);
	for (i = 0; i < n / 2 && fl; i++)

		if (str[i] != str[n - i - 1])
			fl = false;

	cout << (fl ? "Polindrom" : "Non polindrom") << endl;;
}*/

/*#include <iostream.>
using namespace std;

const int m = 40;
void main()
{
	char str[m], k;
	int i, j, n;
	bool fl = true;
	cout << "Enter string:";
	cin >> str;         // Можно ввести не более 19 символов.
 // Подсчет количества символов в строке.
 // Символ ‘\0’ – признак конца строки.
	for (n = 0; str[n] != '\0'; n++);

	for (i = 0; i < n && fl; i++)
	{
		fl = false;
		for (j = 0; j < n - i - 1; j++)
			if (str[j] > str[j + 1])
			{
				k = str[j];
				str[j] = str[j + 1];
				str[j + 1] = k;
				fl = true;
			}
	}
	cout << str << endl;
	// Вывод С-строки (последний символ - ‘\0’)
}*/

//arb2014_gusen_8_6
#include <iostream>
#include <cstring>     // Библиотека С-строковых функций (‘\0’) 
using namespace std;

void main()
{
	char buf[30];
	int n;
	bool fl = true;
	cout << "Enter text :";
	while (fl)
	{
		cin >> buf;           // Чтение слова в массив.
		n = strlen(buf);      // Возвращает кол-во символов в строке.
		if (buf[n - 1] == '.')
		{
			n--;
			fl = false;
		}
		for (int i = n - 1; i >= 0; i--)
			cout << buf[i];
		if (fl)
			cout << ' ';
	}
	cout << '\n';
}
