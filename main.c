#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list_headers.h"

int main() {
    char divider[50] = "------------------------------------";

    printf("LINKED LIST TESTS\n");
    printf("====================================\n\n");

    //========================================================================
    struct song_node * list = NULL;
    printf("Testing insert_front:\n");
    printf("Inserting at front: [tyler, the creator: boredom]\n");
    list = insert_front(list, "boredom", "tyler, the creator");
    printf("Inserting at front: [kendrick lamar: dna]\n");
    list = insert_front(list, "dna", "kendrick lamar");    
    printf("Inserting at front: [jeremih: oui]\n");
    list = insert_front(list, "oui", "jeremih");
    printf("Inserting at front: [emotional oranges: someone else]\n");
    list = insert_front(list, "someone else", "emotional oranges");
    printf("%s\n\n", divider);

    printf("Testing print_list:\n");
    print_list(list);
    printf("%s\n\n", divider);

    //========================================================================
    printf("Testing print_node:\n");
    print_node(list);
    printf("\n%s\n\n", divider);

    //========================================================================
    printf("Testing insert_order:\n");
    list = insert_order(list, "baby shark", "pinkfong");
    list = insert_order(list, "humble", "kendrick lamar");
    print_list(list);
    printf("%s\n\n", divider);

    //========================================================================
    printf("Testing find_node:\n");
    char artist[50] = "emotional oranges";
    char name[50] = "someone else";
    printf("looking for [%s: %s]\n", artist, name);
    find_node(list, artist, name);

    strcpy(artist, "thisIsNotAnArtist");
    strcpy(name, "thisIsNotAname");
    printf("looking for [%s: %s]\n", artist, name);
    find_node(list, artist, name);

    strcpy(artist, "kendrick lamar");
    strcpy(name, "dna");
    printf("looking for [%s: %s]\n", artist, name);
    find_node(list, artist, name);
    printf("%s\n\n", divider);

    //========================================================================
    printf("Testing find_artist:\n");
    strcpy(artist, "emotional oranges");
    printf("looking for [%s]\n", artist);
    find_artist(list, artist);

    strcpy(artist, "jeremih");
    printf("looking for [%s]\n", artist);
    find_artist(list, artist);

    strcpy(artist, "death grips");
    printf("looking for [%s]\n", artist);
    find_artist(list, artist);
    printf("\n%s\n\n", divider);

    //========================================================================
    //testing songcmp (helper function) not sure if this is necessary but its part of sample output

    //========================================================================
    printf("Testing random_node:\n");
    int i;
    for(i=0; i<5; i++) {
        random_node(list, time(NULL)*(i+2));
    }
    printf("%s\n\n", divider);

    //========================================================================
    printf("Testing remove:\n");
    strcpy(artist, "emotional oranges");
    strcpy(name, "someone else");
    printf("Removing [%s: %s]\n", artist, name);
    list = remove_node(list, name, artist);
    print_list(list);

    strcpy(artist, "kendrick lamar");
    strcpy(name, "dna");
    printf("Removing [%s: %s]\n", artist, name);
    list = remove_node(list, name, artist);
    print_list(list);

    strcpy(artist, "kendrick lamar");
    strcpy(name, "fear");
    printf("Removing [%s: %s]\n", artist, name);
    list = remove_node(list, name, artist);
    print_list(list);

    strcpy(artist, "tyler, the creator");
    strcpy(name, "boredom"); 
    printf("Removing [%s: %s]\n", artist, name);
    list = remove_node(list, name, artist);
    print_list(list);
    printf("%s\n\n", divider);

    //========================================================================
    printf("Testing free_list:\n");
    print_list(list);
    list = free_list(list);
    printf("list after free_list:\n");
    print_list(list);

    printf("====================================\n");
    printf("MUSIC LIBRARY TESTS\n");
    printf("====================================\n\n");

    struct song_node * table[27];

    return 0;
}