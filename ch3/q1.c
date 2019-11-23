#include <stdio.h>
#include <stddef.h>
#define N 5
#define M 5

int gcd(int u, int v) {
  int t;
  if (u > v) { t = u; u = v; v = t; }
  while (u > 0) {
    if (u < v) {
      t = u; u = v; v = t % u;
    }
    u = u - v;
  }
  return v;
}

int main(void) {
  int array[N][M];
  size_t i, j;

  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
      array[i][j] = gcd(i, j) == 1;

  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
      printf("i = %d, j = %d, gcd = %d, array[i][j] = %d\n", i, j, gcd(i, j), array[i][j]);

  return 0;
}
