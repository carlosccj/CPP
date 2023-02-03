#include <iostream>
#include <array>
using namespace std;

int const NVECTOR = 5;
int const c = 1;

typedef array <int, NVECTOR> Vector;

void leer (Vector& v)
{
    cout << "Introduzca " << (v.size()) << " numeros enteros: " << endl;
    for (int i = 0; i < NVECTOR; i++)
    {
        cin >> v[i];
    }
}

void mostrar (const Vector& v, int n1, int n2)
{
    int z = 0;
    for (int i = 0; i < int(v.size()); i++)
    {
        if (n2 == v[i])
        {
            z = 1 + i;
        }
    }
    if (n1 == n2)
    {
        cout << "El centro de este vector es el indice " << z;
    }
    else
    {
        cout << "Este vector no tiene centro";
    }
}

int sum_d (const Vector& v)
{
    int sum = 0;
    int j = c + 1;
    for (int i = j; i < NVECTOR - 1; i++)
    {
       sum += (j - c) * v[j];
    }
    return sum;
}

int sum_i (const Vector& v)
{
    int sum = 0;
    for (int i = 0; i < c; i++)
    {
       sum += (c - i) * v[i];
    }
    return sum;
}

int main ()
{
    Vector v;
    leer (v);
    int n1 = sum_i (v);
    int n2 = sum_d (v);
    mostrar (v, n1, n2);
}
