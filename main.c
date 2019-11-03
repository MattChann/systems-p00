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
    find_artist(list, "emotional oranges");
    find_artist(list, "jeremih");
    find_artist(list, "death grips");
    printf("\n%s", divider);

    //========================================================================
    printf("Testing songcmp:\n");
    
    printf("Comparing [");
    print_node(testCmpNode1);
    printf(" ] to [");
    print_node(testCmpNode1);
    printf(" ]\n");
    printf(" %d\n", songcmp(testCmpNode1, testCmpNode1));

    printf("Comparing [");
    print_node(testCmpNode1);
    printf(" ] to [");
    print_node(testCmpNode2);
    printf(" ]\n");
    printf(" %d\n", songcmp(testCmpNode1, testCmpNode2));

    printf("Comparing [");
    print_node(testCmpNode2);
    printf(" ] to [");
    print_node(testCmpNode1);
    printf(" ]\n");
    printf(" %d\n", songcmp(testCmpNode2, testCmpNode1));

    printf("Comparing [");
    print_node(testCmpNode0);
    printf(" ] to [");
    print_node(testCmpNode1);
    printf(" ]\n");
    printf(" %d\n", songcmp(testCmpNode0, testCmpNode1));
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

    printf("%s",divider);
    printf("MUSIC LIBRARY TESTS\n\n");
    printf("%s",divider);

    struct song_node * table[27];

    printf("Testing print_library\n");
    // print_library(table);
    printf("%s",divider);

    printf("Testing print_letter\n");
    // print_letter(table, '0');
    // print_letter(table, 'a');
    // print_letter(table, 'g');
    printf("%s", divider);

    // printf("Testing search_song\n");
    
    // printf("%s", divider);

    // printf("Testing search_artist\n");
    
    // printf("%s", divider);

    // printf("Testing clear_library\n");
    
    // printf("%s", divider);

    // printf("Adding songs to empty library\n");
    
    // printf("%s", divider);

    // printf("Testing print_artist\n");
    
    // printf("%s", divider);

    // printf("Testing shuffle\n");
    
    // printf("%s", divider);
    return 0;
}