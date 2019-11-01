#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_headers.h"

struct song_node * insert_front(struct song_node * node, char * name, char * artist) {
    
}

struct song_node * insert_order(struct song_node * node, char * name, char * artist) {
    struct song_node *currentNode, sentinelNode;
    sentinelNode.next = node;
    for(currentNode=&sentinelNode; currentNode!=NULL; currentNode=currentNode->next) {
        if(strcmp(artist, currentNode->artist) > 0 ||
          (strcmp(artist, currentNode->artist) == 0 && strcmp(name, currentNode->name)))
        {
            struct song_node * newSong = malloc(sizeof(struct song_node));
            currentNode->next = currentNode->next->next;
            newSong->next = currentNode->next->next;
            currentNode->next = newSong;
            return node;
        }
    }
    return node;
}

void print_list(struct song_node * node) {

}

struct song_node * find_song(char * artist, char * song) {
    
}

struct song_node * find_artist(char * artist) {

}

struct song_node * random_song(struct song_node * node) {

}

struct song_node * remove_node(struct song_node * node, char * name, char * artist) {

}

struct song_node * free_list(struct song_node * node) {

}