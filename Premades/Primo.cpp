#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Introduce un n�mero: ";
    cin >> num;
    int cnt = 0;
    for (int i = 1; i <= num; ++i)
    {
        if ((num % i) == 0)
        {
            ++cnt;
        }
    }
    if (cnt == 2)
    {
        cout << "El n�mero " << num << " es primo" << endl;
    }
    else
    {
        cout << "El n�mero " << num << " es compuesto" << endl;
    }
}
