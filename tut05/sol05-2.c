#include<stdio.h>

void swap(int*, int*);
void swapCool(int*, int*);

int main() {
  int i = 1, j = 2;

  printf("(i, j) = (%d, %d)\n", i, j);
  printf("&i = %i\n", &i);
  printf("swapping\n");
  swapCool(&i, &j);
  printf("&i = %i\n", &i);
  printf("(i, j) = (%d, %d)\n", i, j);

  return 0;
}

void swap(int* i, int* j) {
  int h = *i;
  *i = *j;
  *j = h;
}

void swapCool(int* i, int* j) {
  *i = *i ^ *j;
  *j = *i ^ *j;
  *i = *j ^ *i;
}
