#include <iostream>
using namespace std;
int main()
{
int num1, num2;
cout << "Introduzca el primer n�mero entero: ";
cin >> num1;
cout << "Introduzca el segundo n�mero entero: ";
cin >> num2;
int suma = num1 + num2;
cout << "Primer n�mero: " << num1 << endl;
cout << "Segundo n�mero: " << num2 << endl;
cout << "Resultado (num1 + num2): " << suma << endl;
}
// Este programa suma dos n�meros enteros cualesquiera, positivos o negativos.
// Los problemas que derivan de operar con numeros como 2000.000.000 es que el l�mite de la variable int
// en 32 bits para un n�mero es 2147.483.647, por lo que al exceder el producto de la suma a dicho n�mero
// ocurren resultados err�neos.
