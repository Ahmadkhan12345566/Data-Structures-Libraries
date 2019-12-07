#include<iostream>
#include<conio.h>
#include<queue>
using namespace std;
void enqueue(struct node *data);
node dquue();
int ize();
struct node
{

	int ab;
	node *right;
	node *left;

};
struct nde
{
	node *data;
	nde *next;
};


node* NewNode(int data) {
	node* node = new struct node;
	node->ab = data;
	node->left = node->right = NULL;

	return node;
}


// Insert
node* insert(node* node, int data) {

	if (node == NULL) return(NewNode(data));
	else if (data <= node->ab) node->left = insert(node->left, data);
	else node->right = insert(node->right, data);

	return(node); // return the (unchanged) node pointer
}

void bredth_serch(node *root,int search) {
	
	bool dec = false;
	if (root == NULL) {
		cout << "Root is Null: \n";

	}
	else if(root->ab==search )
	{ 

		dec = true;
		cout << "Num found :" << root->ab;
		return;
	}
	else
	{
		if (root->left != NULL) {
			enqueue(root->left);
		}
		if (root->right != NULL) {
			enqueue(root->right);
		}
	}
	struct node *temp = new node;
	if (ize() != 0) {
		*temp = dquue();
		
		bredth_serch(temp, search);
	}
	else {
		int cnt = 0;
		if (cnt == 0 && ize() == 0 && dec == false) {
			cout << "Num not found ";
		}
	}
}


struct nde *head = new nde;
void enqueue(struct node *data) {
	struct nde *q = new nde;
	q->data = data;
	q->next = NULL;
 	struct nde *p = head;
	int c = 1;
	if (c == 1) {
		head = q;
	}
	else
	{
	while (p) {
			if (p->next == NULL) {
				p->next = q;
			}
			else
			{
				p = p->next;
			}
		}

	}
}
node dquue() {
	struct node *temp =new node;
	head = head->next;
	return *temp;
}
int ize() {
	struct nde *a = new nde;
	int b = 1;
	while (a->next!=NULL) {
		
			b++;
			a = a->next;
		
	}
	return b;
}

int main() {
struct node *root= NewNode(44);
insert(root, 111);
insert(root, 166);
insert(root,200);
insert(root, 11);
insert(root, 151);
insert(root, 745);
insert(root, 1006);
insert(root, 1856);
//print_Postorder(root);
bredth_serch(root, 18);
_getch();
}