#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "Numero argomenti sbagliato" << endl;
        return 0;
    }

    ifstream originFile;
    ofstream destinationFile;

    originFile.open(argv[1]);
    destinationFile.open(argv[2]);

    if(!originFile || !destinationFile) {
        cout << "E' successo un problema" << endl;
        return 0;
    }

    char buffer[256];
    while (originFile.getline(buffer, 256)) {
        destinationFile << buffer << endl;
    }

    originFile.close();
    destinationFile.close();
    

    return 0;
}