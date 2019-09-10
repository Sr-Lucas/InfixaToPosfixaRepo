#include <iostream>
using namespace std;

#include "Pilha.h"

//Um construtor � um m�todo que deve ser executado obrigatoriamente antes da pilha ser utilizada
Pilha::Pilha()
{

  Topo = NULL;  //O construtor da Pilha deve iniciar uma Pilha vazia, sem mem�ria alocada
                //para essa estrutura de dados (n�o h� ainda Dados armazenados)
                //Portanto, o ponteiro Topo deve apontar para NULL

  Contador = 0;  //Inicia a vari�vel para indicar a quantidade de Dados armazenados na Pilha
}

//M�todo para recuperar a mem�ria din�mica alocada para a Pilha
//Ao contr�rio de um construtor, o destrutor � um m�todo que deve ser executado
//depois da pilha ser utilizada
Pilha::~Pilha()
{

   Celula *Temp;  //Ponteiro tempor�rio utilizado para desalocar a mem�ria

   while(Topo != NULL)  //Enquanto Topo n�o chegar em Nulo (Enquanto a Pilha n�o estiver vazia)
   {
     Temp = Topo;  //o ponteiro tempor�rio deve apontar para o mesmo endere�o que Topo
     Topo = Topo -> Prox; //Topo avan�a para a c�lula seguinte

     Temp->Prox = NULL; //Para quebrar o v�nculo que existia entre as c�lulas da Pilha (seguran�a)
     delete Temp;  //desaloca o espa�o de mem�ria (c�lula) apontado por Temp
   }

}

//Fun��o para indicar se a Pilha est� ou n�o vazia (se exite ou n�o algum Dado armazenado)
bool Pilha::Vazia()
{
   return Topo == NULL;   //Pela forma como os Dados s�o Empilhados e Desempilhados (m�todos a seguir)
                          //a Pilha est� vazia se Topo apontar para NULL


                          //se Topo for igual a NULL, a fun��o retorna verdadeiro
                          //caso contr�rio, ser� retornado falso (operador de compara��o ==)

                          //Esse comando poderia tamb�m ser substitu�do por Contador == 0
                          //uma vez que essa vari�vel indica a quantidade de Dados
                          //armazenados na Pilha
}

//Fun��o para retornar a quantidade de Dados armazenados na Pilha
int Pilha::Tamanho()
{

    return Contador;   //� retornado o contador de Dados, manipulado nos m�todos de Empilhar e Desempilhar
}


//M�todo para adicionar Dados do topo da Pilha
//Se o Dado for Empilhado (armazenado na Pilha), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//Esse m�todo tamb�m � conhecido como Push
bool Pilha::Empilhar(TipoDado Dado)
{

   Celula *Nova;  //Ponteiro tempor�rio utilizado para apontar para a nova c�lula a ser criada

   if((Nova = new (Celula))==NULL)  //tenta alocar din�micamente na mem�ria uma nova c�lula da Pilha
   {                              //e Nova deve apontar para esse endere�o de mem�ria

       //caso n�o for poss�vel alocar mais uma c�lula na mem�ria (Nova aponta para NULL e torna a condi��o do if verdadeira)
       //Retona falso, indicando que nenhum Dado foi empilhado (n�o foi poss�vel alocar mais mem�ria)
       return false;
   }
   else
   {
       Nova->Dado = Dado;  //Como Nova aponta para um espa�o de mem�ria dispon�vel, guardamos o Dado a ser armazenado nesse espa�o
       Nova->Prox = Topo;      //Para fazer a liga��o entre as c�lulas da Pilha, o novo espa�o de mem�ria reservado
                               //e apontado por Nova possui um ponteiro Prox que deve apontar para c�lua seguinte
                               //Nesse caso, o ponteiro Prox deve apontar para o mesmo endere�o que Topo aponta
                               //Resumindo: O Prox do Nova aponta agora para Topo

       Topo = Nova;            //Como a Pilha possui agora um novo topo apontado por Nova e o ponteiro Topo est� um n�vel abaixo
                               //deve-se fazer com que Topo aponte para a nova c�lula criada

       Contador++;             //Como foi armazenado um novo Dado, o contador deve ser incrementado

       return true;            //Retorna verdadeiro, indicando que o Dado foi empilhado (inserido na Pilha)
   }
}


//M�todo para remover Dados da Pilha
//Se o Dado for Desempilhado (removido da Pilha), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//O Dado no topo da Pilha � removido e retornado por refer�ncia pelo par�metro da fun��o
//Esse m�todo tamb�m � conhecido como Pop
bool Pilha::Desempilhar(TipoDado &Dado)
{

   if(!Vazia())  //primeiro deve-se conferir se a Pilha n�o est� vazia
   {

      Celula *Temp = Topo;  //Cria um ponteiro tempor�rio (Temp) e faz apontar para o mesmo endere�o de Topo
                                //Essa c�lula ser� exclu�da da Pilha

      Topo = Topo->Prox; //Faz o topo apontar para a c�lula seguinte
                         //Esse procedimento define a c�lula eleita como topo da Pilha

      Dado = Temp->Dado;  //O Dado a ser retornado est� na c�lula que ser� exclu�da
                              //Esse Dado � o �ltimo que foi empilhado (inserido na Pilha)

      Temp->Prox = NULL;  //Remove a liga��o entre a c�lula a ser exclu�da e a c�lula de topo da Pilha (seguran�a)

      delete Temp;        //Desaloca o espa�o de mem�ria reservado pela c�lula apontada por Temp
                          //(devolve esse espa�o de mem�ria ao sistema)

      Contador--;          //Como foi removido um Dado, o contador deve ser decrementado

      return true;        //Retona verdadeiro, indicando que o Dado foi removido
   }
   else  //caso a Pilha esteja vazia
     return false;      //Retona falso, indicando que nenhum Dado foi removido (N�o h� Dado para ser removido, a Pilha est� vazia)
}


//M�todo para retornar o Dado no topo da Pilha sem remov�-lo
//O Dado � retornado por refer�ncia pelo par�metro da fun��o
bool Pilha::Top(TipoDado &Dado)
{

     if(!Vazia())  //primeiro deve-se conferir se a Pilha n�o est� vazia
     {
        Dado = Topo->Dado;  //Topo aponta uma c�lula com o �ltimo Dado empilhado

        return true;  //retorna verdadeiro indicando que o �ltimo Dado da Pilha foi retornado (mas n�o desempilhado)
     }
     else //caso a Pilha esteja vazia
     return false;  //retorna falso, indicando que n�o foi poss�vel retornar o Dado
}
