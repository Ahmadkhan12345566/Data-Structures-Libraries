#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int row, col;
	cout << "Enter the row :" << endl;
	cin >> row;
	cout << "Enter the col :" << endl;
	cin >> col;
	int **arr = new int *[row];
	for (int i = 0;i < row;i++)
	{
		arr[i] = new int[col];

	}
	for (int i = 0;i < row;i++) {


		for (int j = 0;j < col;j++) {
			cout << "Enter the value at " << i << j << endl;
			cin >> arr[i][j];
		}
	}
	for (int i = 0;i < row;i++) {


		for (int j = 0;j < col;j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	system("pause");
		return 0;


}
