#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
const int maxSize = 4;
int stack[maxSize];
int front = -1;
int rear = -1;
bool isEmpty()
{
	if (rear == -1 ||rear>=maxSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull()
{
	if (rear == maxSize - 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}
void diq() {

	if (!isEmpty) {

		cout << stack[front];
	}

}

void Queue() {

	rear = -1;
	front = 0;
}

void enqueue(int data) {

	stack[++rear] = data;

}

void  dequeue() {

	cout << stack[rear++];

}
void display() {
	if (!isEmpty()) {
		for (int i = 0;i < rear;i++)
		{
			cout << stack[i] << endl;

		}
	
	}
	else {

		cout << "queue is empty";
	}

}

void size() {
cout << (rear - front - 1);
}
int main() {




	_getch();
}