#include<iostream>
#include<conio.h>
using namespace std;


struct node
{

	int ab;
	node *right;
	node *left;

};



void initlize(struct node *head, int a) {



	head->ab = a;
	head->right = NULL;
	head->left = NULL;


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



void insrtnum_tree(int strt, int end) {
	int rt = strt / 2;
	struct node *root = NewNode(rt);

}
void search(struct node* root, int num,int a=0) {

	if (root == NULL) {
		return;
	}
	else if (root->ab == num) {
		cout << root->ab << "  Number Found In tree";
		a++;
		return;

	}
	else {
		search(root->left, num,a);
		search(root->right, num,a);
		
	}
	if (a == 0) {
		cout << "Number not found ";
	}
}
int main() {

	struct node *root = NewNode(2);



	insert(root, 9);
	insert(root, 117);
	insert(root, 11);
	insert(root, 7);
	insert(root, 1000);
	int num;
	cout << "Enter the from the list to search :(2,9,117,11,7,1000)" << endl;
	cin >> num;

	search(root, num);


	_getch();
}
