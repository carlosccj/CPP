#include <iostream>
using namespace std;

const char ESP = ' ';
const char AST = '*';

void leer (int& x)
{
    cout << "Introduzca un numero: ";
    cin >> x;
}

void ast_sup (int f)
{
    for (int i = 1; i <= f; i++)
    {
        cout << AST;
        cout << ESP;
    }
    cout << endl;
}

void esp (int x, int f)
{
    for (int i = f; i < x; i++)
    {
        cout << ESP;
    }
}

void inv_esp (int f)
{
    for (int i = 1; i <= f; i++)
    {
        cout << ESP;
    }
}

void ast_inf (int x, int f)
{
    for (int i = f; i < x; i++)
    {
        cout << AST;
        cout << ESP;
    }
    cout << endl;
}

int main ()
{
    int num;
    leer (num);
    for (int f = 1; f <= num; f++)
    {
        esp (num, f);
        ast_sup (f);
    }
    for (int f2 = 1; f2 < num; f2++)
    {
        inv_esp (f2);
        ast_inf (num, f2);
    }
}

