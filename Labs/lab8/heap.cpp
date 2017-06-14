#include "heap.h"

Heap::Heap() {

	heap = new string[INIT_SIZE];
	heapSize = 0;
}

Heap::Heap(string list[], int listSize) {

	heap = new string[listSize + 1];

	//remember our implementation of a
	//heap starts at 1 not zero, so
	//we store a sentinal value at 0
	//this is not ideal as we could support
	//the null string, so it is best to
	//remember index 0 is not used
	heap[0] = "";

	//copy the unsorted list over
	for (int i = 0; i < listSize; i++) {
		heap[i + 1] = list[i];
	}

	heapSize = listSize;

	//use the build heap function
	//to make it a heap
	buildHeap();

}

//doesn't really work
//as the upHeap function
//is not implemented as it
//is nearly the same as the
//down heap funciton

void Heap::insert(string x) {

	if (heapSize >= maxCapacity) {
		expand();
	}

	//location to insert is heapSize+1 
	//(Recall, 0th location not used)
	heap[heapSize + 1] = x;
	heapSize++;

	//heapsize points to index of last element now
	//reheap or upHeap to fix
	upHeap(heapSize);

}

string Heap::removeMin() {
	// TODO: your code here
	string tmp = heap[1];
	heap[1] = heap[heapSize];
	heapSize--;
	downHeap(1);
	return tmp;

}

int Heap::size() {
	return heapSize;
}

void Heap::downHeap(int location) {
	// TODO: your code here
	int smallest = location;
	while (1) {
		if (location * 2 <= heapSize && heap[leftChild(location)]
				< heap[smallest])
			smallest = leftChild(location);
		if ((location * 2 + 1) <= heapSize
				&& heap[rightChild(location)] < heap[smallest])
			smallest = rightChild(location);
		if (location == smallest)
			return;

		string tmp = heap[smallest];
		heap[smallest] = heap[location];
		heap[location] = tmp;
		location = smallest;
	}
}

void Heap::upHeap(int location) {
	// not provided, as it is similar to downHeap.
	// write if you wish, but it is not mandatory for this lab.
}

void Heap::buildHeap() {
	// TODO: your code here
	for (int i = heapSize / 2; i > 0; i--)
		downHeap(i);
}

int Heap::leftChild(int index) {
	return index * 2;
}
int Heap::rightChild(int index) {
	return index * 2 + 1;
}
int Heap::parent(int index) {
	return index / 2;
}

//same old expand function, copying
//each element preserves the heap property
void Heap::expand() {
	string *temp = new string[maxCapacity * 2];
	for (int i = 0; i < heapSize + 1; i++) {
		temp[i] = heap[i];
	}
	maxCapacity = maxCapacity * 2;

	delete[] heap;
	heap = temp;
}
