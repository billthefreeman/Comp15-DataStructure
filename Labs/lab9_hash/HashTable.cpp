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
HashTable::HashTable() {
	m_table_capacity = 4000;
	m_table_count = 0;

	table = new HashedItems[ m_table_capacity ];
//	for (int i = 0; i < m_table_capacity; i++) {
//		table[i].alpha_word = "";
//		table[i].songs=NULL;
//	}
	//song.wordCount = 0;
}
HashTable::~HashTable() {
	//delete [] table;
}
void HashTable::insert(string word, vector<SongInfo> *songs) {
	//check load factor
	unsigned int hash_value = hash_string(word);
	int table_position;
	bool done_insert = false;
	int attempt = 0;
	while (!done_insert) {
		//determine table_position
		// mod table size
		table_position = (hash_value + attempt) % m_table_capacity;
		if (table[table_position].alpha_word != "") {
			//bucket is taken, increase attempt
			attempt++;
		} else {
			//free spot, put word in
			//alpha_word & the songs into songs
			//in our struct at that position
			table[table_position].alpha_word = word;
			table[table_position].songs = songs;
			done_insert = true;
		}
	}
}
vector<SongInfo> *HashTable::find(string word) {
	unsigned int hash_value = hash_string(word);
	int table_position;
	bool done_searching = false;
	int attempt = 0;
	while (!done_searching) {
		table_position = (hash_value + attempt) % m_table_capacity;
		if (table[table_position].alpha_word == "") {
			//return NULL;
		} else if (table[table_position].alpha_word != word) {
			attempt++;
		} else {
			//if we found the word, return the songs pointer at
			//that position
			done_searching = true;
			return table[table_position].songs;
		}
	}
}

void HashTable::expand() {
	//1. create a new table with twice capacity
	//2. initialize the new table with alpha_word ""
	//3. swap the new table pointer and the old table pointers, using a temp pointer
	//4. change the capacity to twice
	//5. make m_table_count=0
	//6. rehash all the old keys(alpha only)
	// which you get by walking the old table
	//(note: you determine if you have to rehash if alpha_word !="")
	//7. delete[] the old table

	int new_capacity =m_table_capacity* 2+1;

	HashedItems *new_table = new HashedItems[ new_capacity ];
	for(int i = 0; i < new_capacity ; i++){
		new_table[i].alpha_word = "";
	}
	HashedItems *temp=table;
	table=new_table;
	int temp_capacity=m_table_capacity;
	m_table_count = 0;
	m_table_capacity=new_capacity;
	for(int i = 0; i < temp_capacity ; i++){
		if (temp[i].alpha_word != ""){
			insert(temp[i].alpha_word,temp[i].songs);
		}
	}
	delete [] temp;


}
