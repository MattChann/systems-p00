struct song_node * add_song(struct song_node * library, char * artist, char * name);

struct song_node * search_song(struct song_node * library, char * artist, char * name);

struct song_node * search_artist(struct song_node * library, char * artist);

void print_letter(struct song_node * library, char letter);

void print_artist(struct song_node * library);

void print_library(struct song_node * library);

void shuffle(struct song_node * library);

struct song_node * remove_song(struct song_node * library, char * artist, char * name);

struct song_node * clear(struct song_node * library);