#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int v[], int size);
void initArray(int v[], int size);
void substituteValues(int v[], int size);
void bubbleSort(int v[], int size);


int main() {
    srand(time(NULL));
    const int SIZE = 10;
    int v[SIZE] = {1,2,3,4,4,6,2,1,4,10};
    printArray(v, SIZE);
    substituteValues(v, SIZE);
    cout << "" << endl;
    printArray(v, SIZE);

    return 0;
}


void printArray(int v[], int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i] << endl;
    }
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

void substituteValues(int v[], int size) {
    bubbleSort(v, size);
    int lastValue = v[0];

    for (int i = 1; i < size; i++) {
        if(v[i] == lastValue) {
            v[i] = -1;
            
        }else {
            lastValue = v[i];
        }
        
    }
    for (int i = 0; i < size; i++) {
        if(v[i] == -1 && i != 0) {
            v[i-1] = -1;
        }
            
    }
}