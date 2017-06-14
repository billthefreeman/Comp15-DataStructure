/*
 * main.cpp
 *
 */
#include "WordList.h"
#include "song.h"

int main(int argc, char *argv[]) {
	string filename;
	WordList wordlist;

	if (argc == 2) { // if there is a filename on the command line
		wordlist.read_lyrics(argv[1], true);
	} else { // use a pre-defined filename
		//filename = "sort.txt";
		filename = "rick_db.txt";
		//filename = "lyrics_fulldb.txt";
		wordlist.read_lyrics(filename.c_str(), true);
		//
	}
	//cout<<"finished reading database "<<endl;
	while (1) {
		string search_word;
		cin >> search_word;

		if (search_word == "<BREAK>")
			break;
		wordlist.search(search_word);
	}
	return 1;
}
