# include "node.h"

int position_in_alpha(char artist[100]);

void add_song(struct node ** library, char newName[100], char newArtist[100]);

struct node * song_from_library(struct node ** library, char newName[100], char newArtist[100]);
struct node * first_of_artist(struct node ** library, char newArtist[100]);

void print_all_from_letter(struct node ** library, char * letter);
void print_artist(struct node ** library, char newArtist[100]);
void print_library(struct node ** library);
void shuffle(struct node ** library);

struct node * delete_song(struct node ** library, char newName[100], char newArtist[100]);
void free_library(struct node ** library);
