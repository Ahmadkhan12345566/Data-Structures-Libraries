#include<conio.h>
#include<iostream>
#include<array>
#include<string>
using namespace std;
int* sort(int arr[], int i, int size) {
	int p = (i - 1) / 2;
	while (i >= 0) {
		if (arr[i] > arr[p]) {
			int temp;
			temp = arr[i];
			arr[i] = arr[p];
			arr[p] = temp;
			sort(arr, p, size);

		}
		return arr;
	}



}
int* heap(int arr[], int siz) {

	for (int i = 0;i < siz;i++) {
		if (i != 0) arr = sort(arr, i, siz);
	}
	return arr;

}


int main() {

	int* arr = new int[7];
	for (int i = 0;i < 7;i++) {

		arr[i] = i + 1;
	}
	int*  heep = new int[7];
	heep = heap(arr, 7);
	cout << "output" << endl;
	for (int i = 0;i < 7;i++) {
		cout << heep[i] << endl;
	}
	_getch();
}
