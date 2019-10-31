struct song_node {
    char name[100];
    char artist[100];
    struct song_node * next;
};

struct song_node * insert_front(struct song_node * node, char * name, char * artist);

//insert_order header 

void print_list(struct song_node * node);

//find and return a pointer to a node based on artist and song name 

struct song_node * first_song_of(char * artist);

// return a pointer to random element in the list 

struct song_node * remove_node(struct song_node * node, char * name, char * artist);

// free the entire list 
