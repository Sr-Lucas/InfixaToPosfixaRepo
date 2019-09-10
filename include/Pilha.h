#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef char TipoDado;

class Pilha
{

    private:

        struct Celula
        {
            TipoDado Dado;
            Celula *Prox;
        };

        Celula *Topo;
        int Contador;

    public:

        Pilha();
        ~Pilha();
        bool Vazia();
        int Tamanho();
        bool Empilhar(TipoDado Dado);
        bool Desempilhar(TipoDado &Dado);
        bool Top(TipoDado &Dado);
};

#endif // PILHA_H_INCLUDED
