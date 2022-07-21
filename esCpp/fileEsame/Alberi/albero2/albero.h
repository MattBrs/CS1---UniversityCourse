#ifndef ALBERO_H
#define ALBERO_H

struct node;
typedef node* tree;
struct node {
  int value;
  node* nextRight;
  node* nextLeft;
};

bool empty(tree &t);
void init(tree &t);
bool push(tree &t, int newElement);
void print(tree t);
bool search(tree &t, int element);

#endif
