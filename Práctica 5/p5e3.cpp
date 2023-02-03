#include <iostream>
using namespace std;

int main ()
{
    int n1, n2, comp;
    bool is_zigzag = true;
    comp = 0;
    cout << "introduce una serie: ";
    cin >> n1;

    while (n1 != 0)
    {
        n2 = n1;
        cin >> n1;
        cout << n2 << ", ";

        if (n1 != 0)
        {
            if (comp == 0)
            {
                if (n1 > n2)
                {
                    comp = 1;
                }
                else if (n2 > n1)
                {
                    comp = -1;
                }
                else
                {
                    is_zigzag = false;
                }
            }
            else if (comp == 1)
            {
                if (n2 > n1)
                {
                    comp = -1;
                }
                else
                {
                    is_zigzag = false;
                }
            }
            else if (comp == -1)
            {
                if (n1 > n2)
                {
                    comp = 1;
                }
                else
                {
                    is_zigzag = false;
                }
            }
        }
    }
    if (is_zigzag)
    {
        cout << n1 << endl;
        cout << "La secuencia introducida SI es en zigzag";
    }
    else
    {
        cout << n1 << endl;
        cout << "La secuencia introducida NO es en zigzag";
    }

}
