#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
using namespace std;
void display(int **arr, int size) {

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
bool check(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 7)
			{
				return false;
			}
		}
	}
	return true;
}






int main() {
	string dec = "n";
	int score = 0;
	int size;
	cout << "Enter the size of blocks\n size must be greatr then 2 :" << endl;
	cin >> size;
	while (size < 3) {
		cout << "Enter the size again of blocks\n size must be greatr then 2 :" << endl;
		cin >> size;
	}
	int **ary = new int*[size];
	int **dis = new int*[size];
	for (int i = 0; i < size; ++i) {
		dis[i] = new int[size];
		ary[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			dis[i][j] = 7;
			ary[i][j] = rand() % 5;
		}
	}
	
	int strike = 9;
	int row, col;
	string again = "n";
	int total_places_for_strike = size / 2;
	for (int j = 0; j < total_places_for_strike; j++) {
		row = rand() % size;
		col = rand() % size;
		if (ary[row][col] == strike) {
			again = "y";
		}
		else
		{
			ary[row][col] = strike;
		}
		while (again == "y") {
			row = rand() % size;
			col = rand() % size;
			again = "n";
			if (ary[row][col] == strike) {
				again = "y";
			}
			else
			{
				ary[row][col] = strike;
			}
		}
	}
	
	string game = "N";
	cout << "You want to play a game :\n Press (Y) for Yes and (N) for No :" << endl;
	cin >> game;
	if (game == "Y") {
		display(dis, size);
		while (!check(dis, size))
		{
			cout << "Enter the number of row :" << endl;
			cin >> row;
			while (row > size) {
				cout << "Enter the number of row Again\nLess then  " << size << endl;
				cin >> row;
			}
			cout << "Enter the Number of column :" << endl;
			cin >> col;
			while (col > size) {
				cout << "Enter the Number of column Again \nLess then  " << size << endl;
				cin >> col;
			}
			while (dis[row][col] != 7) {
				cout << "Enter the Number of rows Again :" << endl;
				cin >> row;
				cout << "Enter the Number of columns Again :" << endl;
				cin >> col;

			}
			dis[row][col] = ary[row][col];

			if (dis[row][col] != strike) {
				score = score + ary[row][col];
			}
			else
			{
				cout << " Game End   " << endl << "Your Socre :" << score;
				break;
			}
			display(dis, size);
		}

	}

	_getch();
}





