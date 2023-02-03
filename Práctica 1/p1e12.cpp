#include <iostream>
using namespace std;
int main()
{
int num1, num2;
cout << "Introduzca el primer número entero: ";
cin >> num1;
cout << "Introduzca el segundo número entero: ";
cin >> num2;
int suma = num1 + num2;
cout << "Primer número: " << num1 << endl;
cout << "Segundo número: " << num2 << endl;
cout << "Resultado (num1 + num2): " << suma << endl;
}
// Este programa suma dos números enteros cualesquiera, positivos o negativos.
// Los problemas que derivan de operar con numeros como 2000.000.000 es que el límite de la variable int
// en 32 bits para un número es 2147.483.647, por lo que al exceder el producto de la suma a dicho número
// ocurren resultados erróneos.
