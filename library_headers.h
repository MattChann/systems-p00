// matthew
// Add song nodes
void * add_song(struct song_node * library, char * artist, char * name);

// eric
// Search for a song given song and artist name (return a pointer)
struct song_node * search_song(struct song_node * library, char * artist, char * name);

// matthew
// Search for an artist
struct song_node * search_artist(struct song_node * library, char * artist);

// eric
// Print out all the entries under a certain letter
void print_letter(struct song_node * library, char letter);

// matthew
// Print out all the songs of a certain artist
void print_artist(struct song_node * library);

// eric
// Print out the entire library
void print_library(struct song_node * library);

// matthew
// Shuffle - print out a series of randomly chosen songs
void shuffle(struct song_node * library);

// eric
// Delete a song
struct song_node * remove_song(struct song_node * library, char * artist, char * name);

// matthew
// Clear the library
struct song_node * clear(struct song_node * library);