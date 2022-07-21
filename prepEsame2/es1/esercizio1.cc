#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
  if(argc != 3) {
    cout << "Numero parametri inserito non corretto, riprova" << endl;
    exit(0);
  }
  char *inputFileName = argv[1];
  char *outputFileName = argv[2];

  fstream input;
  fstream output;

  input.open(inputFileName, ios::in);
  output.open(outputFileName, ios::out);

  char buffer;
  bool toUpper = true;
  while(input.get(buffer)) {
    char toWrite = buffer;
    
    if(buffer == '.' || buffer == '?' || buffer == '!') {
      toUpper = true;
    }else if(toUpper && buffer != ' ' && buffer != '\n') {
      toUpper = false;
      toWrite = toupper(buffer);
      cout << "to write: " << toWrite << endl;
    }
    output << toWrite;
  }

  input.close();
  output.close();
  return 0;
}


