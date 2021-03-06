// ReverseArray(3.3).cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void showVector(vector<int>array) {
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

vector<int>reversedArray(vector<int>array, int i = 0){
	if(i == array.size() / 2)
		return array;
	int tmp = array[i];
	array[i] = array[array.size() - 1 - i];
	array[array.size() - 1 - i] = tmp;
	return reversedArray(array, i + 1);
}


int main()
{
	vector<int>array = { 1,2,3,4,5 };
	showVector(reversedArray(array));
	system("pause");
}

