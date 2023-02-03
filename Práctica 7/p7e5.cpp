#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

const int NFILS = 5;
const int NCOLS = 5;

typedef array <int, NCOLS> Fila;
typedef array <Fila, NFILS> Cuadrado;

int circular (const Cuadrado& A, int x)
{
    x -= 1;
    if (x < 0)
    {
        x = (int(A.size()) - 1);
    }
    return x;
}

int circular_f (const Cuadrado& A, int x)
{
    x += 1;
    if (x > (int(A.size()) - 1))
    {
        x = 0;
    }
    x += 1;
    if (x > (int(A.size()) - 1))
    {
        x = 0;
    }
    return x;
}

int circular_c (const Cuadrado& A, int x)
{
    x += 1;
    if (x > (int(A.size()) - 1))
    {
        x = 0;
    }
    return x;
}

void mostrar (const Cuadrado& A)
{
    cout << "El cuadrado magico para N = " << int(A.size()) << " es: " << endl << endl;
    for (const Fila& f : A)
    {
        for (int x : f)
        {
            cout << setw(2) << x << " ";
        }
        cout << endl;
    }
}

void construirMagico (Cuadrado& A)
{
    for (int a = 0; a < int(A.size()); a++)
    {
        for (int b = 0; b < int(A[a].size()); b++)
            {
                A[a][b] = 0;
            }
    }
    int cnt = 2;
    int f = 0;
    f = circular (A, f);
    int c = NCOLS / 2;
    c = circular (A, c);
    int inc = (NCOLS * NCOLS) - 1;
    A[0][NCOLS / 2] = 1;
    while (inc != 0)
    {
        if (A[f][c] != 0)
        {
            f = circular_f (A, f);
            c = circular_c (A, c);
            A[f][c] = cnt;
            f = circular (A, f);
            c = circular (A, c);
            inc--;
            cnt++;
        }
        else
        {
            A[f][c] = cnt;
            f = circular (A, f);
            c = circular (A, c);
            inc--;
            cnt++;
        }
    }
    mostrar (A);
}

int main ()
{
    Cuadrado A;
    construirMagico (A);
}
