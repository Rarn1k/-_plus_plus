#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		fout << a[i] << " ";
	}
}
