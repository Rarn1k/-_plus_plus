#include <iostream>
using namespace std;
void Create_mas(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void Show_mas(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

bool Is_prime(int k)
{
	if (k <= 1) return false;
	if (k == 2) return true;
	bool c = true;
	for (int j = 2; (j <= sqrt(k)) && c; j++)
		if (k % j == 0) c = false;
    return c;
}

bool E_prime(int* a, int n)
{
	bool b = false;
	for (int i = 0; (i < n) && !b; i++)
		if (Is_prime(a[i]) == true)
			b = true;
	return b;

}

bool Even_number(int x)
{
	bool c = false;
	if (x % 2 == 0) c = true;
	return c;
}

bool A_even(int* a, int n)
{
	bool g = true;
	for (int i = 0; (i < n) && g; i++)
		if (Even_number(a[i]) == false)
			g = false;
	return g;
}

int Even_sum(int* a, int n)
{
	int even_sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (Even_number(a[i])) even_sum += a[i];
	}
	return even_sum;
}

void Shift(int* a, int n)
{
	int c;
		c = a[0];
		a[0] = a[n - 1];
		for (int i = n - 2; i > 0; i--)
			a[i + 1] = a[i];
		a[1] = c;

}

void Mult_num(int* a, int n)
{
	int k;
	cout << "Enter k = ";
	cin >> k;
	for (int i = 0; i < n; i++)
		a[i] *= k;
}

void Swap(int* a, int n)
{
	int r;
	r = a[2];
	a[2] = a[1];
	a[1] = r;
}

int main()
{
	int n;
	cout << "Enter n = ";
	cin >> n;
	int* a = new int[n];
	Create_mas(a, n);
	Show_mas(a, n);
	cout << endl;
	/*if (E_prime(a, n)==true)
		cout << "Prime exists";
	else cout << "Prime doesn't exists";
	if (A_even(a, n)==true)
		cout << "All numbers are even";
	else cout << "Not all numbers are even";
	cout << Even_sum(a, n);*/
	if (A_even(a, n)) Shift(a, n);
	else if (E_prime(a, n)) Swap(a, n);
	Mult_num(a, n);
	Show_mas(a, n);
	return 0;
}
