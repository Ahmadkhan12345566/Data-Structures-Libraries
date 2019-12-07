#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
const int maxSize = 4;
int stack[maxSize];
int top = -1;
bool isFull();
bool isEmpty();
int rec = 0;

void Push(int value)
{
	if (isFull())
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
  int max = 0;
  int input;

		cout << "enter the value at index " << i << " :";
		cin >> input;
		if (input > max) {
			max = input;
		}
		Push(input);
	




		_getch();
}