#include<iostream>
#include<conio.h>
using namespace std;


struct NodePointer
{

	char ab;
	NodePointer *right;
	NodePointer *left;

};



void initlize(struct NodePointer *head, char a) {



	head->ab = a;
	head->right = NULL;
	head->left = NULL;


}
NodePointer* NewNode(char data) {
	NodePointer* node = new struct NodePointer;
	node->ab = data;
	node->left = node->right = NULL;

	return node;
}


NodePointer* treeinsert(char c, NodePointer* node) {

	if (node == NULL) return(NewNode(c));
	else if (c <= node->ab) node->left = treeinsert(c, node->left);
	else node->right = treeinsert( c, node->right);

	return(node); // return the (unchanged) node pointer
}





void print_Preorder(NodePointer *root) {

	if (root) {
		cout << root->ab << endl;
		print_Preorder(root->left);

		print_Preorder(root->right);
	}
}
int main() {

	struct NodePointer *root = NewNode('g');
	treeinsert( 'b',root);
	treeinsert('z',root);
	treeinsert('h',root);
	treeinsert('d',root);
	treeinsert('k',root);
	treeinsert('n',root);

	
	cout << "PreOrder " << endl;
	print_Preorder(root);
	
	
	_getch();
}
