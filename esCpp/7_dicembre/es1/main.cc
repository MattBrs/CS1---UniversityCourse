#include <iostream>
#include <cstdlib>

using namespace std;

void initArray(int size, int array[]);
void printArray(int size, int array[]);
bool checkPatternInText(int patternArray[], int textArray[], int patternSize, int textSize);

int main() {
  srand(time(NULL));
  int patternSize = -1;
  int textSize = -1;

  
  cout << "Inserisci la dimensione del pattern:";
  cin >> patternSize;
  cout << "Inserisci la dimensione del testo:";
  cin >> textSize;


  int *patternArray = new int[patternSize];
  int *textArray = new int[textSize];

  initArray(patternSize, patternArray);
  initArray(textSize, textArray);

  printArray(patternSize, patternArray);
  printArray(textSize, textArray);
  
  if(checkPatternInText(patternArray, textArray, patternSize, textSize)) {
    cout << "Il pattern e' contenuto nel testo" << endl;
  } else {
    cout << "Il pattern non e' contenuto nel testo" << endl;
  }
  
  return 0;
}

void initArray(int size, int array[]) {
  if(size < 1) {
    exit(0);
  }

  for (int i = 0; i < size; i++ ) {
    array[i] = rand()%100;
  }
}

void printArray(int size, int array[]) {
  cout << "[";
  
  for (int i = 0; i < size; i++) {
    cout << array[i];
    if(i < size-1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

bool checkPatternInText(int patternArray[], int textArray[], int patternSize, int textSize) {
  bool contained = false;
  for (int i = 0; i < textSize; i++) {
    if(textArray[i] == patternArray[0]) {
      for(int j = 1; j < patternSize; j++) {
	if(textArray[i+j] == patternArray[j]) {
	  contained = true;
	} else {
	  contained = false;
	}
      }
      if(contained) {
	return contained;
      }
    }
  }
  return false;
}
