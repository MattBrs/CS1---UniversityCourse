#include <iostream>
#include <fstream>
#include "albero.h"

using namespace std;

int main() {
  fstream input;
  input.open("input.txt", ios::in);
  tree newTree;
  init(newTree);

  if (!input.is_open()) {
    cout << "Errore apertura file\n";
    exit(1);
  }

  char buffer[100];
  int value = -1;
  while (input >> buffer) {
    value = atoi(buffer);
    cout << value << endl;
    push(newTree, value);
  }

  // push(newTree, 5);
  // push(newTree, 3);
  // push(newTree, 7);
  // push(newTree, 2);
  // push(newTree, 4);
  // push(newTree, 6);

  print(newTree);
  cout << endl;

  search(newTree, 6);
  cout << endl;
  input.close();
  return 0;
}

