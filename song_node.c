#include <stdio.h>

struct song_node{ char name[100]; char artist[100]; struct song_node * next;};

struct song_node * insert_front(char name[100], char artist[100], song_node * front){
	struct song_node new_song;
	new_song.name = name;
	new_song.artist = artist;
	new_song.next = front;
	return &new_song;
}

struct song_node * insert(char name[100], char artist[100], song_node * front){
	while
}