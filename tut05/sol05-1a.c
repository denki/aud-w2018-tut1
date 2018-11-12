#include<stdio.h>

int fib_naive(int);
int fib_it(int);
int fib_rec(int);

int main() {
  int n;

  printf("number: ");
  scanf("%i", &n);
  printf("fib(%d) = %d\n", n, fib_rec(n));

  return 0;
}

int fib_naive(int n) {
  if (n <= 1) return n;

  return fib(n - 2) + fib(n - 1);
}

int fib_it(int n) {
  int x = 0, y = 1, h;

  while (n > 1) {
    h = x + y;
    x = y;
    y = h;
    --n;
  }

  if (n == 0) return x;
  if (n == 1) return y;
}

int fib_rec3(int x, int y, int n) {
  if (n == 0) return x;
  if (n == 1) return y;

  fib_rec3(y, x + y, n - 1);
}

int fib_rec(int n) {
  return fib_rec3(0, 1, n);
}
