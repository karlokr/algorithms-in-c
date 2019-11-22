#include <stdlib.h>
#include <stdio.h>
#define MAX 1000

static int queue[MAX + 1], head, tail;

void put(int v) {
  queue[tail++] = v;
  if (tail > max) tail = 0;
}

int get() {
  int t = queue[head++];
  if (head > max) head = 0;
  return t;
}

queueinit() {
  head = 0; tail = 0;
}

int queueempty() {
  return head == tail;
}
