#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
using namespace std;
void init(string **arr, int row,int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = "e";
		}
	}
}
void display(string **arr, int row,int col) {

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	;
	}
}
bool valid(string **arr,int row,int col,string *paper,int cnt,int colm) {

	if (row > 0 && col == 0) {
		if(arr[row-1][col]==paper[cnt]||arr[row-1][col+1]==paper[cnt]){
			return false;
		}
		
	}
	else if (col>0 && row == 0)
	{
		if (arr[row][col - 1] == paper[cnt]) {
			return false;
		}
	}
	else if(col==colm-1 && row>0)
	{
		if (arr[row][col - 1] == paper[cnt] ||arr[row-1][col-1]==paper[cnt]||arr[row-1][col]==paper[cnt]) {
			return false;
		}
	}
	else if (row > 0 && col>0)
	{
		if (arr[row - 1][col - 1] == paper[cnt] || arr[row - 1][col] == paper[cnt] || arr[row - 1][col + 1] == paper[cnt] || arr[row][col - 1] == paper[cnt]) {
			return false;
		}
	}

	return true;
}
void disput_paper(string **arr,int row,int col,string *paper) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
         		int cnt = 0;
				arr[i][j] = paper[cnt];
			while (!valid(arr,i,j,paper,cnt,col)) {
				cnt++;
				arr[i][j] = paper[cnt];
			}
		//	cout << "                   Afer distrubting in row " << i+1<<endl;
		//	cout << endl;

		//display(arr, row, col);
		}
		
	}
	cout << "                   Afer distrubting in all students " << row*col << endl;
	cout << endl;
	display(arr, row, col);
}
int main() {
	int col,row;
	cout << "Enter the size of columnx\n size must be greatr then 0 :" << endl;
	cin >> col;
	while (col <=0) {
		cout << "Enter the size again of columnx\n size must be greatr then 2 :" << endl;
		cin >> col;
	}
	cout << "Enter the size of rows\n size must be greatr then 0 :" << endl;
	cin >> row;
	while (row <=0) {
		cout << "Enter the size again of rows\n size must be greatr then 2 :" << endl;
		cin >> row;
	}
	string **ary = new string*[row];

	for (int i = 0; i < row; ++i) {
		ary[i] = new string[col];
	}
	int S = row*col;
	init(ary, row, col);
	cout << "               Number of Students are " << S << endl;
	display(ary, row, col);
	string *k = new string[4];
	cout << "Number of papers are : 4" << endl;
	cout << "colors of papers are " << endl;
	k[0] = "red";
	k[1] = "blu";
	k[2] = "grn";
	k[3] = "wht";
	for (int i = 0; i < 4; i++) {
		cout << k[i] << endl;
	}
	disput_paper(ary, row, col, k);
	_getch();
}