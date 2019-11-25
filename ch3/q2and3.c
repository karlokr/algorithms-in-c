#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *next;
};

struct node *head, *z;

void listinitialize() {
  head = (struct node *) malloc(sizeof *head);
  z = (struct node *) malloc(sizeof *z);
  head->next = z; z->next = z;
}

void deletenext(struct node *t)
{
    struct node *temp = malloc(sizeof *temp);
    temp->key = t->next->key;
    temp->next = t->next->next;
    if (t->next != z)
    {
        free(t->next);
        t->next = temp->next;
        free(temp);
    }
}

struct node *insertafter(int v, struct node *t) {
  struct node* x;
  x = (struct node *) malloc(sizeof *x);
  x->key = v;
  x->next = t->next;
  t->next = x;
  return x;
}

/* q2 */
void movenexttofront(struct node *t) {
  struct node *x;
  x = t->next;
  t->next = x->next;
  x->next = head->next;
  head->next = x;
}

/* q3 */
void exchange(struct node *t, struct node *u) {
  struct node *t_previous = head->next;
  struct node *u_previous = head;
  struct node *temp;
  while (t_previous->next != t)
    t_previous = t_previous->next;  
  while (u_previous->next != u)
    u_previous = u_previous->next;

  t_previous->next = u;
  u_previous->next = t;
  temp = u->next;
  u->next = t->next;
  t->next = temp;

}


int main() {
  listinitialize();
  struct node *t; 
  struct node *a;
  struct node *b;
  t = insertafter('A', head);
  a = insertafter('L', t);
  t = insertafter('I', a);
  b = insertafter('S', t);
  insertafter('T', b);
  
  movenexttofront(b);
  exchange(a, b);
  deletenext(b);


  t = head->next;
  while(t != t->next) {
    printf("%c ", t->key);
    t = t->next;
  }

  return 0;
}

