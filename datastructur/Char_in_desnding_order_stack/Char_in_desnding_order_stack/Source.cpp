#include<iostream>
#include<conio.h>
#include<string>
#include<stack>
using namespace std;
void display(const std::stack<int>& foo) {
	for (int i = 0;i < foo.size();i++) {
		cout << foo.top() << endl;


	
	}

}
void dec_Alphabets() {

	stack<char> orignal;
	stack<char> temp;
	char value = ' ';
	int d = 0;
	bool dec = false;
	string decc = " ";

	do {
		cout << "Enter the value : ";
		cin >> value;
		dec = false;
		if (orignal.size()>0) {
			while (!orignal.empty() && dec == false) {
				if ((int)value<(int)orignal.top()) {
					temp.push(orignal.top());
					orignal.pop();
				}
				if (orignal.size() != 0) {
					if ((int)value >= (int)orignal.top()) {
						temp.push(value);
						dec = true;
					}
				}
				else {
					temp.push(value);
				}
			}
			//ending of while loop



			/*	if (orignal.top()<=value) {
			orignal.push(value);
			dec = true;
			}*/

			while (!temp.empty())
			{
				orignal.push(temp.top());
				temp.pop();
			}

		}
		else {
			orignal.push(value);
		}

		//	cout << "you want to entr value again y/n : ";
		//cin >> decc;
		dec = "y";
		d++;
	} while (decc == "y" || d <= 4);

	int max = orignal.size();
	cout << "Your Require order is" << endl;
	for (int i = 0;i<max;i++) {

		cout << orignal.top() << endl;
		orignal.pop();
	}


}
void counting_in_desnding() {
	stack<int> orignal;
	stack<int> temp;
	int value = 0;
	int d = 0;
	bool dec = false;
	string decc = " ";
	int  cnt = -1;
	do {
		cout << "Enter the value : ";
		cin >> value;
		dec = false;
		if (orignal.size()>0) {
			while (!orignal.empty() && dec == false) {
				if (value<orignal.top()) {
					temp.push(orignal.top());
					orignal.pop();
				}
				if (orignal.size() != 0) {
					if (value >= orignal.top()) {
						temp.push(value);
						dec = true;
					}
				}
				else {
					temp.push(value);
				}
			}
			//ending of while loop



			/*	if (orignal.top()<=value) {
			orignal.push(value);
			dec = true;
			}*/

			while (!temp.empty())
			{
				orignal.push(temp.top());
				temp.pop();
			}

		}
		else {
			orignal.push(value);
		}
		cnt++;
		//	cout << "you want to entr value again y/n : ";
		//cin >> decc;
		dec = "y";
		d++;
	} while (decc == "y" || d <= 4);

	int max = orignal.size();
	cout << "Your Require order is" << endl;
	for (int i = 0;i <max;i++) {

		cout << orignal.top() << endl;
		orignal.pop();
	}

}
int main() {
	int dec=0;
	cout << "What you want to perform ?:" << endl;
		cout << "press 1 to set cahrcters in desending order "<<endl;
	cout << "Press 2 to set integers in assending order" << endl;
	cin >> dec;
	switch (dec) {
	case 1:
		dec_Alphabets();
		break;
	case 2:
		counting_in_desnding();
		break;
	}
	system("Pause");
}