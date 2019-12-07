#include <iostream>
#include <conio.h>
using namespace std;
int main(){

	int row=3, col=2;
	int higesht = 0;

	int Lowest = 0;
	int **arr = new int *[row];
	for (int i = 0;i < row;i++)
	{
		arr[i] = new int[col];

	}
	cout << "Enter your ID           " << "Enter your Exam marks"<< endl;
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
		
			
			cin >> arr[i][j];
			
			for (int k = 0;k < i;k++) {

				if (arr[k][0] == arr[i][0]) {

					i--;
					j++;
					cout << "id enterd before " << endl;
				}
			}
			cout << "                        ";
		}
		cout << endl;

	}
	int tto=0;
	for (int i = 0;i < row;i++) {
		int j = 1;
		if (arr[i][j] > higesht) {
			higesht = arr[i][j];
		}
		tto = arr[i][j] + tto;


	}
	Lowest = higesht;
	for (int i = 0;i < row;i++) {
		int j = 1;
		if (arr[i][j] < Lowest) {
			Lowest = arr[i][j];
		}
		


	}
	int avg;
	avg = tto / row;
	cout <<"Your requir average :"<< avg<<endl;
	cout << "higest scoures are:" << higesht << endl;
	cout << "Lowest is :" << Lowest << endl;
	system ("pause");

}
