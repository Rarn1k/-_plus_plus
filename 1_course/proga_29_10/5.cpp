#include <iostream>
using namespace std;
int main()
{
	int n, i, j = 0, q = 0, g = 0, b = 0, k = 0;
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

		//for (i = 0; i < n; i++)
		//{
		//	if (a[i] > 0)
		//	{
		//		q = i;
		//		k++;
		//		//cout << k;
		//	}
		//	else
		//	{
		//		
		//		k = 0;
		//	}
		//}
		//kol = true;
	
	for (i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			k++;

		}
		else
		{
			if (k > b)
			{
				b = k;
				k = 0;
				j = i;
			}
			
		}
	}
	q = j - b;

			//for (i = 0; i < n; i++ /*g++*/)
			//{
			//	if (a[i] > 0)
			//	{
			//		q = i;
			//		k++;
			//	}
			//	else 
			//	{
			//		if (k > b)
			//		{
						/*for (g = j; g <= q; g++)
							a[g] = a[i];*/
						/*b = k;
						k = 0;

					}
					j = i + 1;
				}
			}*/

			for ( i = q; g < b; g++, i++ )
			{
				cout << a[i] << " ";
			}
		
       

		//for (i = q; i < n && kol; i++)
		//{
		//	if (a[i] > 0)
		//	{
		//		b++;
		//		//cout << k;
		//	}
		//	else kol = false;
		//}
		//kol = true;
	
		
	return 0;
}
