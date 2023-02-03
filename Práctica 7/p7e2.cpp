#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

const int NFILS = 5;
const int NCOLS = 5;

typedef array <int, NCOLS> Fila;
typedef array <Fila, NFILS> Matriz;

void leer (Matriz& m)
{
    cout << "Introduzca 5 filas de 5 numeros: " << endl;
    for (Fila& f : m)
    {
        for (int& x : f)
        {
            cin >> x;
        }
    }
}

bool simetrico (const Matriz& m)
{
    bool cnt = true;
    for (int f = 0; f < int(m.size()) && cnt; f++)
    {
        for (int c = 0; c < int(m[0].size()) && cnt; c++)
        {
            if (m[f][c] != m[c][f])
            {
                cnt = false;
            }
        }
    }
    return cnt;
}

void mostrar (const Matriz& m, bool sim)
{
    cout << endl << "La matriz " << endl;
    for (const Fila& f : m)
    {
        for (int x : f)
        {
            cout << setw(2) << x << " ";
        }
        cout << endl;
    }
    if (sim)
    {
        cout << "SI es simetrica" << endl;
    }
    else
    {
        cout << "NO es simetrica" << endl;
    }
}

int main ()
{
    Matriz m;
    leer (m);
    bool sim = simetrico (m);
    mostrar (m, sim);
}
