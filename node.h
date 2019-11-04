#ifndef NODE
#define NODE

struct node {
  char name[100];
  char artist[100];
  struct node * next;
};
#endif
