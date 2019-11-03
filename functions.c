# include <stdio.h>
# include <stdlib.h>
# include "headers.h"
# include <string.h>
# include <time.h>
# include <ctype.h>

struct node * create_node(char newName[100], char newArtist[100] ) {
  struct node * head = calloc(208, 1);
  strcpy(head->name, newName);
  strcpy(head->artist, newArtist);
  head->next = NULL;
  return head;
}

void print_list(struct node * node) {
  printf("LinkedList:\n");
  for ( ; node != NULL; node = node->next)
    printf("Name: %s, Artist: %s\n", node->name, node->artist);
  printf("\n\n");
}

struct node * insert_front(struct node * node, char newName[100], char newArtist[100]) {
  struct node * newHead = create_node(newName, newArtist);
  newHead->next = node;
  return newHead;
}

struct node * free_list(struct node * head) {
  if (head != NULL) {
    free_list(head->next);
    free(head);
  }
  else
    return head;
}

struct node * remove_node(struct node * front, char newName[100], char newArtist[100]) {

  if (strcmp(front->name, newName) == 0 && strcmp(front->artist, newArtist) == 0) {
    struct node * returnNode = front->next;
    free(front);
    return returnNode;
  }
  struct node * node = front;
  for ( ; node->next != NULL; node = node->next) {
    if (strcmp(node->next->name, newName) == 0 && strcmp(node->next->artist, newArtist) == 0) {
      struct node * nodeToFree = node->next;
      node->next = node->next->next;
      free(nodeToFree);
      return front;
    }
  }
  return front;

}

struct node * insert_in_order(struct node * node, char newName[100], char newArtist[100]) {
  if (node == NULL) return insert_front(node, newName, newArtist);

  if (node->next == NULL
    ||
      (strcmp(node->next->artist, newArtist) >= 0
    && strcmp(node->next->name, newName) >= 0))
    return insert_front(node, newName, newArtist);


  struct node * head = node;
  for ( ; ; node = node->next) {

    if (
      node->next == NULL
      ||
        strcmp(node->next->artist, newArtist) > 0
    || (strcmp(node->next->artist, newArtist) == 0 && strcmp(node->next->name, newName) >= 0)) {

      struct node * new = create_node(newName, newArtist);
      new->next = node->next;
      node->next = new;
      return head;

    }
  }
  return head;
}

struct node * return_song(struct node * node, char newName[100], char newArtist[100]) {
  for ( ; node != NULL; node = node->next)
    if (strcmp(node->name, newName) == 0 && strcmp(node->artist, newArtist) == 0)
      return node;
}

struct node * return_first_of_artist(struct node * node, char newArtist[100]) {
  for ( ; node != NULL; node = node->next)
    if (strcmp(node->artist, newArtist) == 0)
      return node;
}

int length_of_list(struct node * node){
  int length;
  for (length = 0; node != NULL; node = node->next, length += 1) {}
  return length;
}

struct node * return_song_by_number(struct node * node, int number){
  int counter;
  for (counter = 0; counter != number; node = node->next, counter++){}
  return node;
}

struct node * return_random(struct node * node) {
  srand(time(NULL));
  int length = length_of_list(node);
  int desiredNode = rand() % length;
  return return_song_by_number(node, desiredNode);
}

// -------------------------------------------------------------

void shuffle(struct node ** library) {
  srand(time(NULL));
  int i, songs;
  float chance;
  for (i = 0, songs = 0; i < 27; i++)
      songs += length_of_list(library[i]);

  for (i = 0; i < 27; i++) {
    struct node * temp = library[i];
    for ( ; temp != NULL; temp = temp->next) {
      if (rand() % songs > songs / 2) {
        printf("%s: %s\n", temp->name, temp->artist);
      }
    }
  }
}

int position_in_alpha(char artist[100]) {
  char first = artist[0];
  if (first > 96 && first < 123) return first - 97;
  if (first > 64 && first < 91)  return first - 65;
  else return 27;
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
    if (library[i] != NULL)
      print_list(library[i]);
}

void free_library(struct node ** library) {
  int i;
  for (i = 0; i < 27; i += 1)
      library[i] = free_list(library[i]);
}

struct node * delete_song(struct node ** library, char newName[100], char newArtist[100]) {
  return remove_node(library[position_in_alpha(newArtist)], newName, newArtist);
}

int find_artist(struct node ** library, char newArtist[100]) {
  struct node * temp = library[position_in_alpha(newArtist)];
  for ( ; temp != NULL; temp = temp->next) {
    if (strcmp(temp->artist, newArtist) == 0) {
      print_list(temp);
      return 0;
    }
  }
  printf("Artist not found\n");
  return 1;
}

void print_artist(struct node ** library, char newArtist[100]) {
  struct node * temp = library[position_in_alpha(newArtist)];
  for ( ; temp != NULL; temp = temp->next)
    if (strcmp(temp->artist, newArtist) == 0)
      printf("%s: %s\n", temp->name, temp->artist);
}
