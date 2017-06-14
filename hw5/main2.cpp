//
//  main.cpp
//  QuickSort
//
#include <iostream>
#include "sort2.h"

using namespace std;

int main()
{
        QuickSort sorter;

        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
        return 0;
}
