/*
 * song.cpp
 *
 *  Created on: 2014/11/21
 *      Author: Feiyu Lu
 *  coded to store song lyrics
 *  and to print out the information of the top 10 songs of a particular word
 */
#include "song.h"

/*
 * insert_word
 * purpose: insert words to the lyrics vector
 */
Song::Song() {
	num_in_map = 0;
}

void Song::insert_word(const string word) {
	lyrics.push_back(word);
}

void Song::clean_lyrics() {
	lyrics.clear();
}
/*
 alpha_only
 purpose: converts a string to lowercase and alphabetic characters
 only. E.g., "Bang!" becomes "bang"
 arguments: a string
 returns: the alpha-only string
 does: converts the string
 */
string Song::alpha_only(string s) {
	ostringstream ss;
	for (size_t i = 0; i < s.length(); i++) {
		if (isalnum(s[i])) {
			ss << (char) (tolower(s[i]));
		}
	}
	return ss.str();
}

/*
 * print
 * purpose: print out the information of the top ten songs
 * arguments: 4 vector iterators
 * returns: none
 */
void Song::print(string word) {
	vector<string>::iterator it1, it2, first, last;
	//Test:
	//cout <<"Key: "<<alpha_only(word)<< endl;
	//cout << alpha_only(word) << endl;
	for (it1 = lyrics.begin(); it1 != lyrics.end(); ++it1) {
		//compare word with word
		if (alpha_only(*it1) == alpha_only(word)) {
			//TEST
			//cout<<"Word: "<< *it1<<endl;
			//print title, artist
			cout << "Title: " << title << endl;
			cout << "Artist: " << artist << endl;

			cout << "Context: ";
			//get the 5 front words
			//begin with the start of the song
			first = GETMAX(it1 - 5, lyrics.begin());
			//get the 5 after words
			//end with the end of the song
			last = GETMIN(it1 + 6, lyrics.end());
			//print the 10 words
			for (it2 = first; it2 != last; ++it2) {
				cout << *it2 << " ";
			}
			cout << endl;
			cout << endl;
		}
	}

}
