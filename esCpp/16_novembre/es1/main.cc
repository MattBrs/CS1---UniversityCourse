#include <iostream>
#include <cstring>

using namespace std;

struct Studente {
	char name[20];
	char surname[20];
	int id;
	double mean;
};

void printStudent(const Studente & studente);
Studente makeStudent(char *name, char *surname, int id, double mean );

int main() {
  char name[20] = {'m','a', 't', 't', 'e', 'o'};
  char surname[20] = {'B','r','s'};

  int id = 123;
  double mean= 8.45;

  Studente s = makeStudent(name, surname, id, mean);
  printStudent(s);
  
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

