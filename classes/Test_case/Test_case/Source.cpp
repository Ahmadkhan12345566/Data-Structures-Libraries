#include<iostream>
#include<conio.h>
using namespace std;
struct node {
	int distance;
	string  marked;
};

void disgistra(int **arr, int sixe) {

}

int main() {
	int nodes;
	cout << "total number of nodes :" << endl;
	cin >> nodes;
	int **arry = new int*[nodes];
	for (int i = 0; i < nodes; i++) {
		arry[i] = new int[nodes];
	}
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			arry[i][j]= 0;
		}
	}
}
