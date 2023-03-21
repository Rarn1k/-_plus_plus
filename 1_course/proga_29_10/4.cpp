 //#include <iostream>
//using namespace std;
//int main()
//{
//	int n, i, b, q,  p = 0, k = 0, j;
//	bool kol = true, cikl = true;
//	cout << "n = ";
//	cin >> n;
//	int* a = new int[n];
//	
//
//	for (i = 0; i < n; i++)
//	{
//		cout << "a[" << i << "] = ";
//		cin >> a[i];
//	}
//
//	for (i = 0; i < n; i++)
//		cout << a[i] << " ";
//	cout << endl;
//
//	for (i = 0; i < n; i++)
//	{
//		kol = true;
//		b = a[i];
//		for (j = i + 1; j < n && kol; j++)
//			if (a[j] == b)
//			{
//				k++;
//				kol = false;
//			}
//	}
//	cout <<"k = " << k << endl;
//
//	int* c = new int[k];
//	q = 0;
//	for (i = 0; i < n; i++)
//	{
//		b = a[i];
//		cikl = true;
//		for (j = i + 1; j < n; j++)
//			if (a[j] == b)
//			{
//				for (; q < k && cikl;)
//				{
//					c[q] = a[j];
//					cikl = false;
//					q++;
//				}
//			}
//	}
//	for (q = 0; q < k; q++)
//		cout << c[q] << " ";
//	cout << endl;
//
//	for (q = 0; q < 1; q++)
//		cout << c[q] << " ";
//	for (q = 0; q < k; q++)
//	{
//		cikl = true;
//		b = c[q];
//		for (i = q + 1; i < k && cikl; i++)
//		{
//			if (c[i] != b)
//			{
//				cout << c[i] << " ";
//				cikl = false;
//			}
//
//		}
//	}
//
//	/*for (i = 0; i < n; i++)
//	{
//		b = a[i];
//		for (j = 0; j < n; j++)
//		{
//			if (a[j] == b && j>i)
//				p++;
//		}
//		if (p >= 1) k++;
//		p = 0;
//	}
//	cout << k << ", ";*/
//
//	return 0;
//}
#include <iostream>
using namespace std;
int main()
{
	int n, i, j, q, b, k = 0;
	bool kol = true, rav = true;
	cout << "n = ";
    cin >> n;
	int* a = new int[n];
	for (i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	for (i = 0; i < n; i++)
	{
		b = a[i];
		if (i > 0)
		for (q = i - 1; q >= 0; q--)
			if (a[q] == b)
				rav = false;
		for (j = i + 1; j < n &&  kol && rav; j++)
			if (a[j] == b)
		    {
				k++;
				kol = false;
		    }
		rav = true;
		kol = true;
	}
    cout << k << ", ";
	for (i = 0; i < n; i++)
	{
		b = a[i];
		if (i > 0)
			for (q = i - 1; q >= 0; q--)
				if (a[q] == b)
					rav = false;
		for (j = i + 1; j < n && kol && rav; j++)
			if (a[j] == b)
			{
				cout << a[j] << " ";
				kol = false;
			}
		rav = true;
		kol = true;
	}
	return 0;
}