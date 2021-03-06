// BSTree.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include <iostream>
#include <vector>

using namespace std;

string blank;

class Node {
public:
	int key;
	Node * leftChild;
	Node * rightChild;
	Node * parent;

	void displayNode() {
		printf(" %d ", key);
	}
};

class Tree {
private:
	Node * root = NULL;
public:

	Node* getRoot() {
		return root;
	}

	void insert(int key) {
		Node  * newNode = new Node();
		newNode->key = key;

		if (root == NULL) {
			root = newNode;
		}
		else{
			Node * current = root;
			Node * parent;
			while (true){
				parent = current;
				if (key < current->key) {
					current = current->leftChild;
					if (current == NULL){
						parent->leftChild = newNode;
						newNode->parent = parent;
						return;
					}
				}
				else
				{
					current = current->rightChild;
					if (current == NULL) {
						parent->rightChild = newNode;
						newNode->parent = parent;
						return;
					}
				}
			}
		}

	}
	void display(string sp, string sn, Node * root)
	{
		string s;

		if (root)
		{
			s = sp;
			if (sn == blank) s[s.length() - 2] = ' ';
			display(s + blank, blank, root->rightChild);

			s = s.substr(0, sp.length() - 2);
			printf("%s%s", s.c_str(), sn.c_str());
			cout << root->key << endl;

			s = sp;
			if (sn == blank) s[s.length() - 2] = ' ';
			display(s + blank, blank, root->leftChild);
		}
	}

	void create(vector<int>tab) {
		for (int i = 0; i < tab.size(); i++)
		{
			this->insert(tab[i]);
		}
	}
	Node* find(int key, Node * current) {
		if(current == NULL || current->key == key)
			return current;

		if (key < current->key)
			find(key, current->leftChild);
		else if(key > current->key)
			find(key, current->rightChild);
	}
};




int main()
{
	blank = "  ";

	vector<int>tab = {38,96,40,29,61,21,23,31,15,98,74,85};

	Tree testTree;
	testTree.create(tab);
	testTree.display("","",testTree.getRoot());

	int key = 96;

	if (testTree.find(key, testTree.getRoot()))
		cout << "Znaleziono galaz o kluczu " << testTree.find(key, testTree.getRoot())->key;
	else
		cout << "Nie ma galezi z takim kluczem";

	cout << endl;

	system("pause");
}

