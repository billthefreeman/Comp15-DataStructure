/*
 * Queue.cpp
 *
 */

#include <iostream>
#include "Queue.h"
#include <cassert>

// TODO: Student writes this class

// constructor
Queue::Queue() {
	front = 0;
	back = 0;
	size = back - front;
	capacity = 4;
	queue_array = new Student[capacity];
}
// destructor
Queue::~Queue() {
	delete[] queue_array;
}

// enqueue a char onto at the back of the queue
void Queue::enqueue(Student c) {

	//expand if size > capacity
	if (size == capacity)
		expand();
	queue_array[back] = c;
	back = (back + 1) % capacity;
	size++;
}

// dequeue a char from the front of the queue
Student Queue::dequeue() {

	//assert there's element left
	Student c;
	if (size != 0) {
		c = queue_array[front];
		size--;
		front = (front + 1) % capacity;
	}
	return c;
}

// returns true if there are elements in the
// stack, false otherwise
bool Queue::is_empty() {

	if (size == 0)
		return true;
	else
		return false;
}

void Queue::expand() {

	Student *temp = new Student[capacity * 2];
	for (int i = 0; i < capacity; i++)
		temp[i] = queue_array[(i + front) % capacity];
	front = 0;
	back = front + size;
	delete[] queue_array;
	queue_array = temp;
	capacity *= 2;

}
