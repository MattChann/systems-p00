struct song_node {
    char name[100];
    char artist[100];
    struct song_node * next;
};

struct song_node * insert_front(struct song_node * node, char * artist, char * name);

int songcmp(struct song_node * node1, struct song_node * node2); // helper function
struct song_node * insert_order(struct song_node * node, char * artist, char * name);

void print_list(struct song_node * node);

void print_node(struct song_node * node);

struct song_node * find_node(struct song_node * node, char * artist, char * name);

struct song_node * find_artist(struct song_node * node, char * artist);

struct song_node * random_node(struct song_node * node, int seed);

int correct_info(struct song_node * node, char * artist, char * name); // helper function
struct song_node * remove_node(struct song_node * node, char * artist, char * name);

struct song_node * free_list(struct song_node * node);