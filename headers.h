struct node {
  char name[100];
  char artist[100];
  struct node * next;
};


void print_list(struct node * node);



struct node * create_node(char newName[100], char newArtist[100]);
struct node * insert_front(struct node * node, char newName[100], char newArtist[100]);
struct node * insert_in_order(struct node * node, char newName[100], char newArtist[100]);

struct node * return_song(struct node * node, char newName[100], char newArtist[100]);
struct node * return_first_of_artist(struct node * node, char newArtist[100]);
struct node * return_song_by_number(struct node * node, int number);
struct node * return_random(struct node * node);

struct node * remove_node(struct node * front, char newName[100], char newArtist[100]);
struct node * free_list(struct node * head);





int position_in_alpha(char artist[100]);
int length_of_list(struct node * node);


void add_song(struct node ** library, char newName[100], char newArtist[100]);
struct node * song_from_library(struct node ** library, char newName[100], char newArtist[100]);
int find_artist(struct node ** library, char newArtist[100]);
void print_all_from_letter(struct node ** library, char * letter);
void print_artist(struct node ** library, char newArtist[100]);
void print_library(struct node ** library);
void shuffle(struct node ** library); 
struct node * delete_song(struct node ** library, char newName[100], char newArtist[100]);
void free_library(struct node ** library);
