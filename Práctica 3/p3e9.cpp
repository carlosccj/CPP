#include <iostream>
using namespace std;

int main ()
{
    char operand;
    double num1, num2, result;

    do
    {
        cout << " Operacion (+-*/&): ";
        cin >> operand;
        if ((operand!='+') && (operand!='-') && (operand!='*') && (operand!='/') && (operand!='&'))
        {
            throw " El operando introducido no es correcto, repita: ";
            cin >> operand;
        }
        if (operand=='&')
        {
            cout << " FIN DEL PROGRAMA " << endl;
        }
        else
        {
            cout << " Introduzca el primer numero ";
            cin >> num1;
            cout << " Introduzca el segundo numero ";
            cin >> num2;

            switch (operand)
            {
            case '+':
                result=(num1+num2);
                cout << " El resultado es: " << result << endl;
                break;
            case '-':
                result=(num1-num2);
                cout << " El resultado es: " << result << endl;
                break;
            case '*':
                result=(num1*num2);
                cout << " El resultado es: " << result << endl;
                break;
            case '/':
                if (num2==0)
                {
                    cout << " Operacion invalida, no se puede dividir por 0 " << endl;
                }
                else
                {
                    result=(num1/num2);
                    cout << " El resultado es: " << result << endl;
                    break;
                }
            }
        }
    }
    while (operand!='&');
}
