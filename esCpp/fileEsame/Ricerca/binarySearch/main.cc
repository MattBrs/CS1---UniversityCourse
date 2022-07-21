//binary search
#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int v[], int size);
void initArray(int v[], int size);
void bubbleSort(int v[], int size);
int binarySearch(int v[], int value, int start, int end);

int main() {
    srand(time(NULL));
    const int SIZE = 10;
    int v[SIZE];
    int value = 0;

    initArray(v, SIZE);
    printArray(v, SIZE);

    bubbleSort(v, SIZE);
    printArray(v, SIZE);

    cout << "Inserisci un valore che vuoi cercare: ";
    cin >> value;
    cout << binarySearch(v, value, 0, SIZE) << endl;

    return 0;
}


void printArray(int v[], int size) {
    cout << "inizio Array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << v[i] << endl;
    }
    cout << "Fine array" << endl;
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


int binarySearch(int v[], int value, int start, int end) {
    if(start <= end) {
        int middle = (start+end)/2;     //(10-0)/2  = 5;

        if(v[middle] == value) {        
            return middle;
        } 
        if(value > v[middle]) {
            return binarySearch(v, value, middle+1, end);
        }
        if(value < v[middle]) {
            return binarySearch(v, value, start, middle-1);
        }
        
        return -1;
    }
}

