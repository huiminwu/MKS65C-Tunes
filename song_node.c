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
	char * rtrnStr = malloc(sizeof(char) * 200);
	while(front){
		if(strcmp(name, front->name) == 0 && strcmp(artist, front->artist) == 0){
			strcat(rtrnStr, name);
			strcat(rtrnStr, ": ");
			strcat(rtrnStr, artist);
			return rtrnStr;
		}
	}
	strcat(rtrnStr, "node not found");
	return rtrnStr;
}

struct song_node * find_artist(char artist[100], struct song_node * front){
	while(front){
		if(strcmp(artist, front->artist) == 0){
			return front;
		}
	}
	return front;
}

struct song_node * shuffle(struct song_node * front){
	int length = 0;
	struct song_node * curr = front;
	while(curr){
		curr = curr->next;
		length++;
	}

	int select = length * rand() / RAND_MAX;
	while(select > 0){
		front = front->next;
	}

	return front;
}

int remove_song(char name[100], char artist[100], struct song_node * front){
	while(front){
		if(strcmp(name, front->next->name) == 0 && strcmp(artist, front->next->artist) == 0){
			struct song_node * tempptr = front->next->next;
			free(front->next);
			front->next = tempptr;
			return 1;
		}
	}
	return 0;
}

void remove_all(struct song_node * front){
	int len = 0;
	struct song_node * curr = front;
	while(curr){
		curr = curr->next;
		len++;
	}

	struct song_node * nodeptrs[len];
	curr = front;
	while(curr){
		nodeptrs[len-1] = curr;
		len--;
		curr = curr->next;
	}

	int i;
	for(i = 0; i < sizeof(nodeptrs) / 8; i++){
		free(nodeptrs[i]);
	}
}
