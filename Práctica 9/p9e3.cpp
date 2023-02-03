#include <iostream>
#include <array>
#include <string>
using namespace std;

const int NCOLS = 12;
const int NFILS = 7;
const char FONDO = '.';
const char LINEA = '*';

typedef array <char, NCOLS> Fila;
typedef array <Fila, NFILS> Matriz;

void leer (Matriz& tri)
{
    cout << "Introduce la imagen de 7 x 12 caracteres: " << endl;
    for (int f = 0; f < int(tri.size()); f++)
    {
        for (int c = 0; c < int(tri[f].size()); c++)
        {
            cin >> tri[f][c];
        }
    }
}

void mostrar (int resultado)
{
    cout << "Resultado: " << resultado;
}

int empezar_cuenta (const Matriz& tri)
{
    bool ok = false;
    int cnt = 0;
    for (int f = 0; f < int(tri.size()) && ok == false; f++)
    {
        for (int c = 0; c < int(tri[f].size()) && ok == false; c++)
        {
            if (tri[f][c] == LINEA)
            {
                ok = true;
                cnt = f;
            }
        }
    }
    return cnt;
}

bool fila_de_uno (const Matriz& tri, int fil)
{
    bool ok = true;
    int cnt = 0;
    for (int c = 0; c < int(tri[fil].size()) && ok == true; c++)
    {
        if (tri[fil][c] == LINEA)
        {
            cnt++;
        }
    }
    if (cnt < 2)
    {
        ok = false;
    }
    return ok;
}

int anchura (const Matriz& tri, int fil, int col)
{
    int cnt = 1;
    bool terminar = false;
    bool fila_valida = fila_de_uno (tri, fil);
    while (terminar == false && fila_valida == true)
    {
        if (tri[fil][col + 1] == FONDO && col < int(tri[fil].size() - 2))
        {
            cnt++;
            col++;
        }
        else
        {
            terminar = true;
        }
    }
    return cnt + 1;
}

int calcular_radio (const Matriz& tri)
{
    int cntact = 0;
    int cntlast = -1;
    int resultado = 0;
    bool encontrado = false;
    int cuenta = empezar_cuenta (tri);
    for (int f = cuenta; f < int(tri.size()) && resultado == 0; f++)
    {
        encontrado = false;
        for (int c = 0; c < int(tri[f].size()) && resultado == 0 && encontrado == false; c++)
        {
            if (tri[f][c] == LINEA)
            {
                encontrado = true;
                cntact = anchura (tri, f, c);
                if (cntact > cntlast)
                {
                    cntlast = cntact;
                }
                else
                {
                    resultado = cntlast;
                }
            }
        }
    }
    if(resultado == 0)
    {
        resultado += 1;
    }
    return resultado;
}

int main ()
{
    Matriz tri;
    leer (tri);
    int radio = calcular_radio (tri);
    mostrar (radio);


}
