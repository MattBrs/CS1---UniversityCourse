#include <iostream>
#include <cstdlib>

using namespace std;

int ** generate_matrix(int R, int C);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if(argc != 3) {
        return 0;
    }

    int R = atoi(argv[1]);
    int C = atoi(argv[2]);
    int ** matrix = generate_matrix(R, C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    for (int i = 0; i < R; i++) {
        delete[] matrix[i];
    }
    delete matrix;

    return 0;
}


int ** generate_matrix(int R, int C) {
    int ** matrix = new int*[R];
    for (int i = 0; i < R; i++) {
        matrix[i] = new int[C];
    }
    

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++) {
            matrix[i][j] = rand()%100;
        }
        
    }

    return matrix;
}