#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_headers.h"

int main() {
    printf("LINKED LIST TESTS\n");
    printf("====================================\n\n");
    printf("Testing print_list:\n");
    struct song_node * list;
    list = insert_front(list, "DNA", "Kendrick Lamar");
    list = insert_front(list, "Someone Else", "Emotional Oranges");
    print_list(list);
    return 0;
}