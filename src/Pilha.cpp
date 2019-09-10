#include <iostream>
using namespace std;

#include "Pilha.h"

//Um construtor é um método que deve ser executado obrigatoriamente antes da pilha ser utilizada
Pilha::Pilha()
{

  Topo = NULL;  //O construtor da Pilha deve iniciar uma Pilha vazia, sem memória alocada
                //para essa estrutura de dados (não há ainda Dados armazenados)
                //Portanto, o ponteiro Topo deve apontar para NULL

  Contador = 0;  //Inicia a variável para indicar a quantidade de Dados armazenados na Pilha
}

//Método para recuperar a memória dinâmica alocada para a Pilha
//Ao contrário de um construtor, o destrutor é um método que deve ser executado
//depois da pilha ser utilizada
Pilha::~Pilha()
{

   Celula *Temp;  //Ponteiro temporário utilizado para desalocar a memória

   while(Topo != NULL)  //Enquanto Topo não chegar em Nulo (Enquanto a Pilha não estiver vazia)
   {
     Temp = Topo;  //o ponteiro temporário deve apontar para o mesmo endereço que Topo
     Topo = Topo -> Prox; //Topo avança para a célula seguinte

     Temp->Prox = NULL; //Para quebrar o vínculo que existia entre as células da Pilha (segurança)
     delete Temp;  //desaloca o espaço de memória (célula) apontado por Temp
   }

}

//Função para indicar se a Pilha está ou não vazia (se exite ou não algum Dado armazenado)
bool Pilha::Vazia()
{
   return Topo == NULL;   //Pela forma como os Dados são Empilhados e Desempilhados (métodos a seguir)
                          //a Pilha está vazia se Topo apontar para NULL


                          //se Topo for igual a NULL, a função retorna verdadeiro
                          //caso contrário, será retornado falso (operador de comparação ==)

                          //Esse comando poderia também ser substituído por Contador == 0
                          //uma vez que essa variável indica a quantidade de Dados
                          //armazenados na Pilha
}

//Função para retornar a quantidade de Dados armazenados na Pilha
int Pilha::Tamanho()
{

    return Contador;   //É retornado o contador de Dados, manipulado nos métodos de Empilhar e Desempilhar
}


//Método para adicionar Dados do topo da Pilha
//Se o Dado for Empilhado (armazenado na Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//Esse método também é conhecido como Push
bool Pilha::Empilhar(TipoDado Dado)
{

   Celula *Nova;  //Ponteiro temporário utilizado para apontar para a nova célula a ser criada

   if((Nova = new (Celula))==NULL)  //tenta alocar dinâmicamente na memória uma nova célula da Pilha
   {                              //e Nova deve apontar para esse endereço de memória

       //caso não for possível alocar mais uma célula na memória (Nova aponta para NULL e torna a condição do if verdadeira)
       //Retona falso, indicando que nenhum Dado foi empilhado (não foi possível alocar mais memória)
       return false;
   }
   else
   {
       Nova->Dado = Dado;  //Como Nova aponta para um espaço de memória disponível, guardamos o Dado a ser armazenado nesse espaço
       Nova->Prox = Topo;      //Para fazer a ligação entre as células da Pilha, o novo espaço de memória reservado
                               //e apontado por Nova possui um ponteiro Prox que deve apontar para célua seguinte
                               //Nesse caso, o ponteiro Prox deve apontar para o mesmo endereço que Topo aponta
                               //Resumindo: O Prox do Nova aponta agora para Topo

       Topo = Nova;            //Como a Pilha possui agora um novo topo apontado por Nova e o ponteiro Topo está um nível abaixo
                               //deve-se fazer com que Topo aponte para a nova célula criada

       Contador++;             //Como foi armazenado um novo Dado, o contador deve ser incrementado

       return true;            //Retorna verdadeiro, indicando que o Dado foi empilhado (inserido na Pilha)
   }
}


//Método para remover Dados da Pilha
//Se o Dado for Desempilhado (removido da Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//O Dado no topo da Pilha é removido e retornado por referência pelo parâmetro da função
//Esse método também é conhecido como Pop
bool Pilha::Desempilhar(TipoDado &Dado)
{

   if(!Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
   {

      Celula *Temp = Topo;  //Cria um ponteiro temporário (Temp) e faz apontar para o mesmo endereço de Topo
                                //Essa célula será excluída da Pilha

      Topo = Topo->Prox; //Faz o topo apontar para a célula seguinte
                         //Esse procedimento define a célula eleita como topo da Pilha

      Dado = Temp->Dado;  //O Dado a ser retornado está na célula que será excluída
                              //Esse Dado é o último que foi empilhado (inserido na Pilha)

      Temp->Prox = NULL;  //Remove a ligação entre a célula a ser excluída e a célula de topo da Pilha (segurança)

      delete Temp;        //Desaloca o espaço de memória reservado pela célula apontada por Temp
                          //(devolve esse espaço de memória ao sistema)

      Contador--;          //Como foi removido um Dado, o contador deve ser decrementado

      return true;        //Retona verdadeiro, indicando que o Dado foi removido
   }
   else  //caso a Pilha esteja vazia
     return false;      //Retona falso, indicando que nenhum Dado foi removido (Não há Dado para ser removido, a Pilha está vazia)
}


//Método para retornar o Dado no topo da Pilha sem removê-lo
//O Dado é retornado por referência pelo parâmetro da função
bool Pilha::Top(TipoDado &Dado)
{

     if(!Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
     {
        Dado = Topo->Dado;  //Topo aponta uma célula com o último Dado empilhado

        return true;  //retorna verdadeiro indicando que o último Dado da Pilha foi retornado (mas não desempilhado)
     }
     else //caso a Pilha esteja vazia
     return false;  //retorna falso, indicando que não foi possível retornar o Dado
}
