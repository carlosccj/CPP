#include <iostream>
#include <array>
using namespace std;

const int NELMS = 10;

typedef array <int, NELMS> Numeros;

void mostrar (const Numeros& v)
{
    for (int i = 0; i < int(v.size()); i++)
    {
        cout << i << ": " << v[i] << endl;
    }
}

void leer (int& num)
{
    cout << "Introduzca una secuencia de numeros (hasta negativo): ";
    cin >> num;
    Numeros v = {};
    while (num >= 0)
    {
        v[num]++;
        cin >> num;
    }
    mostrar (v);
}

int main ()
{
    int num;
    leer (num);
}
