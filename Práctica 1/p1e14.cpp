#include <iostream>
using namespace std;
int main()
{
int num11 = -7;
int num12 = 4;
double num13 = num11 + num12;
cout << "Valor de n�mero11 (int): " << num11 << endl;
cout << "Valor de n�mero12 (int): " << num12 << endl;
cout << "Valor de n�mero13 (double) (num11 + num12): " << num13 << " CORRECTO" << endl;
//-------------------------------
int num21 = -7;
unsigned num22 = 4;
double num23 = num21 + num22;
cout << "Valor de n�mero21 (int): " << num21 << endl;
cout << "Valor de n�mero22 (unsigned): " << num22 << endl;
cout << "Valor de n�mero23 (double) (num21 + num22): " << num23 << " ERROR" << endl;
}
// El problema en el segundo caso es que una de las variables est� declarada como "unsigned" y
// este tipo de variable solo puede operar con n�meros naturales, por lo que da valores err�neos
// con los negativos. Al extrer 7 de 4, lo que hace es saltarse todos los n�meros negativos hasta
// "rodear" y llegar a cerca de su valor m�ximo por el otro lado: 4294967295.
