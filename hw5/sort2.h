//
//  QuickSort.h
//  Header File for SelectionSort class
//

#ifndef __Sorting__sort2__
#define __Sorting__sort2__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class QuickSort {
public:
        QuickSort(); // constructor
        ~QuickSort(); // destructor
        // read in a list of values from stdin
        void readList();

        // sort functions
        void sort();
        void sort(int low, int high, int *arr);

        // print the array
        void printArray();

private:
        arrayWithLength sortArray;
};

#endif
