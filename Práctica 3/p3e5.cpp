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
    if (num%2==0)
    {
        for (int c=1; c<=num; ++c)
        {
            for (int s=(num/2); s<num; ++s)
            {
                cout << 'x' << 'o';
            }
            cout << endl;
        }
    }
    else
    {
        for (int c=1; c<=num; ++c)
        {
            for (int s=((num+1)/2); s<num; ++s)
            {
                cout << 'x' << 'o';
            }
            cout << 'x';
            cout << endl;
        }
    }
}
