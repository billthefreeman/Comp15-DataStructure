/*
 * song.h
 *
 *  Created on: 2014��11��20��
 *      Author: DELL
 */

#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
// macros to get the larger or the smaller of 2 elements
#define GETMAX(a,b) ((a)>(b)?(a):(b))
#define GETMIN(a,b) ((a)<(b)?(a):(b))

class Song {
private:

	string title;
	string artist;
	vector<string> lyrics;
	int num_in_map;


public:
	Song();
	void set_title(string title) {
		this->title = title;
	}
	void set_artist(string artist) {
		this->artist = artist;
	}
	void set_num(int num){
		num_in_map=num;
	}
	int get_num(){
		return num_in_map;
	}
	void minus_num(){
		num_in_map--;

	}
	// read the lyrics from a file to the vector of all lyrics
	void insert_word(const string word);

	void clean_lyrics();
	// convert a string to lower_case and without punctuation
	string alpha_only(string s);

	//print the 10 words around the key word
	void print(string key);

};

#endif /* SONG_H_ */
