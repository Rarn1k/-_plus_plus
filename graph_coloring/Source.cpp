#include <iostream>
#include <fstream>
using namespace std;

struct colors
{
	int c;
	int key;
};

struct step
{
	int versh;
	int rebs;
};

int size(ifstream& in) 
{
	int x, n = 0;
	while (in >> x)
		n++;
	in.close();
	return sqrt(n);
}

int** create(ifstream& in, int n)
{
	int i, j;
	int** g = new int* [n];
	for (i = 0; i < n; i++)
	{
		g[i] = new int[n];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			in >> g[i][j];
		}
	}
	return g;
}

void del(int** N, int n)
{
	for (int j = 0; j < n; ++j)
		delete[] N[j];
	delete[] N;
}

int* sort(int** g, int n)
{
	int* arr = new int[n];//массив вершин
	int i, j;
	step x;
	step* k = new step[n];//массив степеней вершин
	for (i = 0; i < n; i++)
	{
		k[i].rebs = 0;
		k[i].versh = 0;
	}
	for (i = 0; i < n; i++)
	{
		k[i].versh = i + 1;
		for (j = 0; j < n; j++)
		{
			if (g[i][j])
			{
				k[i].rebs++;
			}
		}
	}
	for (i = 0; i < n; i++)
		for (j = n - 1; j >= i + 1; j--)
			if (k[j].rebs > k[j - 1].rebs)
			{
				x = k[j];
				k[j] = k[j - 1];
				k[j - 1] = x;
			}

	for (i = 0; i < n; i++)
	{
		arr[i] = k[i].versh;
	}
	return arr;
}

void coloring(ofstream& out, int** g, int n)
{
	int hr = 0, i, j, z, k, col = 1;
	int* vershin = sort(g, n);
	colors* arr = new colors[n]{ 0 };
	for (i = 0; i < n; i++)
	{
		arr[i].key = i;
		arr[i].c = 0;
	}

	bool t = false;
	bool r;
	while (!t)
	{
		for (k = 0; k < n && !t; k++)
		{
			i = vershin[k] - 1;
			if (!arr[i].c)
				arr[i].c = col;
			for (j = 0; j < n; j++)
			{
				if (!arr[j].c)
				{
					r = true;
					for (z = 0; z < n && r; z++)
						if (g[j][z] && arr[z].c == col)
							r = false;
					if (r)
						arr[j].c = col;
				}
			}

			t = true;
			for (i = 0; i < n && t; i++)
			{
				if (!arr[i].c)
					t = false;
			}
			col++;
		}
	}
	for (i = 0; i < n; i++)
	{
		out << arr[i].key + 1 << " is " << arr[i].c << endl;
		if (arr[i].c > hr)
			hr = arr[i].c;
	}
	out << endl << "x(G) = " << hr;
}

int main()
{
	ifstream in("Graph.txt");
	ofstream out("Out.txt");
	if (!in)
	{
		out << "Can't open file!";
		exit(-1);
	}
	const int n = 5;
	int** g = create(in, n);
	coloring(out, g, n);
	in.close();
	out.close();
	return 0;
}