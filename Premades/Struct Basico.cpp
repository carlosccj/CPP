#include <iostream>
using namespace std;

struct fecha
{
    int dia;
    int mes;
    int anyo;
};

struct empleado
{
    int codigo;
    double sueldo;
    fecha fecha_ingreso;
};

void leer_fecha (fecha& f)
{
    cout << "Introduzca anyo de ingreso: ";
    cin >> f.anyo;
    cout << "Introduzca mes de ingreso: ";
    cin >> f.mes;
    cout << "Introduzca dia de ingreso: ";
    cin >> f.dia;
}

void leer_empleado (empleado& e)
{
    cout << "Introduzca los datos del empleado: " << endl;
    cout << "Codigo: ";
    cin >> e.codigo;
    cout << "Sueldo: ";
    cin >> e.sueldo;
    cout << "FECHA DE INGRESO " << endl;
    leer_fecha (e.fecha_ingreso);
}

bool comparar (const fecha& f1, const fecha& f2)
{
    bool ok;
    if (f1.anyo < f2.anyo)
    {
        ok = true;
    }
    else if (f1.anyo > f2.anyo)
    {
        ok = false;
    }
    else if (f1.mes < f2.mes)
    {
        ok = true;
    }
    else if (f1.mes > f2.mes)
    {
        ok = false;
    }
    else if (f1.dia < f2.dia)
    {
        ok = true;
    }
    else if (f1.dia > f2.dia)
    {
        ok = false;
    }
    else
    {
        ok = false;
    }
    return ok;
}

void mostrar (bool menor)
{
    if (menor)
    {
        cout << "El primer empleado tiene mas antiguedad que el segundo.";
    }
    else
    {
        cout << "El segundo empleado tiene mas antiguedad que el primero";
    }
}

int main ()
{
    empleado e1, e2;
    leer_empleado (e1);
    leer_empleado (e2);
    bool menor = comparar (e1.fecha_ingreso, e2.fecha_ingreso);
    mostrar (menor);

}
