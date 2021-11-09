#include <iostream>
#include <cstdlib>

using namespace std;
const int SIZE_ROW = 10;
const int SIZE_COLUMN = 10;

void init(int v[][SIZE_COLUMN], int size_r = SIZE_ROW, int size_c = SIZE_COLUMN);
void print(int v[][SIZE_COLUMN], int size_r = SIZE_ROW, int size_c = SIZE_COLUMN);
int countIlands(int v[][SIZE_COLUMN], int size_r = SIZE_ROW, int size_c = SIZE_COLUMN);
bool checkIsle(int v[][SIZE_COLUMN], int start, int end);

int main() {
    srand(time(NULL));
    
    int v[SIZE_ROW][SIZE_COLUMN];

    init(v);
    print(v);

    cout << countIlands(v, SIZE_ROW, SIZE_COLUMN) << endl;

    return 0;
}

void init(int v[][SIZE_COLUMN], int size_r, int size_c) {
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++){
            v[i][j] = (rand() % 2);
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

int countIlands(int v[][SIZE_COLUMN], int size_r, int size_c) {
    int count = 0;
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            if(v[i][j] == 1) {
                if(checkIsle(v, i, j)) {
                    count ++;
                }
            }
        }
        
    }
    return count;
    
}

bool checkIsle(int v[][SIZE_COLUMN], int start, int end) {
    int cellsEquals1 = 0;

    for (int i = start-1; i < start+1; i++) {
        for (int j = end-1; j < end+1; j++) {
            if(i >= 0 && i < SIZE_ROW) {
                if(j >= 0 && i < SIZE_COLUMN) {
                    cellsEquals1 += v[i][j];
                }
            } 
        }
        
    }
    //cout << cellsEquals1 << endl;
    if(cellsEquals1 == 1) {
        return true;
    } else {
        return false;
    }
}