#include <iostream>
using namespace std;

int const Bytes_in_KiBytes = 1024;
int const KiBytes_in_MiBytes = 1024;
int const Bytes_in_MiBytes = (Bytes_in_KiBytes*KiBytes_in_MiBytes);
int main ()
{
  int bytestotales;
  cout << " Introduzca un numero de bytes ";
  cin >> bytestotales;
  int MiBytes = (bytestotales / Bytes_in_MiBytes);
  int KiBytes = (bytestotales % Bytes_in_MiBytes) / Bytes_in_KiBytes;
  int Bytes = (bytestotales % Bytes_in_MiBytes) % Bytes_in_KiBytes;
  cout << " MiBytes: " << MiBytes << endl;
  cout << " KiBytes: " << KiBytes << endl;
  cout << " Bytes: " << Bytes << endl;


}
