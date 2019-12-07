#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
	int ab;
	node *next;


};
struct node *A = new node;
struct node *B = new node;
struct node *C = new node;
struct node *D= new node;
void Init(struct node *head, int a) {
	head->ab = a;
	head->next = NULL;

}



void Add(struct node *head, int a) {
	struct node *q = new node;
	q->ab = a;
	q->next = NULL;
	struct node *p = head;

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


void Display(node *Head)
{
	node *p = Head;
	while (p != NULL)
	{
		cout << p->ab << "--";
		p = p->next;
	}
	cout << "NULL";
}
/*

void graph(char input[], int size) {

	struct node *heads = new node[size];
	
	char dec;
	for (int i = 0; i < size;i++) {
		
		for (int j = 0; j < size; j++) {
			cout << input[i] + " contected with " + input[j]<<endl;
			cout << "prees (y) if connected press (n) if not connected \n";
			cin >> dec;
			if (dec == 'y') {
				insert(heads[i], 1);
			}

		}
	}

}


void graph_p(char input[], int size) {

	struct node *heads = new node[size];
	struct node *q = heads[size];
	char dec;
	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {
			cout << input[i] + " contected with " + input[j] << endl;
			cout << "prees (y) if connected press (n) if not connected \n";
			cin >> dec;
			if (dec == 'y') {
				i
			}

		}
	}

}



*/

void creat() {
	Init(A, 0);
	Add(A, 1);
	Add(A, 2);
	Add(A, 3);
	Init(B, 1);
	Add(B, 0);
	Add(B, 2);
	Add(B, 3);
	Init(C, 2);
	Add(C, 0);
	Add(C, 1);
	Add(C, 3);
	Init(D, 3);
	Add(D, 0);
	Add(D, 1);
	Add(D, 2);
}

void display() {
	Display(A);
	cout << endl;
	Display(B);
	cout << endl;
	Display(C);
	cout << endl;
	Display(D);
}

void Bsf() {
	while ()
	{

	}

}



int main() {
	/*
		int sie = 5;
 		cout << "Enter the total number of elements are used(abcs):\n";
		cin >> sie;
		char* arr = new char[sie];
		struct node *heads = new node[sie];
		cout << "Enter the characters that are used:\n";
		for (int i = 0; i < sie; i++) {
          cin>>arr[i];
		}
	

	*/

	creat();
	display();
	_getch();

	}