#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree;
typedef struct node { int key; tree left, right; } node;

tree cons(int v, tree left, tree right) {
  tree t = malloc(sizeof(node));
  t->key = v;
  t->left = left;
  t->right = right;

  return t;
}

void print_tree(tree t) {
  if (!t)
    printf("NULL");
  else {
    printf("%d(", t->key);
    print_tree(t->left);
    printf(", ");
    print_tree(t->right);
    printf(")");
  }
}

int count_value(tree t, int v) {
  if (!t) return 0;
  return (t->key == v) + count_value(t->left, v) + count_value(t->right, v);
}

tree baz(tree s, tree t) {
  if (!s) return NULL;

  // tree s1 = cons(count_value(t, s->key), baz(s->left, t), baz(s->right, t));
  tree s1 = malloc(sizeof(node));
  s1->key = count_value(t, s->key);
  s1->left = baz(s->left, t);
  s1->right = baz(s->right, t);

  return s1;
}

int leafprod(tree t) {
  if (!t) return 1;
  if (!t->left && !t->right) return t->key;
  return leafprod(t->left) * leafprod(t->right);
}

int main() {
  tree s = cons(2,
                cons(3,
                     cons(2, NULL, NULL),
                     cons(4, NULL, NULL)
                     ),
                cons(1, NULL, NULL)
                );
  tree t = cons(2,
                cons(2, NULL, NULL),
                cons(3, NULL, NULL)
                );

  print_tree(s); printf("\n");
  printf("count_value(t, 2) = %d\n", count_value(t, 2));
  print_tree(baz(s, t)); printf("\n");
  printf("leafprod(s) = %d\n", leafprod(s));
  return 0;
}
