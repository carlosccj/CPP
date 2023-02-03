#include <iostream>
using namespace std;

int main ()
{
    char letra1, letra2, letra3, letra4;
    cout << " Introduzca una palabra de 4 letras ";
    cin >> letra1 >> letra2 >> letra3 >> letra4;
     char letra1c = int (letra1+1);
     char letra2c = int (letra2+1);
     char letra3c = int (letra3+1);
     char letra4c = int (letra4+1);
    cout << " La palabra [ " << letra1 << letra2 << letra3 << letra4 << " ] transformada es " << endl;
    cout << " [ " << letra1c << letra2c << letra3c << letra4c << " ] " << endl;

}
