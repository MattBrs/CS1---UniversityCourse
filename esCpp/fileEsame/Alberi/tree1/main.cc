#include <iostream>
#include <cstdlib>

using namespace std;

struct node;
typedef node *tree;
struct node {
  int value;
  node *left, *right;
};


void insertValue(int elementNumber, tree &currentTree);
void printTree(tree &currentTree);

int main() {
  srand(time(NULL));
  tree newTree = NULL;
  int maxValues = 5;
  int randValue = 0; 
  
  for(int i = 0; i < maxValues; i++) {
    insertValue(rand()%100, newTree);
  }

  printTree(newTree);
  cout << endl;
  return 0;
}

void insertValue(int elementNumber, tree &currentTree) {
  if(currentTree == NULL) {
    currentTree = new node{elementNumber, NULL, NULL};
    cout << "Inserted value: " << elementNumber << endl;
    return;
  }
  if(elementNumber > currentTree->value) {
    if(currentTree->right!=NULL) {
      insertValue(elementNumber, currentTree->right);
    } else {
      currentTree->right = new node{elementNumber, NULL, NULL};
      cout << "Inserted value: " << elementNumber << endl;
    }
  } else {
    if(currentTree->left!=NULL) {
      insertValue(elementNumber, currentTree->left);
    } else {
      currentTree->left = new node{elementNumber, NULL, NULL};
      cout << "Inserted value: " << elementNumber << endl;
    }
  }

  
}

void printTree(tree &currentTree) {
  if(currentTree == NULL) {
    return;
  }
  
  if(currentTree->left != NULL) {
    printTree(currentTree->left);
  }
  
  if(currentTree->right != NULL) {
    printTree(currentTree->right);
  }
  cout << currentTree->value << " ";
}
