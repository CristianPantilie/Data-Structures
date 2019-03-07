#include <iostream>
using namespace std;

struct nod{
	int val;
	int height;
	struct nod *left, *right;
};
typedef struct nod Nod;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int height(Nod *n)
{
	if(!n)
		return 0;
	return n->height;
}

Nod* newNode(int val)
{
	Nod *nou = new Nod;
	nou->val = val;
	nou->left = NULL;
	nou->right = NULL;
	nou->height = 1;
	return nou;
}

Nod* rightRotate(Nod *y)
{
	Nod *x = y->left;
	Nod *T2 = x->right;

	//perform rotation
	x->right = y;
	y->left = T2;

	//update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	//return new root
	return x;
}

Nod* leftRotate(Nod *x)
{	
	Nod *y = x->right;
	Nod *T2 = y->left;

	//perform rotation
	y->left = x;
	x->right = T2;

	//update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	//return new root
	return y;
}

int getBalance(Nod *n)
{
	if(!n)
		return 0;
	return height(n->left) - height(n->right);
}

Nod* insert(Nod* rad, int val)
{
	//1. Perform normal BST insertion
	if(!rad)
		return(newNode(val));

	if(val < rad->val)
		rad->left = insert(rad->left, val);
	else if(val > rad->val)
		rad->right = insert(rad->right, val);
	else //equal keys are not allowed in BST
		return rad;

	//2. Update height of this ancestor node
	rad->height = 1 + max(height(rad->left), height(rad->right));

	//3. Get the balance factor of this ancestor node to check
	//   whether this node became unbalanced
	int balance = getBalance(rad);
	//if this node becomes unbalanced there are 4 cases

	//left left
	if(balance > 1 && val < rad->left->val)
		return rightRotate(rad);
	//right right
	if(balance < -1 && val > rad->right->val)
		return leftRotate(rad);
	//left right
	if(balance > 1 && val > rad->left->val)
	{
		rad->left = leftRotate(rad->left);
		return rightRotate(rad);
	}
	//right left
	if(balance < -1 && val < rad->right->val)
	{
		rad->right = rightRotate(rad->right);
		return leftRotate(rad);
	}

	return rad;
}

void preOrder(Nod *rad)
{
	if(rad)
	{
		cout << rad->val << " ";
		preOrder(rad->left);
		preOrder(rad->right);
	}
}

int main()
{
	Nod *rad = NULL;

	rad = insert(rad, 10);
	rad = insert(rad, 20);
	rad = insert(rad, 30);
	rad = insert(rad, 40);
	rad = insert(rad, 50);
	rad = insert(rad, 25);

	preOrder(rad);

}