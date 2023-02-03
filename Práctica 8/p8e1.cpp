#include <iostream>
#include <array>
#include <string>
using namespace std;

void leer (string& cadena)
{
    cout << "Introduzca una cadena: ";
    cin >> ws;
    getline (cin, cadena);
}

void vocales (string& cadena)
{
    string ncadena = "";
    for (int i = 0; i < int(cadena.size()); i++)
    {
        if (cadena[i] != 'a' && cadena[i] != 'e' && cadena[i] != 'i' && cadena[i] != 'o' && cadena[i] != 'u')
        {
            ncadena += cadena[i];
        }
    }
    cout << "Cadena original: " << cadena << endl;
    cout << "Cadena resultado: " << ncadena;
}

int main ()
{
    string cadena;
    leer (cadena);
    vocales (cadena);
}
