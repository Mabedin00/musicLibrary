# include <stdio.h>
# include <stdlib.h>
# include "headers.h"
# include <string.h>

int main() {

  // struct node * head = NULL;
  //
  char name[100] = "Thriller";
  char artist[100] = "Michael Jackson";
  // printf("Insert Thriller by Michael Jackson\n");
  // head = insert_in_order(head, name, artist);
  //
  // strcpy(name, "Rocket Man");
  // strcpy(artist, "Elton John");
  // printf("Insert Rocket Man by Elton John\n");
  // head = insert_in_order(head, name, artist);
  //
  // strcpy(name, "Tiny Dancer");
  // strcpy(artist, "Elton John");
  // printf("Insert Tiny Dancer by Elton John\n");
  // head = insert_in_order(head, name, artist);
  //
  // strcpy(name, "Time");
  // strcpy(artist, "Pink Floyd");
  // printf("Insert Time by Pink Floyd\n");
  // head = insert_in_order(head, name, artist);
  //
  // strcpy(name, "Stressed Out");
  // strcpy(artist, "21 Pilots");
  // printf("Insert Stressed Out by 21 Pilots\n");
  // head = insert_in_order(head, name, artist);
  //
  // strcpy(name, "Numb");
  // strcpy(artist, "Linkin Park");
  // printf("Insert Numb by Linkin Park\n");
  // head = insert_in_order(head, name, artist);

  // printf("\n");
  // print_list(head);
  //
  // strcpy(name, "Stressed Out");
  // strcpy(artist, "21 Pilots");
  // printf("Removing Stressed Out by 21 Pilots\n");
  // head = remove_node(head, name, artist);
  //
  // print_list(head);
  //
  // strcpy(name, "Numb");
  // strcpy(artist, "Linkin Park");
  // printf("Removing Numb by Linkin Park\n");
  // head = remove_node(head, name, artist);
  //
  // print_list(head);
  //
  // strcpy(name, "Tiny Dancer");
  // strcpy(artist, "Elton John");
  // printf("Printing Tiny Dancer by Elton John and following elements\n");
  //
  // print_list(return_song(head, name, artist));
  //
  // strcpy(artist, "Michael Jackson");
  // printf("Printing first song by Michael Jackson\n");
  //
  // print_list(return_first_of_artist(head, artist));
  //
  // printf("Printing random node and following nodes\n");
  // print_list(return_random(head));
  //
  // printf("Freeing list\n");
  // head = free_list(head);

  printf("Testing Lib Functions\n\n");
  struct node * library[216];

  int i;
  for (i = 0; i < 27; i++) {
    library[i] = 0;
  }
  printf("%p\n", library);
  add_song(library, name, artist);

  printf("%s\n", library[12]->artist);

  char name2[100] = "Beat It";
  char artist2[100] = "Michael Jackson";

  add_song(library, name2, artist2);

  print_list(library[12]);

  print_list(song_from_library(library, name, artist));

  print_all_from_letter(library, "m");

  print_library(library);

  // printf("Freeing library\n");
  // free_library(library);

  // print_library(library);

  // delete_song(library, name, artist);

  print_library(library);

  char name3[100] = "Elton John";

  find_artist(library, name3);

  char artist3[100] = "Elton John";
  char name4[100] = "Tiny Dancer";

  add_song(library, name4, artist3);

  printf("printing artist\n");
  print_artist(library, artist2);

  shuffle(library);
}
