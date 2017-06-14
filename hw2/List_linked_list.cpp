#include "List_linked_list.h"

#include <iostream>
#include <cassert>

using namespace std;

// hint: in your constructor, you might want to set the head to NULL
List_linked_list::List_linked_list() {
	head = NULL;
}

List_linked_list::~List_linked_list() {
	// delete list by looping through and deleting each node
	make_empty();
}

// copy constructor
List_linked_list::List_linked_list(const List_linked_list& source) {
	// explicit copy constructor necessary because of cards array
	if (source.head == NULL)
		return; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
			new_node->card = source_current->next->card;
		} else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
}

// operator= overload
List_linked_list List_linked_list::operator =(const List_linked_list& source) {
	// explicit operator= overload necessary because of cards array

	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}
	// delete all current cards
	while (head != NULL) {
		Card_Node *next = head->next;
		delete head;
		head = next;
	}
	// copy over all cards from source list
	if (source.head == NULL)
		return *this; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		this_current->card = source_current->card;
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
		} else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
	return *this;
}

void List_linked_list::print_list() {
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card();
		if (current->next != NULL) {
			cout << ",";
		} else {
			cout << "\n";
		}
		current = current->next;
	}
}

void List_linked_list::print_list_int() {
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card_int();
		if (current->next != NULL) {
			cout << ",";
		} else {
			cout << "\n";
		}
		current = current->next;
	}
}

// students must write the following functions in the .cpp file
// returns the number of cards in the hand
int List_linked_list::cards_in_hand() {//seg fault
	Card_Node *current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}
// empties the list; head should equal NULL
void List_linked_list::make_empty() {
	Card_Node * current = head;
	Card_Node * prev = NULL;

	while (current != NULL) {
		prev = current;
		current = current->next;
		delete prev;
	}
	head = NULL;
}

// inserts a card at the head
// Should allow insert into an empty list
void List_linked_list::insert_at_head(Card c) {
	Card_Node *newnode = new Card_Node;
	assert(newnode != NULL);
	if (head == NULL) {
		head = newnode;
		head->card = c;
		head->next = NULL;
	} else {
		newnode->next = head;
		head = newnode;
		newnode->card = c;
	}

}

// inserts a card at the tail (final node)
// should allow insert into an empty list
void List_linked_list::insert_at_tail(Card c) {
	Card_Node *newnode = new Card_Node;
	assert(newnode != NULL);
	if (head == NULL) {
		head = newnode;
		newnode->card = c;
		newnode->next = NULL;
		return;
	}
	// check if at tail
	Card_Node *current = head;
	Card_Node *prev = NULL;
	while (current != NULL) {
		prev = current;
		current = current->next;
	}
	prev->next = newnode;
	newnode->next = NULL;
	newnode->card = c;

}

// inserts a card at an index such that
// all cards following the index will be moved farther
// down the list by one.
// The index can be one after the tail of the list
// I.e., you can insert at index 0 into an empty list,
// and you can insert at index 4 in a list with 4 nodes.
// In the first case, the node inserted would become the head
// In the second case, the node inserted would be inserted
// after the current tail.
void List_linked_list::insert_at_index(Card c, int index) {// failed test
	assert(index >= 0 && index <= cards_in_hand());
	if (index == 0)
		insert_at_head(c);
	else if (cards_in_hand() == index)
		insert_at_tail(c);
	else {
		Card_Node *newnode = new Card_Node;
		Card_Node *current = head;
		Card_Node *prev = NULL;
		int count = 0;
		while (current != NULL) {
			if (count == index) {
				prev->next = newnode;
				newnode->next = current;
				newnode->card = c;

				break;
			}
			count++;
			prev = current;
			current = current->next;
		}
	}
}
// replaces the card at index
// A card at index must already exist
void List_linked_list::replace_at_index(Card c, int index) {
	assert(index >= 0 && index < cards_in_hand());
	Card_Node *current = head;
	int count = 0;
	while (current != NULL) {
		if (count == index) {
			current->card = c;
			break;
		}
		count++;
		current = current->next;
	}
}

// returns the card at index.
// ??? allowed to crash if index is not in the list
Card List_linked_list::card_at(int index) { //warning
	assert(index >= 0 && index < cards_in_hand());
	Card_Node *current = head;
	int count = 0;
	while (current != NULL) {
		if (count == index) {
			break;
		}
		count++;
		current = current->next;
	}
	return current->card;
	//assert(count==index);
}

// returns true if the card is in the list
// returns false if the card is not in the list
bool List_linked_list::has_card(Card c) {//warning
	Card_Node *current = head;
	while (current != NULL) {
		if (current->card.same_card(c))
			return true;
		current = current->next;
	}
	return false;
}

// removes the card from the list
// Returns true if the card was removed
// Returns false if the card was not in the list
bool List_linked_list::remove(Card c) { //failed, seg fault
	Card_Node *current = head;
	Card_Node *prev = NULL;
	while (current != NULL) {
		if (current->card.same_card(c)) {
			if (current == head)
				head = current->next;
			else
				prev->next = current->next;
			delete current;
			return true;
		}
		prev = current;
		current = current->next;
	}

	return false;
}

// Removes the card from the head, and assigns the head
// to head->next
// Returns the card that was removed
// Allowed to fail if list is empty
Card List_linked_list::remove_from_head() {//warning
	assert(head != NULL);
	Card c = head->card;
	Card_Node * prev = head;
	Card_Node *current = head->next;
	delete prev;
	head = current;

	return c;
}

// Removes the card from the tail
// Returns the card that was removed
// ??? Allowed to fail if the list is empty
Card List_linked_list::remove_from_tail() {//seg fault
	assert(head != NULL);
	Card_Node * current = head;
	Card_Node * prev = NULL;

	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	Card c = current->card;
	if (current == head) {
		head = NULL;
	} else
		prev->next = current->next;
	delete current;
	return c;
}

// Removes the card from index
// Returns the card that was removed
// ??? Allowed to fail if index is beyond the end of the list
Card List_linked_list::remove_from_index(int index) {//seg fault
	assert(index >= 0 && index < cards_in_hand());
	Card_Node *current = head;
	Card_Node *prev = NULL;
	int count = 0;
	Card c;

	if (index == 0) {
		c = remove_from_head();
		return c;
	}

	while (current != NULL) {

		if (count == index) {
			c = current->card;
			prev->next = current->next;
			delete current;

		}
		count++;
		prev = current;
		current = current->next;
	}
	return c;
}
