struct song_node{ char name[100]; char artist[100]; struct song_node * next;};

struct song_node * insert_front(char name[100], char artist[100], song_node * front);

void song_node * insert(char name[100], char artist[100], song_node * front);

void print_all(struct song_node *);

char * find_node(char name[100], char artist[100]);

char * find_artist(char artist[100]);

struct song_node * shuffle();

void remove(char name[100], char artist[100]);

void remove_all();