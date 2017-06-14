//
//  MergeSort.cpp
//  Sorts integers using the MergeSort algorithm
#include "sort3.h"

using namespace std;

MergeSort::MergeSort() { // constructor
	sortArray.length = 0;
	sortArray.arr = NULL;
}
MergeSort::~MergeSort() {
	delete[] sortArray.arr;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void MergeSort::readList() {
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
void MergeSort::sort() {
	sort(0, sortArray.length - 1, sortArray.arr);
}/*
*recursively sort 2 sub-arrays *Parameters:
*mid:the midpoint
*/
void MergeSort::sort(int low, int high, int*arr) {
	// merge sort on sortArray
	//check if high is bigger than low
	//if so, sort the array
	int mid;
	if (high > low) {
		// get the index of the element
		mid = low + (high - low) / 2;
		//sort the left part
		sort(low, mid, arr);
		//sort the right part
		sort(mid + 1, high, arr);
		//merge both sorted parts
		merge(low, mid, high, arr);
	}
}
/** Parameters:
 *j: right bound of the left part
 *h: left bound of the left part
 *i: index of the tmp array
 *k: index of the remaining arrays
 *tmp[]:temporary array to store sorted part
 */
void MergeSort::merge(int left, int mid, int right, int *arr) {

	int h, i, j, k;
	int * tmp = new int[right + 1 - left];
	j = mid + 1;//
	h = left;//
	i = 0;//
	//Merges the 2 array's into tmp[] until the 1st one finishes
	while ((h <= mid) && (j <= right)) {
		if (arr[h] <= arr[j]) {
			tmp[i] = arr[h];
			h++;
		} else {
			tmp[i] = arr[j];
			j++;
		}
		i++;
	}// fill in missing values to complete the array
	if (h > mid) {
		for (k = j; k <= right; k++) {
			tmp[i] = arr[k];
			i++;
		}
	} else {
		for (k = h; k <= mid; k++) {
			tmp[i] = arr[k];
			i++;
		}
	}
	//store back to the original array
	for (k = 0; k <= right - left; k++) {
		arr[k + left] = tmp[k];
	}
	delete[] tmp;
}
/*
 * print out intergers using for loop on separate lines
 */
void MergeSort::printArray() {
	// prints out the integers in sorted order
	for (int i = 0; i < sortArray.length; i++) {
		cout << sortArray.arr[i] << "\n";
	}
}

