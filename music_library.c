# include <stdio.h>
# include <stdlib.h>
# include "node.h"
# include "music_library.h"
# include "linked_list.h"
# include <string.h>
# include <time.h>

void shuffle(struct node ** library) {
  srand(time(NULL));
  struct node * temp;
  int i, songs;
  for (i = 0, songs = 0; i < 27; i++)
      songs += length_of_list(library[i]);

  for (i = 0; i < 27; i++)
    for (temp = library[i]; temp != NULL; temp = temp->next)
      if (rand() % songs > songs / 2)
        print_node(temp);
}

int position_in_alpha(char artist[100]) {
  char first = artist[0];
  if (first > 96 && first < 123) return first - 97;
  if (first > 64 && first < 91)  return first - 65;
  else return 26;
  }

void add_song(struct node ** library, char newName[100], char newArtist[100]) {
  int pos = position_in_alpha(newArtist);
  if (library[pos] == NULL)
    library[pos] = create_node(newName, newArtist);
  else
    library[pos] = insert_in_order(library[pos], newName, newArtist);
}

struct node * song_from_library(struct node ** library, char newName[100], char newArtist[100]) {
  return return_song(library[position_in_alpha(newArtist)], newName, newArtist);
}

void print_all_from_letter(struct node ** library, char * letter) {
  print_list(library[position_in_alpha(letter)]);
}

void print_library(struct node ** library) {
  int i;
  for (i = 0; i < 27; i += 1)
    if (library[i] != NULL) {
      if (i == 26) printf("non-alphabet list: \n");
      else         printf("%c list: \n", i + 65);
      print_list(library[i]);
      }
}

void free_library(struct node ** library) {
  int i;
  for (i = 0; i < 27; i += 1)
      library[i] = free_list(library[i]);
}

struct node * delete_song(struct node ** library, char newName[100], char newArtist[100]) {
  return remove_node(library[position_in_alpha(newArtist)], newName, newArtist);
}

void print_artist(struct node ** library, char newArtist[100]) {
  struct node * temp = library[position_in_alpha(newArtist)];
  for ( ; temp != NULL; temp = temp->next)
    if (strcmp(temp->artist, newArtist) == 0)
      printf("%s: %s\n", temp->name, temp->artist);
}

struct node * first_of_artist(struct node ** library, char newArtist[100]) {
  return return_first_of_artist(library[position_in_alpha(newArtist)], newArtist);
}
