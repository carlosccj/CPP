#include <iostream>
using namespace std;

int main ()
{
    char c;
    cout << " Introduzca un texto terminado en un punto ";
    cin.get(c);
    while (c!='.')
    {
        cout << int(c) << " ";
        cin.get(c);

    }

}
