#include<iostream>
#include<conio.h>
using namespace std;




struct node
{

	int data;
	node *right;
	node *left;

};



void initlize(struct node *head, int a) {



	head->data = a;
	head->right = NULL;
	head->left = NULL;


}
node* NewNode(int data) {
	node* node = new struct node;
	node->data = data;
	node->left = node->right = NULL;

	return node;
}


// Insert
node* insert(node* node, int data) {

	if (node == NULL) return(NewNode(data));
	else if (data <= node->data) node->left = insert(node->left, data);
	else node->right = insert(node->right, data);

	return(node); // return the (unchanged) node pointer
}


void  dsf(node *root, node *q, int num, int cout = 0) {
	if (root == NULL) {
		return;
	}
	else
	{
		cout++;
	}
	if (root->data==num){
		return;
	}
	if (root->left!=NULL) {
		dsf(root, root->left,num,cout);
	}
	if (root->right != NULL) {
		dsf(root, root->right, num, cout);
	
	}


}
void print_Inorder(node *root) {
	/*node *p = root;
	while(p){
	cout << p->ab<<endl;
	p = p->left;

	}*/
	if (root) {
		print_Inorder(root->left);
		cout << root->data << endl;
		print_Inorder(root->right);

	}
}
int main() {
	struct node *root = NewNode(2);
	root = NULL;
	insert(root, 9);
	insert(root, 117);
	insert(root, 11);
	insert(root, 7);
	insert(root, 1000);
	//insert(root, 9);
	cout << "InOrder  " << endl;
	print_Inorder(root);

	_getch();
}