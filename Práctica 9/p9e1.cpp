#include <iostream>
#include <array>
#include <string>
#include <iomanip>
using namespace std;

struct Inf
{
    int tamano;
    int repeticiones;
};

const int MAX_ELEMENTOS = 20;
typedef array <Inf, MAX_ELEMENTOS> Word;

struct Lista
{
    int nelms = 0;
    Word elm;
};

bool comprobar (Lista& v, int tmno)
{
    bool ok = false;
    for (int i = 0; i < v.nelms; i++)
    {
        if (tmno == v.elm[i].tamano)
        {
            ok = true;
            v.elm[i].repeticiones++;
        }
    }
    return ok;
}

void anyadir (Lista& v, int tmno)
{
    if (v.nelms < int(v.elm.size()))
    {
        v.elm[v.nelms].tamano = tmno;
        v.elm[v.nelms].repeticiones = 1;
        v.nelms++;
    }
}

void establecer (Lista& v, const string& cadena)
{
    int tmno = int(cadena.size());
    bool esta = comprobar (v, tmno);
    if (esta == false)
    {
        anyadir (v, tmno);
    }
}

void mostrar (const Lista& v)
{
    cout << "Longitudes" << "  " << "Repeticiones" << endl;
    for (int i = 0; i < v.nelms; i++)
    {
        cout << v.elm[i].tamano << setw(12) << v.elm[i].repeticiones << endl;
    }
}

void leer (string& cadena)
{
    cout << "Introduzca un texto (fin para terminar): ";
    cin >> cadena;
}

int main ()
{
    string cadena;
    Lista v;
    leer (cadena);
    while (cadena != "fin")
    {
        establecer (v, cadena);
        cin >> cadena;
    }
    mostrar (v);
}
