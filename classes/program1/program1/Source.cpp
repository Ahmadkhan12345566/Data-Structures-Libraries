#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
using namespace std;
void init(string **arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = "1";
		}
	}
}
void display(string **arr, int size) {

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << "|";
		}
		cout << endl;
		for (int k = 0; k < size; k++) {
			cout << "_" << "|";
		}
		cout << endl;
	}
}
bool fillde(string **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == "1")
			{
				return false;
			}
		}
	}
	return true;
}

//checking row 
bool check_R(string **arry,int size, int row ,int col) {
	int count=0;
	for (int i = 0; i < size;i++){
		if (arry[row][i]!=arry[row][col])
		{
			return false;
		}
		else
		{
			count++;
		}
}
	if (count == size) {
		return true;
	}
	return false;
}
//checking col
bool check_C(string **arry, int size, int row, int col) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arry[i][col] != arry[row][col])
		{
			return false;
		}
		else
		{
			count++;
		}
	}
	if (count == size) {
		return true;
	}
	return false;
}
//checking diagnal from left side top
bool check_D_l(string **arry, int size, int row, int col) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arry[i][i] != arry[row][col])
		{
			return false;
		}
		else
		{
			count++;
		}
	}
	if (count == size) {
		return true;
	}
	return false;
}
//checkis diagnal from right  side top
bool check_D_R(string **arry, int size, int row, int col) {
	int count = 0;
	for (int i = 0,j=size-1; i < size&&j>=0; i++,j--) {
		if (arry[i][j] != arry[row][col])
		{
			return false;
		}
		else
		{
			count++;
		}
	}
	if (count == size) {
		return true;
	}
	return false;
}
bool  check(string **arry,int size,int row, int col) {

	if (check_R(arry,size,row,col)) {
		return true;
	}
	else if(check_C(arry, size, row, col))
	{
		return true;
	}
	else if((row==0 && col==0)||(row==size-1&&col==size-1))
	{
		if (check_D_l(arry, size, row, col)) {
			return true;
		}
	}
	else if((row==0 && col==size-1)||(row==size-1 && col==0))//size%
	{
		if (check_D_R(arry, size, row, col)) {
			return true;
		}
	}

	return false;


}

void input(string **arr, int size, string sig1, string sig2) {
	int row, col;
	string user;
	user = sig1;
	while (!fillde(arr, size))
	{
		if (user == sig1) {
			cout << " User 1 " << "(" << user << ")" << endl;

		}
		else
		{
			cout << " User 2" << "(" << user << ")" << endl;
		}
		cout << "Enter the num of row :" << endl;
		cin >> row;
		cout << "Enter the num of col :" << endl;
		cin >> col;
		while (row > size - 1 || col > size - 1){

			cout << "Invalid input please Enter valid inputin range of " << size - 1 << endl;
			cout << "Enter the num of row again:" << endl;
			cin >> row;
			cout << "Enter the num of col again :" << endl;
			cin >> col;
                }
		while (arr[row][col] != "1") {
			if (arr[row][col] != "1") {
				cout << "this location is filled"<<endl;
				cout << "Enter the num of row again:" << endl;
				cin >> row;
				cout << "Enter the num of col again :" << endl;
				cin >> col;
				while (row > size - 1 || col > size - 1) {

					cout << "Invalid input please Enter valid inputin range of " << size - 1 << endl;
					cout << "Enter the num of row again:" << endl;
					cin >> row;
					cout << "Enter the num of col again :" << endl;
					cin >> col;
				}
			} 
		}
	
		arr[row][col] = user;
		display(arr, size);

		if (check(arr,size,row,col)) {
			if (user == sig1) {
				cout <<" User 1 Wines" <<"("<<user<<")" <<endl;
			
			}
			else
			{
				cout <<" User 2 Wines" <<"("<<user<<")"<<endl;
			}
			return;
	  }
		if (fillde(arr, size)) {
			cout << "Game Draw"<<endl;
			return;
		}
		if (user == sig1) {
			user = sig2;
		}
		else
		{
			user = sig1;
		}
	}
}

int main() {
	string dec="n";
	do {
		int sizeY;
		cout << "Enter the size of blocks\n size must be greatr then 2 :" << endl;
		cin >> sizeY;
		while (sizeY < 3) {
			cout << "Enter the size again of blocks\n size must be greatr then 2 :" << endl;
			cin >> sizeY;
		}
		string **ary = new string*[sizeY];
		for (int i = 0; i < sizeY; ++i) {
			ary[i] = new string[sizeY];
		}

		init(ary, sizeY);
		display(ary, sizeY);
		string sig1;
		string sig2;
		cout << "Select sign to play game \n Select * OR #:" << endl;
		std::cin >> sig1;
		while (sig1 != "*"&&sig1 != "#")
		{
			cout << "Invalid Input\nSelect sign to again play game \nSelect (*) OR (#):" << endl;
			std::cin >> sig1;
		}
		if (sig1 == "*") {
			sig2 = "#";
		}
		else {
			sig2 = "*";
		}
		cout << "Player 1 :" << sig1 << endl;
		cout << "Player 2 :" << sig2 << endl;
		input(ary, sizeY, sig1, sig2);
		cout << "Do you want to play again :\n press (y) for yes and (n) for no" << endl;
		cin >> dec;
	} while (dec == "y");
	_getch();
	
}



