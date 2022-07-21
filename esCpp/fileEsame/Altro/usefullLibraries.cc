#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  //cmath
  sqrt(x);     //radice quadrata
  pow(x, y); //eleva x
  exp(x); //eleva e
  fabs(x); // float abs

  //cctype
  tolower(c);
  toupper(c);
  islower(c);
  isupper(c);

  //cstring
  strlen(s);
  strcpy(s, t); //copia t in s e restituisce s
  strcat(s, t); //concatena t al termine di s e restituisce s
  strcmp(s, t); //confronta le due stringhe. restituisce -1 se s e' minore, 0 se sono uguali e 1 se e' maggiore
}
