#include <iostream>
#include <array>
using namespace std;

const int NCOLS = 5;
const int NFILS = NCOLS;
const char LAVA = '*';
const char SAFE = ' ';

typedef array <int, NCOLS> Fila;
typedef array <Fila, NFILS> Superficie;

typedef array <char, NCOLS> Filalav;
typedef array <Filalav, NFILS> LavaSup;

void leer (Superficie& m, int& x, int& y)
{
    m[0][0] = 4; m[4][0] = 4;
    m[1][0] = 5; m[3][0] = 5; m[4][4] = 5;
    m[0][4] = 6; m[1][1] = 6; m[3][1] = 6; m[3][3] = 6; m[4][1] = 6; m[4][2] = 6;
    m[0][1] = 7; m[0][3] = 7; m[1][4] = 7; m[2][0] = 7; m[2][1] = 7; m[2][4] = 7;
    m[0][2] = 8; m[2][2] = 8; m[2][3] = 8; m[3][2] = 8; m[3][4] = 8;
    m[1][2] = 9; m[1][3] = 9; m[4][3] = 9;

    cout << "Introduzca las coordenadas del crater: ";
    cin >> x >> y;
}

void mostrar (const LavaSup& lava)
{
    cout << "-------" << endl;
    for (int f = 0; f < int(lava.size()); f++)
    {
        cout << "|";
        for (int c = 0; c < int(lava[f].size()); c++)
        {
            cout << lava[f][c];
        }
        cout << "|" << endl;
    }
    cout << "-------" << endl;
}

void valid_fil (const Superficie& sup, LavaSup& lava, int f, int fil, int col)
{
    if (fil + f >= 0 && fil + f < int(lava.size()) && sup[fil + f][col] < sup[fil][col] && lava[fil + f][col] != LAVA)
    {
        lava[fil + f][col] = LAVA;
    }
    else if (col + f >= 0 && col + f < int(lava.size()) && sup[fil][col + f] < sup[fil][col] && lava[fil][col + f] != LAVA)
    {
        lava[fil][col + f] = LAVA;
    }
}

void scan (const Superficie& sup, LavaSup& lava, int fil, int col)
{
    for (int f = - 1; f <= 1; f++)
    {
        valid_fil (sup, lava, f, fil, col);
    }
}

void flujo_lava (const Superficie& sup, int fil, int col, LavaSup& lava)
{
    lava[fil][col] = LAVA;
    scan (sup, lava, fil, col);
    int cnt = 0;
    while (cnt < int(lava.size()))
    {
        for (int f = 0; f < int(lava.size()); f++)
        {
            for (int c = 0; c < int(lava[f].size()); c++)
            {
                if (lava[f][c] == LAVA)
                {
                    scan (sup, lava, f, c);
                }
            }
        }
        cnt++;
    }
    mostrar (lava);
}

LavaSup blank (LavaSup& lava)
{
    for (int f = 0; f < int(lava.size()); f++)
    {
        for (int c = 0; c < int(lava[f].size()); c++)
        {
            lava[f][c] = SAFE;
        }
    }
    return lava;
}

int main ()
{
    int f, c;
    Superficie m;
    LavaSup lava = blank (lava);
    leer (m, f, c);
    flujo_lava (m, f, c, lava);
}
