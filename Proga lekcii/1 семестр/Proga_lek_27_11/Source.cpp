//#include <iostream.>
//using namespace std;
//
//const int m = 20;
//void main()
//{
//	char str[m], k;
//	int i, j, n;
//	bool fl = true;
//	cout << "Enter string:";
//	cin >> str;         // Можно ввести не более 19 символов.
// // Подсчет количества символов в строке.
// // Символ ‘\0’ – признак конца строки.
//	for (n = 0; str[n] != '\0'; n++);
//
//	for (i = 0; i < n && fl; i++)
//	{
//		fl = false;
//		for (j = 0; j < n - i - 1; j++)
//			if (str[j] > str[j + 1])
//			{
//				k = str[j];
//				str[j] = str[j + 1];
//				str[j + 1] = k;
//				fl = true;
//			}
//	}
//	cout << str << endl;
//	// Вывод С-строки (последний символ - ‘\0’)
//}

//#include <iostream>
//#include <cstring>     // Библиотека С-строковых функций (‘\0’) 
//using namespace std;
//
//void main()
//{
//	char buf[30];
//	int n;
//	bool fl = true;
//	cout << "Enter text :";
//	while (fl)
//	{
//		cin >> buf;           // Чтение слова в массив.
//		n = strlen(buf);      // Возвращает кол-во символов в строке.
//		if (buf[n - 1] == '.')
//		{
//			n--;
//			fl = false;
//		}
//		for (int i = n - 1; i >= 0; i--)
//			cout << buf[i];
//		if (fl)
//			cout << ' ';
//	}
//	cout << '\n';
//}

////arb2014_gusen_8_7
//#include <iostream>
//using namespace std;
//
//void main()
//{
//	char symb;
//	int count_word = 0, count_let = 0;
//	cout << "Enter text:";
//	symb = cin.get();      // Ввод символа (в том числе и пробела)
//	while (symb != '.')
//	{
//		if (symb == ' ')
//		{
//			if (count_let == 2)    count_word++;
//			count_let = 0;
//		}
//		else
//			if (symb == 'm')  count_let++;
//		symb = cin.get();  // Экв.  cin.get(symb);
//	}
//	if (count_let == 2)    count_word++;
//	cout << "Word count = " << count_word << '\n';
//}

////arb2014_gusen_8_8
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	const int size = 100;
//	char buf[size];
//	int n, i, lstr;
//	cout << "Enter text:\n";
//	while (1)
//	{
//		cin.getline(buf, size, '\n');
//		if (buf[0] == '\0')
//			break;
//		lstr = strlen(buf);
//		if (buf[lstr - 1] >= '1' && buf[lstr - 1] <= '9')  // Если цифра.
//			n = buf[lstr - 1] - '0';
//		else
//			n = 0;
//		for (i = 0; i < n && i < lstr; i++)
//			buf[i] = '&';
//		cout << "Result :" << endl << buf << endl;
//		cout << "Enter new line or press 'Enter' :" << endl;
//	}
//	return 0;
//}

////arb2009_stroka6_1
//// Never trouble trouble, till trouble troubles you
////Никогда не беспокойте проблему, пока проблема не //беспокоит Вас
////arb2014_basic_functions
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int m;
//	char a[100] = "Never trouble trouble";
//	cout << "Enter length of string m= ";
//	cin >> m;
//	char* p = new char[m];
//	strcpy(p, a);
//	cout << "length p=" << strlen(p) << endl;
//
//	cout << "String p= " << p << endl;
//
//	char b[100] = "Good day!";
//
//	strncpy(p, b, strlen(b) + 1);
//	cout << "String p= " << p << endl;
//	return 0;
//}

