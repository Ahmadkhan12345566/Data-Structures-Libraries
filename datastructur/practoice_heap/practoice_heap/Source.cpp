#include<conio.h>
#include<iostream>
#include<array>
#include<string>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};



//creat  node when call
node* NewNode(int data) {
	node* node = new struct node;
	node->data= data;
	node->left = node->right = NULL;

	return node;
}
//tring to make by using link  list
node* insert(node* node, int data) {

	if (node == NULL) return(NewNode(data));
	else if (data <= node->data) node->left = insert(node->left, data);
	else node->right = insert(node->right, data);

	return(node); // return the (unchanged) node pointer
}




//max  heap from arry
int* max_heap(int arr[],int i,int size) {
	int p = (i - 1) / 2;
	
	int j = i;
	if(j>=0){
		if (arr[i] > arr[p]) {
			int temp;
			temp = arr[i];
			arr[i] = arr[p];
			arr[p] = temp;
			max_heap(arr, p, size);

		}
		//need imprvmnt .... if any..
		
		return arr;

	}
	return arr;


}

void min_heap(int arr[], int i, int size) {
	int p = (i - 1) / 2;
	if (i >= 0) {
		if (arr[i] < arr[p]) {
			int temp;
			temp = arr[i];
			arr[i] = arr[p];
			arr[p] = temp;
			min_heap(arr, p, size);

		}
	//	return arr;
	}
	//return arr;


}

int* bulit_heap(int arr[],int siz) {

	for (int i = 0;i < siz;i++) {
		if (i != 0) 
			//arr =
			min_heap(arr,i,siz);
	}
	return arr;

}
void arry_to_tree(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		struct node *q = new node;
		q->data = arr[i];
		q->left = NULL;
		q->right = NULL;
	
	}
}
/*
int *back(int arr[], int siz) {
	arr[2] = 000;
	arr[4] = 111;
	return arr;
}
*/

int main() {
	int size = 7;

	/*for (int i = 0;i < size;i++) {

		arr[i] = i + 1;

	}*/
	string dec;
	int num;
	cout << "you want to enter a data : "<<endl<<"press y for (yes) and n for (NO)"<<endl;
	cin >> dec;
	if (dec == "y") {
		cout << "how many values you want to enter :" << endl;
		cin >> size;
	}

	
	int* arr = new int[size];
	for (int i = 0;i < size;i++) {
		cout << "Enter the value at indx  :  " << i << "  " << endl;
	    cin>>arr[i];
	//	arr[i] = i + 1;
	}
	int*  back = new int[size];
	back = bulit_heap(arr, size);
	cout << "output" << endl;
	for (int i = 0;i < size;i++) {
		cout << back[i] << endl;
	}
	_getch();
}
