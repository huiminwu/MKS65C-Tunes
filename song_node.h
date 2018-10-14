struct song_node{ char name[100]; char artist[100]; struct song_node * next;};

struct song_node * insert_front(char name[100], char artist[100], song_node * front);

void song_node * insert(char name[100], char artist[100], song_node * front);

void print_list(struct song_node *);

void print_node(struct song_node * song);

char * find_node(char name[100], char artist[100], struct song_node * front);

char * find_artist(char artist[100], struct song_node * front);

struct song_node * shuffle();

void remove_song(char name[100], char artist[100], struct song_node * front);

void remove_all(struct song_node * front);