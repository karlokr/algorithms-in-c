#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next, *prev;
};

struct node *head, *z;

void listinitialize()
{
    head = (struct node *)malloc(sizeof *head);
    z = (struct node *)malloc(sizeof *z);
    head->next = z;
    head->prev = head;
    z->next = z;
    z->prev = head;
}

void deletenext(struct node *t)
{
    struct node *temp = malloc(sizeof *temp);
    temp->next = t->next->next;
    if (t->next != z)
    {
        free(t->next);
        t->next = temp->next;
        t->next->prev = t;
    }
    free(temp);
}

void deleteprevious(struct node *t)
{
    struct node *temp = malloc(sizeof *temp);
    temp->prev = t->prev->prev;
    if (t->prev != head)
    {
        free(t->prev);
        t->prev = temp->prev;
        t->prev->next = t;
    }
    free(temp);
}

struct node *insertafter(int v, struct node *t)
{
    struct node *x;
    x = (struct node *)malloc(sizeof *x);
    if (t != z)
    {
        x->key = v;
        x->next = t->next;
        t->next = x;
        x->prev = t;
        x->next->prev = x;
    }
    return x;
}

struct node *insertbefore(int v, struct node *t)
{
    struct node *x;
    x = (struct node *)malloc(sizeof *x);
    if (t != head)
    {
        x->key = v;
        x->next = t;
        x->prev = t->prev;
        t->prev = x;
        x->prev->next = x;
    }
    return x;
}

int main()
{
    struct node *t, *a, *b;
    listinitialize();

    t = insertafter('A', head);
    a = insertafter('L', t);
    t = insertafter('I', a);
    b = insertafter('S', t);
    t = insertafter('T', b);
    insertbefore('E', t);
    deletenext(head);
    deleteprevious(z);
    

    t = head->next;
    while (t != t->next)
    {
        printf("%c ", t->key);
        t = t->next;
    }

    return 0;
}
