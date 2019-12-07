#include<iostream>
#include<conio.h>
using namespace std;


struct node
{

	int ab;
	node *next;
	node *prv;

};
//initilazition

void initlize(struct node *head, int a) {
	head->ab = a;
	head->next = head;
	head->prv = head;
}

//insert
void insert(struct node *head, int a) {
	struct node *q = new node;
	q->ab = a;
	q->next = head;
	q->prv = head;
	node *p = head;

	while (p) {
		if (p->next ==head) {
			p->next = q;//assining the give node at the end 
			p->next->prv = p;//saving the address of previs node in last node 
			head->prv = q;
			break;
		}
		else {
			p = p->next;
		}
	}

}
//reverse
void revers(struct node *head) {

	node *p = head;

	while (p) {
		if (p->next == NULL) {
			while (p)
			{
				if (p->prv == NULL) {
					cout << p->ab << endl;
					break;
				}
				else
				{
					cout << p->ab << endl;
					p = p->prv;
				}

			}
			break;
		}
		else {
			p = p->next;
		}
	}

}


//display
void display(struct  node *head)
{
	node *p = head;
	do {
		cout << p->ab << endl;
		p = p->next;
	} while (p != head);
}
//delete
void delet(struct node *head, int a) {

	node *p = head;
	if (head->ab == a) {
	//head = head->next;
	while (p->next != head) {
		p = p->next;
	}
		node *q = p;
		p = p->next;
		p->next = head->next;
		head = head->next;
		head->next->prv = head->prv;
		delete(q);//deteting the node
	
	
	}
	else
	{
		do {
			if (p->next->ab == a) {
				if (p->next->next != head) {
					p->next = p->next->next; //skipping the node which value is equal to given number---and assing the addres of next node
					p->next->prv = p;//saving the address of p in the next moved node
				}
				else
				{
					p->next = head;

				}
				break;
			}
			else {
				p = p->next;
			}
		}while (p != head);
	}
}

//edit
void edit(struct node *head, int a, int c) {

	node *p = head;

	do {
		if (p->ab == a) {
			p->ab = c;
			break;
		}
		else {
			p = p->next;
		}
	} while (p != head);
}

int main() {

	struct node *head = new node;
	cout << "Enter Number" << endl;
	int n;
	cin >> n;
	initlize(head, n);
	insert(head, 15);
	insert(head, 10);
	insert(head, 18);
	cout << "After inputr the data" << endl; display(head);
	//cout << "Revers order of input" << endl;	revers(head);


//	delet(head, n);
	delet(head, 18);
	cout << "After deleting the data 18" << endl; display(head);

	edit(head, 10, 100);
	cout << "After editing  the data 10 to 100" << endl; display(head);


	_getch();
}

