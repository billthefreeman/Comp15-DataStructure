#include "hookbook.h"

HookBook::HookBook() {
	hbook = new Pirate[INIT_CAPACITY];
	currentCapacity = INIT_CAPACITY;
	pirateCount = 0;
}

/* Adds a new pirate to HookBook, probably the member should
 be created by the hookbook system, for now it is sent in
 from main, friends is a pointer to a dynamic array we
 copy it to the hookbook data structure, if it is null the pirate
 has no friend*/

bool HookBook::addPirate(int member, string memberName) {
	//check to see if we need to expand to add
	if (pirateCount >= currentCapacity) {
		// check to see if expand worked
		if (!expandPirates()) {
			return false;
		}
	}
	//made it here so we can add a pirate
	hbook[pirateCount].memberID = member;
	hbook[pirateCount].name = memberName;
	hbook[pirateCount].friendList = NULL;
	hbook[pirateCount].friendCount = 0;
	hbook[pirateCount].friendCapacity = 0;
	pirateCount++;
	return true;

}

/* Prints the values in the list in ascending order. */
/* This method is "const", which is a promise to the compiler
 that it won't change the value of any private variables. */
void HookBook::print() const {
	cout << "There are " << pirateCount << " pirates in the system."
			<< endl;
	for (size_t i = 0; i < pirateCount; i++) {
		cout << "Pirate: " << hbook[i].name << " with memberID: "
				<< hbook[i].memberID << " has friends ";

		for (size_t j = 0; j < hbook[i].friendCount; j++) {
			cout << hbook[i].friendList[j] << " ";
		}

		cout << endl;

	}
}

//the function you will write you may have an empty list to start
bool HookBook::addFriend(int memID, int friendID) {
	// TODO: Students write code here
	int index = -1;
	for (int c = 0; c < pirateCount; c++)
		if (hbook[c].memberID == memID)
			index = c;
	if (index == -1)
		if (!addPirate(memID,"" ))
			return false;

	if (hbook[index].friendList == NULL) {
		int *new_friendlist = new int[INIT_CAPACITY];
		hbook[index].friendList = new_friendlist;
		hbook[index].friendCapacity = INIT_CAPACITY;
	}
	if (hbook[index].friendCount >= hbook[index].friendCapacity) {
		int *new_friendlist = new int[hbook[index].friendCapacity * 2];
		for (int i = 0; i < hbook[index].friendCapacity; i++)
			new_friendlist[i] = hbook[index].friendList[i];
		delete[] hbook[index].friendList;
		hbook[index].friendList = new_friendlist;
		hbook[index].friendCapacity *= 2;
	}
	hbook[index].friendList[hbook[index].friendCount] = friendID;
	hbook[index].friendCount++;
	return true;

}

/* destructor */
HookBook::~HookBook() {
	// TODO: Students write code here
	// first delete all the Pirate data
	for (int c = 0; c < pirateCount; c++)

		delete[] hbook[c].friendList;
	// now delete the pirates themselves
	delete[] hbook;
}

bool HookBook::expandPirates() {
	Pirate* temp = new Pirate[currentCapacity * 2];
	if (temp == NULL) {
		return false;
	}
	for (size_t i = 0; i < pirateCount; i++) {
		temp[i] = hbook[i];
	}
	delete[] hbook;
	hbook = temp;
	currentCapacity = currentCapacity * 2;
	return true;
}

