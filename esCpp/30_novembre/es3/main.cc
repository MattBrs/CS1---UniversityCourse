#include <iostream>
#include <fstream>

using namespace std;

void calcMedia(int &media, char fileName[]);
void appendMean(int &media, char fileName[]);

int main(int argc, char *argv[]) {
  if(argc != 2) {
    cout << "Numero parametri sbagliato, riprova" << endl;
    exit(0);
  }
  int media = -1;
  char *fileName = argv[1];
  calcMedia(media, fileName);
  cout << media << endl;
  appendMean(media, fileName);
  return 0;
}

void calcMedia(int &media, char fileName[]) {
  fstream inputFile;
  inputFile.open(fileName, ios::in);
  char buffer[256];
  int mean = 0;
  int n = 0;
  while(inputFile >> buffer) {
    int i = 1;
    for(i; buffer[i] == '*'; i++) {
      
    }
    n++;
    mean += i;
  }
  mean /= n;
  media = mean;
  inputFile.close();
}

void appendMean(int &media, char fileName[]) {
  fstream outputFile;
  outputFile.open(fileName, ios::app);
  char convertedMean[10] = "";
  for(int i = 0; i < media; i++) {
    convertedMean[i] = '*';
  }

  outputFile << convertedMean;
  outputFile << "" << endl;
  outputFile.close();
}
