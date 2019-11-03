#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_headers.h"

// eric
// inserts nodes at the front
struct song_node * insert_front(struct song_node * node, char * artist, char * name) {
    printf(" Inserting at front: [%s: %s]\n", artist, name);
    struct song_node * newSong = malloc(sizeof(struct song_node));
    strcpy(newSong->artist, artist);
    strcpy(newSong->name, name);
    newSong->next = node;
    return newSong;
}

// compares two songs by artist first, then song
// if song1 belongs BEFORE song2, returns NEGATIVE int
// if song1 belongs AFTER  song2, returns POSITIVE int
// if songs are the SAME, returns 0
int songcmp(struct song_node * song1, struct song_node * song2) {
    if(strcmp(song1->artist, song2->artist) == 0) {
        if(strcmp(song1->name, song2->name) == 0) {
            return 0;
        }
        return strcmp(song1->name, song2->name);
    }
    return strcmp(song1->artist, song2->artist);
}

// matthew
// inserts nodes in order (alphabetical by Artist then by Song)
struct song_node * insert_order(struct song_node * node, char * artist, char * name) {
    struct song_node *newNode = malloc(sizeof(struct song_node));
    strcpy(newNode->name, name);
    strcpy(newNode->artist, artist);
    newNode->next = NULL;
    printf(" Inserting in order: [%s: %s]\n", artist, name);

    struct song_node *currentNode, sentinelNode;
    sentinelNode.next = node;
    for(currentNode=&sentinelNode; currentNode!=NULL; currentNode=currentNode->next) {
        if(currentNode->next == NULL) {
            currentNode->next = newNode;
            return node;
        }
        if(songcmp(newNode, currentNode->next) < 0) {
            // checks if the newNode belongs BEFORE the current node
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return node;
        }
    }
}

// eric
// prints the entire list
void print_list(struct song_node * node) {
    for(; node!=NULL; print_node(node), printf(" |"), node = node -> next) { }
    printf("\n");
}

// eric
// prints a single node
void print_node(struct song_node * node) {
    printf(" %s: %s", node->artist, node->name);
}

// matthew
// finds and returns a pointer to a node based on artist and song name
struct song_node * find_node(struct song_node * node, char * artist, char * name) {
    printf("looking for [%s: %s]\n", artist, name);
    for(; node!=NULL; node=node->next) {
        if(strcmp(artist, node->artist)==0 && strcmp(name, node->name)==0) {
            printf(" node found!");
            print_node(node);
            printf("\n");
            return node;
        }
    }
    printf(" node not found\n");
    return NULL;
}

// eric
// finds and returns a pointer to the first song of an artist based on artist name
struct song_node * find_artist(struct song_node * node, char * artist) {
    printf("looking for [%s]\n", artist);
    for(; node != NULL; node = node -> next) {
        if(strcmp(node->artist, artist) == 0) {
            printf(" artist found!");
            print_list(node);
            return node;
        }
    }
    printf(" artist not found");
    return NULL;
}

// matthew
// returns a pointer to random element in the list
struct song_node * random_node(struct song_node * node, int seed) {
    srand(seed);
    int length=0;
    struct song_node * parseNode;
    for(parseNode=node; parseNode!=NULL; parseNode=parseNode->next) {length++;}

    int randIndex = rand() % length;
    int i;
    for(i=0; node!=NULL; node=node->next, i++) {
        if(i == randIndex) {
            print_node(node);
            printf("\n");
            return node;
        }
    }
    return NULL;
}

// eric
// checks info of a given node
int correct_info(struct song_node * node, char * artist, char * name) {
    return (strcmp(node->name, name) == 0 && strcmp(node->artist, artist) == 0);
}

// eric
// removes a single specified node from the list
struct song_node * remove_node(struct song_node * node, char * artist, char * name) {
    printf("Removing [%s: %s]\n", artist, name);
    // the current node is the first node
    struct song_node * current = node;

    // if the list is not empty 
    if(current != NULL) { 
        
        if(correct_info(current, artist, name)) {
            struct song_node * nix = current;

            // shift the first node to the next node 
            node = node -> next;

            free(nix);
            nix = NULL;
        }
        else {
            for(; current->next != NULL; current = current->next) {
                if(correct_info(current -> next, artist, name)) {
                    struct song_node * nix = current->next; 
                    current->next = nix->next;
                    free(nix);
                    nix = NULL;
                    return node;
                }
            }

            // if the end of the list has been reached 
            if(current->next == NULL) {
                printf(" %s - %s not found\n", artist, name);
            }
        }
    }

    // if the list is empty 
    else {
        printf(" %s - %s not found\n", artist, name);
    }

    // return the front of the list 
    return node;
}

// matthew
// frees the entire list
struct song_node * free_list(struct song_node * node) {
    for(; node!=NULL; ) {
        printf("Freeing node:");
        print_node(node);
        printf("\n");

        struct song_node *nullifyNode = node;
        node=node->next;
        free(nullifyNode);
        nullifyNode = NULL;
    }
    return node;
}