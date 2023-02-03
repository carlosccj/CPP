#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

const int NCOLS = 7;
const int NFILS = 5;
const char LIBRE = 'o';
const char OCUPADO = 'x';

typedef array <char, NCOLS> Fila;
typedef array <Fila, NFILS> SalaCine;

SalaCine inicializar (SalaCine& m)
{
    for (Fila& f : m)
    {
        for (char& x : f)
        {
            x = LIBRE;
        }
    }
    return m;
}

void mostrar (const SalaCine& sc)
{
    cout << endl << "   0 1 2 3 4 5 6" << endl;
    cout << "----------------" << endl;
    for (int f = 0; f < int(sc.size()); f++)
    {
        cout << f << ": ";
        for (int c = 0; c < int(sc[f].size()); c++)
        {
            cout << sc[f][c] << " ";
        }
        cout << endl;
    }
}

bool comprobar_datos (int f1, int f2, int n)
{
    bool ok = false;
    if (f1 <= f2 && f1 >= 0 && f1 <= 4 && f2 >= 0 && f2 <= 4 && n >= 1 && n <= 7)
    {
        ok = true;
    }
    return ok;
}

void reservar_asientos (SalaCine& sc, int f, int c, int n)
{
    for (int i = n; i > 0; i--)
    {
        sc[f][c] = OCUPADO;
        c--;
    }
}

void cancelar_reserva (SalaCine& sc, int f, int c, int n)
{
    for (int i = n; i > 0; i--)
    {
        sc[f][c] = LIBRE;
        c--;
    }
}

void cambiar_reserva (SalaCine& sc, int f1, int f2, int n)
{
    {
        bool ok = false;
        int cnt = n;
        for (int f = f1; f <= f2; f++)
        {
            for (int c = 0; c < int(sc[f].size()) && ok == false; c++)
            {
                if (sc[f][c] == OCUPADO)
                {
                    cnt--;
                }
                if (cnt == 0)
                {
                    ok = true;
                    cancelar_reserva (sc, f, c, n);
                    cout << endl << "Asiento cancelado en fila " << f << ", columna " << (c - n + 1) << endl;
                }
            }
            cnt = n;
        }
    }
}

void comprar_ticket_consecutivo (SalaCine& sc, int f1, int f2, int n)
{
    int cnt = n;
    bool ok = false;
    for (int f = f1; f <= f2; f++)
    {
        for (int c = 0; c < int(sc[f].size()) && ok == false; c++)
        {
            if (sc[f][c] == LIBRE)
            {
                cnt--;
            }
            if (cnt == 0)
            {
                ok = true;
                reservar_asientos (sc, f, c, n);
                cout << endl << "Asiento reservado en fila " << f << ", columna " << (c - n + 1) << endl;
            }
        }
        cnt = n;
    }
    if (ok == false)
    {
        cambiar_reserva (sc, f1, f2, n);
    }

}

int main ()
{
    int f1, f2, n;
    int cnt = 0;
    SalaCine sc;
    sc = inicializar (sc);
    while (cnt == 0)
    {
        mostrar (sc);
        cout << endl << "Introduzca un rango de filas valido (0 a 4): ";
        cin >> f1 >> f2;
        cout << "Introduzca el numero de asientos que desea reservar (1 a 7): ";
        cin >> n;
        bool valido = comprobar_datos (f1, f2, n);
        if (valido)
        {
            comprar_ticket_consecutivo (sc, f1, f2, n);
        }
        else
        {
            cout << endl << "Error. Los datos introducidos no son correctos" << endl;
        }
    }
}
