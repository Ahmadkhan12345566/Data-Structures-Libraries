#include<iostream>
#include<stack>
#include<string>
#include<conio.h>
using namespace std;
string InfixToPostfix(string expression);
int HasHigherPrecedence(char operator1, char operator2);
bool IsOperator(char C);
bool IsOperand(char C);
string Evaluteing(string psotfix);
string answer(string values);
int main()
{
	string expression;
	cout << "Enter Infix Expression \n";
	cin >> expression;
	string postfix = InfixToPostfix(expression);
	cout << "Output in Postfix Order = " << postfix << "\n";
	string values = Evaluteing(postfix);
	string asn = answer(values);
	cout << asn;
	_getch();
}
string answer(string values) {
	stack<char> S;
	int  ans=0;
	for (int i = 0;i < values.length();i++) {
		
		if (values[i] >= '0'&& values[i] <= '9') {

			S.push(values[i]);
		}
		else if (values[i] == '+' || values[i] == '-' || values[i] == '*' || values[i] == '/') {
			         
	
			int a =   S.top();
		
		S.pop();
			int b = S.top();
			S.pop();
			switch (values[i]) {
			case '+':
				ans = a + b;
				S.push(ans);
				break;
			case'-':
				ans = a - b;
				S.push(ans);
				break;
			case'*':
				ans = a*b;
				S.push(ans);
				break;
			case'/':
				ans = a / b;
				S.push(ans);
				break;
			
			}
			



		}
		

	
	}

	return (to_string(S.top()));
}



string Evaluteing(string psotfix) {
	string values=psotfix;
	for (int i = 0;i < psotfix.length();i++) {
		if (psotfix[i] >= 'a' && psotfix[i] <= 'z') {
			cout << "Enter the value of " << psotfix[i] << ":";
			cin >> values[i];
		}
		else
		{
			values[i] = psotfix[i];
		}
	}
	return values;
}
 
string InfixToPostfix(string expression)
{
	stack<char> S;
	string postfix = ""; 
	for (int i = 0;i< expression.length();i++) {
	if (expression[i] == ' ') continue;
		else if (IsOperator(expression[i]))
		{
			while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
			{
				postfix += S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
			else if (IsOperand(expression[i]))
		{
			postfix += expression[i];
		}
		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			while (!S.empty() && S.top() != '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}
	while (!S.empty()) {
		postfix += S.top();
		S.pop();
	}
return postfix;
}

bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	return false;
}

bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' )
		return true;

	return false;
}

int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
		weight = 2;
	case '-':
		weight = 1;
	case '*':
		weight = 3;
	case '/':
		weight = 4;
	
	}
	return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	if (op1Weight == op2Weight)
	{
		 return true;
	}
	return op1Weight > op2Weight ? true : false;

}