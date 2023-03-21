#include <iostream>
#include <iomanip>
using namespace std;
const int n = 4;

void create(int a[n][n]) {
	cout << "Enter array a: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void show(int a[n][n]) {
	cout << "Array a: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
}

void in_one_array(int a[n][n]) {
	int k = 0, q = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			k++;
	int* g = new int[k];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			g[q] = a[i][j];
			q++;
		}
	for (q = 0; q < k; q++)
		cout << g[q] << " ";
}

int main() {
	int a[n][n];
	create(a);
	show(a);
	in_one_array(a);
	return 0;
}