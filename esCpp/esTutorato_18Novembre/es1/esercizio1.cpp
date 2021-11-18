#include "esercizio1.h"
#include <fstream>
#include <iostream>

using namespace std;

int leggi_e_calcola_massimo(char fileName[], int &max) {
  fstream inputFile;
  inputFile.open(fileName);

  char buffer;
  max = -1;
  int count = 0;

  char parola[256];
  while(inputFile >> parola) {
    for(count = 0; parola[count] != '\0'; count++) { }
    if(count > max) {
      max = count;
    }
  }

  inputFile.close();
  inputFile.open(fileName, fstream::app);
  
  for(int i = 0; i < max; i++) {
    inputFile << '+';
  }
  inputFile << endl;

  inputFile.close();
  return max;
}
