#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
void Init(Node *Head, int num)
{
	Head->data = num;
	Head->next = NULL;
}
void Add(Node *Head, int num)
{
	Node *q = new Node;
	q->data = num;
	q->next = NULL;
	Node *p = Head;
	while (p)
	{
		if (p->next == NULL)
		{
			p->next = q;
			break;
		}
		else p = p->next;

	}

}
Node Delete(Node *Head, int num)
{
	Node *p = Head;

	if (p->data == num)
	{
		Node *q = p;
		Head = p->next;
		p = p->next;

	}
	else
	{

		while (p)
		{
			if (p->next != NULL)
			{
				if (p->next->data == num)
				{
					p->next = p->next->next;
				}

			}
			p = p->next;
		}
	}
	return *Head;
}
void Edit(Node *Head, int num1, int num2)
{
	Node *p = Head;
	while (p)
	{
		if (p->data == num1)
		{
			p->data = num2;
		}
		else p = p->next;
	}
}
int size(Node *head) {
	int count = 0;
	struct Node *q = head;
	while (q) {

		count++;
		q = q->next;
	}
	return count;
}
void Display(Node *Head)
{
	Node *p = Head;
	while (p)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}
void  bsf(Node  arr[], int serch,int size) {
	Node *q = arr;
	while (q)
	{
		for (int i = 0; i < size; i++)
		{
			q[i]->



		}
	}
}



int main()
{
	Node *Head = new Node();
	Node *Graph[12];
	Graph[0] = new Node();
	Graph[1] = new Node();
	Graph[2] = new Node();
	Graph[3] = new Node();
	Graph[4] = new Node();
	Graph[5] = new Node();
	Graph[6] = new Node();
	Graph[7] = new Node();
	Graph[8] = new Node();
	Graph[9] = new Node();
	Graph[10] = new Node();
	Graph[10] = new Node();
	Graph[11] = new Node();
	
	Add(Graph[0], 1);
	Add(Graph[0], 5);
	Add(Graph[0], 6);
//node2
	Add(Graph[1], 2);
	Add(Graph[1], 7);
    Add(Graph[1], 3);

	//node3
	Add(Graph[2], 3);
	Add(Graph[2], 7);
	Add(Graph[2], 4);
	//node4
	Add(Graph[3], 4);
	Add(Graph[3], 7);
	//node5
	Add(Graph[4], 5);
	Add(Graph[4], 9);
	//node6
	Add(Graph[5], 6);
	Add(Graph[5], 9);
	Add(Graph[5], 2);
	Add(Graph[5], 7);
//node7
	Add(Graph[6], 7);
	Add(Graph[6], 10);
	Add(Graph[6], 11);
	Add(Graph[6], 8);
	//node8
	Add(Graph[7], 8);
	Add(Graph[7], 11);
	Add(Graph[7], 12);
	//node9
	
	Add(Graph[8], 9);
	Add(Graph[8], 10);
//node10

	Add(Graph[9], 10);
	

	//node11
	Add(Graph[10], 11);
	Add(Graph[10], 12);
	for (int i = 0; i < 12; i++) {
		Graph[i] = Graph[i]->next;
	}

	cout << "---------Linked List-------------" << endl;
	Display(Head);

	Display(Graph[1]);


	_getch();
}