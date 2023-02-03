#include <iostream>
using namespace std;

const int mult = 10;
const int teorie = 7;
const int pract = (mult-teorie);

int main(){

    double teo, pr, total;
    cout << " Introduzca nota de teoria ";
    cin >> teo;
    cout << " Introduzca nota de practica ";
    cin >> pr;
    if ((teo>10) || (pr>10) || (teo<0) || (pr<0)) {
        cout << " Error " << endl;
    } else {
        teo = (teo*teorie)/mult;
        pr = (pr*pract) / mult;
        total = teo + pr;
        cout << " La calificacion es " << total << endl;
    }
}
