#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[]) {
    if(argc != 3) {
        cout << "Numero parametri sbagliato" << endl;
        return 0;
    }

    ifstream source;
    ofstream destination;
    source.open(argv[1]);
    destination.open("destination.txt");

    if(!source) {
        cout << "Si e' verificato un problema" << endl;
        return 0;
    }

    char buffer;
    while(source.get(buffer)) {
        if(buffer == argv[2][0]) {
            buffer = '?';
        }
        destination << buffer;
    }
    destination << endl;

    source.close();
    destination.close();
    return 0;
}