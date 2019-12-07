#include<iostream>
#include<conio.h>
#include<string>
#include<stack.>
#include<queue>
using namespace std;
stack<char> orignal;
stack<char> a;
queue<char> b;

void Output() {

	
	while (!orignal.empty())
	{
		a.push(orignal.top());
		orignal.pop();
	}
	if (!a.empty()) {
		cout << a.top()<<endl;
		a.pop();
	}
	else {
		cout << "Empty "<<endl;
	}
	

}
void input() {

	stack<char> a;
	if (orignal.empty()  && !a.empty()) {
		while (!a.empty())
		{
			orignal.push(a.top());
			a.pop();
		}
	}
	else
	{
		char input;
		cout << "enter the value :\n";
		cin >> input;
		orignal.push(input);
	}

		
}

int main()
{
	char dec;
	int chois;
	cout << "enter 1 for  input enter 2 for output" << endl;
	do {

	cout << "Enter your choies" << endl;
	cin >> chois;
	
		switch (chois) {
		case 1:
		{
			input();
			break;
		}
		case 2:
		{

			Output();
			break;
		}
		default:
		{
			cout << "invalid";
		}
		
		}





		cout << "do you want to enter again :" << endl;
		cin >> dec;

	} while (dec == 'y');
	_getch();
}
