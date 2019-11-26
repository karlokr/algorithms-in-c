#include <stdio.h>
#include <stdlib.h>

/* stack implementation with linked list */
static struct node {
  struct tree_node *node;
  struct node *next;
};

static struct node *head, *z, *t;

void stackinit() {
  head = (struct node *) malloc(sizeof *head);
  z = (struct node *) malloc(sizeof *z);
  head->next = z;
  z->next = z;
}

void push(struct tree_node *v) {
  t = (struct node *) malloc(sizeof *t);
  t->node = v; t->next = head->next;
  head->next = t;
}

struct tree_node *pop() {
  struct tree_node *x;
  t = head->next;
  head->next = t->next;
  x = t->node;
  free(t);
  return x;
}

int stackempty() {
  return head->next == z;
}

/* tree implementation */
static struct tree_node {
    char info;
    struct tree_node *l, *r;
};

struct tree_node *tree_x, *tree_z;
char c;

void treeinit() {
    tree_z = (struct tree_node *) malloc(sizeof *tree_z);
    tree_z->l = tree_z; tree_z->r = tree_z;
}

void visit(struct tree_node *t) {
    printf("%c ", t->info);
}

/* pre-order traversal */
void traverse(struct tree_node *t) {
    push(t);
    while (!stackempty()) {
        t = pop(); visit(t);
        if (t->r != tree_z) push(t->r);
        if (t->l != tree_z) push(t->l);
    }
}


int main() {
  treeinit();

  /* build the parse tree (postfix) */
  for (stackinit(); scanf("%1s", &c) != EOF;) {
      tree_x = (struct tree_node *) malloc(sizeof *tree_x);
      tree_x->info = c; tree_x->l = tree_z; tree_x->r = tree_z;
      if (c == '+' || c == '*') {
          tree_x->r = pop(); tree_x->l = pop();
      }
      push(tree_x);
  }

  struct tree_node *root = (struct tree_node *) malloc(sizeof *root);
  root->info = head->next->node->info;
  root->l = head->next->node->l;
  root->r = head->next->node->r;
  stackinit();
  traverse(root);

  return 0;
}
