#include<stdio.h>

int main() {
  int n;

  printf("Bitte Zahl eingeben: ");
  scanf("%i", &n);
  printf("\n");

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      printf("%i\t", i * j);
    printf("\n");
  }

  return 0;
}
