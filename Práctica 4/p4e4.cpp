#include <iostream>
using namespace std;

void leer (int& x, int& y)
{
    cout << "Introduzca un intervalo: ";
    cin >> x >> y;
    while (x >= y)
    {
        cout << "Error. Introduzca otro intervalo: ";
        cin >> x >> y;
    }
}

int sumdiv (int x)
{
    int cnt = 0;
    for (int div = 1; div < x; div++)
    {
        if (x % div == 0)
        {
            cnt = cnt + div;
        }
    }
    return cnt;
}

bool amig (int sumdiv_i, int j, int sumdiv_j, int i)
{
    bool amigos;
    bool i_amigo_j = (sumdiv_i == j);
    bool j_amigo_i = (sumdiv_j == i);
    if (i_amigo_j && j_amigo_i)
    {
        amigos = true;
    }
    else
    {
        amigos = false;
    }
    return amigos;
}

void mostrar (int i, int j)
{
    cout << "Amigos: " << i << ", " << j << endl;
}

void interval (int x, int y)
{
    for (int i = x; i < y; i++)
    {
        int sumdiv_i = sumdiv (i);

        for (int j = i + 1; j <= y; j++)
        {
            int sumdiv_j = sumdiv (j);
            bool amigos = amig (sumdiv_i, j, sumdiv_j, i);
            if ((amigos) && (i != j))
            {
                mostrar (i, j);
            }
        }
    }
}


int main ()
{
    int inf, sup;
    leer (inf, sup);
    interval (inf, sup);
}
