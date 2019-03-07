#include <iostream>
using namespace std;

struct nod{
	int val;
	struct nod *next;
};
typedef struct nod Nod;


void add_last(Nod *&first, Nod *&last, int val)
{
	Nod *nou = new Nod;
	nou->val = val;
	nou->next = NULL;
	if(!first)
	{
		first = nou;
		last = first;
	}
	else
	{
		last->next = nou;
		last = nou;
	}
}

void add_first(Nod *&first, Nod *&last, int val)
{
	Nod *nou = new Nod;
	nou->val = val;
	if(!first)
	{
		first = nou;
		last = first;
	}
	else
	{
		nou->next = first;
		first = nou;
	}
}

void add_poz(Nod *&first, Nod *&last, int poz, int val)
{
	Nod *iter = first;
	for (int i = 0; i < poz - 1; ++i)
		iter = iter->next;

	Nod *nou = new Nod;
	nou->val = val;
	nou->next = iter->next;
	iter->next = nou;
}

void print(Nod *&first, Nod *&last)
{
	if(!first)
		cout << "List is empty";
	else
	{
		Nod *iter = first;
		while(iter)
		{
			cout << iter->val << " ";
			iter = iter->next;
		}
	}
}

int search(Nod *&first, Nod *&last, int val)
{
	Nod *iter = first;
	int k = 0;
	while(iter)
	{
		if(val == iter->val)
			return k;
		k++;
		iter = iter->next;
	}

	return -1;
}

void delet_first(Nod *&first, Nod *&last)
{
	Nod *temp = first;
	first = first->next;
	delete temp;
}

void delet_last(Nod *&first, Nod *&last)
{
	Nod *iter = first;
	while(iter->next != last)
		iter = iter->next;

	Nod *temp = iter->next;
	iter->next = NULL;
	last = iter;
	delete temp;
}

void delet(Nod *&first, Nod *&last, int poz)
{
	Nod *iter = first;
	iter = iter->next;
	
	for (int i = 0; i < poz - 1; ++i)
		iter = iter->next;

	Nod *temp = iter->next;
	iter->next = iter->next->next;
	delete temp;
}


int main()
{
	Nod *first = NULL;
	Nod *last = NULL;

	add_last(first, last, 1);
	add_last(first, last, 3);
	add_last(first, last, 5);
	add_last(first, last, 7);
	add_first(first, last, 0);
	add_first(first, last, -1);
	add_first(first, last, -3);
	add_first(first, last, -5);
	add_first(first, last, -7);
	print(first, last);

	cout << endl << endl;
	add_poz(first, last, 4, 9);
	print(first, last);



}