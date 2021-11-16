#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Studente {
	char name[20];
	char surname[20];
	int id;
	double mean;
};

void printStudent(const Studente & studente);
Studente makeStudent(char *name, char *surname, int id, double mean );
Studente* makeDatabase(int &size);

int main() {
  srand(time(NULL));
  char name[20] = {'m','a', 't', 't', 'e', 'o'};
  char surname[20] = {'B','r','s'};
  const int SIZE = 10;
  Studente *studentDatabase = makeDatabase(SIZE);
  
  ifstream file;
  file.open("output.txt");

  char buffer[256];
  
  for(int i = 0; i < SIZE; i++) {
    file << studentDatabase[i];
  }
  
  

  file.close();
  return 0;
}

void printStudent(const Studente & studente) {
  cout << "Matricola: " << studente.id << endl;
  cout << "Nome: " << studente.name << endl;
  cout << "Cognome: " << studente.surname << endl;
  cout << "Media: " << studente.mean << endl;
}

Studente makeStudent(char *name, char *surname, int id, double mean ) {
  Studente s;
  s.id = id;
  s.mean = mean;
  strcpy(s.name, name);
  strcpy(s.surname, surname);
  return s;
}

Studente* makeDatabase(int &size) {
  Studente * database = new Studente[size];
  char name[20] = "awe";
  char surname[20] = "asdgfg";
  
  for(int i = 0; i < size; i++) {
    database[i] = makeStudent(name, surname, (rand()%100)+10, (rand() % 100) + 10); 
  }

  return database;
}

