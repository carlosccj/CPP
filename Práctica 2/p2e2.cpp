#include <iostream>
using namespace std;

int main ()

{
    int num1, num2, num3;
    cout << " Introduzca tres numeros enteros ";
    cin >> num1 >> num2 >> num3;
    if (((num1>num2) && (num1>num3)) && ((num1!=num2) && (num1!=num3))) {
        cout << " El primer numero es el mayor " << endl;
       } else if ((num2>num3) && ((num2!=num3) && (num2!=num1))) {
            cout << " El segundo numero es el mayor " << endl;
        } else if ((num3>num2) && (num3!=num2) && (num3!=num1)) {
        cout << " El tercer numero es el mayor " << endl;
         } else {
         cout << " Dos o mas numeros son iguales " << endl;}
        }


