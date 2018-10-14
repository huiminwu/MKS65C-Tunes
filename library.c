#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "song_node.h"

int findIndex(char * name) {
    int asciiVal;
    asciiVal = name[0];
    return asciiVal - 65;
}

void insert_song(char * song, char * artist) {
    int index = findIndex(song);
    
}

