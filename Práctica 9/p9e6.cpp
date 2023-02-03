#include <iostream>
#include <array>
using namespace std;

const int NCOLS = 4;
const int NFILS = 3;
const int MAX_ELEMENTOS = NCOLS * NFILS;

typedef array <int, NCOLS> Fila;
typedef array <Fila, NFILS> Matriz;

struct Unused
{
    int numero;
    int repeticiones;
};

typedef array <Unused, MAX_ELEMENTOS> Unused2;

struct Lista
{
    int nelms = 0;
    Unused2 elm;
};

void leer (Matriz& m, int& k)
{
    cout << "Introduzca k: ";
    cin >> k;
    cout << "Introduzca la matriz 3x4 (por filas): " << endl;
    for (Fila& f : m)
    {
        for (int& x : f)
        {
            cin >> x;
        }
    }
}

bool presente (const Lista& v, int cnt)
{
    bool ok = false;
    for (int i = 0; i < v.nelms; i++)
    {
        if (v.elm[i].numero == cnt)
        {
           ok = true;
        }
    }
    return ok;
}

int buscar_posicion (const Lista& v, int cnt)
{
    int idx = -1;
    for (int i = 0; i < v.nelms && idx == -1; i++)
    {
        if (v.elm[i].numero == cnt)
        {
            idx = i;
        }
    }
    return idx;
}

void anyadir (Lista& v, int cnt)
{
    if (v.nelms < int(v.elm.size()))
    {
        v.elm[v.nelms].numero = cnt;
        v.elm[v.nelms].repeticiones = 1;
        v.nelms++;
    }
}

void ordenar (Lista& v)
{
    for (int k = 0; k < v.nelms - 1; k++)
    {
        for (int j = 0; j < v.nelms - 1; j++)
        {
            if (v.elm[j].repeticiones < v.elm[j + 1].repeticiones)
            {
                int aux = v.elm[j].repeticiones;
                int aux2 = v.elm[j].numero;
                v.elm[j].repeticiones = v.elm[j + 1].repeticiones;
                v.elm[j + 1].repeticiones = aux;
                v.elm[j].numero = v.elm[j + 1].numero;
                v.elm[j + 1].numero = aux2;
            }
        }
    }
}

Lista crear_lista (Lista& v, const Matriz& m)
{
    int cnt;
    for (int f = 0; f < int(m.size()); f++)
    {
        for (int c = 0; c < int(m[f].size()); c++)
        {
            cnt = m[f][c];
            bool esta = presente (v, cnt);
            if (esta)
            {
                int pos = buscar_posicion (v, cnt);
                v.elm[pos].repeticiones++;
            }
            else
            {
                anyadir (v, cnt);
            }
        }
    }
    ordenar (v);
    return v;
}

void mostrar (const Lista& v, int k)
{
    cout << "Los valores que mas se repiten son: ";
    int cnt = k;
    for (int i = 0; i < v.nelms && cnt > 0; i++)
    {
        cout << v.elm[i].numero << " ";
        cnt--;
    }
}

int main ()
{
    Matriz m;
    Lista v;
    int k;
    leer (m, k);
    v = crear_lista (v, m);
    mostrar (v, k);
}
