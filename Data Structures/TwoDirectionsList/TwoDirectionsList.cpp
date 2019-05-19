#include "pch.h"
#include <cstring>
#include <iostream>

using namespace std;

class Element {
private:
	friend class OneList;
	Element* next = NULL;
	Element* prev = NULL;
	int data = 0;
	Element(int d) {
		this->data = d;
		this->prev = NULL;
		this->next = NULL;
	}
};
class OneList {
private:
	int listSize = 0;
	Element* first = NULL;
	Element* last = NULL;
public:
	//Add first element to List
	void addFirstElement(int d) {
		if (first == NULL || last == NULL) {
			Element* newElement = new Element(d);
			first = newElement;
			last = newElement;
			cout << "Add " << d << " as the only element" << endl << endl;
			listSize++;
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
		newElement->prev = last;
		last->next = newElement;
		last = newElement;
		listSize++;
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
		first->prev = newElement;
		first = newElement;
		listSize++;
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
		whereIAm->next->prev = newElement;
		newElement->next = whereIAm->next;
		newElement->prev = whereIAm;
		whereIAm->next = newElement;
		listSize++;
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
		whereIAm->prev->next = newElement;
		newElement->next = whereIAm;
		newElement->prev = whereIAm->prev;
		whereIAm->prev = newElement;
		listSize++;
	}

	//Delete item on position pos (counting from 0)
	void deleteElement(int pos) {
		Element* whereIAm = first;
		if (whereIAm == NULL) {
			cout << "There is no elements in List" << endl << endl;
			return;
		}
		if (pos == 0) {
			first = whereIAm->next;
			first->prev = NULL;
			cout << "Delete 1st element in list" << endl << endl;
			listSize--;
			delete whereIAm;
			return;
		}
		if (whereIAm->next == last) {
			cout << "Delete last element in list Data: " << whereIAm->next->data << endl << endl;
			last = whereIAm;
			last->next = NULL;
			listSize--;
			delete whereIAm->next;
			return;
		}
		for (int i = 0; i < pos - 1; i++) {
			whereIAm = whereIAm->next;
		}
		Element* tmp = whereIAm->next;
		whereIAm->next->next->prev = whereIAm;
		whereIAm->next = whereIAm->next->next;
		cout << "Delete " << pos + 1 << " element in list. Data: " << tmp->data << endl << endl;
		listSize--;
		delete tmp;
	}

	void size() {
		cout << "List size: " << listSize << endl << endl;
	}

	void showList() {
		Element* tmp = first;
		cout << "List: " << "|NULL|";
		while (tmp != NULL)
		{
			cout << tmp->data << "|";
			tmp = tmp->next;
		}
		cout << "NULL|" << endl << endl;
	}
	void showReverseList() {
		Element* tmp = last;
		cout << "Reverse list: " << "|NULL|";
		while (tmp != NULL)
		{
			cout << tmp->data << "|";
			tmp = tmp->prev;
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
	myList.deleteElement(1);
	myList.deleteElement(1);
	myList.size();
	myList.showList();
	myList.showReverseList();

	myList.insertBefore(4, 0);
	myList.insertAfter(3, 1);
	myList.size();
	myList.showList();
	myList.showReverseList();

	system("pause");
	return 0;
}