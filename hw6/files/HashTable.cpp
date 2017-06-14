/*
 * HashTable.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: Chris Gregg
 */

#include <iostream>
#include "HashTable.h"
#include "hashfunc.h"

using namespace std;
/*
 * Constructor
 * Purpose: construct and initialize the table
 */
HashTable::HashTable() {
	m_table_capacity = INIT_CAPACITY;
	//m_table_capacity = 3000;
	m_table_count = 0;
	//create a new table
	m_table = new HashedItems[m_table_capacity];
	//initialize each word and song
	for (int i = 0; i < m_table_capacity; i++) {
		m_table[i].alpha_word = "";
		m_table[i].songs = NULL;

	}
}
/*
 * Destructor
 * Purpose: delete dynamic memory
 */
HashTable::~HashTable() {
	delete[] m_table;

}
/*
 * insert:
 * purpose: insert the key and its value into the hash_table
 * argument: the key, the pointer to song vector
 */
void HashTable::insert(string word, vector<SongInfo> *songs) {
	//check load factor
	unsigned int hash_value = hash_string(word);
	int table_position;
	bool done_insert = false;
	int attempt = 0;
	// if exceed load factor, expand
	if (load_factor() >= MAX_LOAD_FACTOR || m_table_count + 1
			== m_table_capacity)
		expand();
	while (!done_insert) {
		//determine table_position
		// mod m_table size
		table_position = (hash_value + attempt) % m_table_capacity;
		//if bucket is taken, increase attempt
		if (m_table[table_position].alpha_word != "") {
			attempt++;
		} else {
			//free spot, put word in
			//alpha_word & the songs into songs
			//in our struct at that position
			m_table[table_position].alpha_word = word;
			m_table[table_position].songs = songs;
			m_table_count++;
			done_insert = true;
		}
	}
}
/*
 * find
 * purpose: find if the hash_table contain a word as a key
 * argument: the key
 * return: the song_info struct in the found bucket of the table
 */
vector<SongInfo> *HashTable::find(string word) {
	unsigned int hash_value = hash_string(word);
	int table_position;
	bool done_searching = false;
	int attempt = 0;

	while (!done_searching) {
		//calculate the next position
		table_position = (hash_value + attempt) % m_table_capacity;

		//if the word is not a key in the hash_table, not found
		if (m_table[table_position].alpha_word == "") {
			return NULL;

			//if key exists, but the word is not in current position
			//keep searching
		}
		if (m_table[table_position].alpha_word != word) {
			attempt++;
		} else {
			//if we found the word, return the songs pointer at
			//that position
			done_searching = true;
			return m_table[table_position].songs;
		}
	}
	return NULL;
}
/* expand
 * purpose: expand the hash_table when exceeding the load factor
 */
void HashTable::expand() {
	//1. create a new m_table with twice capacity
	//2. initialize the new m_table with alpha_word ""
	//3. swap the new m_table pointer and the old m_table pointers,
	//using a old pointer
	//4. change the capacity to twice
	//5. make m_table_count=0
	//6. rehash all the old keys(alpha only)
	// which you get by walking the old m_table
	//(note: you determine if you have to rehash if alpha_word !="")
	//7. delete[] the old m_table
	int old_capacity = m_table_capacity;
	int new_capacity = m_table_capacity * 2 + 1;

	HashedItems *new_table = new HashedItems[new_capacity];
	for (int i = 0; i < new_capacity; i++) {
		new_table[i].alpha_word = "";
		new_table[i].songs = NULL;

	}
	HashedItems *old = m_table;
	m_table = new_table;

	m_table_count = 0;
	m_table_capacity = new_capacity;
	for (int i = 0; i < old_capacity; i++) {
		if (old[i].alpha_word != "") {
			insert(old[i].alpha_word, old[i].songs);
		}
	}
	delete[] old;
}
/* clear
 * purpose: clear contents of the small hash table
 * so that it can be reused for the next song
 */
void HashTable::clear() {
	m_table_count = 0;

	//initialize each word and song
	for (int i = 0; i < m_table_capacity; i++) {
		m_table[i].alpha_word = "";
		//delete m_table[i].songs;
		m_table[i].songs = NULL;
	}
}
//TEST
void HashTable::print() {
	for (int i = 0; i < m_table_capacity; i++) {
		if (m_table[i].alpha_word != "") {
			cout << m_table[i].alpha_word << endl;
			vector<SongInfo>::iterator it;
			for (it = m_table[i].songs->begin(); it
					!= m_table[i].songs->end(); it++) {
				cout << "index: " << it->song_index << endl;
				cout << "freq: " << it->freq << endl;
				cout << endl;
			}
		}
	}
}
