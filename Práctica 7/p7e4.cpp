#include <iostream>
#include <array>
using namespace std;

const int NELMS = 10;

typedef array <int, NELMS> Vector;

void leer (Vector& v)
{
    cout << "Introduzca 10 numeros: ";
    for (int& x : v)
    {
        cin >> x;
    }
}

int buscar_mayor (const Vector& v)
{
    int mayor = v[0];
    for (int i = 0; i < int(v.size()); i++)
    {
        if (mayor < v[i])
        {
            mayor = v[i];
        }
    }
    return mayor;
}

int buscar_menor (const Vector& v)
{
    int menor = v[0];
    for (int i = 0; i < int(v.size()); i++)
    {
        if (v[i] < menor)
        {
            menor = v[i];
        }
    }
    return menor;
}

int alfa (const Vector& v, int mayor, int menor)
{
    int cnt = (menor - 1);
    for (int i = 1; i < int(v.size()); i++)
    {
        if (v[i] > cnt && v[i] < mayor)
        {
            cnt = v[i];
        }
    }
    mayor = cnt;
    return mayor;
}

int reps (const Vector& v, int siguiente)
{
    int cnt = 0;
    for (int x : v)
    {
        if (siguiente == x)
        {
            cnt ++;
        }
    }
    return cnt;
}

void mostrar (const Vector& v, int x, int menor)
{
    if (x != (menor - 1))
    {
    cout << x << " aparece " << reps (v, x);
    int rep = reps (v, x);
    if (rep == 1)
    {
        cout << " vez, en posicion ";
    }
    else
    {
        cout << " veces, en posiciones ";
    }
    for (int i = 0; i < int(v.size()); i++)
    {
        if (x == v[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    }
}

void numeros (const Vector& v, int mayor, int menor)
{
    mostrar (v, mayor, menor);
    for (int i = 0; i < int(v.size()); i++)
    {
        int siguiente = alfa (v, mayor, menor);
        mayor = siguiente;
        if (siguiente != menor)
        {
            mostrar (v, siguiente, menor);
        }
    }
    mostrar (v, menor, menor);
}

int main ()
{
    Vector v;
    leer (v);
    int mayor = buscar_mayor (v);
    int menor = buscar_menor (v);
    numeros (v, mayor, menor);
}
