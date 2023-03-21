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

void show_sequence(int *a, int x) {
	for (int i = 0; i < x; i++)
		cout << a[i] << " ";
}

void sequence(int a[n][n]) {
	int i, j, x = 0, q = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if ((i == j) && (a[i][j] > 0))
				x++;
	int* g = new int[x];
    for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if ((i == j) && (a[i][j] > 0)) {
				g[q] = a[i][j];
				q++;
			}
	cout<< "Matrix sequence with minimum sum of elements : " << endl;
	show_sequence(g, x);
}

int main() {
	int a[n][n];
	cout << "Enter array a: " << endl;
	create(a);
	cout << "Array a: " << endl;
	show(a);
	cout << endl;
	sequence(a);
	return 0;
}