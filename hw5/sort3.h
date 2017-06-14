//
//  MergeSort.h
//  Header File for SelectionSort class
//

#ifndef __Sorting__MergeSort__
#define __Sorting__MergeSort__

#include <iostream>

struct arrayWithLength {
	int length;
	int *arr;
};

class MergeSort {
public:
	MergeSort(); // constructor
	~MergeSort(); // destructor
	// read in a list of values from stdin
	void readList();

	// sort function
	void sort();
	void sort(int low, int high, int*arr);
	void merge(int low, int mid, int high, int*arr);

	// print the array
	void printArray();

private:
	arrayWithLength sortArray;
};

#endif
