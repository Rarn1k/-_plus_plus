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

int vertex_counting(ifstream& in, ofstream& out)
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

void dopper(node*& first, ifstream& in, ofstream& out, int n)
{
	graph g;
	for (int i = 0; i < n; i++)
	{
		in >> g.x;
		in >> g.y;
		in >> g.weight;
		push(first, g);
		out << "x = " << g.x << " y = " << g.y << " weight =  " << g.weight << endl;
	}
}

void verification(node* first, ofstream& out, int a, int b)
{
	bool t = false;
	node* p = first;
	while (p && !t)
	{
		if ((p->data.x == a && p->data.y == b && p->data.weight) || (p->data.x == b && p->data.y == a && p->data.weight))
			t = true;
		p = p->next;
	}
	if (t)
		out << "The weight exist between " << a << " and " << b;
	else
		out << "The weight does not exist between " << a << " and " << b;
}

int main()
{
	ifstream in("Ramp.txt");
	ofstream out("Out.txt");
	if (!in)
	{
		out << "Can't open file!";
		exit(-1);
	}
	node* list = NULL;
	int a, b, n;
	cout << "Enter a = ";
	cin >> a;
	cout << "Enter b = ";
	cin >> b;
	n = vertex_counting(in, out);
	in.close();
	in.open("Ramp.txt");
	dopper(list, in, out, n);
	verification(list, out, a, b);
	in.close();
	out.close();
	return 0;
}