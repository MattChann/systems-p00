#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list_headers.h"

// matthew
// Add song nodes
void add_song(struct song_node ** library, char * artist, char * name) {
    int index = artist[0] - 'a' + 1;
    if (index < 0) {index = 0;}
    library[index] = insert_order(library[index], artist, name);
}

// eric
// Search for a song given song and artist name (return a pointer)
struct song_node * search_song(struct song_node ** library, char * artist, char * name){
    int index = artist[0] - 'a' + 1;
    if (index < 0) {index = 0;}
    return find_node(library[index], artist, name);
}

// matthew
// Search for an artist
struct song_node * search_artist(struct song_node ** library, char * artist) {
    int index = artist[0] - 'a' + 1;
    if (index < 0) {index = 0;}
    struct song_node *foundNode = find_artist(library[index], artist, 1);
    return foundNode;
}

// eric
// Print out all the entries under a certain letter
void print_letter(struct song_node ** library, char letter){
    int index = letter - 'a' + 1;
    if (index < 0) {index = 0;}
    printf("%c list\n", letter);
    print_list(library[index]);
}

// matthew
// Print out all the songs of a certain artist
void print_artist(struct song_node ** library, char * artist) {
    int index = artist[0] - 'a' + 1;
    if (index < 0) {index = 0;}
    
    printf("Printing [%s]\n", artist);
    struct song_node *foundNode = find_artist(library[index], artist,0);
    for(; foundNode!=NULL; foundNode=foundNode->next) {
        if(strcmp(foundNode->artist, artist) != 0) {break;}
        print_node(foundNode);
        printf("\n");
    }
}

// eric
// Print out the entire library
void print_library(struct song_node ** library){
    int i;
    for(i = 0; i < 27; i++) {
        if(library[i] != NULL) {
            printf("%c list\n", i + 96);
            print_list(library[i]); 
        } 
    }
}

// matthew
// Shuffle - print out a series of randomly chosen songs
void shuffle(struct song_node ** library) {
    int i;
    for(i=1; i<=3;) {
        srand((time(NULL)+i)*i);
        struct song_node * random = library[rand() % 27];
        if(random != NULL) {
            random_node(random, rand()*i);
            i++;
        }
    }
}

// eric
// Delete a song
void remove_song(struct song_node ** library, char * artist, char * name){
    int index = artist[0] - 'a' + 1;
    if (index < 0) {index = 0;}
    library[index] = remove_node(library[index], artist, name);
}

// matthew
// Clear the library
void clear(struct song_node ** library) {
    int i;
    for(i=0; i<27; i++) {
        library[i] = free_list(library[i]);
    }
}