#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int key[MAX + 2], next[MAX + 2];
int x, head, z;

void listinitialize() {
  head = 0; z = 1; x = 2;
  next[head] = z; next[z] = z;
}

void deletenext(int t) {
  next[t] = next[next[t]];
}

int insertafter(int v, int t) {
  key[x] = v;
  next[x] = next[t];
  next[t] = x;
  return x++;
}

int main() {
  listinitialize();

  insertafter('A', 0);
  insertafter('L', 2);
  insertafter('I', 3);
  insertafter('S', 4);
  insertafter('T', 5); 

  for (int i = 0; i < 5 + 2; i++){
    int previous = 0;
    for (int j = 0; j < i; j++)
      previous = next[previous];
    printf("%c ", key[next[previous]]);    
  }

  return 0;
}

