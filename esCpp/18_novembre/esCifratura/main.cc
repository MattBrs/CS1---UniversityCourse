#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main(int argc, const char *argv[]) {
  if(argc != 3) {
    cout << "Numero parametri sbagliato" << endl;
    return 0;
  }
  int key = atoi(argv[2]);
  ifstream sourceFile;
  ofstream destinationFile;
  sourceFile.open(argv[1]);
  destinationFile.open("output.txt");

  char buffer[256];
  while(sourceFile.getline(buffer, 256)) {
    crypt(buffer, key);
    destinationFile << buffer;
    destinationFile << endl;
  }
  sourceFile.close();
  destinationFile.close();

  sourceFile.open("output.txt");
  destinationFile.open("decrypted.txt");
  while(sourceFile.getline(buffer, 256)) {
    decrypt(buffer, key);
    destinationFile << buffer;
    destinationFile << endl;
  }

  sourceFile.close();
  destinationFile.close();
  return 0;
}
