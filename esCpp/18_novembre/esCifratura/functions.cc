#include "functions.h"
#include <cstring>

void crypt(char parola[], int chiave) {
  const int LEN = strlen(parola);
  for(int i = 0; i < LEN;i++) {
    char tempCrypt = parola[i] + chiave;
    if(parola[i] >= 'a'  &&  parola[i] <= 'z') {
      if(tempCrypt > 'z') {
	tempCrypt = parola[i] - 'z' + 'a' + chiave - 1;
      }
      parola[i] = tempCrypt;
    }else if(parola[i] >= 'A' && parola[i] <= 'Z') {
      if(tempCrypt > 'Z') {
	tempCrypt = parola[i] - 'Z' + 'A' + chiave - 1;
      }
      parola[i] = tempCrypt;
    }else if(parola[i] >= '0' && parola[i] <= '9') {
      if(tempCrypt > '9') {
	tempCrypt = parola[i] - '9' + '0' + chiave - 1;
      }
      parola[i] = tempCrypt;
    }
  }
}

void decrypt(char parola[], int chiave) {
  const int LEN = strlen(parola);
  for(int i = 0; i < LEN; i++) {
    char tempCrypt = parola[i] - chiave;
    if(parola[i] >= 'a'  &&  parola[i] <= 'z') {
      if(tempCrypt < 'a') {
	tempCrypt = parola[i] - 'a' + 'z' - chiave + 1;
      }
      parola[i] = tempCrypt;
    }else if(parola[i] >= 'A' && parola[i] <= 'Z') {
      if(tempCrypt > 'Z') {
	tempCrypt = parola[i] - 'A' + 'Z' - chiave + 1;
      }
      parola[i] = tempCrypt;
    }else if(parola[i] >= '0' && parola[i] <= '9') {
      if(tempCrypt > '9') {
        tempCrypt = parola[i] - '0' + '9' - chiave + 1;
      }
      parola[i] = tempCrypt;
    }
  }
}

