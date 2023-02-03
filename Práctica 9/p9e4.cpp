#include <iostream>
#include <array>
#include <string>
using namespace std;

const int MAX_ELEMENTOS = 20;

struct Unused
{
    string palabra;
    int fpos;
    int lpos;
};

typedef array <Unused, MAX_ELEMENTOS> Unused2;

struct Lista
{
    int nelms = 0;
    Unused2 elm;
};

void mostrar (const Lista& v)
{
    for (int i = 0; i < v.nelms; i++)
    {
        cout << v.elm[i].palabra << " " << v.elm[i].fpos << " " << v.elm[i].lpos << endl;
    }
}

bool comparar (const Lista& v, const string& cadena)
{
    bool ok = false;
    for (int i = 0; i < v.nelms; i++)
    {
        if (v.elm[i].palabra == cadena)
        {
            ok = true;
        }
    }
    return ok;
}

int buscar_posicion (const Lista& v, const string& cadena)
{
    int idx = -1;
    for (int i = 0; i < v.nelms && idx == -1; i++)
    {
        if (v.elm[i].palabra == cadena)
        {
            idx = i;
        }
    }
    return idx;
}

void anyadir (Lista& v, const string& cadena, int cnt)
{
    if (v.nelms < int(v.elm.size()))
    {
        v.elm[v.nelms].palabra = cadena;
        v.elm[v.nelms].fpos = cnt;
        v.elm[v.nelms].lpos = cnt;
        v.nelms++;
    }
}

void procesar (Lista& v, const string& cadena, int cnt)
{
    bool presente = comparar (v, cadena);
    if (presente)
    {
        int pos = buscar_posicion (v, cadena);
        v.elm[pos].lpos = cnt;
    }
    else
    {
        anyadir (v, cadena, cnt);
    }
}

int main ()
{
    Lista v;
    string cadena;
    cout << "Introduzca el texto en minusculas hasta (fin): ";
    cin >> cadena;
    int cnt = 1;
    while (cadena != "fin")
    {
        procesar (v, cadena, cnt);
        cin >> cadena;
        cnt++;
    }
    mostrar (v);
}
