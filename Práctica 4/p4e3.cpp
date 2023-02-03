#include <iostream>
using namespace std;

void leer (int& a, int& b)
{
    cout << "Introduzca dos numeros: ";
    cin >> a >> b;
}

bool amig (int x, int y)
{
    bool amigos;
    if (x == y)
    {
        amigos = true;
    }
    else
    {
        amigos = false;
    }
    return amigos;
}

int div (int x)
{
    int sum = 0;
    for (int i = 1; i < x; i++)
    {
        if (x % i == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}

void mostrar (bool x, bool y, int a, int b)
{
    if (((x) && (y)) && (a != b))
    {
        cout << a << " y " << b << " son amigos";
    }
    else
    {
        cout << a << " y " << b << " no son amigos";
    }
}

int main ()
{
    int a, b;
    leer (a, b);
    int diva = div (a);
    int divb = div (b);
    bool a_amigo_b = amig (diva, b);
    bool b_amigo_a = amig (divb, a);
    mostrar (a_amigo_b, b_amigo_a, a, b);
}
