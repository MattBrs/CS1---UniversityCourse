#include <iostream>
#include <cstdlib>

using namespace std;

int** initMatrix(int &rows, int &columns);
void defMatrix(int **matrix, int &rows, int &columns);
void printMatrix(int **matrix, int &rows, int &columns);
void delMatrix(int **matrix, int &rows);
void printSubmatrix(int **matrix, int &elementPosY, int &elementPosX, int &colsNum, int &rowsNum, int &mainMatrixRowsNum, int &mainMatrixColsNum);

int main() {
  srand(time(NULL));
  int rows, columns;
  int subRows, subCols;
  int elementPosY, elementPosX;
  
  cout << "Inserisci il numero di righe: ";
  cin >> rows;

  cout << "Inserisci il numero di colonne: ";
  cin >> columns;

  if(rows <=0 || columns <= 0) {
    cout << "Valori inseriti non corretti" << endl;
    exit(0);
  }
  
  int **matrix = initMatrix(rows, columns);
  defMatrix(matrix, rows, columns);
  printMatrix(matrix, rows, columns);

  cout << "Inserisci il numero di righe della sotto matrice: ";
  cin >> subRows;

  cout << "Inserisci il numero di colonne della sotto matrice: ";
  cin >> subCols;

  cout << "Inserisci la posizione x dell'elemento da cui vuoi cominciare: ";
  cin >> elementPosX;

  cout << "Inserisci la posizione y dell'elemento da cui vuoi cominciare: ";
  cin >> elementPosY;

  printSubmatrix(matrix, elementPosX, elementPosY, subCols, subRows, rows, columns);
  
  delMatrix(matrix, rows);
  return 0;
}

int** initMatrix(int &rows, int &columns) {
  int** matrix = new int*[rows];
  for(int i = 0; i < rows; i++) {
    matrix[i] = new int[columns];
  }
  return matrix;
}

void defMatrix(int **matrix, int &rows, int &columns) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      matrix[i][j] = rand()%100;
    }
  }
}

void delMatrix(int **matrix, int &rows) {
  for(int i = 0; i < rows; i++) {
    delete [] matrix[i];
  }
  delete [] matrix;
}

void printMatrix(int **matrix, int &rows, int &columns) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}

void  printSubmatrix(int **matrix, int &elementPosY, int &elementPosX, int &colsNum, int &rowsNum, int &mainMatrixRowsNum, int &mainMatrixColsNum) {
  if(elementPosY+colsNum > mainMatrixColsNum || elementPosX+rowsNum > mainMatrixRowsNum) {
    cout << "I valori inseriti eccedono i limiti della matrice" << endl;
    return;
  }
  
  for (int i = elementPosX; i < elementPosX+rowsNum; i++) {
    for (int j = elementPosY; j < elementPosY+colsNum; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "" << endl;
  }
}
