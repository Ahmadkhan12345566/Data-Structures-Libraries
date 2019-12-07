#include <conio.h>
#include<iostream>
using namespace std;
struct node
{
	int ab;
	node *next;


};


void initlize(struct node *head, int a) {
	head->ab = a;
	head->next = NULL;

}
void insert(struct node *head, int a) {
	struct node *q = new node;
	q->ab = a;
	q->next = NULL;
	node *p = head;

	while (p) {
		if (p->next == NULL) {
			p->next = q;
			break;
		}
		else {
			p = p->next;
		}
	}

}
void display(struct  node *head)
{
	node *p = head;
	while (p) {
		cout << p->ab << endl;
		p = p->next;
	}
}
node *intersectin = new node;
void intersection(node *head1, node *head2) {
	node *p1 = head1;
	node *p2 = head2;

	struct node *head3 = new node;
	node *p3 = head3;
	int a = 0;
	p1 = head1;
	int cn = 0;

	while (p2 != NULL) {
		p1 = head1;
		while (p1 != NULL) {
			if (p1->ab == p2->ab) {
				
				
				if (cn == 0) {
					cn++;
					initlize(intersectin, p1->ab);
					
				}
				else
				{
					insert(intersectin, p1->ab);
				}
				//cout << p1->ab << endl;

			}
			p1 = p1->next;

		}

		p2 = p2->next;
	}

}

int main() {

	struct node *head1 = new node;
	struct node *head2 = new node;
	
	
	initlize(head1, 0);
	insert(head1, 1);
	insert(head1, 2);
	insert(head1, 3);
	insert(head1, 4);
	insert(head1, 5);
	insert(head1, 17);
	insert(head1, 21);
	insert(head1, 30);
	insert(head1, 44);
	insert(head1, 50);


	cout << endl<<"          List 1" << endl<<endl;
	display(head1);

	

	initlize(head2, 11);
	insert(head2, 2);
	insert(head2,5);
	insert(head2, 9);
	insert(head2, 44);
	insert(head2, 50);
	insert(head2, 20);
	insert(head2, 88);
	insert(head2, 99);
	cout<<endl << "           List 2" << endl<<endl;
	display(head2);

	
	intersection(head1, head2);
	cout<<endl << "Intersection Between these two lists are :" << endl << endl;
	display(intersectin);
	
	_getch();
}