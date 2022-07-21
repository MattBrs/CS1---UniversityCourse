#include <iostream>
#include <cstdlib>

struct nodo {
  int valore;
  nodo* nodoPrecedente;
  nodo* nodoSuccessivo;
};
typedef nodo* lista;

using namespace std;


void inizializza (int arrayDiInteri [], int dimensioneArray);
void stampaLista (lista nodoCorrente);
lista creaLista(int array[], int dimensioneArray);
void addElement(lista &list, int newElement);
// Inserire qui la dichiarazione di "creaLista" e "rimuoviNodiAlternati


int main() { 

  // Non modificare la funzione "main"

  int dimensioneArray = 8;
  int arrayDiInteri[dimensioneArray];
  inizializza(arrayDiInteri, dimensioneArray);

  for (int i = 0; i < dimensioneArray; i++){
    cout << arrayDiInteri[i] << " ";
  }
  cout << endl;
  
  lista nodoIniziale = creaLista(arrayDiInteri, dimensioneArray);

  cout << "Lista iniziale: ";
  stampaLista(nodoIniziale);

  //nodoIniziale = rimuoviNodiAlternati(nodoIniziale);

  cout << "Risultato: ";
  stampaLista(nodoIniziale);
  //deallocaLista(nodoIniziale);

  return 0;
}

void inizializza (int arrayDiInteri [], int dimensioneArray) {
    
  // Non modificare la funzione "inizializza"

  srand(time(NULL));

  for (int i = 0 ; i < dimensioneArray ; i++) {
    arrayDiInteri[i] = i % 3;
  }

  int contatore = dimensioneArray;
  while (contatore > 1) {
    int indice = rand() % contatore;
    contatore--;
    int temp = arrayDiInteri[contatore];
    arrayDiInteri[contatore] = arrayDiInteri[indice];
    arrayDiInteri[indice] = temp;
  }
}

void stampaLista(nodo* nodoCorrente) {

  // Non modificare la funzione "stampaLista"

  while (nodoCorrente != NULL) {
    cout << nodoCorrente->valore << " ";
    nodoCorrente = nodoCorrente->nodoSuccessivo;
  }
  cout << endl;
}


// Inserire qui la definizione di "creaLista", "rimuoviNodiAlternati" e di eventuali altre funzioni ausiliarie


lista creaLista(int array[], int dimensioneArray) {
  lista list = new nodo;
  list = NULL;
  for (int i = 0; i < dimensioneArray; i++) {
    addElement(list, array[i]);
  }
  
  return list;
}

void addElement(lista &list, int newElement) {
  lista cur = list;
  lista new_node = new nodo{newElement, cur, NULL};
  if (cur == NULL) {
    list = new nodo{newElement, NULL, NULL};
    return;
  }
  
  while (cur->nodoSuccessivo != NULL) {
    cur = cur->nodoSuccessivo;
  }
  new_node->nodoPrecedente = cur;
  cur->nodoSuccessivo = new_node;
}
