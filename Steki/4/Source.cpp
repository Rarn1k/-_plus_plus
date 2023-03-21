#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct stackk
{
	int data;
	stackk* next;
};

void push(stackk*& first, int data)
{
	stackk* p = new stackk;
	p->data = data;
	p->next = first;
	first = p;
}

void pop(stackk*& first)
{
	stackk* p = new stackk;
	if (first)
	{
		p = first;
		first = first->next;
		delete p;
	}
}

stackk* back(stackk*& first)
{
	stackk* p = new stackk;
	if (first)
	{
		p = first;
		return p;
	}
}

void clear(stackk*& first)
{
	while (first)
		pop(first);
}

stackk* postf(stackk*& first, ifstream& in, ofstream& out)
{
	stackk* p = new stackk;
	char x;
	int y = 0, h = 0;
	while (in>> x)
	{
		if (first)
		{
			if ((x >= 48) && (x <= 57))
			{
				y = (int) x - '0';
				push(first, y);
			}
			else
			{
				if (x == '+')
				{
					h = back(first)->data;
					pop(first);
					y = back(first)->data + h;
					pop(first);
					push(first, y);
				}
				if (x == '-')
				{
					h = back(first)->data;
					pop(first);
					y = back(first)->data - h;
					pop(first);
					push(first, y);
				}
				if (x == '*')
				{
					h = back(first)->data;
					pop(first);
					y = back(first)->data * h;
					pop(first);
					push(first, y);
				}
			}
		}
		else 
		{
			if ((x >= 48) && (x <= 57))
			{
				y = (int) x - '0';
				push(first, y);
			}
			else
			{
				out << "Error";
				exit(-1);
			}
		}
	}
	out << back(first)->data;
}
int main()
{
	ifstream in("ABC.txt");
	ofstream out("Out.txt");
	if (!in)
	{
		out << "Can't open file!" << endl;
		exit(-1);
	}
	stackk* list = NULL;
	postf(list, in, out);
	clear(list);
	return 0;
}