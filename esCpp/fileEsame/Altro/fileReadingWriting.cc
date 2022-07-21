#fstream

using namespace std:

int main() {
  // dichiarazione variabili
  fstream input;
  fstream output;

  // apertura file
  input.open("input.txt", ios::in);
  output.open("output.txt", ios::out); // ios::app per fare append

  char buffer1[256];
  input >> buffer1;   // leggere parola per parola

  char buffer2;
  input.get(buffer2); // leggere carattere per carattere

  char buffer3[512];
  input.getline(buffer3, 512); // leggere riga per riga

  // scrittura file
  output << buffer1;
  output << buffer2;
  output << buffer3;

  // controlli sui file
  if (input.is_open()) {
    // se e' aperto entro, altrimenti no
  }

  if (!input) {
    // guarda se e' avvenuto un errore. Se non e' avvenuto entra.
  }
  
  if (input.bad())
    std::cout << "I/O error while reading\n";
  else if (input.eof())
    std::cout << "End of file reached successfully\n";
  else if (input.fail() && !input.eof())
    std::cout << "Non-integer data encountered\n";

  
  //chiusura file
  input.close();
  output.close();
}
