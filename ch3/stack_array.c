#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

static int stack[MAX + 1], p;

void push(int v) {
  stack[p++] = v;
}

int pop() {
  return stack[--p];
}

void stackinit() {
  p = 0;
}

int stackempty() {
  return !p;
}

