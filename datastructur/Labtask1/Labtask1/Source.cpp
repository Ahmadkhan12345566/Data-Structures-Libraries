#include<iostream>
#include<conio.h>
#include<string>
#include<stack>
using namespace std;
void display(const std::stack<int>& foo) {
	for (int i = 0;i < foo.size();i++) {
		cout<<foo.top()<<endl;
		

	}
}
int main() {
	stack<int> orignal;
	stack<int> temp;
	int value=0;
	int d = 0;
	bool dec=false;
	string decc = " ";
	int  cnt = -1;
	do {
		cout << "Enter the value : ";
		cin >> value;
		dec = false;
		if (orignal.size()>0) {
			while(!orignal.empty()&& dec==false) {
				if(value<orignal.top()){
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

		cout << orignal.top()<<endl;
		orignal.pop();
}

	_getch();
}