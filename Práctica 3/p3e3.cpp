#include <iostream>
using namespace std;

int main ()
{
    int num;
    cout << " Introduzca un numero: ";
    cin >> num;
    while (num<=0)
    {
        cout << " Error. Introduzca un numero mayor que cero: ";
        cin >> num;
    }
    for (int i=1; i<=num; ++i)
    {
        cout << 'x';
    }
}
