#include <iostream>
#include <array>
using namespace std;

const int MAX_ALUMNOS = 20;

typedef array<double, MAX_ALUMNOS> Datos;

struct Notas
{
    int nelms = 0; // aseguramos que se inicializa correctamente a cero
    Datos elm;
};

double calc_media(const Notas& v)
{
    double suma = 0.0;
    if (v.nelms > 0)
    {
        for (int i = 0; i < v.nelms; ++i)
        {
            suma += v.elm[i];
        }
        suma = suma / double(v.nelms);
    }
    return suma;
}

void leer_notas(Notas& v)
{
    cout << "Introduzca total de alumnos: ";
    cin >> v.nelms;
    if (v.nelms <= 0 || v.nelms > int(v.elm.size()))
    {
        v.nelms = 0;
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < v.nelms; ++i)
        {
            cout << "Introduzca nota del alumno " << i << ": ";
            cin >> v.elm[i];
        }
    }
}


void mostrar_notas(const Notas& v, double media)
{
    for (int i = 0; i < v.nelms; ++i)
    {
        if (v.elm[i] >= media)
        {
            cout << "Alumno: " << i << " Aprobado" << endl;
        }
        else
        {
            cout << "Alumno: " << i << " Suspenso" << endl;
        }
    }
}

int main()
{
    Notas notas;
    leer_notas(notas);
    double media = calc_media(notas);
    mostrar_notas(notas, media);
}


