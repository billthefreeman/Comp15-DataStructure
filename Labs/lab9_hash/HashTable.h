#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include<vector>
#include<string>
using namespace std;

#define MAX_LOAD_FACTOR 0.7
#define INIT_CAPACITY 5

struct SongInfo {
	string songName;
	int wordCount;
};

struct HashedItems {
	string alpha_word;
	vector<SongInfo> *songs;
};

class HashTable {
public:
	HashTable();
	~HashTable();

	void insert(string word, vector<SongInfo> *songs);

	vector<SongInfo> *find(string word);

	float load_factor() {
		return (float) m_table_count / m_table_capacity;
	}
private:
	HashedItems *table;
	void expand();
	int m_table_capacity;
	int m_table_count;

};

#endif /* HASHTABLE_H_ */
