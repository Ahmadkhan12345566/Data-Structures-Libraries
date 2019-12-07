#include<iostream>
#include<conio.h>
using namespace std;
class SStack
{
private:
	int top=-1;
	int max[6];
public:
	void Push(int a);
	void pop();
	void Display();
	bool ISEmpty();
	bool ISFull();
	void size();
	SStack();


};
SStack::SStack() {
	top = -1;
}
bool SStack::ISEmpty()
{
	if (top=-1)
	{
		return true;
	}
	return false;
}
bool SStack::ISFull()
{
	if (top=7)
	{
		return true;

	}
	return false;
}
void SStack::Push(int a)
{
	if (false)
	{
	

	}

}
int main()
{

	SStack abc;
	if (abc.ISFull()) {
		cout << "saasas";
	}

	_getch();




}