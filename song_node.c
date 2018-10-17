#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct song_node{ char name[100]; char artist[100]; struct song_node * next;};

struct song_node * insert_front(char name[100], char artist[100], struct song_node * front){
	struct song_node * new_song = malloc(sizeof(struct song_node));
	strcpy(new_song->name, name);
	strcpy(new_song->artist, artist);
	new_song->next = front;
	return new_song;
}

int song_comp(struct song_node * first, struct song_node * second){
	if(strcmp(first->artist, second->artist) < 0){
		return -1;
	}else if(strcmp(first->artist, second->artist) > 0){
		return 1;
	}else{
		if(strcmp(first->name, second->name) < 0){
			return -1;
		}else if(strcmp(first->name, second->name) > 0){
			return 1;
		}else{
			return 1;
		}
	}
}

struct song_node * insert(char name[100], char artist[100], struct song_node * front){
	if(!front){
		return insert_front(name, artist, front);
	}else if(!(front->next)){ //if there isn't a second song,
		struct song_node * new_song = malloc(sizeof(struct song_node));
		strcpy(new_song->name, name);
		strcpy(new_song->artist, artist);
		if(song_comp(new_song, front) < 0){ //if the second song takes precedent over first,
			return insert_front(name, artist, front);
		}else{
			front->next = new_song;
			new_song->next = NULL;
			return front;
		}
	}else{
		struct song_node * new_song = malloc(sizeof(struct song_node));
		strcpy(new_song->name, name);
		strcpy(new_song->artist, artist);
		struct song_node * curr = front;
		while(curr->next && song_comp(new_song, curr->next) > 0){ //while there is a next node and the song next to the current takes precedence,
			curr = curr->next;
		}

		if(curr->next){
			new_song->next = curr->next;
			curr->next = new_song;
		}else{
			curr->next = new_song;
			new_song->next = NULL;
		}

		return front;
	}
}

void print_list(struct song_node * front){
	while(front){
		printf("%s: %s | ", front->artist, front->name);
		front = front->next;
	}
	printf("\n");
}

void print_node(struct song_node * song){
	if(song->name){
		printf("%s: %s\n", song->artist, song->name);
	}else{
		printf("NULL\n");
	}
}

struct song_node * find_node(char name[100], char artist[100], struct song_node * front){
	while(front){
		if(strcmp(name, front->name) == 0 && strcmp(artist, front->artist) == 0){
			return front;
		}
		front = front->next;
	}
	return front;
}

struct song_node * find_artist(char artist[100], struct song_node * front){
	while(front){
		if(strcmp(artist, front->artist) == 0){
			return front;
		}
		front = front->next;
	}
    if(!front) {
        printf("NULL");
    }
	return front;
}

struct song_node * shuffle(struct song_node * front){
    int len = 0;
	struct song_node * curr = front;
	while(curr){
		curr = curr->next;
		len++;
	}
    srand(time(NULL));
    int select = len * ((float)rand() / RAND_MAX);
	while(select > 0){
	    front = front->next;
	    select--;
	}

	return front;
}

struct song_node * remove_song(char name[100], char artist[100], struct song_node * front){
	if(strcmp(name, front->name) == 0 && strcmp(artist, front->artist) == 0){
        struct song_node * newFront = front->next;
        free(front);
        return newFront;
    } else {
        while(front->next) {
            struct song_node * after = front->next;
            if (strcmp(name, after->name) == 0 && strcmp(artist, after->artist) == 0) {
                front->next = after->next; //skip the matching node
                free(after);
            } else {
                front = after; //increment
            }
        }
        return front;
	}
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
