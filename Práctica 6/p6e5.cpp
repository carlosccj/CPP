#include <iostream>
#include <array>
#include <cmath>
using namespace std;

const int MAX_NELMS = 100;

typedef array <int, MAX_NELMS> Numeros;

struct Primos
{
    int nelms = 0;
    Numeros elm;
};

void leer (double& num)
{
    cout << "Introduzca el valor de K (<= 100): ";
    cin >> num;
    while ((num < 0) || (num > 100))
    {
        cout << "Error. Introduzca valor de K (<= 100): ";
        cin >> num;
    }
}

int buscar (const Primos& v, int x)
{
    int i = 0;
    while ((i < v.nelms) && (x != v.elm[i]))
    {
        i++;
    }
    return i;
}

void mostrar (const Primos& v)
{
    for (int i = 0; i < v.nelms; i++)
    {
        cout << v.elm[i] << " ";
    }
}

void eliminar (Primos& v, int x)
{
    int pos = buscar (v, x);
    if ((pos >= 0) && (pos < v.nelms))
    {
        for (int i = pos + 1; i < v.nelms; i++)
        {
            v.elm[i-1] = v.elm[i];
        }
        --v.nelms;
    }
}

void eratostenes (int num, double r, Primos& v)
{
    int cero = 0;
    int uno = 1;
    for (int i = 0; i < v.nelms; i++)
    {
        v.elm[i] = i;
    }
    eliminar (v, cero);
    eliminar (v, uno);
    for (int i = 2; i < r; i++)
    {
        for (int e = (i + 1); e < num; e++)
        {
            if (e % i == 0)
            {
                eliminar (v, e);
            }
        }
    }
    mostrar (v);
}

int main ()
{
    double num;
    Primos v = {};
    leer (num);
    v.nelms = num;
    double r = sqrt (num);
    eratostenes (num, r, v);
}
