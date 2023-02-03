#include <iostream>
using namespace std;

const char ESP = ' ';
const int COL = 17;

void leer (int& x)
{
    cout << "Introduzca el numero de filas (menor de 10): ";
    cin >> x;
    while ((x >= 10) || (x <= 0))
    {
        cout << "Error. Introduzca el numero de filas (menor de 10): ";
        cin >> x;
    }
}

void numpost (int f)
{
    for (int i = f - 1; i > 0; i--)
    {
        cout << i;
    }
    cout << endl;
}

void numant (int f)
{
    for (int i = 1; i <= f; i++)
    {
        cout << i;
    }
}

void esp (int f, int x)
{
    for (int i = f; i <= x; i++)
    {
        cout << ESP;
    }
}

int pyr (int x)
{
    for (int f = 1; f <= x; f++)
    {
       esp (f, x);
       numant (f);
       numpost (f);
    }
    return x;
}

int main ()
{
    int numf;
    leer (numf);
    pyr (numf);
}
