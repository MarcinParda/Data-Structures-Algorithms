// BubbleSort.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int n = 7;
int tab[n] = { 4,8,32,64,16,128,2 };

void displayTab(int tab[]) {
	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl;
}

void bubble(int tab[]) {

	for (int i = 1; i < n; i++)
	{
		int countOfSwaps = 0;

		for (int j = i; j <= n - i; j++) { //zapamiętanie indeksu to: (j <= n - i) i (j = i)
			if (tab[j] < tab[j - 1]) {
				int tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
				countOfSwaps++;
			}
		}
		if (!countOfSwaps)
			break;

		for (int j = n - i - 1; j >= i; j--) { //zapamiętanie indeksu to: (j = n - i - 1) i (j = n - 1)
			if (tab[j] < tab[j - 1]) {
				int tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
				countOfSwaps++;
			}
		}
		if (!countOfSwaps)
			break;

		cout << countOfSwaps << " zamian" << endl << endl;
		displayTab(tab);
	}
}


int main()
{
	displayTab(tab);
	bubble(tab);

	system("pause");
}