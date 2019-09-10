#include <iostream>
#include <stdio.h>

#include "Infixa.h"

using namespace std;

int main()
{
    char str[50];
    cout << "Digite a forma infixa do calculo: ";
    gets(str);

    cout << endl;
    cout << endl;

    Infixa *ifx = new Infixa();

    cout << "Posfixa: ";
    ifx->toPosfixa(str);

    cout << endl;
    cout << endl;
    return 0;
}
