#include <iostream>
#include <fstream>
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

void push(node*& first, graph x)
{
	node* p = new node;
	p->data = x;
	p->next = first;
	first = p;
}

int rebrs_counting(ifstream& in, ofstream& out)
{
	int x, n = 0;
	while (in >> x)
		n++;
	if (n % 3 != 0)
	{
		out << "invalid input";
		exit(-1);
	}
	return n / 3;
}

int dopper(node*& first, ifstream& in, ofstream& out, int n)
{
	int k = 0;
	graph g;
	for (int i = 0; i < n; i++)
	{
		in >> g.x;
		in >> g.y;
		in >> g.weight;
		if (g.x >= g.y)
			k = g.x;
		if (g.y >= g.x)
			k = g.y;
		push(first, g);
		out << "x = " << g.x << " y = " << g.y << " weight =  " << g.weight << endl;
	}
	return k;
}

void search(node*& first, ifstream& in, ofstream& out, int k, int n)
{
	node* p = first;
	int a, b, i, j, min = 10000, min_index = 0;
	cout << "Enter vertex a = ";
	cin >> a;
	cout << "Enter vertex b = ";
	cin >> b;
	int* m = new int[k];
	int* t = new int[k];
	for (j = 0; j < k; j++)
		t[j] = 0;
	for (i = 0; i < k; i++)
	{
		if (i != a - 1)
			m[i] = 10000;
		else
		{
			m[i] = 0;
			min_index = i;
		}
	}
	for (i = 0; i < k; i++)
	{
		min = 10000;
		while (p)
		{
			if ((p->data.x - 1 == min_index || p->data.y - 1 == min_index) && (!t[p->data.x - 1] && !t[p->data.y - 1]))
			{
				if (p->data.x - 1 == min_index && (m[min_index] + p->data.weight < m[p->data.y - 1]))
				{
					m[p->data.y - 1] = m[min_index] + p->data.weight;
				}
				if (p->data.y - 1 == min_index && (m[min_index] + p->data.weight < m[p->data.x - 1]))
				{
					m[p->data.x - 1] = m[min_index] + p->data.weight;
				}
			}
			p = p->next;
		}
		t[min_index] = 1;

		for (j = 0; j < k; j++)
			if (!t[j] && m[j] < min)
			{
				min = m[j];
				min_index = j;
			}
		p = first;
	}
	j = 1;
	int ves = m[b - 1];
	bool r = true;
	int temp;
	int* ver = new int[k];
	ver[0] = b;
	while (b != a)
	{
		p = first;
		while (p && r)
		{
			if (p->data.x == b || p->data.y == b)
			{
				temp = ves - p->data.weight;
				if (p->data.x == b && temp == m[p->data.y - 1])
				{
					ves = temp;
					b = p->data.y;
					ver[j] = p->data.y;
					j++;
				}
				else
					if (temp == m[p->data.x - 1])
					{
						ves = temp;
						b = p->data.x;
						ver[j] = p->data.x;
						j++;
					}
			}
			p = p->next;
		}
	}
	for (i = j - 1; i >= 0; i--)
	{
		if (i != j - 1)
			out << " -> " << ver[i];
		else
			out << ver[i];
	}
}

int main()
{
	ifstream in("Dijkstra.txt");
	ofstream out("Out.txt");
	if (!in)
	{
		out << "Can't open file!";
		exit(-1);
	}
	node* list = NULL;
	int n, k;
	n = rebrs_counting(in, out);
	in.close();
	in.open("Dijkstra.txt");
	k = dopper(list, in, out, n);
	search(list, in, out, k, n);
	in.close();
	out.close();
	return 0;
}