#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Studente {
  char nome[20];
  char cognome[20];
  int matricola;
  double media;
};


void stampa_studente(const Studente & s);
Studente genera_studente(char nome[20], char cognome[20], int matricola, double media);
void getStudents(Studente *database, char fileName[], int studentCount);
int fileLines(char fileName[]);
void printDatabase(Studente *database, int studentCount);

int main() {
  Studente s1 = genera_studente("matteo", "brusa", 226791, 25.3);
  stampa_studente(s1);

  int studentCount = fileLines("input.txt");
  Studente *database = new Studente[studentCount];
  getStudents(database, "input.txt", studentCount);
  printDatabase(database, studentCount);
  return 0;
}

void stampa_studente(const Studente & s) {
  cout << s.nome << ", " << s.cognome << ", " << s.matricola << ", " << s.media << endl; 
}

Studente genera_studente(char nome[20], char cognome[20], int matricola, double media) {
  Studente tempStudent = {"", "", matricola, media};
  strcpy(tempStudent.nome, nome);
  strcpy(tempStudent.cognome, cognome);
  return tempStudent;
}

void getStudents(Studente *database, char fileName[], int studentCount) {
  fstream input;
  input.open(fileName, ios::in);
  Studente *tempDatabase = new Studente[studentCount];
  
  char buffer[100];
  for(int i = 0; input >> buffer; i++) {
    char nome[20];
    strcpy(nome, buffer);
    
    input >> buffer;
    char cognome[20];
    strcpy(cognome, buffer);

    input >> buffer;
    int matricola = atoi(buffer);

    input >> buffer;
    double media = atoi(buffer);

    database[i] = genera_studente(nome, cognome, matricola, media);
  }
  
  input.close();
}

void printDatabase(Studente *database, int studentCount) {
  for (int i = 0; i < studentCount; i++) {
    stampa_studente(database[i]);
  }
}

int fileLines(char fileName[]) {
  fstream input;
  input.open(fileName, ios::in);
  char buffer[256];
  int count = 0;
  while (input.getline(buffer, 256)) {
    count++;
  }
  cout << "found " << count << " students" << endl;
  input.close();
  return count;
}
