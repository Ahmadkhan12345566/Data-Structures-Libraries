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
void insert(struct node *head, int a) {
	struct node *q = new node;
	q->ab = a;
	q->next = NULL;
	node *p = head;

	if (head->next != NULL && c == 0) {
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

void display(struct  node *head)
{
	node *p = head;
	while (p) {
		cout << p->ab << "-->";
		p = p->next;
	}
	cout << endl;
}

void search(struct  node *head,int num)
{
	node *p = head;
	while (p) {
		if (p->ab == num) {
			cout << p->ab << "numfound";
		}
		p = p->next;
	}
	
}


void auto_insert(node *mhead) {
	insert(mhead, 48);
	insert(mhead, 55);
	insert(mhead, 60);
	insert(mhead, 65);
	insert(mhead, 22);
	insert(mhead, 25);
	insert(mhead, 29);
	insert(mhead, 33);
	insert(mhead, 31);
	insert(mhead, 35);
	insert(mhead, 40);
	insert(mhead, 41);
	insert(mhead, 43);
	insert(mhead, 45);

	insert(mhead, 30);
	insert(mhead, 32);
	insert(mhead, 44);
	insert(mhead, 45);
	insert(mhead, 67);
	insert(mhead, 19);
	insert(mhead, 0);
	insert(mhead, 56);
	insert(mhead, 33);
	insert(mhead, 1);
	insert(mhead, 9);
	insert(mhead, 5);
	insert(mhead, 11);

}






void dumping(struct node *mhead, struct node *head1, struct node *head2, struct node *head3, struct node *head4) {
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	struct node *p = mhead;
	while (p)
	{
		if (p->ab %4==0) {
			if (head1->next != NULL&&n1 == 0) {
				c = 0;
				n1++;
			}
			insert(head1, p->ab);
		}
		else if (p->ab %4 ==1) {

			if (head2->next != NULL&&n2 == 0) {
				c = 0;
				n2++;
			}
			insert(head2, p->ab);


		}
		else if (p->ab%4==2)
		{
			if (head3->next != NULL && n3 == 0) {
				c = 0;
				n3++;
			}
			insert(head3, p->ab);


		}
		else if(p->ab % 4 == 3)
		{

			if (head4->next != NULL&&n4 == 0) {
				c = 0;
				n4++;
			}
			insert(head4, p->ab);



		}

		p = p->next;
	}

}


int main() {
	struct node *mhead = new node;
	struct node *h1 = new node;
	struct node *head1 = new node;
	struct node *head2 = new node;
	struct node *head3 = new node;
	struct node *head4 = new node;
	auto_insert(mhead);
	//dm(mhead, h1);
	int num=4;
	dumping(mhead, head1, head2, head3, head4);
	cout << "enter a numeber to search " << endl;
	cin >> num;
	int rem = num % 4;
	if (rem == 0) {
		search(head1, num);
	}
	else if (rem==1)
	{
		search(head2, num);
	}
	else if (rem==2)
	{
		search(head3, num);
	}
	else if(rem==3)
	{
		search(head4, num);
	}
	_getch();
}