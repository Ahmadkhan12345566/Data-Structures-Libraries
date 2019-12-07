#include<iostream>
#include<conio.h>
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
int c = 0;
/*void insert(struct node *head, int a) {
	struct node *q = new node;
	q->ab = a;
	q->next = NULL;
	node *p = head;
	
	if (head->next!=NULL && c==0) {
		initlize(head, a);
		c++;
	}
	else
	{


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
}
*/
//sort insert
void insert(struct node *head, int a) {
	struct node *q = new node;
	q->ab = a;
	q->next = NULL;
	node *p = head;
	
	if (head->next != NULL && c == 0) {
		initlize(head, a);
		c++;
	}
	else if (head->ab > a) {
		struct node *temp = new node;
		temp = head;
		initlize(head, a);
		head->next = temp;
	}
	else
	{
     while (p) {
			if (p->next == NULL) {
				p->next = q;
				break;
			}
			else if(p->ab>a)
			{
				struct node *temp = new node;
				temp = p;
				p = q;
				q->next = temp;

			}
			else {
				p = p->next;
			}
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
int main() {
	struct node *mhead = new node;
	
	insert(mhead, 9);
	insert(mhead, 6);
	insert(mhead, 1);
	insert(mhead, 8);
	insert(mhead,0);
	insert(mhead, 29);
	insert(mhead, 39);
	insert(mhead, 41);
	insert(mhead, 46);
	insert(mhead, 50);
	insert(mhead, 55);
	insert(mhead, 57);
	insert(mhead, 64);
	insert(mhead, 70);
	insert(mhead, 74);
	insert(mhead, 76);
	insert(mhead, 78);
	insert(mhead, 80);
	insert(mhead, 85);
	insert(mhead, 89);

	display(mhead);
	_getch();


}