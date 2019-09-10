#include <iostream>
#include "Pilha.h"

using namespace std;


//Um construtor é um método que deve ser executado obrigatoriamente antes da pilha ser utilizada
Pilha::Pilha()
{

   Topo = -1;  //estado inicial da pilha.
               //Topo deve se referir ao índice -1 do vetor Pilha
               //para indicar que nenhum Dado foi empilhado
}

//Função para indicar se a Pilha está ou não vazia (se exite ou não algum Dado armazenado)
bool Pilha::Vazia()
{

   return Topo == -1;    //Pela forma como os Dados são Empilhados e Desempilhados (métodos a seguir)
                         //tem-se que a Pilha está vazia se o valor de Topo for -1
                         //O indice zero indicará que há um Dado armazenado nesta posição

                         //Se os valor de Topo for igual a -1, a função retorna verdadeiro
                         //caso contrário, será retornado falso (operador de comparação ==)
}


//Função para indicar se a Pilha está ou não cheia (se todas as posições do vetor foram ou não preenchidas)
bool Pilha::Cheia()
{
    if(Topo >= MAXTAM-1)  //Pela forma como os Dados são Empilhados e Desempilhados (métodos a seguir)
                          //tem-se que se o Topo for igual ao último índice do vetor (MAXTAM-1) então a Pilha está cheia
                          //Lembrar que o vetor começa no índice zero e vai até MAXTAM-1
                          //e o valor de Topo indica onde o último Dado inserido foi empilhado
      return true;
    else
      return false;
}

//Função para retornar o número de Dados armazenados na Pilha
int Pilha::Tamanho()
{

    return Topo+1;   //Observe que pela lógica do método Empilhar a seguir, o Topo + 1
                     //sempre se refere a quantidade de Dados na Pilha
}


//Método para adicionar Dados do topo da Pilha
//Se o Dado for Empilhado (armazenado na Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//Esse método também é conhecido como Push
bool Pilha::Empilhar(TipoDado Dado)
{

     if(!Cheia())  //Se a Pilha não estiver cheia, podemos adicionar algum Dado
     {

        Topo++;  //Topo é incrementado para indicar onde o Dado deve ser inserido no vetor
        Dados[Topo] = Dado; //O Dado atual é inserido (cópia) na posição indicada por Topo
        return true;  //Retona verdadeiro, indicando que o Dado foi empilhado (inserido na Pilha)
     }
     else //caso a Pilha esteja cheia
      return false;  //Retona falso, indicando que nenhum Dado foi empilhado (a Pilha está cheia)
}


//Método para remover Dados da Pilha
//Se o Dado for Desempilhado (removido da Pilha), o método retorna verdadeiro
//caso contrário, retorna falso
//O Dado no topo da Pilha é removido e retornado por referência pelo parâmetro da função
//Esse método também é conhecido como Pop
bool Pilha::Desempilhar(TipoDado &Dado)
{
     if(!Vazia())   //primeiro deve-se conferir se a Pilha não está vazia
     {
        Dado = Dados[Topo]; //Copia para a variável Dado o valor
                                //armazenado no topo da Pilha
                                //Esse valor é indicado pela variável Topo


        Topo--;  //Será decrementada a variável Topo para indicar o
                 //o novo Dado no Topo da Pilha


                 //Repare que o método Desempilhar não remove de fato o
                 //Dado da Pilha.

        return true;   //Retona verdadeiro, indicando que o Dado foi removido
     }
     else  //caso a Pilha esteja vazia
       return false;  //Retona falso, indicando que nenhum Dado foi removido (Não há Dado para ser removido, a Pilha está vazia)
}


//Método para retornar o Dado no topo da Pilha sem Desempilha-lo
//O método retorna verdadeiro se a Pilha contém algum Dado e
//falso caso a Pilha esteja vazia
//O Dado é retornado por referência pelo parâmetro da função
bool Pilha::Top(TipoDado &Dado)
{
     if(!Vazia())  //primeiro deve-se conferir se a Pilha não está vazia
     {
        Dado = Dados[Topo];  //assim como no método Desempilhar, o Dado no topo da pilha
                                 //está no índice indicado pela variável Topo
                                 //Repare que aqui não é feito Topo--, o que iria "remover" o Dado da Pilha
        return true;
     }
     else //caso a Pilha esteja vazia
          return false;  //retorna falso, indicando que não foi possível retornar o Dado
}
