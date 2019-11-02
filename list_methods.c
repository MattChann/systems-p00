#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list_headers.h"

struct song_node * insert_front(struct song_node * node, char * name, char * artist) {
    struct song_node * newSong = malloc(sizeof(struct song_node));
    strcpy(newSong->artist, artist);
    strcpy(newSong->name, name);
    newSong->next = node;
    return newSong;
}

struct song_node * insert_order(struct song_node * node, char * song, char * artist) {
    struct song_node *currentNode, sentinelNode;
    sentinelNode.next = node;
    for(currentNode=&sentinelNode; currentNode!=NULL; currentNode=currentNode->next) {
        if(strcmp(artist, currentNode->artist) > 0 ||
          (strcmp(artist, currentNode->artist) == 0 && strcmp(song, currentNode->name)))
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
    for(; node!=NULL; node = node -> next) {
        printf("%s: %s | ", node->artist, node->name);
    }
    printf("\n");
}

struct song_node * find_song(struct song_node * node, char * artist, char * song) {
    for(; node!=NULL; node=node->next) {
        if(artist == node->artist && song == node->name) {
            return node;
        }
    }
    return NULL;
}

struct song_node * find_artist(char * artist) {

}

struct song_node * random_song(struct song_node * node) {
    srand(time(NULL));
    int length=0;
    struct song_node * parseNode;
    for(parseNode=node; parseNode!=NULL; parseNode=parseNode->next) {length++;}

    int randIndex = rand() % length;
    int i;
    for(i=0; node!=NULL; node=node->next, i++) {
        if(i == randIndex) {return node;}
    }
    return NULL;
}

struct song_node * remove_node(struct song_node * node, char * name, char * artist) {

}

struct song_node * free_list(struct song_node * node) {
    for(; node!=NULL; node=node->next) {
        struct song_node *nullifyNode = node;
        free(nullifyNode);
        nullifyNode = NULL;
    }
    return node;
}