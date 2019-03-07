#include <iostream>
using namespace std;

struct Nod{
	int val;
	struct Nod *back;
};

typedef struct Nod Nod;

void push(int a, Nod * &varf)
{
	if(!varf)
	{
		varf = new Nod;
		varf->val = a;
		varf->back = NULL;
	}
	else
	{
		Nod *nou = new Nod;
		nou->back = varf;
		nou->val = a;
		varf = nou;
	}
}

int pop(Nod* &varf)
{
	int ret = varf->val;
	Nod *nod = varf->back;
	delete varf;
	varf = nod;
	return ret;
}

int peek(Nod *varf)
{
	return varf->val;
}

bool empty(Nod *varf)
{
	if(!varf)
		return true;
	return false;
}

int search(int a, Nod *varf)
{
	int dist = 0;
	Nod *nod = varf;
	do
	{
		if(nod->val == a)
			return dist;
		dist++;
		nod = nod->back;
	}while(nod->back);

	return -1;
}

void afiseaza(Nod *varf)
{	
	Nod *nod = varf;

	while(nod)
	{
		cout << nod->val << " ";
		nod = nod->back;
	}
	cout<<endl;
}


int main()
{
	Nod *varf = NULL;

	empty(varf) ? cout << "\nStiva este goala\n" : cout << "\nStiva nu este goala\n";

	push(5, varf);
	push(9, varf);
	push(12, varf);
	push(-4, varf);

	afiseaza(varf);

	cout << "\nCauta elementul 7";
	int res= search(7, varf);
	if(res == -1)
		cout << "\nNu l-a gasit.";
	else
		cout << "\nL-a gasit pe pozitia " << res << endl;
	
	cout << "\nCauta elementul 12";
	res = search(12, varf);
	if(res == -1)
		cout << "\nNu l-a gasit.";
	else
		cout << "\nL-a gasit pe pozitia " << res << endl;

	cout << "\nVarful stivei este " << peek(varf) << endl;

	empty(varf) ? cout << "\nStiva este goala\n" : cout << "\nStiva nu este goala\n";

	cout << pop(varf) << endl;
	cout << pop(varf) << endl;
	afiseaza(varf);

	return 0;
}