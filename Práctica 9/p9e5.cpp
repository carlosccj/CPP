#include <iostream>
#include <array>
#include <string>
using namespace std;

const int NCOLS = 6;
const int NFILS = 6;

typedef array <char, NCOLS> Fila;
typedef array <Fila, NFILS> Matriz;


const Matriz CLAVE = {{
{{'p','k','a','f','5','v'}},
{{'e','9','o','t','y','0'}},
{{'s','3','z','7','d','j'}},
{{'r','n','b','u','m','1'}},
{{'2','w','4','h','8','g'}},
{{'c','x','6','q','i','l'}}
}};

void leer (string& texto)
{
    cout << "Introduzca el texto (sin espacios): ";
    cin >> texto;
}

void mostrar (const string& texto, const string& resultado, const string& crib)
{
    cout << "Entrada: " << "[" << texto << "]" << endl;
    cout << "Cifrado: " << "[" << resultado << "]" << endl;
    cout << "Descifrado: " << "[" << crib << "]" << endl;
}

string cribar (string& texto)
{
    string cribado = "";
    for (int i = 0; i < int(texto.size()); i++)
    {
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= '0' && texto[i] <= '9'))
        {
            cribado += texto[i];
        }
    }
    return cribado;
}

char buscar_filas (const string& par)
{
    int fil_a = 0;
    int fil_b = 0;
    for (int f = 0; f < int(CLAVE.size()); f++)
    {
        for (int c = 0; c < int(CLAVE[f].size()); c++)
        {
            if (CLAVE[f][c] == par[0])
            {
                fil_a = f;
            }
            else if (CLAVE[f][c] == par[1])
            {
                fil_b = f;
            }
        }
    }
    char fin = CLAVE[fil_a][fil_b];
    return fin;
}

char buscar_columnas (const string& par)
{
    int col_a = 0;
    int col_b = 0;
    for (int f = 0; f < int(CLAVE.size()); f++)
    {
        for (int c = 0; c < int(CLAVE[f].size()); c++)
        {
            if (CLAVE[f][c] == par[0])
            {
                col_a = c;
            }
            else if (CLAVE[f][c] == par[1])
            {
                col_b = c;
            }
        }
    }
    char fin = CLAVE[col_a][col_b];
    return fin;
}

string cifrar (string& texto, int i)
{
    string cambiado = "";
    string par = texto.substr(i, 2);
    cambiado += buscar_filas (par);
    cambiado += buscar_columnas (par);
    return cambiado;
}

int numero_letras (const string& texto)
{
    int cnt = 0;
    for (int i = 0; i < int(texto.size()); i++)
    {
       cnt++;
    }
    return cnt;
}

string analizar (string& texto)
{
    string cifrado = "";
    for (int i = 0; i < int(texto.size()); i++)
    {
       cifrado += cifrar (texto, i);
       i += 1;
    }
    return cifrado;
}

string recortar (string& texto)
{
    int letras = numero_letras (texto);
    if (letras % 2 != 0)
    {
        texto.resize(int(texto.size()) - 1);
    }
    return texto;
}

int main ()
{
    string texto;
    leer (texto);
    string crib = cribar (texto);
    texto = crib;
    crib = recortar (crib);
    string resultado = analizar (crib);
    mostrar (texto, resultado, crib);
}
