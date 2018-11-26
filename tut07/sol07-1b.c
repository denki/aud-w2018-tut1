#include <stdio.h>
#include <stdlib.h>

typedef struct node * tree;
typedef struct node { int key; tree left, right; } node;

tree cons(int v, tree left, tree right) {
  tree res = malloc(sizeof(node));
  res->key = v;
  res->left = left;
  res->right = right;

  return res;
}

void print_tree(tree t) {
  if (!t) {
    printf("NULL");
  } else {
    printf("%d(", t->key);
    print_tree(t->left);
    printf(", ");
    print_tree(t->right);
    printf(")");
  }
}

void defol(tree* t) {
  if (!t || !*t) return;

  if (!(*t)->left && !(*t)->right) {
    free(*t);
    *t = NULL;
  } else {
    defol(&(*t)->left);
    defol(&(*t)->right);
  }
}

int main() {
  tree s = cons(2,
                  cons(3,
                         cons(2, NULL, NULL),
                         cons(4, NULL, NULL)
                         ),
                  cons(1, NULL, NULL)
                  );

  print_tree(s); printf("\n");
  defol(&s);
  print_tree(s); printf("\n");

  return 0;
}
