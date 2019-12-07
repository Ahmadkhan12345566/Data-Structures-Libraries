#include <iostream>
using namespace std;

// Node class
class Node {
	int data;
	Node* next;

public:
	Node() {};
	void SetData(int aData) { data = aData; };
	void SetNext(Node* aNext) { next = aNext; };
	int Data() { return data; };
	Node* Next() { return next; };
};

// List class
class List {
	Node *head1;
	Node *head2;
public:
	List() { head1 = NULL;head2 = NULL; };
	void Print();
	void Append(int data);
	void Delete(int data);
	void Printlist(List a, List b);
};

/**
* Print the contents of the list
*/
void List::Print() {

	// Temp pointer
	Node *tmp = head1;

	// No nodes
	if (tmp == NULL) {
		cout << "EMPTY" << endl;
		return;
	}

	// One node in the list
	if (tmp->Next() == NULL) {
		cout << tmp->Data();
		cout << " --> ";
		cout << "NULL" << endl;
	}
	else {
		// Parse and print the list
		do {
			cout << tmp->Data();
			cout << " --> ";
			tmp = tmp->Next();
		} while (tmp != NULL);

		cout << "NULL" << endl;
	}
}

/**
* Append a node to the linked list
*/

void List::Append(int data) {

	// Create a new node
	Node* newNode = new Node();
	newNode->SetData(data);
	newNode->SetNext(NULL);

	// Create a temp pointer
	Node *tmp = head1;

	if (tmp != NULL) {
		// Nodes already present in the list
		// Parse to end of list
		while (tmp->Next() != NULL) {
			tmp = tmp->Next();
		}

		// Point the last node to the new node
		tmp->SetNext(newNode);
	}
	else {
		// First node in the list
		head1 = newNode;
	}
}



void List::Printlist(List l1, List l2) {
	Node	*temp1=l1.head1;

	Node    *temp2;
	abc:
	int count=0;
	while (temp1) {
	
	
		temp2=l2.head1;
		while (temp2) {
			if (temp2->Data() <count && temp2->Data()!=l2.head1->Data()) {
				goto abc;
			}
		if (count == temp2->Data()) {
				cout << temp1->Data()<<endl;
				break;
			}
			else {
				temp2 = temp2->Next();
			}
		}
		count++;
		temp1 = temp1->Next();

  }


}

/**
* Delete a node from the list
*/
void List::Delete(int data) {

	// Create a temp pointer
	Node *tmp = head1;

	// No nodes
	if (tmp == NULL)
		return;

	// Last node of the list
	if (tmp->Next() == NULL) {
		delete tmp;
		head1 = NULL;
	}
	else {
		// Parse thru the nodes
		Node *prev = NULL;
		do {
			if (tmp->Data() == data) break;
			prev = tmp;
			tmp = tmp->Next();
		} while (tmp != NULL);
		
		// Adjust the pointers
		prev->SetNext(tmp->Next());

		// Delete the current node
		delete tmp;
	}
}

int main()
{
	// New list
	List list1;
	List list2;

	// Append nodes to the list
list1.Append(100);
list1.Append(101);
list1.Append(102);
list1.Append(103);
list1.Append(104);
list1.Append(105);
	list1.Print();
	list2.Append(0);
	
	list2.Append(2);
	list2.Append(3);

	list2.Append(5);
	list2.Append(0);
list2.Append(1);

	list2.Append(2);

	list2.Print();
	list2.Printlist(list1, list2);
	//list.Append(200);
	//list.Print();
	//list.Append(300);
	//list.Print();
	//list.Append(400);
	//list.Print();
	//list.Append(500);
	//list.Print();

	// Delete nodes from the list
	//list.Delete(400);
	//list.Print();
	//list.Delete(300);
	//list.Print();
	//list.Delete(200);
	//list.Print();
	//list.Delete(500);
	//list.Print();
	//list.Delete(100);
	//list.Print();
	system("pause");
	return 0;
}