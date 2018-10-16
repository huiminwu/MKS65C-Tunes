#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"
#include "song_node.h"

int find_index(char * name) {
    int ascii_val;
    ascii_val = name[0];
    return ascii_val - 65;
}

void insert_song(char * song, char * artist) {
    int index = find_index(artist);
    lib[index] = insert(song, artist, lib[index]);
}

struct song_node * find_song(char * song, char * artist) {
    printf("Finding %s by %s: ", song, artist);
    int index = find_index(artist);
    return find_node(song, artist, lib[index]);
}

struct song_node * find_songs_by_artist(char * artist) {
    int index = find_index(artist);
    return find_artist(artist, lib[index]); //prints the songs of the artist searched for
}

void print_entries_for_letter(char letter) {
    char * l = &letter;
    int index = find_index(l);
    printf("%c list: ", letter);
    if (lib[index]) {
        print_list(lib[index]);
    } else {
        printf("Nothing in there yet!");
    }
}

void print_songs_by_artist(char * artist) {
    print_list(find_songs_by_artist(artist));
}

void print_lib() {
    int i = 0;
    for(; i < 26; i++) {
        if(lib[i]){
            printf("%c list: ", i+65);
            print_list(lib[i]);
        }
    }
}

void shuffle_list() {
    srand(time(NULL));
    int i = 0;
    for (; i < 5; i++) {
        struct song_node * song = shuffle(lib[rand() % 27]);
        print_node(song);
    }
}

void remove_a_song(char * name, char * artist) {
    int index = find_index(artist);
    remove_song(name, artist, lib[index]);
    print_lib();
}

void clear_lib(){
    int i = 0;
    for(; i < 27; i++) {
        remove_all(lib[i]);
    }
}
