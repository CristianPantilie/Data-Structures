#include <iostream>
using namespace std;


struct nod{
	int val;
	struct nod *left, *right;
};
typedef struct nod Nod;

Nod*adauga()
{
	Nod *nou = new Nod;

	cout << "Dati un element"; cin >> nou->val;
	nou->left = nou->right = NULL;
	cout << "Fiu stang pentru " << nou->val << " ? (d/n)" << endl;
	char c;
	cin >> c;
	if(c != 'n')
		nou->left = adauga();
	cout << "Fiu drept pentru " << nou->val << " ? (d/n)" << endl;
	cin >> c;
	if(c != 'n')
		nou->right = adauga();

	return nou;
}
void rsd(Nod *rad)
{//preorder
	if(rad)
	{
		cout << rad->val << " ";
		rsd(rad->left);
		rsd(rad->right);
	}
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
void sdr(Nod *rad)
{//postorder
	if(rad)
	{
		sdr(rad->left);
		sdr(rad->right);
		cout << rad->val << " ";
	}
}

int main()
{
	Nod *rad;

	rad = adauga();
	
	cout << endl << endl;
	cout << "Parcurgerea in preordine: ";
	rsd(rad);
	cout << "Parcurgerea in ordine: ";
	srd(rad);
	cout << "Parcurgerea in postordine: ";
	sdr(rad);

	return 0;
}