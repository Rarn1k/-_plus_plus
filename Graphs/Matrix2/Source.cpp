#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct graph
{
	int x;
	int y;
	int weight;
};

struct node
{
	graph data;
	node* next;
};

void push(node*& first, graph g)
{
	node* p = new node;
	p->data = g;
	p->next = first;
	first = p;
}

int size(ifstream& in)
{
	int x, n = 0;
	while (in >> x)
		n++;
	return sqrt(n);
}

void grib(node*& first, ofstream& out, ifstream& in, int n)
{
	int i, j, x;
	graph r;
	int** g = new int* [n];
	for (i = 0; i < n; i++)
	{
		g[i] = new int[n];
	}
	if (in)
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				in >> g[i][j];
				if (j > i && g[i][j] != 0)
				{
					r.weight = g[i][j];
					r.x = i + 1;
					r.y = j + 1;
					push(first, r);
					out << r.x << " " << r.y << " " << "Weight = " << r.weight << endl;
				}
			}
		}
	else
	{
		out << "Error";
		exit(-1);
	}
}

int main()
{
	ifstream in("Pit.txt");
	ofstream out("Out.txt");
	if (!in)
	{
		out << "Can't open file!";
		exit(-1);
	}
	node* list = NULL;
	int n;
	n = size(in);
	in.close();
	in.open("Pit.txt");
	grib(list, out, in, n);
	in.close();
	out.close();
	return 0;
}