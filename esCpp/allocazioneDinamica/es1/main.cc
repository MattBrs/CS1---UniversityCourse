#include <iostream>
#include <cstdlib>

using namespace std;


int main() {
	srand(time(NULL));

	int size = 0;
	cin >> size;

	int *number = new int;
	int *numbers = new int[size];

	cout << endl;

	*number = 4;


	cout << *number << endl;

	cout << endl;

	for (int i = 0; i < size; i++) {
		numbers[i] = (rand()%100) + 10;
	}

	for(int i = 0; i < size; i++) {
		cout << numbers[i] << endl;
	}

	delete number;
	delete[] numbers;

	return 0;
}
