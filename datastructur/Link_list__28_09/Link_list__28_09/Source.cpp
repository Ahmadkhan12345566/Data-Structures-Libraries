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
void insert( struct node *head, int a) {
	struct node *q = new node;
	q->ab = a;
	q->next = NULL;
	node *p= head;

		while (p) {
			if (p->next==NULL) {
				p->next =q;
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
		cout << p->ab<<endl;
		p = p->next;
	}
}
void delet(struct node *head, int a) {
	
	node *p = head;
	if(head->ab==a){
		head = head->next;
	
	}
else
	{
	while (p) {
		if (p->next->ab == a) {
			p->next = p->next->next;
			break;
		}
		else {
			p = p->next;
		}
	}
	}
	
 }
void edit(struct node *head, int a,int c) {

	node *p = head;

	while (p) {
		if (p->ab == a) {
			p->ab=c;
			break;
		}
		else {
			p = p->next;
		}
	}
}
 







void printfrwd(node *head) {
	if (head == NULL) {
		return;
	}
	cout << head->ab << endl;
	printfrwd(head->next);
}
void printbwk(node *head) {
	
		if (head == NULL) return;
		printbwk(head->next);
		cout << head->ab <<endl;
	

}
bool search(struct node *head, int a) {

	node *p = head;

	while (p) {
		if (p->ab == a) {
			return true;
			break;
		}
		else {
			p = p->next;
		}
	}
	return false;
}
void uni(node *head1, node *head2) {
	node *p1 = head1;
	node *p2 = head2;
	struct node *head3 = new node;
	node *p3 = head3;

	int a = 0;

	while (p1 != NULL) {
		if (a == 0) {
			initlize(head3, p1->ab);
			a++;
		}
		else
		{
			insert(head3, p1->ab);
		}
		
		p1 = p1->next;
	}

	p1 = head1;
	while (p2 != NULL) {
	
		if (!search(p1, p2->ab)) {
			insert(head3, p2->ab);
		}
		p2 = p2->next;
	}
	cout << "union"<<endl;

	display(head3);


}



/*
void intersection(node *head1,node *head2) {
	node *p1 = head1;
	node *p2 = head2;
	struct node *head3 = new node;
	node *p3 = head3;
	int a = 0;
	p1 = head1;
	while (p2 != NULL) {

		if (search(p1, p2->ab)) {
			//insert(head3, p2->ab);
			if (a == 0) {
				initlize(head3, p2->ab);
				a++;
			}
			else
			{
				insert(head3, p2->ab);
			}
		
		}
		p2 = p2->next;
	}
	cout << "intersection" << endl;

	display(head3);

}



*/

void intersection(node *head1, node *head2) {
	node *p1 = head1;
	node *p2 = head2;
	struct node *head3 = new node;
	node *p3 = head3;
	int a = 0;
	p1 = head1;
cout << "intersection"<<endl;
	while (p2 != NULL) {
		p1 = head1;
		while (p1 != NULL) {
			if(p1->ab == p2->ab) {
				cout << p2->ab<<endl;

			}
			p1 = p1->next;

		}

		


		p2 = p2->next;
		}
	
	}


/*
void swap(node *head1) {
	node *p = head1;
      int  	count = 0;
      int 	incr = 2;
	while (p) {
		if (count == 0||count==incr) {
			
			node *q=p;
			p = p->next;
			p->next = q;
			
			incr = incr + 2;
		}
		else
		{
			p = p->next;
		}
		count++;
	}

}
node Delete(node *Head, int num)
{
	node *p = Head;


	if (p->ab == num)
	{
		node *q = p;
		Head = p->next;
		p = p->next;

	}
	else
	{

		while (p)
		{
			if (p->next != NULL)
			{
				if (p->next->ab == num)
				{
					p->next = p->next->next;
				}

			}
			p = p->next;
		}
	}
	return *Head;

}



void Swaping(node *Head, node *Fake)
{

	while (Head->next != NULL)
	{


		insert(Fake, Head->next->ab);
		insert(Fake, Head->ab);

		if (Head->next->next == NULL)
		{

			*Fake = Delete(Fake, Fake->ab);
			
		}
		else
		{
			*Head = Delete(Head, Head->ab);
			*Head = Delete(Head, Head->ab);
		}

	}
	*Fake = Delete(Fake, Fake->ab);
	display(Fake);
}




*/

int main() {
	
	struct node *head1 = new node;
	struct node *head2 = new node;
	struct node *fake = new node;
	cout << "Enter Number" << endl;  
	int n; 
	cin >> n;
	initlize(head1, n);
	//insert(head1, 1);
	//insert(head1, 2);
	//insert(head1, 3);
	//insert(head1, 4);
	//insert(head1, 5);
	cout << "List 1" << endl;
	display(head1);
	delet(head1, n);
	cout << "List " << endl;
	display(head1);
	
	/*initlize(head2, n);
	insert(head2, 2);
	insert(head2,5);
	insert(head2, 9);
	insert(head1, 5);
	insert(head1, 8);
	cout << "List 2" << endl;
	display(head2);
	
	uni(head1, head2);
	//intersection(head1, head2);
	cout << "print 4rwd"<<endl;
	printfrwd(head1);
	cout << "print Back" << endl;
	
	printbwk(head1);
	//swap(head1,fake);
	cout << "List 1" << endl;
	display(head1);*/
	_getch();
}

