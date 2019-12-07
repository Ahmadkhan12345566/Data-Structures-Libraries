#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int arrsize;
const int maxSize = 4;
int stack[maxSize];


int top = -1;
bool isFull();
bool isEmpty();
int rec = 0;

void Push(int value)
{
	if (!isFull())
	{
		stack[++top] = value;
	}
	else
	{
		cout << "\nStack is full" << endl;;
	}
}

bool isFull()
{
	if (top == maxSize - 1)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void pop()
{
	if (isEmpty())
	{
		cout << "Value at index : " << top << " is : " << stack[top--] << endl;;
	}
	else
	{
		cout << "Stack is empty " << endl;
	}
}

bool isEmpty
()
{
	if (top != -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char terminate;
	int Input;
	int choice;
	int max = 0;

	cout << "..........................** Selection Menu **.............................." << endl;

	do
	{
		cout << "\nPress 1 to enter data &\n 2  for view 3 \nto Quickformat satack 4 \nto deepFormatr stack \n 5 to recover satck (on quick format only)" << endl;;
		cin >> choice;

		{
			switch (choice)
			{
			case 1:
			{
				do
				{
					cout << "\nEnter a value: ";
					cin >> Input;
					if (top >= 0) {
						int value = stack[top];
						if (value > Input) {
							pop();
							Push(Input);
							Push(value);
						}
					}
					else
					{
						Push(Input);
					}
					Push(Input);
					cout << "\nDo you want to enter another entry (Y/N) " << endl;
					cin >> terminate;
				} while (terminate == 'y');
				break;
			}
			case 2:
			{
				do
				{
					pop();

					cout << "\nDo you want to pop again (Y/N) " << endl;
					cin >> terminate;

				} while (terminate == 'y');
				break;
			}
			default:
			{
				cout << "\nInvalid Selection" << endl;
			}

			}
		}
		cout << "\nDo you want to Enter in 'Selection Menu', Press 'Y / N' " << endl;
		cin >> terminate;
	} while (terminate == 'y');
	cout << "\n\nSucessfully Ended" << endl;;

	_getch();
}