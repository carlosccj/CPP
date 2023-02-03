#include <iostream>
using namespace std;

void leer (int& filas)
{
    cout << "Introduzca el numero de filas: ";
    cin >> filas;
    while ((filas < 1) || (filas > 9))
    {
        cout << "Error. Introduzca numero de filas: ";
        cin >> filas;
    }
}

void incremento_circular (int filas, int maxi)
{
    for (int i = 1; i <= filas; i++)
    {
        if (maxi < filas)
        {
            cout << maxi << " ";
            maxi++;
        }
        else
        {
            maxi = 0;
            cout << maxi << " ";
            maxi ++;
        }
    }
    cout << endl;
}

void crear (int filas)
{
    int maxi = 0;
    for (int i = 1; i <= filas; i++)
    {
        incremento_circular (filas, maxi);
        maxi++;
    }
}

int main ()
{
    int filas;
    leer (filas);
    crear (filas);
}
