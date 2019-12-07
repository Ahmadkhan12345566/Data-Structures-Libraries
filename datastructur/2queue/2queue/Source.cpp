//
//  Queue2Stack.h
//  A1DS
//
//  Created by Asif Raza on 28/09/2016.
//  Copyright © 2016 Asif Raza. All rights reserved.
//

#ifndef Queue2Stack_h
#define Queue2Stack_h

#include<iostream>
#include<queue>
using namespace std;

#endif /* Queue2Stack_h */


class Queue2Stack {
private:
	queue<int> _orgQueue;
	queue<int> _bkpQueue;

	void __push(int number) {
		_orgQueue.push(number);
		while (!_orgQueue.empty()) {
			_bkpQueue.push(_orgQueue.front());
			_orgQueue.pop();
		}
	}
	void __pop() {
		while (!_bkpQueue.empty()) {
			_orgQueue.push(_bkpQueue.front());
			_bkpQueue.pop();
		}
		_orgQueue.pop();
		while (!_orgQueue.empty()) {
			_bkpQueue.push(_orgQueue.front());
			_orgQueue.pop();
		}
	}
	void __display() {
		while (!_bkpQueue.empty()) {
			cout << _bkpQueue.front() << endl;
			_orgQueue.push(_bkpQueue.front());
			_bkpQueue.pop();
		}
		while (!_orgQueue.empty()) {
			_bkpQueue.push(_orgQueue.front());
			_orgQueue.pop();
		}
	}
	unsigned long int __size() {
		return _bkpQueue.size();
	}

public:
	Queue2Stack() {
		cout << "\nFile Name: " << __FILE__ << endl
			<< "Function Name: " << __func__ << endl
			<< "Date & Time: " << __DATE__ << " & " << __TIME__
			<< endl;
	}
	~Queue2Stack() {
		cout << "Goodbye! " << __func__ << endl << endl;
	}
	void StartFunction() {
		cout << "1.\tPush()\n2.\tPop()\n3.\tSize()\n4.\tDisplay()\n0.\tExit()\n";
		cout << "Enter a choice : ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 0:
			break;
		case 1:
			// Push
			int number;
			cout << "Enter an number: ";
			cin >> number;
			__push(number);
			StartFunction();
		case 2:
			// pop
			__pop();
			StartFunction();
		case 3:
			// size
			cout << __size();
			StartFunction();
		case 4:
			// display
			__display();
			StartFunction();
		default:
			cout << "Worng choice ! Try again ;)\n";
			StartFunction();
		}
	}
};



