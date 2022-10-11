#include "Functions.h"

/*
*	Binary Search
	Complexity: O(log N)

*/
int binarySearch(int* list, int size, int target)
{
	int min = 0, max = size - 1, mid = 0;
	bool found = false;
	while (!found && min <= max)
	{
		mid = (min + max) / 2; // (integer div!)
		if (list[mid] == target)
			found = true;
		else if (target < list[mid])
			max = mid - 1;
		else min = mid + 1;
	}
	if (found) return mid;
	else return -1;
}
/*
	Linear Search
	Complexity: O(N)
*/
int linearSearch(int* list, int size, int value)
{
	for (int x = 0; x < size; x++)
		if (list[x] == value) return x;

	return -1;
}
/*
	Print First Item
	Complexity: O(1)
*/
void printFirstItem(int arrayOfItems[])
{
	cout << arrayOfItems[0] << endl;
}

/*
	Bubble Sort
	Complexity: O(N^2)
*/
void bubbleSort(int arr[], int size)
{
	int n = size;
	int tmp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i - 1); j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
/*
	factorial of All Numbers to N
	Complexity: O(N^2)
*/
void factorial(int i)
{
	int sum = 0;
	for (int x = i; x > 0; x--)
	{
		sum += x;
	}
	cout << sum << endl;

	if (i > 0)
		factorial(i - 1);
	else
		return;
}
