# include <stdio.h>
# include <stdlib.h>
# include "node.h"
# include "music_library.h"
# include "linked_list.h"
# include <string.h>

int main() {

  printf("Testing Linked List\n========================\n");
  struct node * head = NULL;

  head = insert_in_order(head, "Thriller", "Michael Jackson");
  head = insert_in_order(head, "Rocket Man", "Elton John");
  head = insert_in_order(head, "Tiny Dancer", "Elton John");
  head = insert_in_order(head, "Time", "Pink Floyd");
  head = insert_in_order(head, "Stressed Out", "21 Pilots");
  head = insert_in_order(head, "Numb", "Linkin Park");

  printf("\nPrinting print_list: \n");
  print_list(head);

  printf("\nTesting print_node(helper) and return_song: (using Tiny Dancer by Elton John)\n");
  print_node(return_song(head, "Tiny Dancer", "Elton John"));

  printf("\nTesting return_first_of_artist: (using Elton John)\n");
  print_node(return_first_of_artist(head, "Elton John"));

  printf("\nTesting return_random:\n");
  print_node(return_random(head));

  printf("\nTesting remove_node (using Thriller by Michael Jackson and Time by Pink Floyd)");
  printf("\nPrinting list after removals: \n");
  head = remove_node(head, "Thriller", "Michael Jackson");
  head = remove_node(head, "Time", "Pink Floyd");
  print_list(head);

  printf("\nTesting free_list\nPrinting list after freeing:\n");
  head = free_list(head);
  print_list(head);

  printf("Testing Linked List\n========================\n");

  struct node * library[216];
  int i;
  for (i = 0; i < 27; i++)
    library[i] = 0;

  add_song(library, "Thriller", "Michael Jackson");
  add_song(library, "Beat It", "Michael Jackson");
  add_song(library, "Outro", "M83");
  add_song(library, "Rocket Man", "Elton John");
  add_song(library, "Tiny Dancer", "Elton John");
  add_song(library, "Stressed Out", "21 Pilots");

  printf("\nTesting print_library: \n");
  print_library(library);

  printf("\nTesting print_all_from_letter (using m):\n");
  print_all_from_letter(library, "m");

  printf("\nTesting song_from_library (using Tiny Dancer by Elton John):\n");
  print_node(song_from_library(library, "Tiny Dancer", "Elton John"));

  printf("\nTesting print_artist: (using Elton John) \n");
  print_artist(library, "Elton John");

  printf("\nTesting print_artist: (using Lil Pump) \n");
  print_artist(library, "Lil Punp");

  printf("\nTesting first_of_artist: \n");
  print_list(first_of_artist(library, "M83"));

  printf("\nTesting delete_song (using Gucci Gang by Lil Pump)\n");
  printf("Testing delete_song (Thriller by Michael Jackson)\n");
  printf("Printing list after removals: \n");
  print_library(library);

  printf("Testing shuffle: \n");
  shuffle(library);

  printf("\nTesting free_library: \n");
  free_library(library);
  printf("Printing list after freeing: \n");
  print_library(library);
}
