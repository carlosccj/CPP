#include <iostream>
#include <array>
#include <string>
using namespace std;

void ordenar (string& palabra)
{
    for (int k = 0; k < int(palabra.size() - 1); ++k)
    {
        for (int i = 0; i < int(palabra.size() - 1); ++i)
        {
            if (palabra[i] > palabra[i + 1])
            {
                char aux = palabra[i];
                palabra[i] = palabra[i + 1];
                palabra[i + 1] = aux;
            }
        }
    }
}

bool comparar (const string& principal, const string& cadena)
{
    string org = principal;
    string sig = cadena;
    bool igual = false;
    ordenar (org);
    ordenar (sig);
    if (org == sig)
    {
        igual = true;
    }
    return igual;
}

void mostrar (const string& principal, int cnt)
{
    cout << "En este texto hay " << cnt << " anagramas como <" << principal << ">";
}

int main ()
{
    string cadena;
    string principal;
    cout << "Introduzca el texto a comprobar hasta (fin) con el anagrama a comprobar al principio: ";
    getline (cin, principal, ' ');
    int cnt = 0;
    while (cadena != "fin")
    {
        cin >> cadena;
        if (int(principal.size()) == int(cadena.size()))
        {
            bool ok = comparar (principal, cadena);
            if (ok)
            {
                cnt++;
            }
        }
    }
    mostrar (principal, cnt);
}
