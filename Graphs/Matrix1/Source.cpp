#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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

void smezh(node*& first, ifstream& in, ofstream& out, int n)
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
				}
				
			}

		}
	else
	{
		out << "Error";
		exit(-1);
	}
}

	int countt(node*& first, ofstream& out)
	{
		int n = 0;
		node* p = first;
		while (p)
		{
			n++;
			p = p->next;
		}
		return n;
	}

	void smezh2(node*& first, ofstream& out, int n, int m)
	{
		node* p = first;
		int i, j;
		int** g = new int* [n];
		for (i = 0; i < n; i++)
		{
			g[i] = new int[m];
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (p->data.y == j + 1 || p->data.x == j + 1)
				{
				    g[i][j] = 1;
				}
				else
				{
					g[i][j] = 0;
				}
			}
			p = p->next;
		}
		for (i = 0; i < n; i++)
		{
			for (j = m - 1; j >=0 ; j--)
			{
				out << setw(5) << g[j][i];
			}
			out << endl;
		}
	}

int main()
{
	ifstream in("Conn.txt");
	ofstream out("Out.txt");
	if (!in)
	{
		out << "Can't open file!";
		exit(-1);
	}
	node* list = NULL;
	int n, k;
	n = size(in);
	in.close();
	in.open("Conn.txt");
	smezh(list, in, out, n);
	k = countt(list, out);
	in.close();
	in.open("Conn.txt");
	smezh2(list, out, n, k);
	in.close();
	out.close();
	return 0;
}