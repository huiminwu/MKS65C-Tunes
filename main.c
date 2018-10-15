#include <stdio.h>
#include "song_node.h"

int main() {
    char * dashes = "===========================\n";
    struct song_node * song1 = NULL;
    song1 = insert("Kung Fu Fighting", "Carl Douglas", song1);
    print_list(song1);
    song1 = insert("Manic Monday", "The Bangles", song1);
    print_list(song1);
    song1 = insert("True", "Spandau Ballet", song1);
    print_list(song1);
    song1 = insert("Hotel California", "Eagles", song1);
    print_list(song1);
    song1 = insert("Take It Easy", "Eagles", song1);
    print_list(song1);
    song1 = insert("Rocket Man", "Elton John", song1);
    print_list(song1);
    song1 = insert("Tiny Dancer", "Elton John", song1); 
    printf("LINKED LIST TESTS \n%s \n", dashes);
    printf("Testing print_list: \n");
    printf("%s", dashes);
    print_list(song1);
    
    printf("%s", dashes);
    printf("Testing print_node:\n");
    print_node(song1);

    printf("%s", dashes);
    printf("Testing find node:\n");
    printf("looking for [Eagles: Hotel California] (exists)\n");
    print_node(find_node("Hotel California", "Eagles", song1));
    printf("looking for [Eagles: Take It To The Limit] (doesn't exist)\n");
    print_node(find_node("Take It To The Limit", "Eagles", song1));

    printf("%s", dashes);
    printf("Testing find artist:\n");
    printf("looking for [Elton John] (exists) \n");
    print_list(find_artist("Elton John", song1));
    printf("looking for [The Beach Boys] (doesn't exist) \n");
    print_list(find_artist("The Beach Boys", song1));

    printf("%s", dashes);
    printf("Testing shuffle:\n");
    print_node(shuffle());
    print_node(shuffle());
    print_node(shuffle());

    printf("%s", dashes);
    printf("Testing removing a song: \n");
    printf("removing [Carl Douglas, Kung Fu Fighting] (exists)\n");
    remove_song("Kung Fu Fighting", "Carl Douglas", song1);
    print_list(song1);
    printf("removing [Toto, Africa] (doesn't exist)\n");
    remove_song("Africa", "Toto", song1);
    print_list(song1);

    printf("%s", dashes);
    printf("Testing removing everything: \n");
    remove_all(song1);
    printf("List after freeing everything: \n");
    print_list(song1);

    return 0;
}
