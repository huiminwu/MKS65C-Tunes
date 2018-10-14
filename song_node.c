#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song_node{ char name[100]; char artist[100]; struct song_node * next;};

struct song_node * insert_front(char name[100], char artist[100], struct song_node * front){
	struct song_node * new_song = malloc(sizeof(struct song_node));
	strcpy(new_song->name, name);
	strcpy(new_song->artist, artist);
	new_song->next = front;
	return new_song;
}

void insert(char name[100], char artist[100], struct song_node * front){
	struct song_node * new_song = malloc(sizeof(struct song_node));
	strcpy(new_song->name, name);
	strcpy(new_song->artist, artist);
	while(strcmp(new_song->artist, front->next->artist) > 0){
		front = front->next;
	}
	while(strcmp(new_song->name, front->next->name) > 0){
		front = front->next;
	}
	new_song->next = front->next;
	front->next = new_song;
}

void print_list(struct song_node * front){
	while(front){
		printf("%s: %s | ", front->artist, front->name);
		front = front->next;
	}
	printf("\n");
}

void print_node(struct song_node * song){
	printf("%s: %s\n", song->artist, song->name);
}

char * find_node(char name[100], char artist[100], struct song_node * front){
	while(front){
		if(strcmp(name, front->name) == 0 && strcmp(artist, front->artist) == 0){
			
		}
	}

}