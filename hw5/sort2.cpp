//
//  QuickSort.cpp
//  Sorts integers using the QuickSort algorithm
#include "sort2.h"

using namespace std;

QuickSort::QuickSort() { // constructor
	sortArray.length = 0;
	sortArray.arr = NULL;
}
QuickSort::~QuickSort() {
	delete[] sortArray.arr;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void QuickSort::readList() {
	int currentCapacity = 10;
	sortArray.arr = new int[currentCapacity];

	while (cin >> sortArray.arr[sortArray.length]) {
		++sortArray.length;
		if (sortArray.length == currentCapacity) {
			int *temp = new int[currentCapacity * 2];
			for (int i = 0; i < currentCapacity; i++) {
				temp[i] = sortArray.arr[i];
			}
			delete[] sortArray.arr;
			sortArray.arr = temp;
			currentCapacity *= 2;
		}
	}
}
/*pass parameters to the main sort
 * */

void QuickSort::sort() {
	sort(0, sortArray.length - 1, sortArray.arr);
}
/* sort *parameter:
 * i: index in the left part
 * j: index in the left part
 * pivot: flag, middle point in this case
 */
void QuickSort::sort(int low, int high, int * arr) {
	// quick sort on sortArray
	int i = low;
	int j = high;
	int tmp;
	int pivot = arr[low+(high-low) / 2];
	//partition
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if(i<=j){
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
		}
	}
	//recursion
	if (low < j)
		sort(low, j, arr);
	if (i < high)
		sort(i, high, arr);
}
/*
 * print out intergers using for loop on separate lines
 */
void QuickSort::printArray() {
	// prints out the integers in sorted order
	for (int i = 0; i < sortArray.length; i++) {
		cout << sortArray.arr[i] << "\n";
	}
}

