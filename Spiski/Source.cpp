#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;
struct node
{
	int data;
	node* next;
};
 
void add_First(node*&first, int data)
{
	node* tmp = new node;
	tmp->data = data;
	tmp->next = first;
	first = tmp;
}

void add_Last(node*& first, int data)
{
	node* tmp = new node;
	tmp->data = data;
	tmp->next = NULL;
	if (first == NULL)
		first = tmp;
	else
	{
		node* p = first;
		while (p && p->next != NULL)
			p = p->next;
		p->next = tmp;
	}
}

void create_list(node*& first, int n)
{
	int x;
    first = new node;
	first = NULL;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		add_Last(first, x);
	}
}

void show_list(node* first)
{
	node* p = first;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

void pop_First(node*& first)
{
	if (first)
	{
		node* tmp = first;
		first = first->next;
		delete tmp;
	}
}

void clear_list(node*& first)
{
	while (first)
	{
		pop_First(first);
	}
}

node* previous (node* first, node* q) 
{
	node* p, *pr;
	p = first;
	pr = NULL;
	while (p != q && p) 
	{
		pr = p;
		p = p->next;
	}
	if (p == q)
		return pr;
	return NULL;
}

node* find_address(node* first, int data)
{
	node* p;
	p = first;
	while (p && (p->data) != data)
		p = p->next;
	return p;
}

void before_q(node*& first, node* q, int data) 
{
	node* r, *p;
	p = new node;
	r = previous(first, q);
	if (q == first)
		add_First(first, data);
	else 
		if (q == NULL)
		{
			cout << " Sorry, impossible insert element " << endl;
			system("pause");
			exit(-1);
		}
	{
		p->data = data;
		p->next = r->next;
		r->next = p;
	}
}

void after_q(node* &q, int data) 
{
	node* p;
	p = new node;
	p->data = data;
	p->next = q->next;
	q->next = p;
}

int main()
{
	node* list, *p;
	int n, data, data1, data2;
	cout << "Enter n : ";
	cin >> n;
	create_list(list, n);
	cout << " list = ";
	show_list(list);
	cout << "Enter q : ";
	cin >> data;
	p = find_address(list, data);
	cout<<"Previous q = " << previous(list, p)->data << endl;
	cout << "Enter before q : ";
	cin >> data1;
	before_q(list, p, data1);
	cout << "Enter after q : " << endl;
	cin >> data2;
	after_q(p, data2);
	show_list(list);
	pop_First(list);
	clear_list(list);
	return 0;
}