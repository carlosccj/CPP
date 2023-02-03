#include <iostream>
#include <array>
#include <iomanip>
#include <string>
using namespace std;

const int NCOLS = 15;
const int NFILS = 10;

const int MAX_ELM_ARRAY = 10;

typedef array <int, NCOLS> Fila;
typedef array <Fila, NFILS> Matriz;

struct Votos
{
    string partido;
    int nvots;
};

typedef array <Votos, MAX_ELM_ARRAY> Principal;

struct Pol
{
    int nelms = 0;
    Principal elm;
};

typedef array <Votos, MAX_ELM_ARRAY> Principal;

void leer (int& carg, Pol& part)
{
    cout << "Introduzca el Numero de Cargos (>= 1 y <= 15): ";
    cin >> carg;
    while (carg < 1 || carg > 15)
    {
        cout << "Error. Introduzca el Numero de Cargos (>= 1 y <= 15): ";
        cin >> carg;
    }
    cout << "Introduzca el Numero de Partidos (>= 1 y <= 10): ";
    cin >> part.nelms;
    while (part.nelms < 1 || part.nelms > 10)
    {
        cout << "Error. Introduzca el Numero de Partidos (>= 1 y <= 10): ";
    }
    cout << "Introduzca el Nombre y el Numero de Votos por Partido: " << endl;
    for (int i = 0; i < part.nelms; i++)
    {
        cout << "Partido " << i + 1 << ": ";
        cin >> part.elm[i].partido;
        cin >> part.elm[i].nvots;
    }
}

void mostrar (const Pol& electos)
{
    cout << endl << "Los Cargos Electos son: " << endl;
    for (int i = 0; i < electos.nelms; i++)
    {
        if (electos.elm[i].nvots > 0)
        {
            cout << electos.elm[i].partido << ": " << electos.elm[i].nvots << endl;
        }
    }
}

Matriz crear_matriz (const Pol& part, int carg)
{
    Matriz m;
    int cnt = 1;
    for (int f = 0; f < int(m.size()); f++)
    {
        for (int c = 0; c < int(m[f].size()); c++)

            if (f < part.nelms && c < carg)
            {
                m[f][c] = part.elm[f].nvots / cnt;
                cnt++;
            }
            else
            {
                m[f][c] = 0;
            }
        cnt = 1;
    }
    return m;
}

int alfa (const Matriz& m, int cnt)
{
    int mayor = m[0][0];
    for (int f = 0; f < int(m.size()); f++)
    {
        for (int c = 0; c < int(m[f].size()); c++)
        {
            if (m[f][c] > mayor && m[f][c] < cnt)
            {
                mayor = m[f][c];
            }
        }
    }
    return mayor;
}

int seek (const Matriz& m, int cnt)
{
    int result = 0;
    for (int f = 0; f < int(m.size()); f++)
    {
        for (int c = 0; c < int(m[f].size()); c++)
        {
            if (cnt == m[f][c])
            {
                result = f;
            }
        }
    }
    return result;
}

void eliminar (Matriz& m, int cnt)
{
    for (int f = 0; f < int(m.size()); f++)
    {
        for (int c = 0; c < int(m[f].size()); c++)
        {
            if (m [f][c] == cnt)
            {
                (m[f][c] = 0);
            }
        }
    }
}

void recuento_votos (Matriz& m, const Pol& part, int carg)
{
    Pol electos = part;
    for (int e = 0; e < electos.nelms; e++)
    {
        electos.elm[e].nvots = 0;
    }

    int recuento = 0;
    int cnt = 0;
    for (int i = 0; i < carg; i++)
    {
        cnt = alfa (m, cnt);
        recuento = seek (m, cnt);
        electos.elm[recuento].nvots += 1;
        eliminar (m, cnt);
    }
    mostrar (electos);
}

int main ()
{
    int carg;
    Pol part;
    leer (carg, part);
    Matriz m = crear_matriz (part, carg);
    recuento_votos (m, part, carg);
}
