struct song_node {
    char name[100];
    char artist[100];
    struct song_node * next;
};

//eric
struct song_node * insert_front(struct song_node * node, char * artist, char * name);

//matthew
int songcmp(struct song_node * node1, struct song_node * node2); // helper function
struct song_node * insert_order(struct song_node * node, char * artist, char * name);

//eric
void print_list(struct song_node * node);

//eric
void print_node(struct song_node * node);

//matthew
struct song_node * find_node(struct song_node * node, char * artist, char * name);

//eric
struct song_node * find_artist(struct song_node * node, char * artist);

//matthew
struct song_node * random_node(struct song_node * node, int seed);

//eric
int correct_info(struct song_node * node, char * artist, char * name); // helper function
struct song_node * remove_node(struct song_node * node, char * artist, char * name);

//matthew
struct song_node * free_list(struct song_node * node);