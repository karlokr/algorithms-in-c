#include <stdlib.h>
#include <stdio.h>

static struct node {
  int key;
  struct node *next;
};

static struct node *head, *z, *t;

void queueinit() {
  head = (struct node *) malloc(sizeof *head);
  z = (struct node *) malloc(sizeof *z);
  head->next = z; z->next = z;
}

int queueempty() {
  return head->next == z;
}

void put(int v) {
  t = (struct node *) malloc(sizeof *t);
  t->key = v;
  t->next = head->next;
  head->next = t;
}

int get() {
  if (queueempty()) return 0;
  int x;
  t = head;
  while (t->next->next != z) {
    t = t->next;
  }

  x = t->next->key;
  free(t->next);
  t->next = z;
  return x;
}



int main() {
  queueinit();
  put(5);
  put(2);
  put(3);
  printf("%d ", get());
  printf("%d ", get()); 
  printf("%d ", get());
  printf("%d ", get());
  printf("%d ", get());

  return 0;
}
