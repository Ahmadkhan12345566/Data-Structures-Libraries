#include<iostream>
#include<conio.h>
#include<stack>
#include<Queue>
using namespace std;
int main() {
	queue<int> pap;
//	pap.push(i);
	int s;
	int k=5;
	cout << "Enter the numnber of students in a class  :  ";
	//cin >> s;
	s = 40;
	cout << "\nenter the number of papers to distribute in class  :"<<endl;
    //cin >> k;
	//k = 5;
	for (int i = 1; i <= k; i++) {
		pap.push(i);
	}
	int num_ofcol = s / k;
	int num_ofrows = k;
	int arr[8][5];
	
	int givpap = 0;
	for (int i = 0; i < num_ofrows;i++) {
		
			for (int j = 0; j < num_ofcol; j++) {
				//givpap = pap.front();
				//pap.pop();
				bool dec =true;
				do {
					cout << "num of papeer to giv :" << endl;
					cin >> givpap;

					arr[i][j] = givpap;
					//pap.push(givpap);
					if (j > 0 && i > 0) {
						if (arr[i - 1][j - 1] == arr[i][j] || arr[i + 1][j + 1] == arr[i][j] || arr[i + 1][j] == arr[i][j] || arr[i - 1][j] == arr[i][j] || arr[i + 1][j - 1] == arr[i][j] || arr[i - 1][j + 1] == arr[i][j] || arr[i][j - 1] == arr[i][j] || arr[i][j + 1] == arr[i][j]) {
							cout << "dblacate" << endl;
							dec = false;
						}
					}
				} while (dec);

		}
	}
	for (int i = 0; i < num_ofrows; i++) {
		for (int j = 0; j < num_ofcol; j++) {

			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	
	_getch();

} 