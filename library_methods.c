#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_headers.h"

// matthew
// Add song nodes

// eric
// Search for a song given song and artist name (return a pointer)
struct song_node * search_song(struct song_node * library, char * artist, char * name){
    int index = artist[0] - 'a' + 1;
    if (index < 0) {index = 0;}
    return find_node(&library[index], artist, name);
}

// matthew
// Search for an artist

// eric
// Print out all the entries under a certain letter
void print_letter(struct song_node * library, char letter){
    int index = letter - 'a' + 1;
    if (index < 0) {index = 0;}
    print_list(&library[index]);
}

// matthew
// Print out all the songs of a certain artist

// eric
// Print out the entire library
void print_library(struct song_node * library){
    int i;
    for(i = 0; i < 27; i++) { print_list(&library[i]); }
}

// matthew
// Shuffle - print out a series of randomly chosen songs

// eric
// Delete a song
struct song_node * remove_song(struct song_node * library, char * artist, char * name){
    int index = artist[0] - 'a' + 1;
    if (index < 0) {index = 0;}
    library[index] = *remove_node(&library[index], artist, name);
    return library;
}

// matthew
// Clear the library