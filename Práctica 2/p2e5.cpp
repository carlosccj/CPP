#include <iostream>
using namespace std;

double const IVA = 0.12;
double const REBAJA = 0.05;
int const PRECIO_LIM = 300;

int main ()
{
    int articulo;
    double precio, precio_total, iva;
    cout << " Introduzca la cantidad de unidades adquiridas ";
    cin >> articulo;
    cout << " Introduzca el precio de una unidad ";
    cin >> precio;

    iva = ((articulo*precio) * IVA);
    precio_total = ((articulo*precio) + iva);

    if (precio_total>=PRECIO_LIM) {
        precio_total = (precio_total-(precio_total*REBAJA));
        cout << " Se aplica el descuento del 5% " << endl;
        cout << " El precio total a pagar es " << precio_total << endl;
    } else {
    cout << " El precio total es " << precio_total << endl;
    }
}

