#include <iostream>
#include <array>
using namespace std;

const int NELMS = 10;
const char AST = '*';
const char ESP = ' ';

typedef array <int, NELMS> Numeros;

int mayor (const Numeros& v)
{
    int mayor = v[0];
    for (int x : v)
    {
        if (mayor <= x)
        {
            mayor = x;
        }
    }
    return mayor;
}

void mostrar (const Numeros& v)
{
    int m = mayor (v);
    int cnt = m;
    for (int i = 0; i < m; i++)
    {
        for (int e = 0; e < int(v.size()); e++)
        {
            if (v[e] < cnt)
            {
                cout << ESP << " ";
            }
            else
            {
                cout << AST << " ";
            }
        }
        cout << endl;
        cnt--;
    }
    cout << "-------------------" << endl;
    for (int i = 0; i < int(v.size()); i++)
    {
        cout << i << " ";
    }
}

void leer (int& num)
{
    Numeros v = {};
    cout << "Introduzca una secuencia de numeros (hasta negativo): ";
    cin >> num;
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
