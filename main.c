#include <stdio.h>
#include "song_node.h"

int main() {
    struct song_node * song1 = NULL;
    song1 = insert_front("Kung Fu Fighting", "Carl Douglas", song1);
    insert("Manic Monday", "The Bangles", song1);
    insert("True", "Spandau Ballet", song1);
    insert("Hotel California", "Eagles", song1);
    insert("Take It Easy", "Eagles", song1);
    printf("LINKED LIST TESTS \n====================================\n");
    printf("Testing print_list: \n");
    print_list(song1);
    return 0;
}