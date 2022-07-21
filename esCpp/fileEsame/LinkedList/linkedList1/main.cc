#include <iostream>
#include <cstdlib>

using namespace std;
struct node;
typedef node* list;
struct node {
  int number;
  list next;
};


list initList(int elementNumber);
void printList(list list);
void delList(list list);
void addElement(list list, int newElement);
void popElement(list list);

int main(int argc, char *argv[]) {
  list list1;
  int elementNumber = 10;
  srand(time(NULL));
  
  list1 = initList(elementNumber);
  printList(list1);
  
  addElement(list1, 0);
  printList(list1);
  
  popElement(list1);
  printList(list1);
  
  delList(list1);
  return 0;
}


list initList(int elementNumber) {
  list numberList = new node{rand()%100, NULL};
  node* currentNode = numberList;
  
  for(int i = 0; i < elementNumber; i++) {
    node* nextNode = new node{(rand()%100), NULL};
    currentNode->next=nextNode;
    currentNode = nextNode;
  }

  return numberList;
}

void printList(list list) {
  while(list != NULL) {
    cout << list->number << " ";
    list = list->next;
  }
  cout << "\n";
}

void delList(list list) {
  node* nextNode = list;
  while(nextNode != NULL) {
    nextNode = list->next;
    delete list;
    list = nextNode;
  }
}

void addElement(list list, int newElement) {  
  while(list->next != NULL) {
    list = list->next;
  }
  list->next = new node{newElement, NULL};
}

void popElement(list list) {
  node* currentNode = list;
  while(list->next != NULL) {
    currentNode = list;
    list = list->next;
  }
  currentNode->next = NULL;
  delete list;
  
}
