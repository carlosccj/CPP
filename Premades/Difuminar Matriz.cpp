#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

const int NFILS = 3;
const int NCOLS = 4;
typedef array<int, NCOLS> Fila;
typedef array<Fila, NFILS> Matriz;

void leer(Matriz& m)
{
    cout << "Introduce " << m.size() << " x " << m[0].size() << " números" << endl;
    for (int f = 0; f < int(m.size()); ++f)
    {
        for (int c = 0; c < int(m[f].size()); ++c)
        {
            cin >> m[f][c];
        }
    }
}

void mostrar(const Matriz& m)
{
    for (int f = 0; f < int(m.size()); ++f)
    {
        for (int c = 0; c < int(m[f].size()); ++c)
        {
            cout << setw(3) << m[f][c] << " ";
        }
        cout << endl;
    }
}

bool es_valido(const Matriz& m, int f, int c, int ff, int cc)
{
    return (0 <= f+ff && f+ff < int(m.size())) && (0 <= c+cc && c+cc < int(m[f+ff].size()));
}

double media_vecinos(const Matriz& m, int f, int c)
{
    int nvec = 0;
    int suma = 0;
    for (int ff = -1; ff <= +1; ++ff)
    {
        for (int cc = -1; cc <= +1; ++cc)
        {
            if (es_valido(m, f, c, ff, cc))
            {
                suma += m[f+ff][c+cc];
                ++nvec;
            }
        }
    }
    return double(suma) / double(nvec);
}

void difuminar(Matriz& m)
{
    Matriz aux = m;
    for (int f = 0; f < int(m.size()); ++f)
    {
        for (int c = 0; c < int(m[f].size()); ++c)
        {
            m[f][c] = media_vecinos(aux, f, c);
        }
    }
}

int main ()
{
    Matriz m;
    leer(m);
    difuminar(m);
    mostrar(m);
}


