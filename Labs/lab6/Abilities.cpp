/*
 * Abilities.cpp
 *
 *  Created on: Oct 17, 2014
 *      Author: Chris Gregg
 */

#include "Abilities.h"

using namespace std;

Abilities::Abilities() {
	// start with only your hand
	head = new AbilityNode();
	head->ability.strength = 1;
	head->ability.weapon = "hand";
	head->next = NULL;
}

// copy constructor

Abilities::Abilities(const Abilities &source) {
	// TODO: Students write code here
	if (source.head == NULL)
		return; // nothing to do

	head = new AbilityNode;
	AbilityNode *this_current ;
	this_current = head;
	AbilityNode *source_current = source.head;
	while (source_current != NULL) {
		// deep copy each Card_Node
		if (source_current->next != NULL) {
			AbilityNode *newnode;
			newnode = new AbilityNode();
			this_current->next = newnode;
			newnode->ability = source_current->next->ability;
		} else
			this_current->next = NULL;// at tail
		this_current = this_current->next;
		source_current = source_current->next;
	}
}

// assignment (=) overload
Abilities &Abilities::operator=(const Abilities &source) {
	// TODO: Students write code here
	// check for self-assignment
	if (this == &source)
		return *this;
	// delete all current cards
	while (head != NULL) {
		AbilityNode *next = head->next;
		delete head;
		head = next;
	}
	if (source.head == NULL)
		return *this;
	head = new AbilityNode;
	AbilityNode *this_current = head;
	AbilityNode *source_current = source.head;
	while (source_current != NULL) {
		if (source_current->next != NULL) {
			AbilityNode *newnode = new AbilityNode();
			this_current->next = newnode;
			newnode->ability = source_current->next->ability;
		} else
			this_current->next = NULL;
		this_current = this_current->next;
		source_current = source_current->next;
	}
	return *this;
}

Abilities::~Abilities() {
	deleteList();
}

void Abilities::deleteList() {
	// TODO: Students write code here
	AbilityNode *current = head;
	AbilityNode *prev = NULL;
	while (current != NULL) {
		if (current == head)
			head = current->next;
		else
			prev->next = current->next;

		delete current;
		prev = current;
		current = current->next;
	}
}

void Abilities::updateAbility(std::string name, int amount) {
	AbilityNode *curr = head;
	AbilityNode *prev = NULL;

	while (curr != NULL) {
		if (curr->ability.weapon == name) {
			// found the node to update
			curr->ability.strength = amount;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	// not found, create new node to populate
	curr = new AbilityNode();
	curr->ability.weapon = name;
	curr->ability.strength = amount;
	curr->next = NULL;

	if (prev == NULL) {
		// at head
		head = curr;
	} else {
		prev->next = curr;
	}
}

int Abilities::getStrength(std::string name) {
	// returns -1 if the name does not exist in the list
	AbilityNode *curr = head;
	while (curr != NULL) {
		if (curr->ability.weapon == name) {
			return curr->ability.strength;
		}
		curr = curr->next;
	}
	return -1;
}

int Abilities::abilityCount() {
	AbilityNode *curr = head;
	int count = 0;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

Ability &Abilities::abilityByIndex(int index) {
	// does not do error checking on index!
	AbilityNode *curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->ability;
}

void Abilities::printAbilities() {
	// walk the list and print all weapons and abilities
	AbilityNode *curr = head;
	while (curr != NULL) {
		cout << "\t" << curr->ability.weapon << " : "
				<< curr->ability.strength << "\n";
		curr = curr->next;
	}
}

int Abilities::totalStrength() {
	int totalStrength = 0;

	// walk the list and calculate total strength
	AbilityNode *curr = head;
	while (curr != NULL) {
		totalStrength += curr->ability.strength;
		curr = curr->next;
	}
	return totalStrength;
}
