struct song_node{ char name[100]; char artist[100]; struct song_node * next;};

struct song_node * insert_front(char name[100], char artist[100]);

struct song_node * insert(char name[100], char artist[100]);

void print_all();

struct song_node * find(char name[100], char artist[100]);

struct song_node * find_first(char artist[100]);

struct song_node * shuffle();

void remove(char name[100], char artist[100]);

void remove_all();