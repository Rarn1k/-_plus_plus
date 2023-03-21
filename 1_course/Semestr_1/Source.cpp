//#include<iostream>
//using namespace std;
//const double eps = 0.030;
//int main()
//{
//	double sum, x, t, a, i, b, y;
//	int n, j; 
//	cout << "Enter n ";
//	cin >> n;
//	a = 0;
//	t = 0;
//	b = 0;
//	x = 0;
//	i = 0;
//	y = 0;
//
//	for (j = 1; (j <= n); j++)
//	{
//		cout << "Enter x[" << j << "] = ";
//		cin >> x;
//		if (fabs(x) < 1)
//		{
//			a = 3 + 0.2 * x;
//			b = 0.02 * x * x;
//			t = - x / 2;
//			sum = -x / 2;
//								   
//			for (i = 2; fabs(t) > eps; i++)
//			{
//				t = t * ((-x * (2 * i - 1)) / (2 * i));
//				sum += t;
//				cout << "t = " << t << endl;
//				
//			}
//			cout << endl << "Sum = " << sum << endl << endl;
//			y = a / sqrt(1 + x + b);
//			cout << "f(x) = " << y << endl << endl ;
//		}
//		else
//		{
//			cout << "Error, enter |x| < 1" << endl;
//		}
//		
//	}
//	
//	return 0;
//}


#include<iostream>
using namespace std;
const double eps = 0.030;
int main()
{
	double sum, x, t, a, i, b, y;
	int n, j;
	cout << "Enter n ";
	cin >> n;
	a = 0;
	t = 0;
	b = 0;
	x = 0;
	i = 0;
	y = 0;

	for (j = 1; (j <= n); j++)
	{
		cout << "Enter x[" << j << "] = ";
		cin >> x;
		if (fabs(x) < 1)
		{
			
			b = 3 + 0.2 * x;
			x = x + 0.02 * x * x;
			t = -x / 2;
			sum = -x / 2;

			for (i = 2; fabs(t) > eps; i++)
			{
				t = t * ((-x * (2 * i - 1)) / (2 * i));
				sum += t;
				cout << "t = " << t << endl;

			}
			cout << endl << "Sum = " << sum << endl ;
		
			y = b * sum;
			cout << "f(x) = " << y << endl << endl;
		}
		else
		{
			cout << "Error, enter |x| < 1" << endl;
		}

	}

	return 0;
}



//int main()
//{
//	long int n, znak, factorial_1, factorial_11, factorial_2, factorial_22;
//	double x, y, stepen, sum, z;
//	const double eps = 0.030;
//	cout << "Enter n ";
//	cin >> n;
//	stepen = 1;
//	sum = 0;
//	znak = 1;
//	factorial_1 = 1;
//	factorial_11 = 1;
//	factorial_2 = 1;
//	factorial_22 = 1;
//	for (int j = 1; (j <= n); j++)
//	{
//		cout << "Enter x[" << j << "]=" << " ";
//		cin >> x; 
//		int i = 1;
//		
//		do
//		{
//			znak = -znak;
//			stepen *= x;
//			factorial_1 *= (2 * i - 1);
//			factorial_11 *= factorial_1;
//			factorial_2 *= (2 * i);
//			factorial_22 *= factorial_2;
//			z = znak * (factorial_11 / factorial_22) * stepen;
//			sum += z;
//			i++;
//		} while ((sum > eps) || (sum < -eps));
//
//		
//	}
//
//	
//	return 0;
//}