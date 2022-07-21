#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{
  fstream input;
  fstream output;

  input.open("input.txt", ios::in);
  output.open("output.txt", ios::out);


  char buffer;
  bool isToUpper = true;
  if(!input.is_open() || !output.is_open()) {
    cout << "Errore nell'apertura di un file, riprovare" << endl;
  } else {
    while(input.get(buffer)) {
      char tempChar = buffer;
      if (buffer == '.' || buffer == '!' || buffer == '?') {
	isToUpper = true;
      }

      if (buffer > 'a' && buffer < 'z' && isToUpper) {
	tempChar = toupper(buffer);
	isToUpper = false;
      }

      output << tempChar;
    }
  }
  return 0;
}
