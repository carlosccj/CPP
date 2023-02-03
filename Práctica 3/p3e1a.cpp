#include <iostream>
using namespace std;

int main ()
{
    int num, numfin = 0;
    cout << " Introduzca un numero (>0) ";
    cin >> num;
    while (num<0)
    {
        cout << " Error, introduzca otro numero ";
        cin >> num;
    }
    for (int i=0; i<=num; i++)
    {
        numfin = numfin + i;
    }
    cout << " La suma es " << numfin << endl;
}
