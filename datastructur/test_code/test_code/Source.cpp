#include<iostream>
#include<conio.h>
using namespace std;
struct node {
	node *next;
};
void MoveNode(struct node** destRef, struct node** sourceRef) {
	struct node* newNode = *sourceRef; // the front source node assert(newNode != NULL);
	*sourceRef = newNode->next; // Advance the source pointer
	newNode->next = *destRef; // Link the old dest off the new node *destRef = newNode; // Move dest to point to the new node
}
int main() {
 node *a = new node;
	node *b = new node;
	MoveNode(&a, &b);
	_getch();
}