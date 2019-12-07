#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

bool fillde(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
void display(int **arr, int size) {

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {
			if (arr[i][j]!=0) {
				cout << " "<<arr[i][j] <<" "<< "|";
			}
			else
			{
				cout << "   " << "|";
			}
			}
		cout << endl;
		for (int k = 0; k < size; k++) {
			cout << "___" << "|";
		}
		cout << endl;
	}
}
/*
bool check(int **arr,int size) {
	for (int row = 0; row < size;row++) {
		for (int col = 0; col < size-1;col++) {
			if (col == 0 && row ==0) {
				if (arr[col][row] == arr[col + 1][row] || arr[col][row] == arr[col][row + 1]) {
					return false;
				}

			}
			else if (row==0)
			{
				if (arr[col][row] == arr[col + 1][row] || arr[col][row] == arr[col][row + 1]) {
					return false;
				}

			} 
		}
	}
}

*/
int main() {
	int size,score=0;
	cout << "Enter the size :" << endl;
	cin >> size;
	int **arr = new int*[size];
	//string **arrr = new string*[size];
	for (int i = 0; i < size;i++) {
		arr[i] = new int[i];
		//arrr[i] = new string[i];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = 0;
		}
	}
	string move;
	int r, c;
	int row, col;
	 char dec = 'n';
	cout <<"You want to play a Game :\n Press (y) for Yes (n) for No" << endl;
	cin >> dec;
	while (dec == 'y') {
		int i = 2;
		while (!fillde(arr, size))
		{
		for (int j = 0; j < i;j++) {
			row = rand() % size;
			col = rand() % size;
			while (arr[row][col] != 0) {
				row = rand() % size;
				col = rand() % size;
			}
			arr[row][col] = 2;
		  }
		if (fillde(arr, size)) {
			break;
		}
		i = 1;
	//	cout<< "                  Your Score :" << score << endl << endl;
			display(arr, size);
			cout << "            Enter your place \n";
			cout << "Enter your row :";
				cin >> r;
				while (r>size-1 )
				{
					cout << "Enter your row agin:\n must be less the number of rows "<<endl;
					cin >> r;
				}
				cout << "Enter your col :";
				cin >> c;
				while (c>size - 1)
				{
					cout << "Enter your col agin:\n must be less the number of cols " << endl;
					cin >> c;
				}
				while (arr[r][c]==0)
				{
					cout << endl<<"                 This box is empty \n               Enter the filled box "<<endl;
					cout << "Enter your place Again \n";
					cout << "Enter your row :";
					cin >> r;
					while (r>size - 1)
					{
						cout << "Enter your row agin:\n must be less the number of rows " << endl;
						cin >> r;
					}
					cout << "Ent er your col :";
					cin >> c;
					while (c>size - 1)
					{
						cout << "Enter your col agin:\n must be less the number of cols " << endl;
						cin >> c;
					}

				}
				cout << "Select the your move \n (r)for right \n (l) for left\n (u) for Up \n (d) for Down"<<endl;
				cin >> move;
				if (move == "r") {
					if (arr[r][c] == arr[r][c + 1]) {
						arr[r][c + 1] = arr[r][c + 1] + arr[r][c];
						score = score + arr[r][c];
						arr[r][c] = 0;
						
					}
					else
					{
						arr[r][c + 1] = arr[r][c];
						arr[r][c] = 0;
					}
				}
				else if(move=="l")
				{
					if (arr[r][c] == arr[r][c - 1]) {
						arr[r][c -1] = arr[r][c - 1] + arr[r][c];
						score = score + arr[r][c];
						arr[r][c] = 0;
					}
					else
					{
						arr[r][c - 1] = arr[r][c];
						arr[r][c] = 0;
					}

				}
				else if (move == "u")
				{
					if (arr[r][c] == arr[r-1][c]) {
						arr[r-1][c] = arr[r-1][c] + arr[r][c];
						score = score + arr[r][c];
						arr[r][c] = 0;
					}
					else
					{
						arr[r-1][c] = arr[r][c];
						arr[r][c] = 0;
					}

				}
				else 
				{
					if (arr[r][c] == arr[r+1][c]) {
						arr[r+1][c] = arr[r+1][c] + arr[r][c];
						score = score + arr[r][c];
						arr[r][c] = 0;
					}
					else
					{
						arr[r+1][c] = arr[r][c];
						arr[r][c] = 0;
					}

				}


			
		}
		cout << "Game End \n Your score : " << score<<endl;
		dec = 'n';
		cout << "You want to play Again :\ Press (y) for Yes (n) for No" << endl;
		cin >> dec;
}
	_getch();
} 