#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int v[], int size);
void initArray(int v[], int size);
int sequentialSearch(int v[], int value, int size);

int main() {
    const int SIZE = 10;
    int v[SIZE];
    int value  = 0;
    srand(time(NULL));

    initArray(v, SIZE);
    printArray(v, SIZE);

    cout << "Inserisci il numero che vuoi cercare:" << endl;
    cin >> value;

    int position = sequentialSearch(v, value, SIZE);
    cout << "posizione " << position << endl;
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



int sequentialSearch(int v[], int value, int size) {
    int posizione = -1;
    for (int i = 0; i < size; i++)
    {
        if(v[i] == value) {
            posizione = i;
        }
    }
    return posizione;

}
