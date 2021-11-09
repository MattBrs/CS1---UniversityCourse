#include <iostream>
#include <cstdlib>

using namespace std;
const int SIZE_ROW = 3;
const int SIZE_COLUMN = 5;

void init(int v[][SIZE_COLUMN], int size_r , int size_c);
void print(int v[][SIZE_COLUMN], int size_r , int size_c);
void print(int v[][SIZE_ROW], int size_r , int size_c);
void trasposeMatrix(int v1[][SIZE_ROW], int v2[][SIZE_COLUMN], int size_r = SIZE_COLUMN, int size_c = SIZE_ROW);

int main() {
    srand(time(NULL));
    
    int v1[SIZE_ROW][SIZE_COLUMN];
    int v2[SIZE_COLUMN][SIZE_ROW];

    init(v1,SIZE_ROW, SIZE_COLUMN);
    cout << "Matrice normale" << endl;
    print(v1, SIZE_ROW, SIZE_COLUMN);
    
    cout << "Matrice trasposta" << endl;
    trasposeMatrix(v2, v1);
    print(v2, SIZE_COLUMN, SIZE_ROW);

    return 0;
}

void init(int v[][SIZE_COLUMN], int size_r, int size_c) {
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++){
            v[i][j] = (rand() % 100) + 1;
        }
    }
}

void print(int v[][SIZE_COLUMN], int size_r, int size_c) {
    cout << "---------------Inizio array---------------" << endl;
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++){
            cout << v[i][j] << " ";
        }
        cout << " " << endl;
    }
    cout << "---------------Fine array---------------" << endl;
}
void print(int v[][SIZE_ROW], int size_r, int size_c) {
    cout << "---------------Inizio array---------------" << endl;
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++){
            cout << v[i][j] << " ";
        }
        cout << " " << endl;
    }
    cout << "---------------Fine array---------------" << endl;
}

void trasposeMatrix(int v1[][SIZE_ROW], int v2[][SIZE_COLUMN], int size_r, int size_c ) {
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++){
            v1[i][j] = v2[j][i];
        }
    }
}
