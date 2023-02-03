#include <iostream>
#include <array>
using namespace std;

struct complejos
{
    double real;
    double img;
};

void leer (complejos& c1, complejos& c2)
{
    cout << "Introduzca un numero complejo (real, img): ";
    cin >> c1.real >> c1.img;
    cout << "Introduzca un numero complejo (real, img): ";
    cin >> c2.real >> c2.img;
}

void sumar (complejos& c1, complejos& c2)
{
    complejos res;
    res.real = c1.real + c2.real;
    res.img = c1.img + c2.img;
    cout << "(" << c1.real << ", " << c1.img << ")" << " + " << "(" << c2.real << ", " << c2.img << ")" << " = ";
    cout << "(" << res.real << ", " << res.img << ")" << endl;
}

void restar (complejos& c1, complejos& c2)
{
    complejos res;
    res.real = c1.real - c2.real;
    res.img = c1.img - c2.img;
     cout << "(" << c1.real << ", " << c1.img << ")" << " - " << "(" << c2.real << ", " << c2.img << ")" << " = ";
    cout << "(" << res.real << ", " << res.img << ")" << endl;
}

void multiplicar (complejos& c1, complejos& c2)
{
    complejos res;
    res.real = (c1.real * c2.real) + (c1.img * c2.img * (-1));
    res.img = (c1.real * c2.img) + (c1.img * c2.real);
     cout << "(" << c1.real << ", " << c1.img << ")" << " * " << "(" << c2.real << ", " << c2.img << ")" << " = ";
    cout << "(" << res.real << ", " << res.img << ")" << endl;
}

void dividir (complejos& c1, complejos& c2)
{
    complejos res;
    complejos numer;
    complejos denom;
    complejos inv = c2;
    inv.img = -inv.img;
    numer.real = (c1.real * inv.real) + (c1.img * inv.img * (-1));
    numer.img = (c1.real * inv.img) + (c1.img * inv.real);
    denom.real = (c2.real * inv.real) + (c2.img * inv.img * (-1));
    denom.img = (c2.real * inv.img) + (c2.img * inv.real);
    res.real = numer.real / denom.real;
    res.img = numer.img / denom.real;
    cout << "(" << c1.real << ", " << c1.img << ")" << " / " << "(" << c2.real << ", " << c2.img << ")" << " = ";
    cout << "(" << res.real << ", " << res.img << ")" << endl;
}

int main ()
{
    complejos c1, c2;
    leer (c1, c2);
    sumar (c1, c2);
    restar (c1, c2);
    multiplicar (c1, c2);
    dividir (c1, c2);
}
