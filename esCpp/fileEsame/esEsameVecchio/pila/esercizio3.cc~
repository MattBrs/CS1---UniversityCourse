#include <iostream>
#include "pila.h"


using namespace std;

bool visited[5][5] = {false};
bool found = false;
/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * }; */

void risolviLabirinto(int [][5], int, int);
void searchPath(int labirinto[][5], int currentX, int currentY, int destinationX, int destinationY, int gridXsize, int gridYsize);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[5][5] = {
        { 1, 1, 1, 0, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 1, 1, 1, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0 }
    };
    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"percorso: \n" << endl;
    init();
    risolviLabirinto(labirinto, 3, 3);
   
    return 0;
}

void risolviLabirinto(int lab[][5], int x, int y){
  searchPath(lab, 0, 0, y, x, 5, 5);
  cella c;
  if (found) {
    while(top(c)) {
      if (!(c.indiceRiga == y && c.indiceColonna == x)) {
	cout << c.indiceRiga << ", " << c.indiceColonna << endl;
      } else {
	cout << c.indiceRiga << ", " << c.indiceColonna << endl;
      }
      pop();
    }
  }
}

void searchPath(int labirinto[][5], int currentX, int currentY, int destinationX, int destinationY, int gridXsize, int gridYsize) {
  cella c = {currentX, currentY};
  cella temp;
  top(temp);
  int nextCellUp=0, nextCellDown=0, nextCellLeft=0, nextCellRight=0;
  if (currentY-1 >= 0) {
    nextCellUp = labirinto[currentX][currentY-1];
  }

  if (currentY+1 < gridYsize) {
    nextCellDown = labirinto[currentX][currentY+1];
  }

  if (currentX+1 < gridXsize) {
    nextCellRight = labirinto[currentX+1][currentY];
  }

  if (currentX-1 >= 0) {
    nextCellLeft = labirinto[currentX-1][currentY];
  }    
  if (currentX == destinationX && currentY == destinationY) {
    push(c);
    found = true;
  }

  if (!visited[currentX][currentY] && !found) {
    push(c);
    visited[currentX][currentY] = true;
    if (nextCellRight == 1 && !found) {
      cella next = {currentX+1, currentY};
      if((temp.indiceRiga != next.indiceRiga || temp.indiceColonna != next.indiceColonna)) {
	searchPath(labirinto, currentX+1, currentY, destinationX, destinationY, gridXsize, gridYsize);
      }
    }

    if (nextCellDown == 1 && !found) {
      cella next = {currentX, currentY+1};
      if((temp.indiceRiga != next.indiceRiga || temp.indiceColonna != next.indiceColonna)) {
	searchPath(labirinto, currentX, currentY+1, destinationX, destinationY, gridXsize, gridYsize);
      }
    }

    if (nextCellLeft ==1 && !found) {
      cella next = {currentX-1, currentY};
      if((temp.indiceRiga != next.indiceRiga || temp.indiceColonna != next.indiceColonna)) {
	searchPath(labirinto, currentX-1, currentY, destinationX, destinationY, gridXsize, gridYsize);
      }
    }

    if (nextCellUp == 1 && !found) {
      cella next = {currentX+1, currentY};
      if((temp.indiceRiga != next.indiceRiga || temp.indiceColonna != next.indiceColonna)) {
	searchPath(labirinto, currentX, currentY-1, destinationX, destinationY, gridXsize, gridYsize);
      }
    }
  } else {
    if (temp.indiceRiga == c.indiceRiga && temp.indiceColonna == c.indiceColonna) {
      pop();
    }
  }
}
