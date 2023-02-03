#include <iostream>
using namespace std;

void leer (int& x)
{
    cout << "Introduzca un numero: ";
    cin >> x;
}

void mostrar (int n)
{
    cout << n << ", ";
}

bool seek (int n)
{
    bool primo;
    int cnt = 2;
    for (int div = 2; div <= n / 2; ++div)
    {
        if ((n % div) == 0)
        {
            ++cnt;
        }
    }
    if (cnt == 2)
    {
        primo = true;
    }
    else
    {
        primo = false;
    }
    return primo;
}

void prim (int x)
{
    bool primo;
    int cnt = 0;
    int n = 2;
    while (cnt < x)
    {
        primo = seek (n);
        if (primo)
        {
            ++cnt;
            mostrar (n);
        }
        n++;
    }
}

int main ()
{
    int input;
    leer (input);
    prim (input);
}
