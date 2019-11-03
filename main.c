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
    printf("Inserting at front: [emotional oranges: someone else]\n");
    list = insert_front(list, "someone else", "emotional oranges");
    printf("Inserting at front: [jeremih: oui]\n");
    list = insert_front(list, "oui", "jeremih");
    printf("Inserting at front: [kendrick lamar: dna]\n");
    list = insert_front(list, "dna", "kendrick lamar");    
    printf("Inserting at front: [tyler, the creator: boredom]\n");
    list = insert_front(list, "boredom", "tyler, the creator");
    printf("%s\n\n", divider);

    printf("Testing print_list:\n");
    print_list(list);
    printf("%s\n\n", divider);

    //========================================================================
    printf("Testing print_node:\n");
    print_node(list);
    printf("\n%s\n\n", divider);

    //========================================================================
    printf("Testing find_node:\n");
    char findingArtist[50] = "emotional oranges";
    char findingSong[50] = "someone else";
    printf("looking for [%s: %s]\n", findingArtist, findingSong);
    find_node(list, findingArtist, findingSong);

    strcpy(findingArtist, "thisIsNotAnArtist");
    strcpy(findingSong, "thisIsNotASong");
    printf("looking for [%s: %s]\n", findingArtist, findingSong);
    find_node(list, findingArtist, findingSong);

    strcpy(findingArtist, "kendrick lamar");
    strcpy(findingSong, "dna");
    printf("looking for [%s: %s]\n", findingArtist, findingSong);
    find_node(list, findingArtist, findingSong);
    printf("%s\n\n", divider);

    //========================================================================
    printf("Testing find_artist:\n");
    printf("looking for [emotional oranges]\n");
    find_artist(list, "emotional oranges");
    printf("looking for [jeremih]\n");
    find_artist(list, "jeremih");
    printf("looking for [death grips]\n");
    find_artist(list, "death grips");
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
    printf("%s\n\n", divider);

    //========================================================================
    printf("Testing free_list:\n");
    list = insert_front(list, "Baby Shark", "Pinkfong");
    list = insert_front(list, "humble", "Kendrick Lamar");
    print_list(list);
    list = free_list(list);


    
    printf("\n====================================\n");
    printf("MUSIC LIBRARY TESTS\n");
    printf("====================================\n\n");

    struct song_node * table[27];



    return 0;
}