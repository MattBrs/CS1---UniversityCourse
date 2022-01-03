#include <iostream>
#include <cstdlib>


using namespace std;

int **defineMatrix(int size_rows, int size_cols);

int main() {
	int size_rows = 5;
	int size_cols = 8;
	int **matrix;
	srand(time(NULL));
		
	matrix = defineMatrix(size_rows, size_cols);

	cout << "Matrice: " << endl;
	for(int i = 0; i < size_rows; i++) {
		for(int j = 0; j < size_cols; j++) {
			cout << matrix[i][j] << " "; 
		}
		cout << "\n";
	}

	return 0;
}


int **defineMatrix(int size_rows, int size_cols) {
	int **matrix = new int *[size_rows];
	for(int i = 0; i < size_rows; i++) {
		matrix[i] = new int[size_cols];
	}



	for(int i = 0; i < size_rows; i++) {
		for(int j = 0; j < size_cols; j++) {
			matrix[i][j] = (rand()%100) + 10;
		}
	}
	return matrix;	
}
