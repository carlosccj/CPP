#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

const int NFILS = 5;
const int NCOLS = 7;

typedef array <int, NCOLS> Fila;
typedef array <Fila, NFILS> Matriz;

void leer (Matriz& m)
{
    cout << "Introduce una matriz de " << m.size() << " x " << m[0].size() << endl;
    for (int f = 0; f < int(m.size()); f++)
    {
        for (int c = 0; c < int(m[f].size()); c++)
        {
            cin >> m[f][c];
        }
    }
}

int buscar_mayor (const Matriz& m)
{
    int cnt = m[0][0];
    for (const Fila& f : m)
    {
        for (int x : f)
        {
            if (cnt < x)
            {
                cnt = x;
            }
        }
    }
    return cnt;
}

void mostrar (const Matriz& m, int mayor)
{
    int cnt = 0;
    for (int f = 0; f < int(m.size()) && cnt == 0; f++)
    {
        for (int c = 0; c < int(m[f].size()); c++)
        {
            if (mayor == m[f][c])
            {
                cout << endl << "El numero " << mayor << " es el mayor de la matriz" << endl;
                cout << " Se encuentra en [" << f << "][" << c << "]";
                cnt++;
            }
        }
    }
}

int main ()
{
    Matriz m;
    leer (m);
    int mayor = buscar_mayor (m);
    mostrar (m, mayor);
}
