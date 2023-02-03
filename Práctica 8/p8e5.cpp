#include <iostream>
#include <array>
#include <string>
using namespace std;

void ordenar (string& op1, string& op2)
{
    if (int(op1.size()) > int(op2.size()))
    {
        string aux = op1;
        op1 = op2;
        op2 = aux;
    }
}

void alfa (string& palabra)
{
    for (int k = 0; k < int(palabra.size() - 1); ++k)
    {
        for (int i = 0; i < int(palabra.size() - 1); ++i)
        {
            if (palabra[i] > palabra[i + 1])
            {
                char aux = palabra[i];
                palabra[i] = palabra[i + 1];
                palabra[i + 1] = aux;
            }
        }
    }
}

string multiplicar (string& op1, string& op2)
{
    string res = "";
    char cnt = ' ';
    ordenar (op1, op2);
    for (int i = 0; i < int(op1.size()); i++)
    {
        for (int j = 0; j < int(op2.size()); j++)
        {
            if (op1[i] == op2[j] && cnt != op1[i])
            {
                res += op1[i];
                cnt = op1[i];
            }
        }
    }
    return res;
}

string sumar (string& op1, string& op2)
{
    char cnt = ' ';
    string res = "";
    string aux = op1 + op2;
    alfa (aux);
    for (int i = 0; i < int(aux.size()); i++)
    {
        for (int j = 0; j < int(aux.size()); j++)
        {
            if (aux[i] == aux[j] && cnt != aux[i])
            {
                res += aux[i];
                cnt = aux[i];
            }
        }
    }
    return res;
}

string restar (string& op1, string& op2)
{
    ordenar (op1, op2);
    alfa (op1);
    alfa (op2);
    bool ok = true;
    string res = "";
    for (int i = 0; i < int(op2.size()); i++)
    {
        for (int j = 0; j < int(op1.size()) && ok; j++)
        {
            if (op2[i] == op1[j])
            {
                ok = false;
                op1 = op1.substr (1, int(op1.size()));
            }
        }
        if (ok)
        {
            res += op2[i];
        }
        ok = true;
    }
    return res;
}

    int main ()
    {
        char operador;
        string op1;
        string op2;
        string res = "";
        cout << "Introduzca la operacion a realizar (& para terminar): ";
        cin >> operador;
        while (operador != '&')
        {
            cout << "Introduzca op1: ";
            cin >> ws;
            getline (cin, op1);
            cout << "Introduzca op2: ";
            cin >> ws;
            getline (cin, op2);
            if (operador == '*')
            {
                res = multiplicar (op1, op2);
            }
            else if (operador == '+')
            {
                res = sumar (op1, op2);
            }
            else if (operador == '-')
            {
                res = restar (op1, op2);
            }
            cout << res << endl;
            cout << "Introduzca la operacion a realizar (& para terminar): ";
            cin >> operador;
        }
    }
