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

void anyadir_elemento(Notas& v, double valor)
{
    if (v.nelms < int(v.elm.size()))   // Si el nuevo elemento cabe en el array
    {
        v.elm[v.nelms] = valor; // Añade el elemento al final de la lista
        ++v.nelms; // Incrementa la cuenta de elementos
    }
    else
    {
        cout << "Error" << endl;
    }
}
void leer_notas_alternativo(Notas& v)
{
    double valor;
    v.nelms = 0;
    cout << "Introduzca nota del alumno " << v.nelms << " (0 para fin): ";
    cin >> valor;
    while (valor > 0)
    {
        anyadir_elemento(v, valor);
        cout << "Introduzca nota del alumno " << v.nelms << " (0 para fin): ";
        cin >> valor;
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
    leer_notas_alternativo(notas);
    double media = calc_media(notas);
    mostrar_notas(notas, media);
}
