#include <iostream>
using namespace std;
int checkAdiacentNumbers(int number);
int getNumber(int number);

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
        exit(1);
    }
    int n = atoi(argv[1]);
    std::cout << "The read string is: " << argv[1] << std::endl;
    std::cout << "The converted value is: " << n << std::endl;
    std::cout << "function(" << n << ") = " << checkAdiacentNumbers(n) << std::endl;
}




int checkAdiacentNumbers(int number) {
  int value = 0;
  if(number==0) {
    return 0;
  }
  if(getNumber(number) == getNumber(number/10)) {
    value = 1;
  }
  return value + checkAdiacentNumbers(number/10);   
}

int getNumber(int number) {
  return number%10;
}
