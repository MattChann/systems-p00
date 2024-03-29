#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list_headers.h"
#include "library_headers.h"

int main() {
    char divider[50] = "====================================\n\n";

    printf("LINKED LIST TESTS\n");
    printf("%s", divider);

    //========================================================================
    struct song_node * list = NULL;
    printf("Testing insert_front:\n");
    list = insert_front(list, "tyler, the creator", "boredom");
    list = insert_front(list, "kendrick lamar", "dna");
    list = insert_front(list, "jeremih", "oui");
    list = insert_front(list, "emotional oranges", "someone else");
    printf("%s", divider);

    //========================================================================
    printf("Testing print_list:\n");
    print_list(list);
    printf("%s", divider);

    //========================================================================
    printf("Testing print_node:\n");
    print_node(list);
    printf("\n%s", divider);

    //========================================================================
    printf("Testing insert_order:\n");
    list = insert_order(list, "pinkfong", "baby shark");
    list = insert_order(list, "kendrick lamar", "humble");
    list = insert_order(list, "wu tang clan", "method man");
    list = insert_order(list, "beyonce", "single ladies");
    print_list(list);
    printf("%s", divider);

    //========================================================================
    printf("Testing find_node:\n");
    struct song_node *testCmpNode0 = find_node(list, "emotional oranges", "someone else");
    find_node(list, "thisIsNotAnArtist", "thisIsNotAname");
    struct song_node *testCmpNode1 = find_node(list, "kendrick lamar", "dna");
    struct song_node *testCmpNode2 = find_node(list, "kendrick lamar", "humble");
    printf("%s", divider);

    //========================================================================
    printf("Testing find_artist:\n");

    int show_print = 1; //will show diagnostic statements

    find_artist(list, "emotional oranges", show_print);
    find_artist(list, "jeremih", show_print);
    find_artist(list, "death grips", show_print);
    printf("\n%s", divider);

    //========================================================================
    printf("Testing songcmp:\n");
    
    printf(" %d\n", songcmp(testCmpNode1, testCmpNode1, show_print));
    printf(" %d\n", songcmp(testCmpNode1, testCmpNode2, show_print));
    printf(" %d\n", songcmp(testCmpNode2, testCmpNode1, show_print));
    printf(" %d\n", songcmp(testCmpNode0, testCmpNode1, show_print));
    printf("%s", divider);

    //========================================================================
    printf("Testing random_node:\n");
    int i;
    for(i=0; i<5; i++) {
        random_node(list, time(NULL)*(i+2));
    }
    printf("%s", divider);

    //========================================================================
    printf("Testing remove:\n");
    list = remove_node(list, "emotional oranges", "someone else");
    print_list(list);

    list = remove_node(list, "kendrick lamar", "dna");
    print_list(list);

    list = remove_node(list, "kendrick lamar", "fear");
    print_list(list);

    list = remove_node(list, "tyler, the creator", "boredom");
    print_list(list);
    printf("%s", divider);

    //========================================================================
    printf("Testing free_list:\n");
    printf("list before free_list:\n");
    print_list(list);
    list = free_list(list);
    printf("list after free_list:\n");
    print_list(list);


    //=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/
    printf("%s",divider);
    printf("MUSIC LIBRARY TESTS\n\n");
    printf("%s",divider);
    //=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/=\=/

    //========================================================================
    struct song_node * table[27] = {NULL};

    printf("Populating library\n");
    add_song(table, "lil nas x", "panini");
    add_song(table, "childish gambino", "redbone");
    add_song(table, "childish gambino", "this is america");
    add_song(table, "lil tecca", "ransom");
    add_song(table, "tyler, the creator", "earfquake");
    add_song(table, "chance the rapper", "no problem");
    add_song(table, "drake", "money in the grave");
    add_song(table, "childish gambino", "feels like summer");
    add_song(table, "*NSYNC", "bye bye bye");
    add_song(table, "6lack", "prblms");
    printf("%s",divider);

    //========================================================================
    printf("Testing print_library\n");
    print_library(table);
    printf("%s",divider);

    //========================================================================
    printf("Testing print_letter\n");
    print_letter(table, '`');
    print_letter(table, 'c');
    print_letter(table, 'l');
    print_letter(table, 'g');
    printf("%s", divider);

    //========================================================================
    printf("Testing search_song\n");
    search_song(table, "childish gambino", "redbone");
    search_song(table, "childish gambino", "BLUEbone");
    search_song(table, "ADULTish gambino", "redbone");
    search_song(table, "tyler, the creator", "earfquake");
    printf("%s", divider);

    //========================================================================
    printf("Testing search_artist\n");
    search_artist(table, "lil nas x");
    search_artist(table, "childish gambino");
    search_artist(table, "drake");
    search_artist(table, "this is not an artist");
    printf("%s", divider);

    //========================================================================
    printf("Testing remove_song\n");
    remove_song(table, "childish gambino", "redbone");
    print_library(table);
    printf("\n");
    remove_song(table, "tyler, the creator", "earfquake");
    print_library(table);
    printf("\n");
    remove_song(table, "pinkfong", "baby shark");
    print_library(table);
    printf("%s", divider);

    //========================================================================
    printf("Testing clear_library\n");
    clear(table);
    printf("Library after clear:\n");
    print_library(table);
    printf("%s", divider);

    //========================================================================
    printf("Adding songs to empty library\n");
    add_song(table, "lil nas x", "panini");
    add_song(table, "childish gambino", "redbone");
    add_song(table, "lil tecca", "ransom");
    add_song(table, "tyler, the creator", "earfquake");
    add_song(table, "drake", "money in the grave");
    add_song(table, "childish gambino", "feels like summer");
    add_song(table, "*NSYNC", "bye bye bye");
    add_song(table, "6lack", "prblms");

    print_library(table);
    printf("%s", divider);

    //========================================================================
    printf("Testing print_artist\n");
    print_artist(table, "*NSYNC");
    printf("\n");
    print_artist(table, "childish gambino");
    printf("\n");
    print_artist(table, "lil tecca");
    printf("\n");
    print_artist(table, "lil xan");
    printf("%s",divider);
    
    //========================================================================
    printf("Testing shuffle\n");
    shuffle(table);
    printf("%s", divider);

    clear(table);
    return 0;
}