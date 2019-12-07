#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
double add(double num1, double num2) {
	return(num1 + num2);
}
double sub(double num1, double num2) {
	return(num1 - num2);
}
double mul(double num1, double num2) {
	return(num1 * num2);
}
double div(double num1, double num2) {
	return(num1 / num2);
}
int main() {
	string dec="n";
	double num1,num2,result;
	char opr;
	cout << "you want to perform calculation \nPress (y) for yes and (n) for No: \n";
	cin >> dec;
	while (dec == "y") {
		cout << "Enter 1st number :\n";
			cin >> num1;
			cout << "Enter the operator you want to perform \nOperators must be from + - / * \nPress (f) to find factorial :\n";
			cin >> opr;
			if (opr == 'f') {
				double fac = 1;
				double cndt = num1;
				while (cndt>0)
				{
					fac = fac*cndt;
					cndt--;
				}

				result = fac;
			}
			else
			{


				cout << "Enter 2st number :\n";
				cin >> num2;
				switch (opr)
				{
				case '+':
					result = add(num1, num2);
					break;
				case '-':
					result = sub(num1, num2);
					break;
				case '/':
					result = div(num1, num2);
					break;
				case '*':
					result = mul(num1, num2);
					break;
				default:
					cout << "invalid input :\n";
					break;
				}
			}
			cout << "Result :"<< result<<endl;
			cout << "You want to perform More calculation \nPress (y) for yes and (n) for No: \n";
			cin >> dec;
	}
	cout << "press to exit ";
	_getch();

}