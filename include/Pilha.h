#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef char TipoDado;
//defini��o de vari�veis utilizadas para controlar e armazenar os dados na pilha
const int MAXTAM = 50;  //define o n�mero m�ximo de Dados que a pilha pode armazenar

class Pilha
{

private:


    TipoDado Dados[MAXTAM];  //esta implementa��o utiliza
    //um vetor para armazenar os dados na pilha
    //Nesse exemplo ser� criada uma pilha de inteiros, mas poderia ser
    //qualquer outro tipo de dado

    int Topo;    //Vari�vel utilizada para manter o controle do estado atual da pilha



public:

    Pilha();
    bool Vazia();
    bool Cheia();
    int Tamanho();
    bool Empilhar(TipoDado Dado);
    bool Desempilhar(TipoDado &Dado);
    bool Top(TipoDado &Dado);
};

#endif // PILHA_H_INCLUDED
