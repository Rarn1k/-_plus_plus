#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int a, n, b;
	bool t = true;
	cout << "���������� ������ ������������������ = ";
	cin >> n;
    if (n > 1)
    {
		cout << "a[0] = ";
		cin >> a;
		b = a;
		for (int i = 1; i < n; i++)
		{
			cout << "a[" << i << "] = ";
			cin >> a;
			if (b >= a)
			{
				t = false;
			}
			else
			{
				b = a;
			}
		}
		if (t) cout << "������������������ ����������";
		else cout << "������������������ �� ����������";
    }
	
	else
	{
		cout << "������������������ ���";
	}
	return 0;
}





//���� �������, ���� ������������ ������

//#include<iostream>
//using namespace std;
//const int n = 5;

//int main()
//{
//	setlocale(LC_ALL, "rus");
//	int a[n];
//	bool t = true;
//	cout << "Enter array a " << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "a[" << i << "] = ";
//		cin >> a[i];
//	}
//
//	cout << "Array a : ";
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << ' '; ;
//	}
//
//	for (int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)
//			if ((a[j] <= a[i]) && (t))
//			{
//				t = false;
//			}
//	if (t)
//	{
//		cout << endl << "������������������ ����������";
//	}
//	else cout << endl << "������������������ �� ����������";
//	return 0;
//}