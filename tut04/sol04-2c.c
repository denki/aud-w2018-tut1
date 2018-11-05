#include<stdio.h>

#define LEN 101

int main() {
  unsigned int sieve[LEN];

  sieve[0] = 1;
  sieve[1] = 1;

  for (int i = 2; i <= LEN - 1; ++i)
    sieve[i] = 0;

  for (int i = 2; i <= LEN - 1; ++i)
    if (sieve[i] == 0) {
      printf("%u ", i);
      for (int j = 2 * i; j <= LEN; j = j + i)
        sieve[j] = 1;
    }

  printf("\n");

  return 0;
}
