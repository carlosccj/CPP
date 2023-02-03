#include <iostream>
using namespace std;

void leer (double& x)
{
    cout << "Introduzca un valor de X [0..1]: ";
    cin >> x;
    while ((x < 0) || (x > 1))
    {
        cout << "Error. Introduza una valor de X [0..1]: ";
        cin >> x;
    }
}

void mostrar (double resultado)
{
    cout << "Serie: " << resultado;
}

double numeros (double serie)
{
    double arriba = -1;
    double abajo;
    double fin = 1;
    for (double top = 1; top <= serie; top++)
    {
        arriba = arriba + 2;
        abajo = arriba + 1;
        fin = fin * (arriba / abajo);
    }
    return fin;
}

double potencias (double serie, double x)
{
    double arriba = x;
    double abajo = 1;
    double fin = 0;
    for (double top = 1; top <= serie; top++)
    {
        arriba = arriba * x * x;
        abajo = abajo + 2;
        fin = arriba / abajo;
    }
    return fin;
}

double calcular (double x)
{
    double sumando = x;
    double x_fracs = 1;
    double prev_fracs;
    for (double serie = 1; serie <= 7; serie ++)
    {
        prev_fracs = numeros (serie);
        x_fracs = potencias (serie, x);
        sumando = sumando + (prev_fracs * x_fracs);
    }
    return sumando;
}

int main ()
{
    double x, resultado;
    leer (x);
    resultado = calcular (x);
    mostrar (resultado);

}
