#include <iostream>
using namespace std;

const int PI = 2;

int main ()
{
    long num, top1=1, bott=1;
    long double numfin;
    cout << " Introduzca el numero de fracciones: ";
    cin >> num;
    while (num<=0)
    {
        cout << " Error. Introduzca un numero valido de fracciones ";
        cin >> num;
    }
    if (num%2==0)
    {
        for (int i=2; i<=num; i++)
        {
            if ((i>1)&&(i%2!=0))
            {
                top1=top1;
            }
            else
            {
                top1 = top1*(i*i);
            }
        }
        for (int i=2; i<=num; i++)
        {
            if ((i>1)&&(i%2!=0))
            {
                bott = bott*(i*i);
            }
            else
            {
                bott=bott;
            }
        }
        top1=top1;
        bott=bott*(num+1);
        numfin=((long double) top1/bott)*PI;
        cout << " El valor de PI con " << num << " fracciones es: " << numfin;
    }
    else
    {
        num=(num+1);
        for (int i=2; i<=num; i++)
        {
            if ((i>1)&&(i%2!=0))
            {
                top1=top1;
            }
            else
            {
                top1 = top1*(i*i);
            }
        }
        for (int i=2; i<=num; i++)
        {
            if ((i>1)&&(i%2!=0))
            {
                bott = bott*(i*i);
            }
            else
            {
                bott=bott;
            }
        }
        top1=(top1/num);
        bott=bott;
        numfin=((long double) top1/bott)*PI;
        cout << " El valor de PI con " << (num-1) << " fracciones es: " << numfin;
    }
}
