#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione[], bool & corretta);
void readExpression(char expression[]);
char calculateExpression(bool &isCorrect);
char expRes(char boolOperator, char bool1, char bool2);

int main() {

    int dimensioneMassima = 100;
    char espressioneBooleana [dimensioneMassima];
    bool corretta = true;
    char risultatoEspressione;

    cout << "Inserisci l'espressione: ";
    cin >> espressioneBooleana;

    risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

    if (corretta) {
        cout << "Risultato: " << risultatoEspressione << endl;
    }
    else {
        cout << "Espressione malformata" << endl;
    }

    return 0;
}


char parseEspressioneBooleanaPrefissa(char espressione[], bool & corretta) {
  readExpression(espressione);
  return calculateExpression(corretta);
}

void readExpression(char expression[]) {
  for (int i = 0; expression[i] != '\0'; i++) {
    push(expression[i]);
  }
}

char calculateExpression(bool &isCorrect) {
  char topChar;
  isCorrect = true;
  char queque[2];
  int quequeCount = 0;
  
  while (top(topChar) && isCorrect) {
    if ((topChar == 'T' || topChar == 'F') && quequeCount <= 2) {
      queque[quequeCount] = topChar;
      quequeCount++;
    } else if (quequeCount > 2) {
      isCorrect = false;
    }
    

    if (topChar == '!') {
      queque[quequeCount-1] = expRes(topChar, queque[quequeCount-1], 'F');
    }

    if (topChar == '&') {
      if (quequeCount == 2) {
	queque[0] = expRes(topChar, queque[0], queque[1]);
	quequeCount = 1;
      } else {
	isCorrect = false;
      }
    }
    pop();
  }  
  return queque[0];
}

char expRes(char boolOperator, char bool1, char bool2) {
  if (boolOperator == '!') {
    return bool1 == 'T' ? 'F':'T';
  } else {
    return bool1 == bool2 && bool1 == 'T' ? 'T':'F';
  }
}
