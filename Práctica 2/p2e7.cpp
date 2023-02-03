#include <iostream>
using namespace std;

int main ()
{
    int mes;
    cout << " Introduzca numero de mes (del 1 hasta el 12): " << endl;
    cin >> mes;

    if ((mes<0) || (mes>12))
    {
        cout << " Mes erroneo " << endl;
    }
    else
    {
        switch (mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << " Ese mes tiene 31 dias " << endl;
            break;
        case 2:
            cout << " Ese mes tiene 28 dias " << endl;
            break;
        default:
            cout << " Ese mes tiene 30 dias " << endl;
            break;
        }
    }
}
