#ifndef sTrees

#include<iostream>
#include<conio.h>
#endif // !sTrees
#pragma once
template <typename T>
class sTrees {

	struct Node{
		T data;
		Node *left;
		Node *right;
	};
private :
	Node *root;
	void creat_node(T a) {
		Node *p = new Node;
		p->data = a;
		p->left = NULL;
		p->right = NULL;
		root = p;
		return;

	}
public:
	
	void add(T a){
		if (root == NULL) creat_node(, a);
		else if(true) {

		}
		else {

		}

	}
	
	sTrees() {
		root = NULL;
	}
};