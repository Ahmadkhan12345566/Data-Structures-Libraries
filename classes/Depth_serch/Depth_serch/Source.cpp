#include<iostream>
#include<conio.h>
using namespace std;
struct node {
	int data;
	node *left;
	node *rignt;
};

node* NewNode(int data) {
	node* node = new struct node;
	node->data= data;
	node->left = node->rignt = NULL;

	return node;
}


// Insert
node* insert(node* node, int data) {

	if (node == NULL) return(NewNode(data));
	else if (data <= node->data) node->left = insert(node->left, data);
	else node->rignt = insert(node->rignt, data);

	return(node); // return the (unchanged) node pointer
}



void breth_searc(node *head,node *root,int num,int count,int dec=0) {
	if (root == NULL) {
		return;
	}
	else
	{
		count = count++;
	}
	
	
	if (root->data==num) {
		cout << "num found   " << root->data<<endl;
		cout << count; 
		dec = 1;
	}
	
		breth_searc(head, root->left, num,count);
	
	
		breth_searc(head, root->rignt, num,count);
	

    


}

int main() {

	struct node *root = NewNode(100);

	insert(root, 9);
	insert(root, 117);
	insert(root, 11);
	insert(root, 7);
	insert(root, 199);
	insert(root, 57);
	insert(root, 78);
	insert(root, 1000);
	insert(root, 115);
	breth_searc(root, root, 100,0);
	_getch();
}
