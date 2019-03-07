#include <iostream>
using namespace std;

struct nod{
	int val;
	struct nod *next;
};
typedef struct nod Nod;



void push(Nod* &front, Nod* &rear, int val)
{
	Nod *nou = new Nod;
	nou->val = val;
	nou->next = NULL;
	
	if(!rear)   	//coada era vida
		front = nou;
	else
		rear->next = nou;

	rear = nou;
}

int pop(Nod *&front, Nod *&rear)
{
	int ret = front->val;
	Nod *n = front;
	if(front->next)
		front = front->next;
	else
		rear = NULL;

	delete n;

	return ret;	
}

int peek(Nod *front, Nod *rear)
{
	return front->val;
}

bool empty(Nod *front, Nod *rear)
{
	if(!front)
		return true;
	return false;
}

int search(Nod *front, Nod *rear, int val)
{
	Nod *iter = front;
	int dist = 0;
	while(iter)
	{
		if(iter->val == val)
			return dist;
		dist++;
		iter = iter->next;
	}
	return -1;
}

void afiseaza(Nod *front, Nod *rear)
{
	Nod *iter = front;
	cout << "Coada: ";
	while(iter)
	{
		cout << " " << iter->val;
		iter = iter->next;
	}
	cout << endl;
}

int main()
{
	Nod *front = NULL;
	Nod *rear = NULL;
	empty(front, rear) ? cout << "\nCoada este goala\n" : cout<< "\nCoada nu este goala\n";

	push(front, rear, 4);
	push(front, rear, 1);
	push(front, rear, 9);
	push(front, rear, 3);

	afiseaza(front, rear);

	cout << endl << pop(front, rear) << endl;

	afiseaza(front, rear);

	cout << endl << peek(front, rear);

	empty(front, rear) ? cout << "\nCoada este goala\n" : cout<< "\nCoada nu este goala\n";

	cout << "\nNumarul 9 este pe pozitia: " << search(front, rear, 9);
	cout << "\nNumarul 18 este pe pozitia: " << search(front, rear, 18); 
	



	return 0;
}