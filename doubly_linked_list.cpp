#include <iostream>
using namespace std;

struct nod{
	int val;
	struct nod *next;
	struct nod *prev;
};

typedef struct nod Nod;

void add_back(Nod* &first, Nod* &last, int val)
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
		last->next = nou;
		nou->prev = last;
		last = nou;
	}
}

void add_front(Nod* &first, Nod * &last, int val)
{
	Nod *nou = new Nod;
	nou->val = val;
	nou->next = first;
	nou->prev = NULL;

	first->prev = nou;
	first = nou;
}

void add_pos(Nod* &first, Nod* &last, int val, int pos)
{
	Nod *iter = first;
	for(int k = 0; k <= pos; k++)
		iter = iter->next;

	Nod *nou = new Nod;
	nou->prev = iter;
	nou->next = iter->next;
	
	iter->next->prev = nou;
	iter->next = nou;
}

void print_order(Nod* &first, Nod* &last)
{
	Nod* iter = first;
	while(iter){
		cout << iter->val << " ";
		iter = iter->next;
	}
	cout << endl;
}

void print_reverse(Nod* &first, Nod* &last)
{
	Nod* iter = last;
	do{
		cout << iter->val << " ";
		iter = iter->prev;
	}while(iter != first);
	cout << endl;
}

void delete_pos(Nod* &first, Nod* &last, int pos)
{
	if(pos == 0)
	{
		Nod *t = first;
		first = first->next;
		first->prev = NULL;
		delete t;
	}
	else
	{
		Nod* iter = first;
		for(int k = 0; k < pos; k++)
		{
			iter = iter->next;
			if(!iter->next){
				cout << "Pozitia nu exista";
				return;
			}
		}
		
		if(iter == last)
		{
			last = last->prev;

			Nod *t = last->next;
			last->next = NULL;

			delete t;
		}
		else
		{
			iter->prev->next = iter->next;
			iter->next->prev = iter->prev;
			delete iter;
		}
	}
}

void delete_val(Nod* & first, Nod* &last, int val)
{
	Nod *iter = first;
	int pos = 0;
	while(iter->next)
	{
		if(iter->val == val)
			delete_pos(first, last, pos);
		iter = iter->next;
		pos++;
	}
}

int main()
{
	Nod *inceput = NULL; 
	Nod *sfarsit = NULL;

	add_back(inceput, sfarsit, 9);
	add_back(inceput, sfarsit, 10);
	add_front(inceput, sfarsit, 5);
	add_front(inceput, sfarsit, 3);
	add_front(inceput, sfarsit, 4);

	print_order(inceput, sfarsit);

	delete_val(inceput, sfarsit, 5);
	cout << "\nAm sters valoarea 5\n";

	print_order(inceput,sfarsit);

	return 0;
}