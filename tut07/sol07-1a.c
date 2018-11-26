#include <stdio.h>
#include <stdlib.h>

typedef struct element * list;
typedef struct element { int value; list next; } element;

list cons(int v, list l) {
  list l1 = malloc(sizeof(*l));
  l1->value = v; // (*l1).value = v;
  l1->next = l;
  return l1;
}

void printList(list l) {
  printf("[");
  while (l) {
    printf("%d", l->value);
    if (l->next) printf(", ");
    l = l->next;
  }
  printf("]\n");
}

int f(list l) {
  if (!l) return 1;

  int prev = l->value;
  while (l) {
    if (l->value - prev > 1 || l->value - prev < -1)
      return 0;
    prev = l->value;
    l = l->next;
  }

  return 1;
}

int main() {
  list l_true = cons(1, cons(2, cons(1, NULL)));
  list l_false = cons(1, cons(2, cons(4, NULL)));

  printf("l_true = ");
  printList(l_true);
  printf("f(l_true) = %d\n", f(l_true));

  printf("l_false = ");
  printList(l_false);
  printf("f(l_false) = %d\n", f(l_false));
}
