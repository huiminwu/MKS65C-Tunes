struct song_node{ char name[100]; char artist[100]; struct song_node * next;};

struct song_node * insert_front(char name[100], char artist[100], struct song_node * front);

struct song_node * insert(char name[100], char artist[100], struct song_node * front);

//struct song_node * insert(char name[100], char artist[100], struct song_node * front, struct song_node * curr);

void print_list(struct song_node * front);

void print_node(struct song_node * song);

struct song_node * find_node(char name[100], char artist[100], struct song_node * front);

struct song_node * find_artist(char artist[100], struct song_node * front);

struct song_node * shuffle();

struct song_node * remove_song(char name[100], char artist[100], struct song_node * front);

struct song_node * remove_all(struct song_node * front);
