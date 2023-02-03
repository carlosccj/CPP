#include<iostream>
#include<array>
using namespace std;

const int MAX_ELEMENTS = 10;

typedef array<int, MAX_ELEMENTS> Unused;

struct Lista
{
    int nelms = 0;
    Unused elm;
};

void leer(Lista& lista1, int& x)
{
    cout << "Cuantos numeros desea introducir (maximo 10): ";
    cin >> lista1.nelms;
    while ((lista1.nelms < 1) || (lista1.nelms > MAX_ELEMENTS))
    {
        cout << "ERROR. Cuantos numeros desea introducir (maximo 10): ";
        cin >> lista1.nelms;
    }
    cout << "Introduzca " << lista1.nelms << " numeros: ";
    for (int i = 0; i < lista1.nelms; i++)
    {
        cin >> lista1.elm[i];
    }
    cout << "Introduzca el numero de repeticiones para realizar la criba: ";
    cin >> x;

}

bool comparar(const Lista& lista1, int i, int x)
{
    int cnt = 0;
    bool ok = false;
    for (int j = 0; j < lista1.nelms; j++)
    {
        if (lista1.elm[j] == lista1.elm[i])
        {
            cnt++;
        }
    }
    if (cnt == x)
    {
        ok = true;
    }
    return ok;
}

bool repetido(const Lista& lista2, int num)
{
    bool rep = false;
    for (int i = 0; i < lista2.nelms && !rep; i++)
    {
        if (lista2.elm[i] == num)
        {
            rep = true;
        }
    }
    return rep;
}

Lista criba(const Lista& lista1, int x)
{
    Lista lista2;
    lista2.nelms = 0;
    int cnt = 0;
    for (int i = 0; i < lista1.nelms; i++)
    {
        bool ok = comparar(lista1, i, x);
        if (ok)
        {
            bool rep = repetido(lista2, lista1.elm[i]);
            if (!rep)
            {
                lista2.nelms++;
                lista2.elm[cnt] = lista1.elm[i];
                cnt++;
            }
        }
    }
    return lista2;
}

void mostrar(const Lista& lista2)
{
    cout << "La lista cribada es: ";
    for (int i = 0; i < lista2.nelms; i++)
    {
        cout << lista2.elm[i] << " ";
    }
}

int main()
{
    Lista lista1;
    int x;
    leer(lista1, x);
    Lista lista2 = criba(lista1, x);
    mostrar(lista2);
}
