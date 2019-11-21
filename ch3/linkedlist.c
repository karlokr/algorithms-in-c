#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

struct node {
  int key;
  struct node *next;
};

struct node *head, *z, *t;

void listinitialize() {
  head = (struct node *) malloc(sizeof *head);
  z = (struct node *) malloc(sizeof *z);
  head->next = z; z->next = z;
}

void deletenext() {
  t->next = t->next->next;
}

struct node *insertafter(int v, struct node *t) {
  struct node* x;
  x = (struct node *) malloc(sizeof *x);
  x->key = v;
  x->next = t->next;
  t->next = x;
  return x;
}

int main() {
  listinitialize();
  
  struct node *first = insertafter('A', head);
  struct node *second = insertafter('L', first);
  struct node *third = insertafter('I', second);
  struct node *fourth = insertafter('S', third);
  insertafter('T', fourth);
  
  t = first;
  while(t != t->next) {
    printf("%c ", t->key);
    t = t->next;
  }

  return 0;
}

