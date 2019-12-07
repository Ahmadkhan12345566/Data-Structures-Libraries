#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct node {
	string name;
	string color;
	node *next;
};
void init(node *head,string name,string color) {

	head->name = name;
	head->color = color;
	head->next = NULL;

}



void add(node *head, string name, string color) {
	node *n = new node;
	n->color = color;
	n->name = name;
	n->next = NULL;
	node *m = head;
	while (m) {
		if (m->next == NULL) {
			m->next=n;
			return;
		}
		else
		{
			m = m->next;
		}
	}
}
string color[4] = { "Red","blue","green","yellow" };
void chage_color(node *head,int strt, int size,node *arr[],int count=0){
	node *p = head->next;
	while (p) {
		if (p->color == head->color) {
         	count++;
			p->color = color[count];
			for (int i = 0; i < size; i++) {
				node *q = arr[i];
				while (q) {
					if (p->name == q->name) {
                   q->color = color[count];
					}
					q = q->next;

				}

			}
		}
		
			p = p->next;
		
	}

}
void display(node *head) {
	node *q = head;
	while (q)
	{
		cout << "Name : " << q->name << " color " << q->color<<"  -->";
		q = q->next;
	}

}
//string color[4] = { "Red","blue","green","yellow" };
int main() {
	int total_nodes = 5;
	//cout << "Enter number of nodes :" << endl;
	//cin >> total_nodes;

	node **ary = new node*[total_nodes];
	for (int i = 0; i < total_nodes; i++) {
		ary[i] = new node[total_nodes];
		//cout << "Enter the name of node " << i << endl;
		//string name;
		//std::cin >> name;
		//string  color = "red";
		
			//init(ary[i], name, color);
	
		
      }
	  
	string  color = "red";
	init(ary[0], "a", color);
	init(ary[1], "b", color);
	init(ary[2], "c", color);
	init(ary[3], "d", color);
	init(ary[4], "e", color);

	add(ary[0], "b", "red");
	add(ary[0], "d", "red");
	add(ary[1], "c", "red");
	add(ary[1], "e", "red");
	add(ary[2], "e", "red");
	add(ary[3], "e", "red");
	add(ary[3], "c", "red");

	for (int i = 0; i < total_nodes; ++i) {
		display(ary[i]);
		cout << endl;
	}


	//add(ary[4], "e", "red");

	/*for (int i = 0; i <total_nodes ; i++)
	{
		string dec = "f";
		std::cout << "Is there any node connected with " << ary[i]->name << "  ";
		std::cin >> dec;
		int cnt = 0;
		while (dec == "Y")
		{
			//struct node *temp = new node;
			string num;
			std::cout << " Enter the  name OF THAT NODE" << endl;
			std::cin >> num;
			
			add(ary[i], num, "red");
			
			dec = "f";
			std::cout << "Is there any more node connected with " << ary[i]->name << "  ";
			std::cin >> dec;
		}

	}

	*/
	for (int i = 0; i < total_nodes; i++){
	chage_color(ary[i],i,total_nodes,ary);
	}


	for (int i = 0; i < total_nodes; i++) {
		display(ary[i]);
		cout << endl;
	}
	_getch();

}