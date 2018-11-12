#include<stdio.h>

int g(int);

int main() {
  int n;

  printf("number: ");
  scanf("%i", &n);
  printf("G(%d) = %d\n", n, g(n));

  return 0;
}

int g(int n) {
  if (n == 0) return 0;

  return n - g(g(n - 1));
}
