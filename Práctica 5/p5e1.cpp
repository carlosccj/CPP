#include <iostream>
using namespace std;

const int S = 1;
const double MIN = 0.0001;

void leer (long double& x)
{
    cout << "Introduzca el valor de X [0..1]: ";
    cin >> x;
    while (x >= 1)
    {
        cout << "Error. Introduzca un valor correcto [0..1]: ";
        cin >> x;
    }
}

double potencia (double top, long double x)
{
    top = top * x;
    return top;
}

long double factorial (long double bott)
{
    long double fact = 1;
    for (int i = 2; i <= bott; i++)
    {
        fact = fact * i;
    }
    return fact;
}

long double serie (long double x)
{
    long double acum = S + x;
    double top = x;
    long double bott = 2;
    long double div = top / bott;

    do
    {
        top = potencia (top, x);
        long double denomin = factorial (bott);
        div = top / denomin;
        acum = acum + div;
        bott++;
    }
    while (div >= MIN);
    return acum;
}

void mostrar (long double x)
{
    cout << "Serie: " << x;
}

int main ()
{
    long double num;
    leer (num);
    long double result = serie (num);
    mostrar (result);
}
