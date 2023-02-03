#include <iostream>
#include <string>
#include <array>
using namespace std;

int const ELEMENTOS = 20;

typedef array <string, ELEMENTOS> Lista;

bool comprobar (const string& principal, const string& cadena)
{
    bool ok = false;
    int cnt = int(principal.size());
    int i = 0;
    for (int j = 0; j < int(cadena.size()) && cnt > 0; j++)
    {
        if (cadena[j] == principal[i])
        {
            cnt--;
            i++;
        }
        else
        {
            cnt = int(principal.size());
            i = 0;
        }
    }
    if (cnt == 0)
    {
        ok = true;
    }
    return ok;
}

int main ()
{
    string principal;
    string cadena;
    Lista v;
    cout << "Introduzca el patron en minusculas: ";
    getline (cin, principal, '\n');
    cout << "Introduzca el texto en minusculas hasta (fin): ";
    int cnt = 0;
    while (cadena != "fin")
    {
        cin >> cadena;
        bool ok = comprobar (principal, cadena);
        if (ok)
        {
            v[cnt] = cadena;
            cnt++;
        }
    }
    cout << "Resultado: " << endl;
    for (int i = 0; i <= cnt; i++)
    {
        cout << v[i] << " ";
    }
}
