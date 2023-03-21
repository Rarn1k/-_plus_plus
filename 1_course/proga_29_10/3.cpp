#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	int* A = new int[n];
	//bool t = false, p = false;
	int i = 0, j = 0, g = 0;
	for (i = 0; i < n; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> A[i];

	}

	for (i = 0; i < n - 2; i++)
	{
		if (((A[i] > A[i + 1]) && (A[i + 1] < A[i + 2])) || ((A[i] < A[i + 1]) && (A[i + 1] > A[i + 2])))
			j++;
	}
	
	if (j==n-2) cout << "Yes";
	else cout << "No";
	return 0;
}





