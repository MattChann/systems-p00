#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list_headers.h"

int main() {
    char divider[50] = "------------------------------------\n\n";

    printf("LINKED LIST TESTS\n");
    printf("====================================\n\n");

    //========================================================================
    struct song_node * list = NULL;
    printf("Testing insert_front:\n");
    list = insert_front(list, "boredom", "tyler, the creator");
    list = insert_front(list, "dna", "kendrick lamar");    
    list = insert_front(list, "oui", "jeremih");
    list = insert_front(list, "someone else", "emotional oranges");
    printf("%s", divider);

    printf("Testing print_list:\n");
    print_list(list);
    printf("%s", divider);

    //========================================================================
    printf("Testing print_node:\n");
    print_node(list);
    printf("\n%s", divider);

    //========================================================================
    printf("Testing insert_order:\n");
    list = insert_order(list, "baby shark", "pinkfong");
    list = insert_order(list, "humble", "kendrick lamar");
    print_list(list);
    printf("%s", divider);

    //========================================================================
    printf("Testing find_node:\n");
    struct song_node *testCmpNode0 = find_node(list, "emotional oranges", "someone else");
    find_node(list, "thisIsNotAnArtist", "thisIsNotAname");
    struct song_node *testCmpNode1 = find_node(list, "kendrick lamar", "dna");
    struct song_node *testCmpNode2 = find_node(list, "kendrick lamar", "humble");
    printf("%s\n\n", divider);

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
    printf("] to [");
    print_node(testCmpNode1);
    printf("]\n");
    printf(" %d\n", songcmp(testCmpNode1, testCmpNode1));

    printf("Comparing [");
    print_node(testCmpNode1);
    printf("] to [");
    print_node(testCmpNode2);
    printf("]\n");
    printf(" %d\n", songcmp(testCmpNode1, testCmpNode2));

    printf("Comparing [");
    print_node(testCmpNode2);
    printf("] to [");
    print_node(testCmpNode1);
    printf("]\n");
    printf(" %d\n", songcmp(testCmpNode2, testCmpNode1));

    printf("Comparing [");
    print_node(testCmpNode0);
    printf("] to [");
    print_node(testCmpNode1);
    printf("]\n");
    printf(" %d\n", songcmp(testCmpNode0, testCmpNode1));
    printf("%s\n\n", divider);

    //========================================================================
    printf("Testing random_node:\n");
    int i;
    for(i=0; i<5; i++) {
        random_node(list, time(NULL)*(i+2));
    }
    printf("%s", divider);

    //========================================================================
    printf("Testing remove:\n");
    list = remove_node(list, "someone else", "emotional oranges");
    print_list(list);

    list = remove_node(list, "dna", "kendrick lamar");
    print_list(list);

    list = remove_node(list, "fear", "kendrick lamar");
    print_list(list);

    list = remove_node(list, "boredom", "tyler, the creator");
    print_list(list);
    printf("%s", divider);

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