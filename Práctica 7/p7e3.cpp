#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

const int NFILS = 5;
const int NCOLS = 5;
const int N2 = 25;

typedef array <int, NCOLS> Fila;
typedef array <Fila, NFILS> Matriz;

void leer (Matriz& m)
{
    cout << "Introduce un cuadrado 5 x 5: " << endl;
    for (Fila& f : m)
    {
        for (int& x : f)
        {
            cin >> x;
        }
    }
}

bool sum_fil (const Matriz& m, int magic)
{
    bool cnt = true;
    int sum = 0;
    for (int f = 0; f < int(m.size()) && cnt; f++)
    {
        for (int c = 0; c < int(m[f].size()) && cnt; c++)
        {
            sum += m[f][c];
        }
        if (sum != magic)
        {
            cnt = false;
        }
        sum = 0;
    }
    return cnt;
}

bool sum_col (const Matriz& m, int magic)
{
    bool mag = true;
    int sum = 0;
    for (int cnt = 0; cnt < int(m.size()); cnt++)
    {
        for (int f = 0; f < int(m.size()); f++)
        {
            {
                sum += m[f][cnt];
            }
        }
        if (sum != magic)
        {
            mag = false;
        }
        sum = 0;
    }
    return mag;
}

bool sum_diag_a (const Matriz& m, int magic)
{
    bool mag = true;
    int f = 0;
    int c = 0;
    int sum = 0;
    while ((f < 5) && (c < 5))
    {
        sum += (m[f][c]);
        f++;
        c++;
    }
    if (sum != magic)
    {
        mag = false;
    }
    return mag;
}

bool sum_diag_b (const Matriz& m, int magic)
{
    bool mag = true;
    int sum = 0;
    int f = 0;
    int c = 4;
    while (f < 5)
    {
        sum += m[f][c];
        f++;
        c--;
    }
    if (sum != magic)
    {
        mag = false;
    }
    return mag;
}

bool cuadrado (const Matriz& m)
{
    bool mag = true;
    for (const Fila& f : m)
    {
        for (int x : f)
        {
            if (x > N2 && x > 0)
            {
                mag = false;
            }
        }
    }
    return mag;
}

bool esMagico (const Matriz& m)
{
    bool magico = false;
    int magic = m[0][0] + m[0][1] + m[0][2] + m[0][3] + m[0][4];
    bool n2 = cuadrado (m);
    bool fila = sum_fil (m, magic);
    bool columna = sum_col (m, magic);
    bool diagonal_a = sum_diag_a (m, magic);
    bool diagonal_b = sum_diag_b (m, magic);
    if (n2 && fila && columna && diagonal_a && diagonal_b)
    {
        magico = true;
    }
    return magico;
}

void mostrar (bool magico)
{
    if (magico)
    {
        cout << "SI es magico" << endl;
    }
    else
    {
        cout << "NO es magico" << endl;
    }
}

int main ()
{
    Matriz m;
    leer (m);
    bool magico = esMagico (m);
    mostrar (magico);
}
