//
// read_lyrics.cpp
//
//   read in song data from a specified file
//

#include "WordList.h"
#include <algorithm>
using namespace std;
WordList::WordList() {
}
/*
 * Destructor:
 * delete Heap for Each element in the HashTable
 */
WordList::~WordList() {
	//delete Vectors of Big Hash Table
	for (int i = 0; i < m_BigMap.get_capacity(); i++) {
		//string skey = m_BigMap.get_table()[i].alpha_word;
		//		if (skey != "") {
		//			delete m_BigMap.get_table()[i].songs;
		//
		//m_BigMap.get_table()[i].songs->clear();
		//delete []m_BigMap.get_table()[i].songs;
		delete m_BigMap.get_table()[i].songs;
	}

}
/*
 *  purpose: overload "greater" for sort function
 */
bool operator>(const SongInfo &lhs, const SongInfo &rhs) {
	if (lhs.freq > rhs.freq) {
		return true;
	}
	return false;
}
/*
 read_lyics
 purpose: read in song data from a disk file
 arguments: the name of the file, bool to ask for progress status
 returns: nothing
 does: calls a function each time a word is found
 */
void WordList::read_lyrics(const char * filename, bool show_progress) {
	// variable declaration
	string key, artist, title, word;
	// create HashTable for each song
	HashTable SubTable;

	// creates an input stream
	ifstream in(filename);

	int song_index = -1; // for progress indicator

	//------------------------------------------------------------
	// -- While more data to read...
	while (!in.eof()) {
		//create new song class
		Song song;

		// -- First line is the artist
		getline(in, artist);
		if (in.fail())
			break;
		//TODO:get artist
		song.set_artist(artist);

		// -- Second line is the title
		getline(in, title);
		if (in.fail())
			break;
		//TODO:get title
		song.set_title(title);

		song_index++;
		// -- Then read all words until we hit the 
		// -- special <BREAK> token
		while (in >> word && word != "<BREAK>") {
			// -- Found a word
			//TODO: insert word to song vector
			song.insert_word(word);
			//TODO: get key which is the process word
			key = song.alpha_only(word);
			//skip empty key
			if (key.length() == 0)
				continue;
			//insert SongInfo into the Sub Hashtable for each song
			SubTableInsert(key, song_index, SubTable);
		}
		// -- Important: skip the newline left behind
		in.ignore();

		//TEST
		//SubTable.print();
		int num = BigMapInsert(SubTable);

		song.set_num(num);

		SubTable.clear();
		//for songs exists in Big HashTable
		//push them to the SongVector

		m_VectSong.push_back(song);
		//song.print("m");
	}
	// delete popped songs
	vector<Song>::iterator it;
	for (it = m_VectSong.begin(); it != m_VectSong.end(); it++) {

		if (it->get_num() <= 0) {
			it->clean_lyrics();
		}
	}

	//m_BigMap.print();

}

/* SubTableInsert
 * purpose: insert SongInfo into the Sub Hashtable for each song
 * arguments: reference to the Small HashTable for each song, index of song
 * 	, key
 */
void WordList::SubTableInsert(string key, int song_index, HashTable &SubTable) {
	//push SongInfo to small HashTable------------------
	vector<SongInfo> *pvsf;
	pvsf = SubTable.find(key);
	if (pvsf != NULL) {
		(*pvsf).at(0).freq++;

	} else {
		pvsf = new vector<SongInfo> ;

		SongInfo sf;
		sf.song_index = song_index;
		sf.freq = 1;
		pvsf->push_back(sf);
		SubTable.insert(key, pvsf);
	}
}
/* BigMapInsert
 * purpose: insert SongInfo from the Small Table for each song
 * 	to the Big hash Table
 * arguments: reference to the Small HashTable for each song
 */
int WordList::BigMapInsert(HashTable &SubTable) {
	int num = 0;
	for (int i = 0; i < SubTable.get_capacity(); i++) {
		//get small table's key
		string skey = SubTable.get_table()[i].alpha_word;
		// skip if key does not exists
		if (skey == "") {
			continue;
		}

		//find key's position in Big Table
		vector<SongInfo> *pvsf = m_BigMap.find(skey);

		//insert new key to a new spot in the hash table
		if (pvsf == NULL) {
			m_BigMap.insert(skey, SubTable.get_table()[i].songs);
			num++;

			continue;
		}
		//if less than 10 spots, insert
		//insert to existing SongInfo Vector
		//with the same key
		else if (pvsf->size() < 10) {
			// create an songInfo struct object, assign SongInfo
			SongInfo sf = SubTable.get_table()[i].songs->at(0);
			//insert SongInfo to the vector
			pvsf->push_back(sf);

			//sort
			sort(pvsf->begin(), pvsf->end(), greater<SongInfo> ());
			num++;

			continue;
		}

		//get key's frequency in the small hash table
		int sub_freq = SubTable.get_table()[i].songs->front().freq;
		//get the smallest frequency of the key in Big Table
		int last_freq = pvsf->back().freq;
		//if >= 10 spots, insert when freq > 10th's freq
		if (last_freq < sub_freq) {

			int pop_index = pvsf->back().song_index;

			//decrease Song_num of the popped song
			m_VectSong.at(pop_index).minus_num();

			// delete the last element
			pvsf->pop_back();

			// create an songInfo struct object, assign SongInfo
			SongInfo sf = SubTable.get_table()[i].songs->at(0);

			//insert SongInfo to the vector
			pvsf->push_back(sf);
			//sort
			sort(pvsf->begin(), pvsf->end(), greater<SongInfo> ());
			num++;

		}
	}

	return num;

}
/* search
 * purpose: print out information of a searched word
 * argument: searched word
 */
void WordList::search(string search_word) {
	Song song;
	string key = song.alpha_only(search_word);
	vector<SongInfo> *pvsf = m_BigMap.find(key);
	if (pvsf == NULL)
		return;

	vector<SongInfo>::iterator it;
	for (it = pvsf->begin(); it != pvsf->end(); it++) {
		int index = it->song_index;

		m_VectSong.at(index).print(search_word);

	}
	cout << "<END OF REPORT>" << endl;
}

