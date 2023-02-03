#include <iostream>
#include <array>
using namespace std;
const int NELMS = 5;
typedef array<int, NELMS> Vector;

void leer(Vector& v)
{
    cout << "Introduce " << v.size()
         << " numeros: " ;
    for (int& x : v)
    {
        cin >> x;
    }
}
int sumar(const Vector& v)
{
    int suma = 0;
    for (int x : v)
    {
        suma += x;
    }
    return suma;
}

void mostrar(const Vector& v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    Vector v1, v2;
    leer(v1);
    leer(v2);
    if (sumar(v1) > sumar(v2))
    {
        mostrar(v1);
    }
    else
    {
        mostrar(v2);
    }
}
