#include <iostream>
using namespace std;

int const FIJO = 1;
int const consumo_a = 100;
double const PRIMERO = 0.50;
int const consumo_b = 250;
double const SEGUNDO = 0.35;
int const consumo_c = (consumo_a+consumo_b);
double const TERCERO = 0.25;

int main ()
{
    double importe;
    int consumo;
    cout << " Introduzca el consumo del contador ";
    cin >> consumo;

    if (consumo<=consumo_a) {
        importe = (FIJO+(PRIMERO*consumo));
        cout << " Consumo: " << consumo << " Kw. " << endl;
        cout << " Importe " << importe << " Euros " << endl;
    } else if (consumo<=consumo_b) {
    importe = (((consumo_a*PRIMERO)+((consumo-consumo_a)*SEGUNDO))+FIJO);
    cout << " Consumo: " << consumo << "Kw. " << endl;
    cout << " Importe: " << importe << " Euros " << endl;
    } else if (consumo>=consumo_b) {
    importe = ((((consumo_a*PRIMERO)+((consumo_b-consumo_a)*SEGUNDO))+((consumo-consumo_b)*TERCERO))+FIJO);
               cout << " Consumo: " << consumo << " Kw. " << endl;
               cout << " Importe: " << importe << " Euros " << endl;
    }
}
