#include <iostream>
#include "Pilha.h"

using namespace std;


//Um construtor � um m�todo que deve ser executado obrigatoriamente antes da pilha ser utilizada
Pilha::Pilha()
{

   Topo = -1;  //estado inicial da pilha.
               //Topo deve se referir ao �ndice -1 do vetor Pilha
               //para indicar que nenhum Dado foi empilhado
}

//Fun��o para indicar se a Pilha est� ou n�o vazia (se exite ou n�o algum Dado armazenado)
bool Pilha::Vazia()
{

   return Topo == -1;    //Pela forma como os Dados s�o Empilhados e Desempilhados (m�todos a seguir)
                         //tem-se que a Pilha est� vazia se o valor de Topo for -1
                         //O indice zero indicar� que h� um Dado armazenado nesta posi��o

                         //Se os valor de Topo for igual a -1, a fun��o retorna verdadeiro
                         //caso contr�rio, ser� retornado falso (operador de compara��o ==)
}


//Fun��o para indicar se a Pilha est� ou n�o cheia (se todas as posi��es do vetor foram ou n�o preenchidas)
bool Pilha::Cheia()
{
    if(Topo >= MAXTAM-1)  //Pela forma como os Dados s�o Empilhados e Desempilhados (m�todos a seguir)
                          //tem-se que se o Topo for igual ao �ltimo �ndice do vetor (MAXTAM-1) ent�o a Pilha est� cheia
                          //Lembrar que o vetor come�a no �ndice zero e vai at� MAXTAM-1
                          //e o valor de Topo indica onde o �ltimo Dado inserido foi empilhado
      return true;
    else
      return false;
}

//Fun��o para retornar o n�mero de Dados armazenados na Pilha
int Pilha::Tamanho()
{

    return Topo+1;   //Observe que pela l�gica do m�todo Empilhar a seguir, o Topo + 1
                     //sempre se refere a quantidade de Dados na Pilha
}


//M�todo para adicionar Dados do topo da Pilha
//Se o Dado for Empilhado (armazenado na Pilha), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//Esse m�todo tamb�m � conhecido como Push
bool Pilha::Empilhar(TipoDado Dado)
{

     if(!Cheia())  //Se a Pilha n�o estiver cheia, podemos adicionar algum Dado
     {

        Topo++;  //Topo � incrementado para indicar onde o Dado deve ser inserido no vetor
        Dados[Topo] = Dado; //O Dado atual � inserido (c�pia) na posi��o indicada por Topo
        return true;  //Retona verdadeiro, indicando que o Dado foi empilhado (inserido na Pilha)
     }
     else //caso a Pilha esteja cheia
      return false;  //Retona falso, indicando que nenhum Dado foi empilhado (a Pilha est� cheia)
}


//M�todo para remover Dados da Pilha
//Se o Dado for Desempilhado (removido da Pilha), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//O Dado no topo da Pilha � removido e retornado por refer�ncia pelo par�metro da fun��o
//Esse m�todo tamb�m � conhecido como Pop
bool Pilha::Desempilhar(TipoDado &Dado)
{
     if(!Vazia())   //primeiro deve-se conferir se a Pilha n�o est� vazia
     {
        Dado = Dados[Topo]; //Copia para a vari�vel Dado o valor
                                //armazenado no topo da Pilha
                                //Esse valor � indicado pela vari�vel Topo


        Topo--;  //Ser� decrementada a vari�vel Topo para indicar o
                 //o novo Dado no Topo da Pilha


                 //Repare que o m�todo Desempilhar n�o remove de fato o
                 //Dado da Pilha.

        return true;   //Retona verdadeiro, indicando que o Dado foi removido
     }
     else  //caso a Pilha esteja vazia
       return false;  //Retona falso, indicando que nenhum Dado foi removido (N�o h� Dado para ser removido, a Pilha est� vazia)
}


//M�todo para retornar o Dado no topo da Pilha sem Desempilha-lo
//O m�todo retorna verdadeiro se a Pilha cont�m algum Dado e
//falso caso a Pilha esteja vazia
//O Dado � retornado por refer�ncia pelo par�metro da fun��o
bool Pilha::Top(TipoDado &Dado)
{
     if(!Vazia())  //primeiro deve-se conferir se a Pilha n�o est� vazia
     {
        Dado = Dados[Topo];  //assim como no m�todo Desempilhar, o Dado no topo da pilha
                                 //est� no �ndice indicado pela vari�vel Topo
                                 //Repare que aqui n�o � feito Topo--, o que iria "remover" o Dado da Pilha
        return true;
     }
     else //caso a Pilha esteja vazia
          return false;  //retorna falso, indicando que n�o foi poss�vel retornar o Dado
}
