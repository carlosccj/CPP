#include <iostream>
#include <string>
#include <array>
using namespace std;

void leer (string& numero)
{
    cout << "Introduzca un valor numerico: ";
    cin >> ws;
    getline (cin, numero);
    cout << "Entrada: " << numero << endl;
    cout << "Valor: " << numero << endl;
}

int transf (string& numero)
{
    int nn = 0;
    int cnt = 1;
    for (int i = int(numero.size() - 1); i >= 0; i--)
    {
        nn += (int(numero[i]) - int('0')) * cnt;
        cnt *= 10;
    }
    return nn;
}

int main ()
{
    string numero;
    leer (numero);
    int doble = transf (numero);
    cout << "Doble: " << doble * 2;
}
