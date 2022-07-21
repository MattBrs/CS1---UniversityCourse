#include <iostream>

using namespace std;

int extract(char string[100], int currentPos);
void makeString(char *newsString, int charCount, int currentPos);

int main() {
  char string[100];

  cout << "Inserisci una stringa nella quale vuoi contare le @:" << endl;
  cin >> string;

  int charCount = extract(string, 0);

  cout << "found " << charCount << " @ in the inserted string" << endl;

  char *newString = new char[charCount+1];
  makeString(newString, charCount, 0);
  cout << "la nuova stringa contenente solo @ e': " << endl;
  cout << newString << endl;
  return 0;
}

int extract(char string[100], int currentPos) {
  int charFound = 0;
  if (string[currentPos] == '\0') {
    return 0;
  } else if (string[currentPos] == '@') {
    charFound++;
  }

  return charFound + extract(string, currentPos+1);
}

void makeString(char *newString, int charCount, int currentPos) {
  if (currentPos >= charCount) {
    newString[currentPos] = '\0';
    return;
  } else {
    newString[currentPos] = '@';
    return makeString(newString, charCount, currentPos+1);
  }
}
