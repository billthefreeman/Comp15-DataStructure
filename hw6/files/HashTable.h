#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include<vector>
#include<string>
using namespace std;

#define MAX_LOAD_FACTOR 7
#define INIT_CAPACITY 8

//contain the index of the song and the frequency of the keyword
struct SongInfo {
	int song_index;
	int freq;

};
// the key word and the array of SongInfo
struct HashedItems {
	string alpha_word;
	vector<SongInfo> *songs;
};

class HashTable {

public:
	HashTable();
	~HashTable();

	//insert the key and its value into the hash_table
	void insert(string word, vector<SongInfo> *songs);

	//return the address of the SongInfo array, if the key is found
	vector<SongInfo> *find(string word);

	int get_capacity() {
		return m_table_capacity;
	}
	HashedItems* get_table() {
		return m_table;
	}

	void clear();
	//TEST
	void print();
private:
	HashedItems *m_table;
	void expand();
	//calculate current load factor
	float load_factor() {
		return (float) m_table_count / m_table_capacity;
	}

	//table's capacity
	int m_table_capacity;
	//the number of hashedItems
	int m_table_count;

};

#endif /* HASHTABLE_H_ */
