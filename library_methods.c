#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_headers.h"

// Add song nodes.
// matthew

// Search for a song given song and artist name (return a pointer).
//eric
struct song_node * find(struct song_node * library, char * artist, char * name){
    int index = artist[0] - 'a' + 1;
    if (index < 0) {index = 0;}
    return find_node(&library[index], artist, name);
}

// Search for an artist.
// matthew

// Print out all the entries under a certain letter.
//eric
void print_letter(struct song_node * library, char letter){
    int index = letter - 'a' + 1;
    if (index < 0) {index = 0;}
    print_list(&library[index]);
}

// Print out all the songs of a certain artist
// matthew

// Print out the entire library.
//eric
void print_library(struct song_node * library){
    int i;
    for(i = 0; i < 27; i++) { print_list(&library[i]); }
}

// Shuffle - print out a series of randomly chosen songs.
// matthew

// Delete a song
//eric
struct song_node * remove_song(struct song_node * library, char * artist, char * name){
    int index = artist[0] - 'a' + 1;
    if (index < 0) {index = 0;}
    library[index] = *remove_node(&library[index], artist, name);
    return library;
}

// Clear the library.
// matthew
