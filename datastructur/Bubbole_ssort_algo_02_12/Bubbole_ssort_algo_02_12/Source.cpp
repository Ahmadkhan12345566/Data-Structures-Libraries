#include<iostream>
#include<conio.h>
using namespace std;
#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
void Add(Node *Head, int data)
{
	Node *q = new Node;
	q->data = data;
	q->next = NULL;
	Node *p = Head;
	while (p)
	{
		if (p->next != NULL)
		{

			p = p->next;

		}
		else
		{
			p->next = q;
			return;
		}
	}

}
void Display(Node *Head)
{

	Node *p = Head;
	while (p)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL";
}

void auto_fill(Node *head) {

	Add(head, 9);
	Add(head, 19);
	Add(head, 25);
	Add(head, 39);
	Add(head, 79);
    Add(head, 3);
}


//bubble sort on arrays
void bubble_sort(int a[],int size) {
	for (int i = 0; i < size; i++)
	{
		int flag = 0;
		for (int k = 0; k < size-1; k++) {


			if (a[k] > a[k + 1]) {
				int temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
				flag++;
	}//end of condition
		}//end of inner loop
		if (flag == 0) break;
	}//end of main loop

}
void bubble_sort_link_list(Node *head){
	struct Node *p = head;
	while (p)
	{
		int flag = 0;
		struct Node *q = head;
		while (q->next->next!=NULL)
		{
			if (q->data > q->next->data) {
				int temp = q->data;
				q->data = q->next->data;
				q->next->data = temp;
				flag++;
			}
			q = q->next;
		}
		if (flag == 0) break;
		p = p->next;
	}


}


void auto_fill_arry(int a[],int size) {
	for (int i = 0; i < size; i++) {
		int Random = rand() % 100 + size / 2;
		a[i] = Random;
	}
}

int main() {

	struct Node *head = new Node();
	auto_fill(head);
	head = head->next;
	Display(head);

	bubble_sort_link_list(head);
	cout << endl;
	Display(head);


	_getch();
}