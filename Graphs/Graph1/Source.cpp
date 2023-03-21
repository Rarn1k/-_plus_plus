#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct graph
{
	int x1, y1;
	int x2, y2;
	int weight;
};

struct node
{
	graph data;
	node* next;
};

void push(node*&first, graph g)
{
	node* p = new node;
	p->data = g;
	p->next = first;
	first = p;
}

void pop(node*& first)
{
	if (first)
	{
		node* p = first;
		first = p->next;
		delete p;
	}
}

int vertex_counting(ifstream& in, ofstream& out)
{
	int x, n = 0;
	while (in >> x)
		n++;
	if (n % 4 != 0)
	{
		out << "invalid input";
		exit(-1);
	}
	return n / 4;
}

void dopper(node*& first, ifstream& in, ofstream& out, int n)
{
	graph g;
	for (int i = 0; i < n; i++)
	{
		in >> g.x1;
		in >> g.y1;
		in >> g.x2;
		in >> g.y2;
		g.weight = sqrt((g.x2 - g.x1) * (g.x2 - g.x1) + (g.y2 - g.y1) * (g.y2 - g.y1));
		push(first, g);
	}
}

void show(node*& first, ofstream& out)
{
	node* p = first;
	while (p)
	{
		out << p->data.x1 << " " << p->data.x2 << " " << p->data.y1 << " " << p->data.y2 << " " << "weight = " << p->data.weight << " " << endl;
		p = p->next;
	}
}

int main()
{
	ifstream in("ABC.txt");
	ofstream out("Out.txt");
	if (!in)
	{
		out << "Can't open file!";
		exit(-1);
	}
	node* list = NULL;
	int n;
	n = vertex_counting(in, out);
	in.close();
	in.open("ABC.txt");
	dopper(list, in, out, n);
	show(list, out);
	in.close();
	out.close();
	return 0;
}