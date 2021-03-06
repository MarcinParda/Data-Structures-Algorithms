// Quicksort.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void quicksort(int tab[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot= tab[(left + right) / 2];
	do
	{
		while (tab[i] < pivot)
			i++;

		while (tab[j] > pivot)
			j--;

		if (i <= j)
		{
			swap(tab[i], tab[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (right > i) quicksort(tab, i, right);
	if (left < j) quicksort(tab, left, j);

}

int main()
{
	int n = 5;
	int tab[5] = { 6,2,5,8,3 };
	quicksort(tab, 0, 4);

	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " ";
	}
	return 0;
}