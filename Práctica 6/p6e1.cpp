#include <iostream>
#include <array>
using namespace std;

const int NVECTOR = 5;
typedef array <double, NVECTOR> Vector;

void leer (Vector& v)
{
    cout << "Introduzca " << (v.size()) << " numeros: ";
    for (int i = 0; i < int(v.size()); ++i)
    {
        cin >> v[i];
    }
}

double buscar (const Vector& v)
{
    double mayor = v[0];
    for (int x : v)
    {
        if (mayor <= x)
        {
            mayor = x;
        }
    }
    return mayor;
}

void mostrar (const Vector& v, double m)
{
    cout << "El mayor elemento de la lista es: " << m << endl;
    for (int x : v)
    {
        cout << x << ", ";
    }
}

int main ()
{
    Vector v;
    leer (v);
    double mayor = buscar (v);
    mostrar (v, mayor);
}
