#include<iostream>
#include<conio.h>
using namespace std;

void inserttion(int arr[])
{
	for (int i = 1; i <10; i++)
	{
		int value = arr[i];
		int hole = i;
		while (hole > 0 && value < arr[hole - 1])
		{
			arr[hole] = arr[hole - 1];
			hole = hole - 1;
		}
		arr[hole] = value;
	}
}





void buble(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		int flag = 0;
		for (int j = 0; j < 9; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = flag + 1;
			}

		}
		if (flag == 0)
		{
			return;
		}
	}
}
int main()
{
	int arr[10] = { 11,22,33,2,92,63,4,66,88,106 };
	int arr2[10] = { 21,32,43,0,82,23,4,36,18,10 };
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "-->";
	}
	cout << endl;
	buble(arr);
	cout << "After Sorting"<<endl;

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "-->";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr2[i] << "-->";
	}
	cout << endl;
	inserttion(arr2);
	cout << "After Sorting" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << arr2[i] << "-->";
	}
	
	_getch();
}