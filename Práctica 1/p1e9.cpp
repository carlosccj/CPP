#include <iostream>
#include <iomanip>
using namespace std;

const int segundos_en_minuto = 60;
const int minutos_en_hora = 60;
const int horas_en_dia = 24;
const int dias_en_semana = 7;

int main ()
{
    int segundos_totales, segundos, minutos, horas, dias, semanas;
    cout << " Introduzca los segundos ";
    cin >> segundos_totales;
    segundos = segundos_totales % segundos_en_minuto;
    minutos = (segundos_totales / segundos_en_minuto) % minutos_en_hora;
    horas = ((segundos_totales / segundos_en_minuto) / minutos_en_hora) % horas_en_dia;
    dias = (((segundos_totales / segundos_en_minuto) / minutos_en_hora) / horas_en_dia) % dias_en_semana;
    semanas = ((((segundos_totales / segundos_en_minuto) / minutos_en_hora) / horas_en_dia) / dias_en_semana);
    cout << segundos_totales << " segundos equivalen a [";
    cout << setfill (' ') << setw (3);
    cout << semanas << "] semanas ";
    cout << dias << " dias ";
    cout << setfill ('0') << setw (2);
    cout << horas;
    cout << ":" << setfill ('0') << setw (2) << minutos;
    cout << ":" << setfill ('0') << setw (2) << segundos << ":";

}
