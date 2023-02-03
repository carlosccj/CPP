#include <iostream>
using namespace std;

int main ()
{
    int coches;
    double precio, preciofin=0;
    cout << " Introduzca precio de modelos de coche: ";
    cin >> coches;
    for (int i = 1; i <= coches; ++i)
    {
        cout << " Precio modelo " << i << ": ";
        cin >> precio;
        preciofin=(preciofin+precio);
    }
    preciofin=(preciofin/coches);
    cout << "El valor medio de los " << coches << " modelos de coche asciende a " << preciofin << endl;
}
