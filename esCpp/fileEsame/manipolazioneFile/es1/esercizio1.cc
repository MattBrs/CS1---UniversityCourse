#include <iostream>
#include <fstream>

using namespace std;

bool checkWord(char word[100], int size);
void saveWord(char wordList[][100], char word[], int wordLenght, int index);

int main(int argc, char * argv[])
{
  if (argc != 3) {
    cout << "Numero parametri errato" << endl;
    exit(0);
  }
  const int wordLenght = 100;

  fstream input;
  fstream output;
  
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);


  if (!input.is_open() || !output.is_open()) {
    cout << "Errore nell'apertura dei file" << endl;
  }

  char buffer[wordLenght];
  char wordList[10000][wordLenght];
  int wordListCount = 0;
  while (input >> buffer) {
    if (checkWord(buffer, wordLenght)) {
      saveWord(wordList, buffer, wordLenght, wordListCount);
      wordListCount++;
    }
  }

  if (input.fail() && !input.eof()) {
    cout << "Errore nella lettura del file" << endl;
    exit(1);
  }


  for (int i = wordListCount-1; i >= 0; i--) {
    output << wordList[i] << endl;;
  }

  if (output.fail() && !output.eof()) {
    cout << "Errore nella lettura del file" << endl;
    exit(1);
  }
  
  output.close();
  input.close();
  return 0;
}

bool checkWord(char word[], int size) {
  int i = 0;
  for (i = 0; word[i] != '\0'; i++) {}

  if (i%2 == 0) {
    return true;
  }
  return false;
}

void saveWord(char wordList[][100], char word[], int wordLenght, int index) {
  for (int i = 0; i < wordLenght; i++) {
    wordList[index][i] = word[i]; 
  }
}
