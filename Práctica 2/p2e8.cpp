#include <iostream>
using namespace std;

int main ()
{
   int codigo;
   cout << " Introduzca el codigo numerico de 4 digitos: ";
   cin >> codigo;

   if ((codigo<1000) || (codigo>9999)) {
    cout << "Error " << endl;
   } else {
   int codigo_pro = (codigo/1000);
   int codigo_op = ((codigo%1000)/10);
   int codigo_cont = ((codigo%1000)%10);
   cout << " Provincia: " << codigo_pro << endl;
   cout << " Numero de operacion " << codigo_op << endl;
   cout << " Numero de control " << codigo_cont << endl;
   cout << " Comprobacion: Correcto " << endl;
   }


}
