#include <iostream>
using namespace std;

int main ()

{
    char caracter;
    cout << " Introduzca un caracter ";
    cin >> caracter;
    if (((caracter>='A') && (caracter<='Z')) || ((caracter>='a') && (caracter<='z'))) {
        cout << " Es letra " << endl;
       } else if (caracter=='.') {
            cout << " Es punto " << endl;
           } else {
                cout << " No es ni letra ni numero " << endl;
            }
        }


