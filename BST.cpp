#include <iostream>
using namespace std;

struct nod{
	int val;
	struct nod *left, *right;
};
typedef struct nod Nod;

void adauga(Nod **rad, int x)
{
	if(!(*rad))
	{
		*rad = new Nod;
		(*rad)->val = x;
		(*rad)->left = NULL;
		(*rad)->right = NULL;
	}
	else
	{
		if(x < (*rad)->val)
			adauga(&(*rad)->left, x);
		if(x > (*rad)->val)
			adauga(&(*rad)->right, x);
	}
}

int cauta(Nod *rad, int x)
{
	while(rad)
	{
		if(rad->val == x)
			return 1;
		if(rad->val < x)
			rad = rad->right;
		if(rad->val > x)
			rad = rad->left;
	}
	return -1;
}

Nod* cautaRecursiv(Nod *rad, int x)
{
	if(!rad || rad->val == x)
		return rad;

	if(x < rad->val)
		return cautaRecursiv(rad->left, x);
	else
		return cautaRecursiv(rad->right, x);
}

int cautar(Nod *rad, int x)
{
	Nod *n = cautaRecursiv(rad, x);
	if(n)
		return n->val;
	return -1;
}

int findMax(Nod *rad)
{	
	Nod *n = rad;
	while(n->right)
		n = n->right;

	return n->val;
}

Nod* findMin(Nod* t)
{
	if(t == NULL)
        return NULL;
 	else if(t->left == NULL)
        return t;
    else
        return findMin(t->left);
}


Nod* delet(Nod *t, int x)
{
	Nod *temp;

	if(!t)
		return NULL;

	//daca x e mai mic decat radacina, x e la stanga
	else if(x < t->val)
		t->left = delet(t->left, x);

	//daca x e mai mare decat radacina, x e la dreapta
	else if(x > t->val)
		t->right = delet(t->right, x);

	else if(t->left && t->right)   
	{//nodul are 2 copii
		temp = findMin(t->right); //cauta succesorul inordine
		t->val = temp->val;		//il copiaza in acest nod
		t->right = delet(t->right, t->val);	   //
	}
	else
	{//nodul are un copil sau niciunul
		temp = t;
		if(!t->left)
			t = t->right;
		else if(!t->right)
			t = t->left;
		delete temp;
	}

	return t;
}

void srd(Nod *rad)
{//inorder
	if(rad)
	{
		srd(rad->left);
		cout << rad->val << " ";
		srd(rad->right);
	}
}


int main()
{
	Nod *rad = NULL;

	adauga(&rad, 5);
	adauga(&rad, 4);
	adauga(&rad, 7);
	adauga(&rad, 9);

	cout << "Cauta 4: " << cautar(rad, 4) << endl;
	cout << "Cauta 3: " << cautar(rad, 3) << endl;
	cout << "Cauta 8: " << cautar(rad, 8) << endl;
	cout << "Cauta 10: " << cautar(rad, 10) << endl;



	cout << "Maximul este: " << findMax(rad) << endl;

	cout << "Parcurgerea in ordine: \n";
	srd(rad);

	delet(rad, 8);

    cout << "\nParcurgerea in ordine: \n";
	srd(rad);


	return 0;
}