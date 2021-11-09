#include <iostream>
#include <cstdlib>

using namespace std;
const int SIZE_ROW = 10;
const int SIZE_COLUMN = 10;

void init(int v[][SIZE_COLUMN], int size_r = SIZE_ROW, int size_c = SIZE_COLUMN);
void print(int v[][SIZE_COLUMN], int size_r = SIZE_ROW, int size_c = SIZE_COLUMN);

int main() {
    srand(time(NULL));
    
    int v[SIZE_ROW][SIZE_COLUMN];

    init(v);
    print(v);

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