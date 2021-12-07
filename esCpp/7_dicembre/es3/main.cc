#include <iostream>

using namespace std;

void initValue(int esagonalArray[], int &size, int currentPos);
void printValue(int esagonalArray[], int &size, int currentPos);

int main(int argc, char *argv[]) {
  if(argc != 2) {
    cout << "Numero parametri sbagliato" << endl;;
  }

  int size = atoi(argv[1]);
  int *esagonalArray = new int[size];
  cout << size << endl;
  initValue(esagonalArray, size, 0);
  printValue(esagonalArray, size, 0);
  return 0;
}

void initValue(int esagonalArray[], int &size, int currentPos) {
  if(currentPos == size) {
    return;
  }
  esagonalArray[currentPos] = currentPos*((2*currentPos) -1);
  initValue(esagonalArray, size, currentPos+1);
}

void printValue(int esagonalArray[], int &size, int currentPos) {
  if(currentPos == size) {
    return;
  }

  cout << "Pos: " << currentPos+1 << " -> " << "Value:" << esagonalArray[currentPos] << endl;
  printValue(esagonalArray, size, currentPos+1);
}

