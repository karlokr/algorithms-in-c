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
  
  t = insertafter('A', head);
  t = insertafter('L', t);
  t = insertafter('I', t);
  t = insertafter('S', t);
  insertafter('T', t);
  
  t = head;
  while(t != t->next) {
    printf("%c ", t->key);
    t = t->next;
  }

  return 0;
}

