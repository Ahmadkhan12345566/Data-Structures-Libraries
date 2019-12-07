//
//  main.cpp
//  LLTask
//
//  Created by Asif Raza on 30/09/2016.
//  Copyright © 2016 Asif Raza. All rights reserved.
//

#include <iostream>
#include <stack>


// change the type 'char' is use reverse
typedef int T;

struct mNode {
	T data;
	mNode *next;
};

void inti(mNode *head, T d) {
	head->data = d; head->next = NULL;
}

void insert(mNode *head, T d) {
	mNode *q = new mNode;
	q->data = d; q->next = NULL;
	mNode *p = head;
	while (p) {
		if (p->next == NULL) {
			p->next = q; break;
		}
		else
			p = p->next;
	}
}

void display(mNode *head) {
	mNode *p = head;
	while (p) { std::cout << p->data << std::endl; p = p->next; }
}


void reverse(mNode *head) {
	mNode *p = head;
	std::stack<T> mStack;
	while (p) { mStack.push(p->data); p = p->next; }

	// rest the head
	p = head;
	while (p) { p->data = mStack.top(); mStack.pop(); p = p->next; }
}

void addtwolist(mNode *head1, mNode *head2) {
	mNode *p1 = head1;
	mNode *p2 = head2;
	while (p1 && p2) {
		p1->data += p2->data;
		p1 = p1->next; p2 = p2->next;
	}
}

/*
void PrintIndex(mNode *head, int index){
mNode *p = head;
short count = 0;

if(count == index)
std::cout << p->data << std::endl;

while (p) {
if(count == index){
std::cout << p->data << std::endl;
break;
}
else
p = p->next;

count++;
}
}*/

void Print2List(mNode *l1, mNode *l2) {
	mNode *h1 = l1;
	mNode *h2 = l2;

	int count;

	while (h2) {

		// rest count and l1
		count = 0;
		h1 = l1;

		while (h1) {
			if (h2->data == count) {
				std::cout << h1->data << std::endl;
				break;
			}

			h1 = h1->next;
			count++;
		}

		h2 = h2->next;

	}

}

void reverseREC(mNode *head) {
	if (head == NULL) return;
	reverseREC(head->next);
	std::cout << head->data << std::endl;
}


void swapAdj(mNode *head) {
	if (head != NULL && head->next != NULL)
	{
		mNode *current = head->next;
		std::swap(*head, *current);
		std::swap(head->next, current->next);

		swapAdj(head->next->next);
	}
}


void sortNodes(mNode * ptr) {
	mNode * temp = ptr;
	mNode * curr;
	for (bool didSwap = true; didSwap; ) {
		didSwap = false;
		for (curr = ptr; curr->next != NULL; curr = curr->next) {
			if (curr->data > curr->next->data) {
				temp->data = curr->data;
				curr->data = curr->next->data;
				curr->next->data = temp->data;
				didSwap = true;
			}
		}
	}
}

void removeDuplicates(mNode* head)
{
	mNode* current = head;

	mNode* next;

	if (current == NULL)
		return;

	while (current->next != NULL)
	{
		/* Compare current node with next node */
		if (current->data == current->next->data)
		{
			next = current->next->next;
			delete (current->next);
			current->next = next;
		}
		else
		{
			current = current->next;
		}
	}
}

mNode& margeLists(mNode *p, mNode *q) {
	mNode *result = new mNode;
	while (p) {
		insert(result, p->data);
		p = p->next;
	}

	while (q) {
		insert(result, q->data);
		q = q->next;
	}

	// return the result
	return *result;
}

void findUnion(mNode *p, mNode *q) {

	mNode *result;

	// store the return address into the resutl Node
	result = &margeLists(p, q);

	// Sort the Node
	sortNodes(result);

	// Remove the Duplicates
	removeDuplicates(result);

	// display
	display(result);

}


int main(int argc, const char * argv[]) {
	// insert code here...
	mNode *h1 = new mNode;
	mNode *h2 = new mNode;



	// Uncomment for char reverse

	/*
	inti(head, 'A');
	insert(head, 'B');
	insert(head, 'C');
	insert(head, 'D');
	insert(head, 'E');
	insert(head, 'F');
	//display(head);
	reverse(head);
	std::cout << std::endl;
	display(head);
	*/

	inti(h1, 1);
	insert(h1, 3);
	insert(h1, 5);
	insert(h1, 6);
	std::cout << "Display List 1:\n";
	display(h1);

	std::cout << "Adj: of List 1\n";
	swapAdj(h1);
	display(h1);

	std::cout << "Revers of List 1\n";
	reverseREC(h1);


	inti(h2, 1);
	insert(h2, 2);
	insert(h2, 4);
	insert(h2, 7);
	std::cout << "Display List 2:\n";
	display(h1);
	std::cout << "Union of List1 & List2\n";
	findUnion(h1, h2);



	//std::cout <<  FindIndexNumber(h1, 2) << std::endl;
	//PrintIndex(h1, 2);





	//display(head);




	return 0;
}
