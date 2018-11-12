#include<stdio.h>

int f(int); // forward-declaration mandatory
int m(int);

int main() {
  int n;

  printf("number: ");
  scanf("%i", &n);
  printf("F(%d) = %d\n", n, f(n));
  printf("M(%d) = %d\n", n, m(n));

  return 0;
}

int f(int n) {
  if (n == 0) return 1;

  return n - m(f(n - 1));
}

int m(int n) {
  if (n == 0) return 0;

  return n - f(m(n - 1));
}
