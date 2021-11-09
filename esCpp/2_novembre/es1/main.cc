#include <iostream>
#include <cstdlib>

using namespace std;
const int SIZE = 10;

void init(int *v, int size = SIZE);
void print(int *v, int size = SIZE);

int main() {
    srand(time(NULL));
    
    int v[SIZE];

    init(v);
    print(v);
    return 0;
}

void init(int *v, int size) {
    for (int i = 0; i < size; i++) {
        *v = (rand() % 100) + 1;
        v++;
    }
}

void print(int *v, int size) {
    cout << "---------------Inizio array---------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << *v << endl;
        v++;
    }
    cout << "---------------Fine array---------------" << endl;
}