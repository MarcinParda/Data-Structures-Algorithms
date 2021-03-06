#include "pch.h"
#include <cstring>
#include <iostream>

using namespace std;

struct Stack {
private:
	friend void push(int d, Stack* &top);
	friend int pop(Stack* &top);
	friend void showStack(Stack* top);
	int data = 0;
	Stack * under = NULL;
};

//add element to stack
void push(int d, Stack* &top) {
	Stack * newElement = new Stack;
	newElement->data = d;
	newElement->under = top;
	top = newElement;
}

//return and remove element from stack
int pop(Stack* &top) {
	if (top == NULL) return 0; //nothing to return
	Stack* tmp = top;

	int rData = top->data;
	top = top->under;

	delete tmp; //release memory
	return rData;
}

void showStack(Stack* top) {
	cout << "|";
	while (top != NULL)
	{
		cout << top->data << "|";
		top = top->under;
	}
	cout << "NULL|" << endl << endl;
}

int main()
{
	Stack* myStack = NULL; //first element will be NULL
	showStack(myStack);

	push(1, myStack);
	push(2, myStack);
	push(3, myStack);
	push(4, myStack);
	showStack(myStack);

	int x = pop(myStack);
	cout << "Value of element taken from stack: " << x << endl << endl;
	showStack(myStack);

	system("pause");
	return 0;
}