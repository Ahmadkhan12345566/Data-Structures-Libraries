#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
const int maxSize = 4;
int stack[maxSize];


int top = -1;
bool isFull();
bool isEmpty();

void Push(int value)
{
	if (isFull() == true)
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

bool isEmpty()
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
string pls(string a, string b) {

	return (a + b + '+');
}
string sub(string a, string b) {

	return (a + b + "-");
}
string mul(string a, string b) {

	return (a + b + "*");
}
string div(string a, string b) {

	return (a + b + "/");
}
int main()
{
	string a = "a+b";
	//char b = 'abaa';
	int col = a.length();

	int row = 1;
	string **arr = new string *[row];
	for (int i = 0;i < row;i++)
	{
		arr[i] = new string[col];

	}
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {

			arr[1][j] = a[j];
		}
	}
	string b;
	string c;
	string d;
	string f;
	int dec = 0;
	for (int i = 0;i < col;i++)
	{
		c = arr[0][i + 1];
		if (arr[0][i] == "+") {
			if (dec == 0) {
				b = arr[0][i - 1];

				arr[0][i + 1] = pls(b, c);
				dec++;
			}
			else if (dec != 0 && arr[0][i] == "+")
			{
				arr[0][i + 1] = pls(arr[0][i - 1], c);

				//a[i + 1] = pls(a[i - 1] , a[i + 1]);
			}


		}
		else if (arr[0][i] == "-" || arr[0][i] == "*" || arr[0][i] == "/") {
			arr[0][i + 1] = arr[0][i] + arr[0][i + 1];


		}


	}

	cout << arr[0][2];

	//string a="a";
	//string b="b";
	//string c=pls(a,b);
	//c = a+b+"+";
	//cout << c;
	_getch();
}