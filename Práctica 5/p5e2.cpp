#include <iostream>
using namespace std;

void leer (int& num)
{
    cout << "Introduzca un numero: ";
    cin >> num;
    while (num < 0)
    {
        cout << "Error ";
        cin >> num;
    }
}

void change (int& n1, int& n2, int& fib)
{
    n1 = n2;
    n2 = fib;
}

void mostrar (int num, int fib)
{
    cout << "Fibonacci(" << num << "): " << fib;
}

int fibonacci (int num)
{
    int n1 = 0;
    int n2 = 1;
    int fib = n1 + n2;
    if (num < 2)
    {
        fib = num;
    }
    else
    {
        for (int p = 2; p < num; p++)
        {
            change (n1, n2, fib);
            fib = n1 + n2;
        }
    }
    return fib;
}

int main ()
{
    int num, fib;
    leer (num);
    fib = fibonacci (num);
    mostrar (num, fib);
}
