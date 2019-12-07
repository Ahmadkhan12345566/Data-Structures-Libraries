#include<conio.h>
#include<iostream>
using namespace std;
/*
int heapfy(int arr[],int size) {
	for (int i = 0;i < size;i++) {
		if(arr[data[]]){}


	}
}
*/

int swap(int a,int b) {
	int c;
	c = b;
	a = b;
	b = c;
	return(a);
}

void heapfy_max(int data[], int i,int size) {
	int l = i*i;
	int r = i*i + 1;
	int lrgst;
	while (l !=size) {
		if (data[i] > data[l] && data[i] > data[r]) return;
		if (data[l] > data[r]) lrgst=l;
		else lrgst = r;

		int temp;
		temp = data[lrgst];
		data[lrgst] = temp;
		data[i] = temp;
	}

}

int main() {
	int arr[10];
	for (int i = 0;i < 10;i++) {
		arr[i] = i;
	}
	
	for (int i = 0;i < 10;i++) {
		heapfy_max(arr, i, 10);
	}
	
	_getch();
}