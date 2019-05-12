#include "pch.h"
#include <cstring>
#include <iostream>

using namespace std;

class Element {
public:
	Element* next = NULL;
	int data = 0;
	Element(int d) {
		this->data = d;
		this->next = NULL;
	}
};
class OneList {
public:
	Element* first = NULL;
	Element* last  = NULL;

	//Add first element to List
	void addFirstElement(int d) {
		if (first == NULL || last == NULL) {
			Element* newElement = new Element(d);
			first = newElement;
			last = newElement;
			cout << "Add " << d << " as the only element" << endl << endl;
		}
		else {
			cout << "There is already some elements" << endl << endl;
		}
	}

	//Add element with data d on end pos
	void pushBack(int d) {
		if (first == NULL || last == NULL) { //If there is no elements
			addFirstElement(d);
			return;
		}
		Element* newElement = new Element(d);
		cout << "Add " << d << " as the last element" << endl << endl;
		newElement->next = NULL;
		last->next = newElement;
		last = newElement;
	}

	//Add element with data d on first pos
	void pushFront(int d) {
		if (first == NULL || last == NULL) { //If there is no elements
			addFirstElement(d);
			return;
		}
		Element* newElement = new Element(d);
		cout << "Add " << d << " as the first element" << endl << endl;
		newElement->next = first;
		first = newElement;
	}

	//Add element with data d after position pos
	//Position in list is counting from 0
	void insertAfter(int d, int pos) {
		if (first == NULL || last == NULL) { //If there is no elements
			addFirstElement(d);
			return;
		}
		Element* newElement = new Element(d);
		Element* whereIAm = first;
		
		int i = 0;
		while (i < pos)
		{
			whereIAm = whereIAm->next;
			i++;
		}
		if (whereIAm == last) { //If this is back position
			delete newElement;  //Delete couse pushBack create another1 newElement
			pushBack(d);
			return;
		}
		cout << "Add " << d << " after the " << pos << " element" << endl << endl;
		newElement->next = whereIAm->next;
		whereIAm->next = newElement;
	}

	//Add element with data d before position pos
	//Position in list is counting from 0
	void insertBefore(int d, int pos) {
		if (first == NULL || last == NULL) { //If there is no elements
			addFirstElement(d);
			return;
		}
		Element* newElement = new Element(d);
		Element* whereIAm = first;

		int i = 0;
		while (i < pos)
		{
			if (i != 0)
				whereIAm = whereIAm->next;
			i++;
		}
		if (i == 0) {           //If this is front position
			delete newElement;  //Delete couse pushFront create another1 newElement
			pushFront(d);
			return;
		}
		if (whereIAm == last) { //If this is back position
			delete newElement;  //Delete couse pushBack create another1 newElement
			pushBack(d);
			return;
		}
		cout << "Add " << d << " before the " << pos << " element" << endl << endl;
		newElement->next = whereIAm->next;
		whereIAm->next = newElement;
	}

	void showList() {
		Element* tmp = first;
		cout << "List: " << "|";
		while (tmp != NULL)
		{
			cout << tmp->data << "|";
			tmp = tmp->next;
		}
		cout << "NULL|" << endl << endl;
	}
};


int main()
{
	OneList myList;
	myList.showList();


	myList.addFirstElement(2);
	myList.pushBack(5);
	myList.pushFront(1);
	myList.showList();

	myList.insertBefore(4, 2);
	myList.insertAfter(3, 1);
	myList.showList();

	system("pause");
	return 0;
}