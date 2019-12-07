#include<iostream>
#include<conio.h>
using namespace std;
class Queue {
private:
	int item[10];
	int rear;
	int front;
public:
	Queue();
	void enqueue(int);
	int dequeue();
	int size();
	void display();
	bool isEmpty();
	bool isFull();
};
class MyStack{
private:
	int item[10];
	int top;
	int max;
public:
	MyStack();
	void Push(int);
	void Pop();
	void size();
	void display();
	bool isEmpty();
	bool isFull();
};
MyStack::MyStack() {
	top = -1;
	max = 10;
}
bool MyStack::isFull()
{
	if (top == max - 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool MyStack::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MyStack::Pop()
{
	if (!isEmpty())
	{
		cout << "Value at index : " << top << " is : " << item[top--] << endl;;
	}
	else
	{
		cout << "Stack is empty " << endl;
	}
}
void MyStack::size(){
	cout << "size of stack is" <<top + 1;
}

void MyStack::Push(int value)
{
	if (!isFull())
	{
		item[++top] = value;
	}
	else
	{
		cout << "\nStack is full" << endl;;
	}
}


Queue::Queue() {
	rear = -1;
	front = 0;
}
void Queue::enqueue(int data) {
	item[++rear] = data;
}
int Queue::dequeue() {
	return item[front++];
}
void Queue::display() {
	if (!this->isEmpty()) {
		for (int i = front; i <= rear; i++)
			cout << item[i] << endl;
	}
	else {
		cout << "Queue Underflow" << endl;
	}
}
int Queue::size() {
	return (rear - front + 1);
}
bool Queue::isEmpty() {
	if (front>rear) {
		return true;
	}
	else {
		return false;
	}
}
bool Queue::isFull() {
	if (this->size() >= 10) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	Queue queue;
	int choice, data;
	while (1) {
		cout << "\n1. Enqueue\n2. Dequeue\n3. Size\n4. Display all element\n5 Quit";
			cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (!queue.isFull()) {
				cout << "\nEnter data: ";
				cin >> data;
				queue.enqueue(data);
			}
			else {
				cout << "Queue is Full" << endl;
			}
			break;
		case 2:
			if (!queue.isEmpty()) {
				cout << "The data dequeued is :" << queue.dequeue();
			}
			else {
				cout << "Queue is Emtpy" << endl;
			}
			break;
		case 3:
			cout << "Size of Queue is " << queue.size();
			break;
		case 4:
			queue.display();
			break;
		case 5:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}