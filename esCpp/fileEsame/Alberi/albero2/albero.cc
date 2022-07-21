#include <iostream>
#include "albero.h"

using namespace std;

bool empty(tree &t) {
  return t == NULL ? true:false;
}

void init(tree &t) {
  t = new node;
  t = nullptr;
}

bool push(tree &t, int newElement) {
  tree newNode = new node{newElement, NULL, NULL};
  
  if (t == nullptr) {
    t = newNode;
    return true;
  }

  if (t->value > newElement) {
    push(t->nextLeft, newElement);
  }

  if (t->value < newElement) {
    push(t->nextRight, newElement);
  }

  return false;
}

bool search(tree &t, int element) {
  if (t == nullptr) {
    return false;
  }

  if (t->value == element) {
    return true;
  }

  if (t->value > element) {
    cout << " " << t->value << ", " << "sinistra";
    search(t->nextLeft, element);
  }

  if (t->value < element) {
    cout << t->value << ", " << "destra";
    search(t->nextRight, element);
  }
  
  return false;
}

void print(tree t) {
  if (t == nullptr) {
    return;
  }
  print(t->nextLeft);
  cout << t->value << " ";
  print(t->nextRight);
}
