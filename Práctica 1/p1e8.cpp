#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char letra1, letra2, letra3, letra4;
    cout << " Introduzca una palabra en minusculas ";
    cin >> letra1 >> letra2 >> letra3 >> letra4;
    char letra1m = ((letra1-'0') + 16);
    char letra2m = ((letra2-'0') + 16);
    char letra3m = ((letra3-'0') + 16);
    char letra4m = ((letra4-'0') + 16);
    cout << " La palabra [ " << letra1 << letra2 << letra3 << letra4 << " ] transformada es: " << endl;
    cout << " [ " << letra1m << letra2m << letra3m << letra4m << " ] " << endl;

}
