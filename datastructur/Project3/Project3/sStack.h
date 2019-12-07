#ifndef sStack
#include<iostream>
#include<conio.h>
#endif // !sStack
#pragma once
template <typename T>
class sStack
{
	struct Node
	{
		T data;
		Node *next;
	};
private:
	Node *head;
public:
	
	void puch(T key) {//insert data in stack
		Node *p = new Node;
		p->data = key;
		p->next = head;
		head = p;
	}
	void pop() {//delet the upper most
		if (!empty)
		{
			head = head->next;
		}
	}

	T top() {//return the upper most
		if (!empty())
		{
			return (head->data);
		}
	
	}
	bool empty() {
		if (head == NULL) return true;
		return false;
	}

	//~MyClass();
	sStack() {
		head = nullptr;
	}
};

