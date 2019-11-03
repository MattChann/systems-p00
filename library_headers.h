// Add song nodes.
// matthew

// Search for a song given song and artist name (return a pointer).
//eric
struct song_node * find(struct song_node * library, char * artist, char * name);

// Search for an artist.
// matthew

// Print out all the entries under a certain letter.
//eric
void print_letter(struct song_node * library, char letter);

// Print out all the songs of a certain artist
// matthew

// Print out the entire library.
//eric
void print_library(struct song_node * library);


// Shuffle - print out a series of randomly chosen songs.
// matthew

// Delete a song
//eric
struct song_node * remove_song(struct song_node * library, char * artist, char * name);

// Clear the library.
// matthew
