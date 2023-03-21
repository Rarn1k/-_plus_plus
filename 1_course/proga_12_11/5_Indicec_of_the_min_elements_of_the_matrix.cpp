#include <iostream>
#include <iomanip>
using namespace std;
const int n = 4;
void create(int a[n][n]) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void show(int a[n][n]) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
}

void indices_of_min_elements(int a[n][n]) {
	int i, j, min, k = 0;
	min = a[0][0];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] < min)
				min = a[i][j];

	cout << "Indices of the minimum elements of the matrix : " << endl;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] == min)
				cout << "[" << i << "][" << j << "]" << endl;
}

int main() {
	int a[n][n];
	cout << "Enter array a: " << endl;
	create(a);
	cout << "Array a: " << endl;
	show(a);
	cout << endl;
	indices_of_min_elements(a);
	return 0;
}