#include <iostream>

using namespace std;

bool isPalindroma(char *word, int start, int end);

int main() {
  int wordLenght = -1;
  do {
    cout << "Insert the word length: ";
    cin >> wordLenght;
    if(wordLenght < 1 || wordLenght > 100) {
      cout << "Word lenght must be between 1 and 100" << endl;
    }
  } while(wordLenght < 1 || wordLenght > 100);
  char *word = new char[wordLenght];
  cout << "Type word: ";
  cin >> word;

  
  cout << word << endl;

  cout << isPalindroma(word, 0, wordLenght-1) << endl;
  return 0;
}

bool isPalindroma(char *word, int start, int end) {
    if(start >= end) {
      return true;
    }
    if(word[start] == word[end]) {
      return isPalindroma(word, start+1, end-1);
    }else {
      return false;
    }
}
