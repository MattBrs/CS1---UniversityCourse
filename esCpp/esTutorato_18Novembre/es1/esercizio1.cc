#include <iostream>
#include "esercizio1.h"

using namespace std;

int main() {
  char fileName[] = "input1.txt";
  int max = -1;
  int a = leggi_e_calcola_massimo(fileName, max);
  cout << a << endl;
  return 0;
}
