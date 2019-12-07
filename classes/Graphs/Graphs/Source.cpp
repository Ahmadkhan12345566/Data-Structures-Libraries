#include<conio.h>
#include<iostream>
#include<string>
#include<stack>
#include<Queue>
using namespace std;
struct node {
	int  weight=0;
	string name;
	node *next1;
	node *next2;
	int path=0;

};
queue<node*> lsit;
//

//struct node **arrr = new node[5][];
struct node *arr[5];



void breth_searc(node *root,int count, int dec) {

	

	if (root->next1==NULL&&root->next2==NULL) {
		std::cout << "Reach to destination :" << root->name<< endl;
		cout << root->weight << endl;
		std::cout << count<<endl;
		dec = 1;
	}
	else {
		if (root->weight != 0) {
			count = count + root->weight;
			//root->weight[0] = 0;
			//root->weight[0] = count;
			if (root->next1 != NULL) {
				root->next1->weight = root->weight + root->next1->weight;
			}
			if (root->next2 != NULL) {
				root->next2->weight = root->weight + root->next2->weight;
			}
			}
		else
		{
			//count = count + root->weight[1];
		}
	}
	
	if (dec != 1) {
		cout << root->name << " --> ";
		breth_searc(root->next1, count, dec);
	}

	if (root->next2 != NULL) {
//root->next2->weight=root->next2->weight + root->weight[0];
		//cout << root->next1;
		lsit.push(root->next2);
		
//		lsit.push(root);
	}
	cout << endl;
	if (lsit.size() != 0) {
		//node *tm=new node;
		//tm = lsit.front();
		//lsit.pop();
       
		//cout <<tm. ;	
		node *temp;
		temp = lsit.front();
		lsit.pop();
		dec = 0;
		
	
		breth_searc(temp, count = 0, dec);
	}
	else
	{
		return;
	}

}
/*
void  uptade(node arr,int size) {
	for (int i = 0; i < size;i++) {
		for (int j = 0; j < size; j++) {
				if (arr[i]->name == arr[j]->name) {
				arr[i]->next1 = arr[j]->next1;
				arr[i]->next2 = arr[j]->next2;
			
			}
		 }
	}
}
*/

int main() {
	int num=5;
	//struct node *arr [5];
	char ar[5] = { 'A','B','C','D','E' };
	for (int i=0; i < num;i++)
	{
		arr[i] = new node;
		arr[i]->next1 = NULL;
		arr[i]->next2 = NULL;
		arr[i]->path = 0;
		std::cout << "Enetr the name of index  " << i << endl;
		//std::cin >> 
		arr[i]->name=ar[i];
		cout << arr[i]->name<<endl;
}

	
	for (int i = 0; i < num; i++)
	{
		string dec = "f";
		std::cout << "Is there any node connected with " << arr[i]->name << "  ";
		std::cin >> dec;
		int cnt = 0;
		while (dec=="Y")
		{
			struct node *temp = new node;
			int num;
			std::cout << " Enter the  index OF THAT NODE"<<endl;
			std::cin >> num;
	//	temp->name = arr[num]->name;
		//temp->next1 = arr[num]->next1;
		//temp->next2 = arr[num]->next2;
//			temp->weight = arr[num]->weight;
			temp = arr[num];
			
				std::cout << "Enetr the weight of connection of these " << endl;
				std::cin >> temp->weight;
				//temp->weight[cnt]
			
			if (cnt == 0) {
				arr[i]->next1 = temp;
				cnt++;
			}
			else
			{
				arr[i]->next2 = temp;
			}
			dec = "f";
			std::cout << "Is there any more node connected with " << arr[i]->name << "  ";
			std::cin >> dec;
		}

	}
	for (int i = 0; i < 5; i++) {
		std::cout << arr[i]->name << "--> ";
		if (arr[i]->next1 != NULL) {
			std::cout << arr[i]->next1->name << "    weight:" << arr[i]->next1->weight << "-->  ";
		}
		if (arr[i]->next2 != NULL) {
			std::cout << arr[i]->next2->name << " weight :" << arr[i]->next2->weight << "-->";
		}

		cout << endl;
	}
	
	
	


	
	int c = 0,d=0;
	breth_searc(arr[0], c,d);
	_getch();
	//cin >> num;
}

