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

	if (head->next!= NULL && c == 0) {
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

int max_finder(struct node *head) {
	int max;
	max = head->ab;

	struct node *p = head;
	while (p) {
		if (p->ab>max) {
			max = p->ab;
		}
		p = p->next;
	}

	return max;

}

int min_finder(struct node *head) {
	int min;
	min = head->ab;

	struct node *p = head;
	while (p) {
		if (p->ab<min) {
			min = p->ab;
		}
		p = p->next;
	}

	return min;

}

void dm(struct node *mhead, struct node *h1) {
	c = 0;
	struct node *p = mhead;
	while (p) {
		insert(h1, p->ab);
		p = p->next;
	}
}

void dumping(struct node *mhead, struct node *head1, struct node *head2, struct node *head3, struct node *head4) {
	struct node *abc = new node;


	//First step Finding of min and max
	int max = max_finder(mhead);
		cout << max<<endl;
	int min = min_finder(mhead);
	cout << min<<endl;
	int num_of_buck = 4;
	//cout << "enter the number buckets you want to make to sort data " << endl;
	//cin >> num_of_buck;

	//second step Findding range ,low and higah
	int range = (max - min) / num_of_buck;
	cout << range << endl;
	int l1 = min;
	cout << l1;
	int h1 = min + range;
	int l2 = h1 + 1;
	int h2 = l2 + range;
	int l3 = h2 + 1;
	int h3 = l3 + range;
	int l4 = h3 + 1;
	int h4 = max;
	node *p = mhead;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	
	while (p)
	{
		if (p->ab <= h1) {
			if (head1->next != NULL&&n1==0) {
				c = 0;
				n1++;
			}
			insert(head1, p->ab);
		}
		else if (p->ab <= h2) {

			if (head2->next != NULL&&n2==0) {
				c = 0;
				n2++;
			}
				insert(head2, p->ab);
			
			
		}
		else if (p->ab <= h3)
		{
			if (head3->next != NULL && n3==0) {
				c = 0;
				n3++;
			}
			insert(head3, p->ab);

			
		}
		else
		{
			
			if (head4->next != NULL&&n4==0) {
				c = 0;
				n4++;
			}
			insert(head4, p->ab);


				
			}

		p = p->next;
		}

	}

int size(struct  node *head)
{ 
	 int count = 0;
     node *p = head;
	 while (p) {
		count++;
		p = p->next;
	}
	 return count;
}

void sort_linklist(node*head)
{
	node*p = head;
	while (p)
	{
		node*q = p->next;

		while (q)
		{
			if (p->ab > q->ab)
			{
				int temp = p->ab;
				p->ab = q->ab;
				q->ab = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
}

int count = 0;
void mergr_sort(struct node *head, struct node *h1, struct node *h2, struct node *h3, struct node *h4) {
	struct node *p = head;
		while (h1)
	{
		p->ab = h1->ab;
		p = p->next;
		h1= h1->next;
	
		}

		while (h2)
		{
			p->ab = h2->ab;
			p = p->next;
			h2 = h2->next;
		}
		while (h3)
		{
			p->ab = h3->ab;
			p = p->next;
			h3 = h3->next;
		}
		while (h4)
		{
			p->ab = h4->ab;
			p = p->next;
			h4 = h4->next;
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
	dumping(mhead, head1, head2, head3, head4);
	cout << "head 1"<<endl;
	display(head1);
	//sort_linklist(head1);
	//display(head1);
	cout << "head 2"<<endl;
	display(head2);
	//sort_linklist(head2);
	//display(head2);
	cout << "head3" << endl;
	display(head3);
	//sort_linklist(head3);
	//display(head3);
	cout <<" head4" << endl;
	display(head4);
	sort_linklist(head4);
	//display(head4);
	cout << "Before sorted :" << endl;

	display(mhead);
	mergr_sort(mhead, head1, head2, head3, head4);
	cout << "after sorted"<<endl;
	display(mhead);

	_getch();
}