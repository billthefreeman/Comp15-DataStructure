//
//  read_lyrics.h
//  Reads in lyrics from a database, given the filename
//

#ifndef __read_lyrics__
#define __read_lyrics__

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//#include <map>

#include "song.h"
#include "HashTable.h"
using namespace std;

class WordList {
public:
	WordList();
	~WordList();
	// read the lyrics from a file
	void read_lyrics(const char * filename, bool show_progress);
	//TEST
	//void checkMap(map<string, SongInfo> &myMap);
	void search(string search_word);

private:
	//The Vector that store all songs' information
	vector<Song> m_VectSong;
	//initialize the Big Hash Table
	HashTable m_BigMap;
	//build each song's hash table
	void SubTableInsert(string key, int song_index, HashTable &SubTable);
	//push Songinfo to the big table
	int BigMapInsert(HashTable &SubTable);
};

#endif
