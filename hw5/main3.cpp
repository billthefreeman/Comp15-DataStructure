//
//  main.cpp
//  mergeSort
//
#include <iostream>
#include "sort3.h"

using namespace std;

int main() {
	MergeSort sorter;

	sorter.readList();
	sorter.sort();
	cout << "Output:\n";
	sorter.printArray();
	return 0;
}
