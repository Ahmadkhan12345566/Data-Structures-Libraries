#include<iostream>
#include<conio.h>
using namespace std;


struct node
{

	int ab;
	node *right;
	node *left;

};



void initlize(struct node *head,int a) {

	

		head->ab = a;
		head->right = NULL;
		head->left = NULL;


}




void tree(node *root,int data) {
	node *dta =new node;
	dta->ab = data;
	dta->right = NULL;
	dta->left = NULL;
	node *p = root;
	node *nxt = new node;
	if (p->ab<dta->ab){
		if (p->right == NULL) {
			//dta->left = p;
			p->right = dta;
			return;
		}
		else {
			nxt = root->right;
			tree(nxt, data);

		}
	}
	else if(p->ab>dta->ab)
	{
		
		if (p->left == NULL) {
		//	dta->right = p;
			p->left = dta;
			return;
		}
		else {
			nxt = root->left;
			tree(nxt, data);

		}

	}


}


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

void print_Preorder(node *root) {
	/*node *p = root;
	while(p){
		cout << p->ab<<endl;
		p = p->left;
		
	}*/
	if (root) {
		cout << root->ab << endl;
		print_Preorder(root->left);
		
		print_Preorder(root->right);
	}
}



void print_Postorder(node *root) {
	/*node *p = root;
	while(p){
	cout << p->ab<<endl;
	p = p->left;

	}*/
	if (root) {
		print_Postorder(root->left);
		print_Postorder(root->right);
		cout << root->ab << endl;
	
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
		cout << root->ab << endl;
		print_Inorder(root->right);
		
	}
}
/*
node* creat_node(int data) {
	node *q = new node;
	q->ab = data;
	q->left = NULL;
	q->right = NULL;
	
	return q;
}


node* add(node *root,int num ) {
	if (root == NULL) {
	root=creat_node(num);
	return root;
	}
	else if (num<root->ab) {
		add(root->left, num);
	}
	else if (num > root->ab) {
		add(root->right, num);
	}



}
*/
void insrtnum_tree(int strt,int end) {
	int rt = strt / 2;
	struct node *root = NewNode(rt);
	
}
void search(struct node* root, int num) {

	if (root == NULL) {
		return;
	}
	else if (root->ab == num) {
		cout << root->ab << "  Number Found ";
		return ;

	}
	else {
		search(root->left, num);
		search(root->right, num);
	}
}
int main() {

	struct node *root = NewNode(2);
	//initlize(root, 9);
	//tree(root, 117);
	
/*	tree(root, 11);
	tree(root, 7);
    tree(root, 10000);
	tree(root, 0);*/
	insert(root, 9);
	insert(root, 117);
	insert(root, 11);
	insert(root, 7);
	insert(root, 1000);
	
//	cout << "Pre Order"<<endl;
//	print_Preorder(root);
	search(root, 1000);
//	cout << "post Order" << endl;
	//print_Postorder(root);
	//cout << "InOrder  " << endl;
	//print_Inorder(root);
	//	cout << root->ab;
	/*root = NULL;
	root = add(root, 1);
	root = add(root, 3);
	*/
	_getch();
}
