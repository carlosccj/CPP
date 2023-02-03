#include <iostream>
#include <array>
using namespace std;

const int NALUMNOS = 5;
typedef array<double, NALUMNOS> Notas;

void leer_notas(Notas& v)
{
    for (int i = 0; i < int(v.size()); ++i)
    {
        cout << "Introduzca nota del alumno " << i << ": ";
        cin >> v[i];
    }
}

double calc_media(const Notas& v)
{
    double suma = 0.0;
    for (double x : v)   // FOR-EACH
    {
        suma += x;
    }
    return suma / double(v.size());
}

void mostrar_notas(const Notas& v, double media)
{
    for (int i = 0; i < int(v.size()); ++i)
    {
        if (v[i] >= media)
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
