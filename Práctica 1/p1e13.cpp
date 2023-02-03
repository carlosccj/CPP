#include <iostream>
using namespace std;
int main()
{
bool ok = (3.0 * (0.1 / 3.0)) == ((3.0 * 0.1) / 3.0);
cout << "Resultado de (3.0 * (0.1 / 3.0)) == ((3.0 * 0.1) / 3.0): "
<< boolalpha << ok << " -> ERROR" << endl;
// Este programa usa una variable lógica bool para evaluar si ambas expresiones son equivalentes o no.
// Aunque el resultado aritmético de las dos expresiones es idéntico, bool no lo evalua como tal ya que
// primero resuelve las operaciones de los parentesis interiores y al detectar resultados distintos, ignora
// el resto de la operación y los evalua como diferentes.
