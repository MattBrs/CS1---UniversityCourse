#include <iostream>
#include <fstream>

using namespace std;

struct node {
  int value;
  node* next;
};

typedef node* list;

list createList(char *inputFile);
void printList(list numberList);
void destroyList(list numberList);

int main(int argc, char *argv[]) {
  if(argc != 2) {
    cout << "Numero parametri sbagliato" << endl;
    return 0;
  }

  list numberList = createList(argv[1]);

  printList(numberList);
  destroyList(numberList);
  return 0;
}


list createList(char *inputFile) {
  list numberList = NULL;
  
  fstream input;
  input.open("input.txt", ios::in);
  if(input.fail()) {
    cout << "errore" << endl;
    return NULL;
  }
  int number;
  input >> number;
  numberList = new node{number, NULL};
  node* currentNode = numberList;

  while(input >> number) {
    node* newNode = new node{number, NULL};
    currentNode->next = newNode;
    currentNode = newNode;
  }
  input.close();
  return numberList; 
}


void printList(list numberList) {
  while(numberList != NULL) {
    cout << numberList->value << endl;
    numberList = numberList->next;
  }
}

void destroyList(list numberList) {
  node* nextNode = numberList;
  while(nextNode != NULL) {
    nextNode = numberList->next;
    delete numberList;
    numberList = nextNode;
  }
}
