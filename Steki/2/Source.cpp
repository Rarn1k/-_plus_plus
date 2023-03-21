#include <iostream>
#include <fstream>
using namespace std;

struct stackk
{
	char data;
	stackk* next;
};

void push(stackk*& first, char data)
{
	stackk* p = new stackk;
	p->data = data;
	p->next = first;
	first = p;
}

void pop(stackk*& first)
{
	stackk* p;
	if (first)
	{
		stackk* p = first;
		first = first->next;
		delete p;
	}
}

void clear(stackk*& first)
{
	while (first)
		pop(first);
}

void skobki(stackk*& first, char data, int& k)
{
	stackk* g = first;
	if (data == '(')
		push(first, data);
	if (data == ')')
	{
		if (first == NULL)
		{
			pop(first);
			k++;
		}
		else
		{
				pop(first);
		}
	}
}

void skobki2(stackk*& first, char* x, int&k)
{
	int n = strlen(x);
	for (int i = 0; i < n; i++)
		skobki(first, x[i], k);
}

int oprn(stackk* first)
{
	int k = 0;
	stackk* p = first;
	while (p)
	{
		k++;
		p = p->next;
	}
	return k;
}

int main()
{
	ifstream in("ABC.txt");
	ofstream out("Out.txt");
	char x[1001];
	if (!in)
	{
		out << "Can't open file!" << endl;
		exit(-1);
	}
	in >> x;
	stackk* list = NULL;
	int k = 0;
	skobki2(list, x, k);
	k +=  oprn(list);
	out << k;
	clear(list);
	return 0;
}