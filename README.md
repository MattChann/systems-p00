# Project 0: myTunes

**PROJECT DUE: Monday, 11/4**

You may work with up to 1 other person, and that is highly encouraged.

Write a program in C that implements a music library organizer. The data structure should consist of an array of 27 slots (one for each letter from 'a' to 'z', and another for other symbols). Each slot will contain a linked list of all the artists that have names that start with the corresponding letter. When you add a song, it should go on to a linked list at the appropriate array slot in the correct position alphabetically. Assume no duplicate songs.

Your nodes/links should be able to hold a song's title and artist. You might use structures like the following:
```c
struct song_node{ 
    char name[100];
    char artist[100];
    struct song_node *next;
};

//and later:
struct song_node * table[27];
```

You should start by making your linked lists work with the following functionality:
-insert nodes at the front
-insert nodes in order
    - alphabetical by Artist then by Song
- print the entire list
- find and return a pointer to a node based on artist and song name
- find and return a pointer to the first song of an artist based on artist name
- Return a pointer to random element in the list.
- remove a single specified node from the list
- free the entire list

**DO NOT WORK ON THIS PART UNTIL YOUR LINKED LIST IS COMPLETE**
Then create your array of linked lists for the full program to have the following functions:

- Add song nodes.
- Search for a song given song and artist name (return a pointer).
- Search for an artist.
- Print out all the entries under a certain letter.
- Print out all the songs of a certain artist
- Print out the entire library.
- Shuffle - print out a series of randomly chosen songs.
- Delete a song
- Clear the library.
