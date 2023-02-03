#include <iostream>
using namespace std;
int main()
{
int a = 6;
int b = 14;
int auxiliar;
cout << "a vale " << a << " y b vale " << b << endl;
// ¿Qué hacen estas tres sentencias?
// Primero se declaran dos variables enteras y se les asigna un valor concreto.
// Luego se declara una variable entera que en principio no tiene valor.
// Por último, un mensaje muestra en pantalla cuanto vale "a" y "b".
auxiliar = a;
a = b;
b = auxiliar;
cout << "a vale " << a << " y b vale " << b << endl;
// Ahora se le asigna a la variable sin valor el valor de "a".
// Luego se le asigna a "a" el valor de "b"
// Por ultimo se le asigna a "b" el valor de "auxiliar" que en realidad es el valor original de "a"
// Por tanto, lo que ocurre es que "b" se muestra como "a" y "a" se muestra como "b".
}
