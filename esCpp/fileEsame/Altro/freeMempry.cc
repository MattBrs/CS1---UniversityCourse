using namespace std;
int main() {
  int numeri = new int[3];
  delete[] numeri;        // per cancellare array dinamici senza puntatori

  char lettera = new char;
  delete lettera;         // per cancellare una variabile assegnata con new char

  // se scorro una matrice devo eliminare ogni "nodo". quindi con un for con
  // con indice i scorro la prima dimensione dell'array e per ogni
  // array[i] faccio delete[] array[i];
  // alla fine devo cancellare anche array facendo quindi delete[] array;
}
