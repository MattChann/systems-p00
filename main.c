#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_headers.h"

int main() {
    printf("LINKED LIST TESTS\n");
    printf("====================================\n\n");

    struct song_node * list = NULL;
    list = insert_front(list, "dna", "kendrick lamar");
    list = insert_front(list, "someone else", "emotional oranges");
    list = insert_front(list, "oui", "jeremih");
    list = insert_front(list, "boredom", "tyler, the creator");

    printf("Testing print_list:\n");
    print_list(list);
    printf("====================================\n\n");

    printf("Testing print_node:\n");
    print_node(list);
    printf("\n====================================\n\n");

    //testing find node 

    printf("Testing find_artist:\n");
    printf("looking for [emotional oranges]\n");
    find_artist(list, "emotional oranges");
    printf("looking for [jeremih]\n");
    find_artist(list, "jeremih");
    printf("looking for [death grips]\n");
    find_artist(list, "death grips");
    printf("\n====================================\n\n");

    //testing songcmp (helper function) not sure if this is necessary but its part of sample output

    //testing random

    printf("Testing remove:\n");
    printf("Removing [emotional oranges: someone else]\n");
    list = remove_node(list, "someone else", "emotional oranges");
    print_list(list);
    printf("Removing [kendrick lamar: dna]\n");
    list = remove_node(list, "dna", "kendrick lamar");
    print_list(list);
    printf("Removing [kendrick lamar: fear]\n");
    list = remove_node(list, "fear", "kendrick lamar");
    print_list(list);
    printf("Removing [tyler, the creator: boredom]\n");
    list = remove_node(list, "boredom", "tyler, the creator");
    print_list(list);
    printf("====================================\n\n");

    //testing free list 
    return 0;
}