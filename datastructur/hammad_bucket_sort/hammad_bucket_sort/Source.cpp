#include<iostream>
#include<conio.h>
using namespace std;
struct node {
	int data;
	node*next;
};
int min, max, range;
void init(node*head, int num)
{
	head->data = num;
	head->next = NULL;
}
void add(node*head, int num)
{
	node*q = new node;
	q->data = num;
	q->next = NULL;
	node*p = head;
	while (p)
	{
		if (p->next == NULL)
		{
			p->next = q;
			return;
		}
		else p = p->next;
	}




}
void display(node*head)
{
	node*p = head;
	while (p)
	{
		cout << p->data << "--->";
		p = p->next;
	}
}
int find_min_max(node*head)
{
	node*p = head;
	min = max = head->data;
	while (p)
	{
		if (p->data < min)
		{
			min = p->data;
		}
		else if (p->data > max)
		{
			max = p->data;
		}
		p = p->next;
	}
	return min, max;
}
void find_range()
{
	int num = max - min;
	range = num / 4;
	cout << endl << range;
}
void dumping_buckets(node*head, node*head1, node*head2, node*head3, node*head4)
{
	node*p = head;
	head1 = NULL;
	head2 = NULL;
	head3 = NULL;
	head4 = NULL;
	int l1 = min;
	int h1 = min + range;
	int l2 = h1 + 1;
	int h2 = l2 + range;
	int l3 = h2 + 1;
	int h3 = l3 + range;
	int l4 = h3 + 1;
	int h4 = max;
	while (p)
	{
		if (p->data >= l1&&p->data <= h1)
		{
			if (head1->data == NULL)
			{
				init(head1, p->data);

			}
			else add(head1, p->data);

		}
		else	if (p->data >= l2&&p->data <= h2)
		{
			if (head2 != NULL)
			{
				add(head2, p->data);
			}
			else  init(head2, p->data);
		}
		else	if (p->data >= l3&&p->data <= h3)
		{
			if (head3 != NULL)
			{
				add(head3, p->data);
			}
			else  init(head3, p->data);
		}
		else	if (p->data >= l4&&p->data <= h4)
		{
			if (head4 != NULL)
			{
				add(head4, p->data);
			}
			else init(head4, p->data);
		}
		p = p->next;
	}



}
void sorting(node*head)
{
	node*p = head;
	while (p)
	{
		node*q = p->next;

		while (q)
		{
			if (p->data > q->data)
			{
				int temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
}
/*
void merge(node*head, node*head1, node*head2, node*head3, node*head4)
{

	node*p1 = head1;
	node*p2 = head2;
	node*p3 = head3;
	node*p4 = head4;
	while (p)
	{
		if (p->next == NULL)
		{
			p->next = head2;
		}

	}

}
*/
int main()
{

	node*head = new node;
	node*head1 = new node;
	node*head2 = new node;
	node*head3 = new node;
	node*head4 = new node;
	init(head, 16);
	add(head, 11);
	add(head, 13);
	add(head, 12);
	add(head, 14);
	add(head, 15);
	add(head, 20);
	display(head);
	min, max = find_min_max(head);
	find_range();
	dumping_buckets(head, head1, head2, head3, head4);
	cout << "          -----------    ";

	display(head1);
	cout << "          -----------    ";

	display(head2);
	cout << "          -----------    ";

	display(head3);
	cout << "          -----------    ";
	display(head4);
	sorting(head1);
	sorting(head2);
	sorting(head3);
	sorting(head4);

	_getch();
}