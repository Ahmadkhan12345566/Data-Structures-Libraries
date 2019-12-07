#include<iostream>
#include<conio.h>
using namespace std;

void auto_fill_arry(int a[], int size) {
	for (int i = 0; i < size; i++) {
		int Random = rand() % 100 + size / 3;
		a[i] = Random;
	}
}
void Insertion_sort(int a[],int size) {
	for (int i = 0; i <size; i++)
	{
		int value = a[i];
		int hole = i;

		while(hole>0 && value<a[hole-1] )
		{

			a[hole] = a[hole - 1];
			
			hole = hole - 1;
			}//end of inner loop
		a[hole] = value;

	}//end of inner loop
	
}



int main() {
	int size = 10;
	int a[10];
	int b = 1;

	auto_fill_arry(a, size);
	cout << endl << endl;
	cout << "          befor sort" << endl<<endl;
	for (int i = 0; i <size; i++)
	{
		cout << a[i] << "    ";
	}
	cout << endl;
Insertion_sort(a,size);
cout << endl << endl;
	cout << "          after sort" << endl<<endl<<endl;
	for (int i = 0; i <10; i++)
	{
		cout << a[i] << endl;
	}
	_getch();
}