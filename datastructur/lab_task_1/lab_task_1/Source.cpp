#include<iostream>		// using
#include<conio.h>		// _getch();
#include<stack>			// stack
using namespace std;

void _push();
void _pop();
void _printOrgArray();
void _printBackupArray();

struct myStackArray
{
	stack<int> myStack[2];
};

myStackArray mStack;					// stack array
int aCounter = 0;			// count an array element



// main
void main() {


	short choice;
	cout << "1.\tPush 2 items in Stack.\n2.\tPop one item from Stack.\n3.\tPerview the 'Orignal' Stack\n4.\tPerview the 'Backup' Stack.\n";

again:
	cout << "Enter an choice : ";
	cin >> choice;
	switch(choice) {
		case 1:
			// push two time
			_push();
			goto again;
			break;
		case 2:
			// pop one time
			_pop();
			goto again;
			break;
		case 3:
			// print Array1
			_printOrgArray();
			goto again;
			break;
		case 4:
			// print backup array
			_printBackupArray();
			goto again;
			break;
		default:
			cout << "\nInvalid input! Try again. ;-)\n";
			goto again;
	}
	
} // #end-main();



void _push() {
	int i = 0;					// input terminator

	do {
		int number;
		aCounter = mStack.myStack[0].size() + 1;
		cout << "Enter an value " << aCounter << " :";
		cin >> number;

		mStack.myStack[0].push(number);mStack.myStack[1].push(number);
		i++;
	} while (i != 2);
	i = 0;
}

void _pop() { 
	cout << "Pop() Success! : " << mStack.myStack[0].top() << "." << endl;
	mStack.myStack[0].pop();
}

void _printOrgArray() {

	stack<int> a;

	a = mStack.myStack[0];
	while (!a.empty())
	{
		cout << a.top() << "\n";
		a.pop();
	}
}
void _printBackupArray() {
	
	stack<int> a;

	a = mStack.myStack[1];
	cout << "Perview of Backup Stack!\n";
	while (!a.empty())
	{
		cout << a.top() << ((a.size() == 1) ? "." : ", ");
		a.pop();
	}
	cout << endl;
}
