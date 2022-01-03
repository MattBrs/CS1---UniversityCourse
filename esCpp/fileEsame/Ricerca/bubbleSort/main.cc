#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int v[], int size);
void initArray(int v[], int size);
void bubbleSort(int v[], int size);

int main() {
    const int SIZE = 10;
    int v[SIZE];
    srand(time(NULL));
    
    initArray(v, SIZE);
    printArray(v, SIZE);
    bubbleSort(v, SIZE);
    printArray(v, SIZE);
    return 0;
}


void printArray(int v[], int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i] << endl;
    }
    cout << "\n";
}
void initArray(int v[], int size) {
    for (int i = 0; i < size; i++) {
        v[i] = (rand()%100)+1;
    }

}

void bubbleSort(int v[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if(v[j] > v[j+1]) {
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}