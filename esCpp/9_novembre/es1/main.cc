//atoi()
//atof()
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    if(argc != 4) {
        cout << argc << endl;
        cout << "Numero parametri incorretto" << endl;
        return 0;
    }else {
        int param1 = atoi(argv[1]);
        char calcOperator = argv[2][0];
        int param3 = atoi(argv[3]);
        double result = 0;
        
        cout << param1 << " " << calcOperator << " " << param3 << endl;

        switch (calcOperator)
        {
        case '+':
            result = param1 + param3;
            break;
        case '-':
            result = param1 - param3;
            break;
        case 'x':
            result = param1 * param3;
            break;
        case '/':
            result = param1 / param3;
            break;
        default:
            cout << "Operatore non riconosciuto" << endl;
            break;
        }
        cout << "Il risultato e' : " << result << endl;
    }
    return 0;
}
