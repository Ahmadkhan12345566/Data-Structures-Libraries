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
			cout << arr[i][j] << "    ";
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
		if (log == true)
		{
			break;
		}
	}
	if (log == false)
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
			if (log == true)
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

			if (p != arr[i][j])
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

	return log;
}
bool SpaceCheck(string **arr, int size)
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
	cout << "  Select The size of The Game :" << endl;
	cin >> size;
	string** arr = new string*[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = new string[size];
	}


	string op, op1;
	int row, col, a;
	cout << "Select Option player1:" << endl;
	cout << "1.Tick" << endl;
	cout << "2.Cross" << endl;

	cin >> a;
	while (a<1 || a>2)
	{
		cout << "Wrong Selection" << endl;
		cout << "Select Again" << endl;
		cin >> a;
	}
	if (a == 1)
	{
		op = "-/";
		op1 = "*";
	}
	else
	{
		op = "*";
		op1 = "-/";

	}
	cout << "Seletcted Options :" << endl;
	cout << "player1 :  " << op << endl;
	cout << "player2 :  " << op1 << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = "_";
		}

	}

	bool space = true;
	cout << "------------------------Lets Play The Game---------------------- " << endl;
	while (space)
	{
		DisplayGameBoard(arr, size);
		cout << "Player1 : " << endl;
		cout << "Select Location : " << endl;
		cout << "Select Row : " << endl;
		cin >> row;
		while (row<0 || row>(size - 1))
		{
			cout << "Invalid Command Select Row Again :" << endl;
			cin >> row;
		}

		cout << "select col : " << endl;
		cin >> col;
		while (col<0 || col>(size - 1))
		{
			cout << "Invalid Command Enter col Again :" << endl;
			cin >> col;
		}
		while (arr[row][col] != "_")
		{
			cout << "Location is not Available " << endl;
			cout << "Select Valid Location: " << endl;
			cout << "Player1 : " << endl;
			cout << "Select Location : " << endl;
			cout << "Select Row : " << endl;
			cin >> row;
			while (row<0 || row>(size - 1))
			{
				cout << "Invalid Command Enter Row Again :" << endl;
				cin >> row;
			}

			cout << "Select col : " << endl;
			cin >> col;
			while (col<0 || col>(size - 1))
			{
				cout << "Invalid Command Enter col Again :" << endl;
				cin >> col;
			}

		}
		arr[row][col] = op;
		bool con = Rules(arr, op, size);
		if (con)
		{
			DisplayGameBoard(arr, size);
			cout << "Player 1 is Win " << endl;
			break;
		}
		space = SpaceCheck(arr, size);
		if (space == false)
		{
			cout << "Game Draw " << endl;
			break;
		}

		DisplayGameBoard(arr, size);
		cout << "player2 : " << endl;
		cout << "Select Location : " << endl;
		cout << "Select Row : " << endl;
		cin >> row;
		while (row<0 || row>(size - 1))
		{
			cout << "Wrong Command Enter Row Again :" << endl;
			cin >> row;
		}

		cout << "Select col : " << endl;
		cin >> col;
		while (col<0 || col>(size - 1))
		{
			cout << "Wrong Command Enter col Again :" << endl;
			cin >> col;
		}
		while (arr[row][col] != "_")
		{
			cout << "Location is not Available " << endl;
			cout << "Enter Valid Location: " << endl;
			cout << "user2 : " << endl;
			cout << "Select Location : " << endl;
			cout << "Enter Row : " << endl;
			cin >> row;
			while (row<0 || row>(size - 1))
			{
				cout << "Wrong Command Enter Row Again :" << endl;
				cin >> row;
			}

			cout << "Enter col : " << endl;
			cin >> col;
			while (col<0 || col>(size - 1))
			{
				cout << "Wrong Command Enter col Again :" << endl;
				cin >> col;
			}

		}
		arr[row][col] = op1;
		bool ress = Rules(arr, op1, size);
		if (ress)
		{
			DisplayGameBoard(arr, size);
			cout << "player 2 is Win " << endl;
			break;
		}

		space = SpaceCheck(arr, size);
		if (space == false)
		{
			cout << "Game Draw " << endl;
			break;
		}


	}
	_getch();
}