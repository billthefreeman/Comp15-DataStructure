# ReadMe for COMP 15 HW6
## Song Search 

Your ReadMe file for the assignments **must** include:

1.  The purpose of your program
	search for the top 10 songs containing a word in a lyrics database,
	and print the searched word's nearby 10 words. 

2.  List of files with one/or two-line summary
	hashfunc.h hashfunc.cpp
-- build a hashing function to determine hash value with low collision
	HashTable.h HashTable.cpp
-- provide insert, find functions to build the Hash Table
	song.h song.cpp
-- provide insert, alpha_only function for lyrics in a song
-- provide print to print the 5 words before and after the key
	WordList.h WordList.cpp
-- read lyrics to a song vector; 
-- search for word


3.  How to compile it 
	a Makefile is written by me
4.  Outline of data structure
	Hash Table, Dynamic array

5.  Outline of algorithm 
	The first step is to create a data structure to store the content in the data file.
	For each song in the data file, we store the original words in a vector,
which is part of the song class. The class also includes the title and the artist of 
every song.
	Each song class then becomes an element of a huge vector, which store 
all the words from the database.
	The 2nd step is to create a hash table such that we can search for 
the corresponding top 10 songs for each word. 
	Thus, we create a hash table, with each processed word( no capital and punctuation) as a key. 
	The hash table utilize a 2d vector as the data structure, which is a part of the hashmap class.
It will be constructed using the provided hash functions.
	The value corresponding to each key is the index of the top 10 songs(<=10) of each word, 
and their frequency of word appearance.
	To find the top ten songs, I create 1 more slot to for the song being searched. 
After its frequency is known, we swap them, if its frequency is bigger then that of any top ones.  
The time for this operation is the length of the song+10 at most. 
	Finally, after the hash table is constructed, we deal with how to print out the 5 words 
previous to and after that word. We basically go through the song referred to by the song_index, and print out those words.

6.  A list of people who materially helped you on the assignment. 
