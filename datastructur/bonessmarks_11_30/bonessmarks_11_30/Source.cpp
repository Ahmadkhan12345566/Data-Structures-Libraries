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


void initlize(struct node *head, struct node *q) {
	head->ab = q->ab;
	head->next = q->next;

}
void display(struct  node *head)
{
	node *p = head;
	while (p) {
		cout << p->ab << endl;
		p = p->next;
	}
}
void auto_insert(node *mhead) {
	insert(mhead, 9);
	insert(mhead, 6);
	insert(mhead, 1);
	
}
/*
int * min_max_finder(struct node *head) {
	int min_max[2];
	min_max[0] = head->ab;
	min_max[1] = head->ab;
	struct node *p = head;
	while (p) {
		if(p->ab>min_max[0]){
			min_max[0] = p->ab;
		}
		else if(p->ab<min_max[1])
		{
			min_max[1] = p->ab;
		}
		p = p->next;
	}
	cout << min_max[0] << endl;;
	cout << min_max[1] << endl;
	return min_max;

}
*/
//max finder
void insertt(struct node *head,struct node *a) {
	struct node *q = new node;
	q->ab = a->ab;
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

void dumping(struct node *mhead, struct node *head1, struct node *head2, struct node *head3, struct node *head4) {
	struct node *abc = new node;


	//First step Finding of min and max
	int max = max_finder(mhead);
	//	cout << max<<endl;
	int min = min_finder(mhead);
	//cout << min<<endl;
	int num_of_buck = 4;
	//cout << "enter the number buckets you want to make to sort data " << endl;
	//cin >> num_of_buck;

	//second step Findding range ,low and higah
	int range = (max - min) / num_of_buck;
	int l1 = min;
	int h1 = min + range;
	int l2 = h1 + 1;
	int h2 = l2 + range;
	int l3 = h2 + 1;
	int h3 = l3 + range;
	int l4 = h3 + 1;
	int h4 = max;
	node *p = mhead;

	int a;
	while (p)
	{
		if (p->ab <= h1) {
			if (head1 == NULL) initlize(head1, p);
			else
			{
				insertt(head1, p);
			}
		}
		else if (p->ab <= h2) {

			if (head2 == NULL) initlize(head2, p);
			else
			{
				insertt(head2, p);
			}
			//	insertt(head2, p);
		}
		else if (p->ab <= h3)
		{
			if (head3 == NULL) initlize(head3, p);
			else
			{
				insertt(head3, p);


			}

			//insertt(head3, p);
		}
		else
		{
			if (head4 == NULL) initlize(head4, p);
			else
			{
				insertt(head4, p);


				//insertt(head4, p);
			}


		}

	}

}
int main() {
	struct node *mhead = new node;
	auto_insert(mhead);
	display(mhead);
	cout << "min max" << endl;

	//First step Finding of min and max
	int max = max_finder(mhead);
	//	cout << max<<endl;
	int min = min_finder(mhead);
	//cout << min<<endl;
	int num_of_buck = 4;
	//cout << "enter the number buckets you want to make to sort data " << endl;
	//cin >> num_of_buck;

	//second step Findding range ,low and higah
	
	struct node *head1 = new node;
	struct node *head2 = new node;
	struct node *head3 = new node;
	struct node *head4 = new node;
	int range = (max - min) / num_of_buck;
	int l1 = min;
	int h1 = min + range;
	int l2 = h1 + 1;
	int h2 = l2 + range;
	int l3 = h2 + 1;
	int h3 = l3 + range;
	int l4 = h3 + 1;
	int h4 = max;
	node *p = mhead;
	head1 = NULL;
	head3 = NULL;
	head3 = NULL;
	head4 = NULL;
	int a;
	while (p)
	{
		if (p->ab <= h1) {
			if (head1 == NULL) initlize(head1, p);
			else
			{
				insertt(head1, p);
			}
		}
		else if (p->ab <= h2) {

			if (head2 == NULL) initlize(head2, p);
			else
			{
				insertt(head2, p);
			}
			//	insertt(head2, p);
		}
		else if (p->ab <= h3)
		{
			if (head3 == NULL) initlize(head3, p);
			else
			{
				insertt(head3, p);


			}

			//insertt(head3, p);
		}
		else
		{
			if (head4 == NULL) initlize(head4, p);
			else
			{
				insertt(head4, p);


				//insertt(head4, p);
			}


		}

	}





	//dumping(mhead, head1, head2, head3, head4);





	display(head1);
	display(head2);
	display(head3);
	display(head4);



	_getch();


}