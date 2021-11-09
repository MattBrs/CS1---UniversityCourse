#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream file;
    if(argc != 2) {
        cout << "Numero parametri sbagliato" << endl;
    } else {
        file.open(argv[1]);
        if(file.is_open()) {
            char row[100];
            while (file >> row) {
                cout << row << endl;
            }
            file.close();
        }
    }
    return 0;
}


