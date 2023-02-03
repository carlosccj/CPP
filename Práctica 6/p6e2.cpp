#include <iostream>
#include <array>
using namespace std;

const int MAX_ESTATURAS = 50;

typedef array <double, MAX_ESTATURAS> Estatura;

struct Altura
{
    int nelms = 0;
    Estatura elm;
};

void leer (Altura& v)
{
    cout << "Cuantas estaturas va a introducir (maximo 50): ";
    cin >> v.nelms; // Numero de elementos con el que se va a trabajar
    while ((v.nelms <= 0) || (v.nelms > 50))
    {
        cout << "Error, introducir un numero valido." << endl;
        cout << "Cuantas estaturas va a introducir (máximo 50): ";
        cin >> v.nelms;
    }
    for (int i = 0; i < v.nelms; i++)
    {
        cout << "Introduzca la estatura " << i << ": ";
        cin >> v.elm[i]; // Enumerar cada uno de los elementos
    }
}

double calc_media (const Altura& v)
{
    double suma = 0;
    for (int i = 0; i < v.nelms; i++)
    {
        suma += v.elm[i];
    }
    return suma / v.nelms;
}

void mostrar (const Altura& v, double m)
{
    cout << "La media es: " << m << endl;
    int bajos = 0;
    int altos = 0;
    for (int i = 0; i < v.nelms; i++)
    {
        if (v.elm[i] < m)
        {
            bajos++;
        }
        else
        {
            altos++;
        }
    }
    cout << "Numero de alumnos mas bajos que la media: " << bajos << endl;
    cout << "Numero de alumnos mas altos que la media: " << altos << endl;
}

int main ()
{
    Altura x; // Declarar una variable del tipo del struct (Altura)
    leer (x);
    double media = calc_media(x);
    mostrar (x, media);
}
