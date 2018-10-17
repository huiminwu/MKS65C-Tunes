#include <stdio.h>
#include "song_node.h"
#include "library.h"

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
    printf("looking for first [Elton John] (exists) \n");
    print_node(find_artist("Elton John", song1));
    printf("looking for first [The Beach Boys] (doesn't exist) \n");
    print_node(find_artist("The Beach Boys", song1));

    printf("%s", dashes);
    printf("Testing shuffle:\n");
    print_node(shuffle(song1));
    print_node(shuffle(song1));
    print_node(shuffle(song1));

    printf("%s", dashes);
    printf("Testing removing a song: \n");
    printf("removing [Carl Douglas, Kung Fu Fighting] (exists)\n");
    song1 = remove_song("Kung Fu Fighting", "Carl Douglas", song1);
    print_list(song1);
    printf("removing [Toto, Africa] (doesn't exist)\n");
    remove_song("Africa", "Toto", song1);
    print_list(song1);
    printf("remocing [Spandau Ballet, True] (exists) \n");
    remove_song("True", "Spandau Ballet", song1);
    print_list(song1);

    printf("%s", dashes);
    printf("Testing removing everything: \n");
    song1 = remove_all(song1);
    printf("List after freeing everything: \n");
    print_list(song1);

    insert_song("Heaven Is A Place On Earth", "Belinda Carlisle");
    insert_song("Boogie Wonderland", "Earth Wind Fire");
    insert_song("September", "Earth Wind Fire");
    insert_song("Material Girl", "Madonna");
    insert_song("Man In The Mirror", "Michael Jackson");
    printf("%s", dashes);
    printf("TESTING MUSIC LIB\n");
    
    printf("%s", dashes);
    printf("Testing print_library\n");
    print_lib();

    printf("%s", dashes);
    printf("Testing print_letter\n");
    print_entries_for_letter('B');
    print_entries_for_letter('M');
    print_entries_for_letter('A');

    printf("\n%s", dashes);
    printf("Testing find\n");
    print_node(find_song("Heaven Is A Place On Earth", "Belinda Carlisle"));
    print_node(find_song("Alive", "Pearl Jam"));
    
    printf("%s", dashes);
    printf("Testing find_artist\n");
    printf("Finding songs by Earth Wind Fire\n");
    print_songs_by_artist("Earth Wind Fire");
    printf("Finding songs by Bob Marley\n");
    print_songs_by_artist("Bob Marley");

    printf("%s", dashes);
    printf("Testing remove_song\n");

    return 0;
}
