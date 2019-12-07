#include<iostream>
#include<string>
using namespace std;

struct student
{
	string name;
	float cpa;
};
struct node
{
student data;
	node * next;
};

int main()
{
	node * n;
	node * h;
	node * t;

	n = new node;
	n->data.name = "arslan";
	n->data.cpa = 3.12;
	
	t = n, h = n;

	n = new node;

	n->data.name = "as";
	n->data.cpa = 3.12;
	t->next = n;
	t = n;

	n = new node;

	n->data.name = "asif";
	n->data.cpa = 3.12;
	t->next = n;
	t = n;

	n = new node;

	n->data.name = "safi";
	n->data.cpa = 0.12;
	t->next = n;
	t = n;
	t->next = NULL;


	node *temp = h;
	do {
		cout << temp->data.name<<"     ";
		cout << temp->data.cpa<<endl;
		cout << " --> ";
		temp = temp->next;
	} while (temp != NULL);
	system("pause");
	return 0;
}