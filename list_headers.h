struct song_node {
    char name[100];
    char artist[100];
    struct song_node * next;
};

// eric
// Insert nodes at the front
struct song_node * insert_front(struct song_node * node, char * artist, char * name);

// matthew
// Compare two songs by artist first, then song
int songcmp(struct song_node * node1, struct song_node * node2, int show_print);

// matthew
// Insert nodes in order (alphabetical by Artist then by Song)
struct song_node * insert_order(struct song_node * node, char * artist, char * name);

// eric
// Print the entire list
void print_list(struct song_node * node);

// eric
// Print a single node
void print_node(struct song_node * node);

// matthew
// Find and return a pointer to a node based on artist and song name
struct song_node * find_node(struct song_node * node, char * artist, char * name);

// eric
// Find and return a pointer to the first song of an artist based on artist name
struct song_node * find_artist(struct song_node * node, char * artist, int show_print);

// matthew
// Return a pointer to random element in the list
struct song_node * random_node(struct song_node * node, int seed);

// eric
// Check info of a given node
int correct_info(struct song_node * node, char * artist, char * name);

// eric
// Remove a single specified node from the list
struct song_node * remove_node(struct song_node * node, char * artist, char * name);

// matthew
// Free the entire list
struct song_node * free_list(struct song_node * node);