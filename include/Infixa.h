#ifndef CONVERTERPARAPOSFIXA_H
#define CONVERTERPARAPOSFIXA_H

#include "Pilha.h"

class Infixa
{
    public:
        Infixa();
        void toPosfixa(char str[]);
    protected:

    private:
        void checkPriority(int prioridade, char op, int &i);
        Pilha *pilha;
};

#endif // CONVERTERPARAPOSFIXA_H
