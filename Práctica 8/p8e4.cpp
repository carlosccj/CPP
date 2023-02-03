#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;

const int MAX_ALUMNOS = 20;

struct Perfil
{
    string alumno;
    double nota1;
    double nota2;
    double nota3;
};

typedef array <Perfil, MAX_ALUMNOS> Vector;

struct Lista
{
    int nelms = 0;
    Vector elm;
};

void leer (Lista& v)
{
    v.nelms = 0;
    cout << "Introduce el numero de alumnos de la clase (maximo 20): ";
    cin >> v.nelms;
    for (int i = 0; i < v.nelms; i++)
    {
        cout << "Introduce el nombre del alumno y sus 3 notas: ";
        cin >> v.elm[i].alumno;
        cin >> v.elm[i].nota1;
        cin >> v.elm[i].nota2;
        cin >> v.elm[i].nota3;
    }
}

void mostrar (const Lista& v, double media1, double media2, double media3)
{
    cout << "Alumno" << setw(10) << "Nota-1" << setw(10) << "Nota-2" << setw(10) << "Nota-3" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < v.nelms; i++)
    {
        cout << v.elm[i].alumno;
        if (v.elm[i].nota1 < media1)
        {
            cout << setw(12) << "Suspenso";
        }
        else
        {
            cout << setw(12) << "Aprobado";
        }
        if (v.elm[i].nota2 < media2)
        {
            cout << setw(12) << "Suspenso";
        }
        else
        {
            cout << setw(12) << "Aprobado";
        }
        if (v.elm[i].nota3 < media3)
        {
            cout << setw(12) << "Suspenso";
        }
        else
        {
            cout << setw(12) << "Aprobado";
        }
        cout << endl;
    }
}

void media (const Lista& v)
{
    double media1 = 0;
    double media2 = 0;
    double media3 = 0;
    for (int i = 0; i < v.nelms; i++)
    {
        media1 += v.elm[i].nota1;
        media2 += v.elm[i].nota2;
        media3 += v.elm[i].nota3;
    }
    media1 = media1 / v.nelms;
    media2 = media2 / v.nelms;
    media3 = media3 / v.nelms;
    mostrar (v, media1, media2, media3);
}

int main ()
{
    Lista v;
    leer (v);
    media (v);
}
