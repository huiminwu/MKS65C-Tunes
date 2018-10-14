struct song_node * lib[27];

int find_index(char * name);
//Add song nodes
void insert_song(char * song, char * artist);

//Search for a song given song and artist name (return pointer)
struct song_node * find_song(char * song, char * artist);

//Search for an artist
struct song_node * find_songs_by_artist(char * artist);

//Print out all entries under a certain letter
void print_entries_for_letter(char letter);

//Print all songs by artist
void print_songs_by_artist(char * artist);

//Print out the entire library
void print_lib();

//Shuffle - print out a series of randomly chosen songs
void shuffle_list();

//Delete a song
void remove_a_song(char * name, char * artist);

//Clear the library
void clear_lib();
