# include "node.h"

void print_list(struct node * node);
void print_node(struct node * node);
int length_of_list(struct node * node);

struct node * create_node(char newName[100], char newArtist[100]);
struct node * insert_front(struct node * node, char newName[100], char newArtist[100]);
struct node * insert_in_order(struct node * node, char newName[100], char newArtist[100]);

struct node * return_song(struct node * node, char newName[100], char newArtist[100]);
struct node * return_first_of_artist(struct node * node, char newArtist[100]);
struct node * return_song_by_number(struct node * node, int number);
struct node * return_random(struct node * node);

struct node * remove_node(struct node * front, char newName[100], char newArtist[100]);
struct node * free_list(struct node * head);
