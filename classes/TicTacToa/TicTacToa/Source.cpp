#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
void DisplayGameBoard(string **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
bool Rules(string **arr, string p, int size)
{
	bool log = false;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (p != arr[i][j])
			{
				log = false;
				break;
			}
			else if (j == size - 1)
			{
				log = true;
			}
		}
		if (log = true)
		{
			
			break;
		}
	}
	if (log ==false)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (p != arr[j][i])
				{
					log = false;
					break;
				}
				else if (j == size - 1)
				{
					log = true;
				}
			}
			if (log = true)
			{
				
				break;
			}
		}
	}
	if (log == false)
	{
		for (int i = 0; i < size; i++)
		{
			if (p != arr[i][i])
			{
				log = false;
				break;
			}
			else if (i == size - 1)
			{
				log = true;
			}
		}
	}
	if (log == false)
	{
		for (int i = 0, j = size - 1; i < size; i++, j--)
		{
			if(p!=arr[i][j])
			{
				log = false;
			     break;
			}
			else if (j == size - 1)
			{
				log = true;
			}
		}
	}
	return log;
}
bool CheckSpace(string **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == "_")
			{
				return true;
				break;
			}
			else if (i == size - 1)
			{
				return false;
			}
		}
	}
}
int main()
{
	int size;
    cout << "Select The Size Of The Game :" << endl;
	cin >> size;
	string **arr = new string *[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = new string[size];
	}
	string op, op1;
	int row, col, a;
	cout << "Select option player1 :" << endl;
	cout << "1.Tick :" << endl;
	cout << "2.Cross :" << endl;
	cin >> a;

	while (a < 1 || a>2)
	{
		cout << "Wrong Selection" << endl;
		cout << "Selection Again" << endl;
		cin >> a;
	}
	if (a == 1)
	{
		op = "*";
		op1 = "#";
	}
	else
	{
		op = "*";
		op1 = "#";
	}
	cout << "Selected options :" << endl;
	cout << "Player1" << op << endl;
	cout << "Player2" << op1 << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = "_";
		}
	}
	bool space = true;
	cout << "---------Lets Play the Game---------" << endl;
	while (space)
	{
		DisplayGameBoard(arr, size);
		cout << "Player1" << endl;
		cout << "Select option" << endl;
		cout << "Select Row" << endl;
		cin >> row;
		while (row<0 || row>(size - 1))
		{
			cout << "Invalid commad Enter Row Again" << endl;
			cin >> row;
		}
		cout << "Select Col" << endl;
		cin >> col;
		while (col<0 || col>(size - 1))
		{
			cout << "Invalid Command Enter Col Again" << endl;
			cin >> col;
		}


		while (arr[row][col] != "_")
		{
			cout << "Location is not available" << endl;
			cout << "Enter valid Location" << endl;
			cout << "Player1" << endl;
			cout << "Select Option" << endl;
			cout << "Select Row" << endl;
			cin >> row;
			while (row<0 || row>(size - 1))
			{
				cout << "Invalid Commad Enter Row Again" << endl;
				cin >> row;

			}
			cout << "Select Col" << endl;
			cin >> col;
			while (col < 0 || col>(size - 1))
			{
				cout << "Invalid Command Enter Col Again" << endl;
				cin >> col;
			}
		}
		arr[row][col] = op;
		bool con = Rules(arr, op, size);
		if (con)
		{
			DisplayGameBoard(arr, size);
			cout << "Player1 Win" << endl;
			break;
		}
		space = CheckSpace(arr, size);
		if (space == false)
		{
			cout << "Game Draw" << endl;
			break;
		}
		DisplayGameBoard(arr, size);
		cout << "Player2" << endl;
		cout << "Select Location" << endl;
		cout << "Select Row" << endl;
		cin >> row;
		while (row<0 || row>(size - 1))
		{
			cout << "Invalid Command Enter Row Again" << endl;
			cin >> row;
		}
		cout << "Select Col" << endl;
		cin >> col;
		while (col<0 || col>(size - 1))
		{
			cout << "Invalid Command Enter Row Again" << endl;
			cin >> col;

		}
		while (arr[row][col] != "_")
		{
			cout << "Location is not Available" << endl;
			cout << "Enter Valid Location" << endl;
			cout << "User2" << endl;
			cout << "Select Location" << endl;
			cout << "Enter Row" << endl;
			cin >> row;
			while (row<0 || row>(size - 1))
			{
				cout << "Invalid Command Enter Row Again" << endl;
				cin >> row;

			}
			cout << "Enter Col" << endl;
			cin >> col;
			while (col<0 || col>(size - 1))
			{
				cout << "Invalid Command Enter Col Again" << endl;
				cin >> col;
			}
			
		}
		arr[row][col] = op1;
		bool ress = Rules(arr, op1, size);
		if (ress)
		{
			DisplayGameBoard(arr, size);
			cout << "Player2 is Win" << endl;
			break;
		}
		space = CheckSpace(arr, size);
		if (space == false)
		{
			DisplayGameBoard(arr, size);
			cout << "Game Draw" << endl;
			break;
		}
	}

	_getch();
}