#include <iostream>
#include <fstream>
#include "pila.h"
#include <cstring>

using namespace std;

void readFile(char inputFile[]);
void writeFile(char outputFile[]);

int main(int argc, char *argv[]) {
  if(argc != 3) {
    cout << "Numero parametri sbagliato" << endl;
    exit(0);
  }

  extern lista pila;

  char* inputFile = argv[1];
  char* outputFile = argv[2];
  readFile(inputFile);
  writeFile(outputFile);
  return 0;
}
void readFile(char inputFile[]) {
  fstream input;
  input.open(inputFile, ios::in);

  char buffer[256];
  while(input >> buffer) {
    push(atoi(buffer));
  }

  input.close();
}

void writeFile(char outputFile[]) {
  fstream output;
  output.open(outputFile, ios::out);
  int topNumber = NULL;
  while(top(topNumber)) {
    
    top(topNumber);
    output << topNumber;
    pop();
  }
  output << endl;
  output.close();
}

