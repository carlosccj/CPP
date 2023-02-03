#include <iostream>
using namespace std;

int main ()
{
    int num;
    cout << " Introduzca un numero: ";
    cin >> num;
    while (num<=0)
    {
        cout << "Error. Introduzca un numero mayor que cero: ";
        cin >> num;
    }
    for (int r=1; r<=num; ++r)
    {
        for (int c=1; c<=num; ++c)
        {
            cout << 'x';
        }
        cout << endl;
    }
}


