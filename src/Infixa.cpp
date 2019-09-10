#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Infixa.h"

using namespace std;

Infixa::Infixa()
{
    /* Ao criar um objeto 'Infixa' é instancioado um objeto 'Pilha' e sua instacia
     * é armazenada em um atributo do mesmo tipo na classe 'Infixa'.
     */
    Infixa::pilha = new Pilha(); //tenho acesso a essa instância em toda a classe por todos os métodos
}

void Infixa::toPosfixa(char str[])
{
    //Vou usar para percorrer a string que foi passada para conversão
    int i = 0;

    //Fluxo que irá percorrer a string que foi passada para conversão
    //Enquanto meu vetor não apontar para '\0' (final da string) o laço não será parado
    while(str[i] != '\0') {
        //Teste resposável por exibir operandos na tela quando encontrados
        if(str[i] != '/' && str[i] != '*' && str[i] != '+' && str[i] != '-' && str[i] != '(' && str[i] != ')' && str[i] != '\0') {
            cout << str[i];
        }

        char c = '\0';

        //Se o caracter apontado pelo vetor não for um operando ele é um operador
        //Faço um switch para saber qual é o operador que o vetor estpa apontando
        switch(str[i]){
            case '/':
                checkPriority(3, '/', i);
            break;
            case '*':
                checkPriority(3, '*', i);
            break;
            case '+':
                checkPriority(2, '+', i);
            break;
            case '-':
               checkPriority(2, '-', i);
            break;
            case '(':
                checkPriority(1, '(', i);
            break;
            case ')':
                checkPriority(1, ')', i);
            break;
        }
        i++;
    }

    //laço resposável por exibir os operadores restantes na pilha caso a string acabe e a pilha ainda contiver operadores!
    while(!pilha->Vazia()) {
        char ch;
        pilha->Desempilhar(ch);

        if(ch != '(' && ch != ')') cout << ch;
    }
}

/* Método privado que auxilia o toPosfixa
 *
 */
void Infixa::checkPriority(int prioridade, char op, int &i) {
    char caracterTopo;
    char ch = '\0';

    //Capturo o operador no topo da pilha
    Infixa::pilha->Top(caracterTopo);

    //Se o operador no topo for um fechamento de parenteses ')':
    //E execultado um laço que se repetira até que seja encontrado uma abertura de parênteses '('
    if(op == ')') {
        Infixa::pilha->Top(caracterTopo);
        while(caracterTopo != '(') {
            Infixa::pilha->Desempilhar(ch);
            Infixa::pilha->Top(caracterTopo);
            if(ch != '(') cout << ch;
        }
        if(caracterTopo == '(') Infixa::pilha->Desempilhar(caracterTopo);
        return;
    }

    //Só é execultado caso não seja um fechamento de parênteses
    /* Se a pilha estiver vazia ou o operador encontrado na string for uma abertura de parênteses:
     * Este operador será diretamente empilhado;
     */
    if(Infixa::pilha->Vazia() || op == '(') {
    Infixa::pilha->Empilhar(op);
    } else {
        /* Caso o operador não seja uma abertura de parênteses ou a pilha nao estiver vazia:
         * É feito um switch para saber qual o operador que está no topo da pilha
         * Esse switch é feito para o teste de prioridade (se é o operador na string ou na pilha que tem prioridade)
         */
        switch(caracterTopo){
            //caso o topo seja '/' ou '*' (possuem a mesma prioridade)
            case '/':
            case '*':
                /* Se a prioridade recebida na funçao (prioridade do operador na string de operação infixa)
                 * For maior que a prioridade das operações '/' e '*': 3
                 *  - É empilhado o operador na pilha
                 */
                if(prioridade > 3){
                    Infixa::pilha->Empilhar(op);
                } else if(prioridade < 3) {
                    //Caso o operador na string tiver prioridade inferior ao da pilha e desempilhado o da pilha
                    Infixa::pilha->Desempilhar(ch);
                    //E direcionado para a saida o da pilha
                    cout << ch;
                    //Indice de controle do vetor que está lendo a pilha e tirado de 1
                    /* Isso é feito pois ao sair dessa função ele será acresentado de 1 novamente permanecendo
                     * no mesmo operador. Assim, quando voltar a está função podera ser testado novamente
                     * para um elemento que estáva empilhado mas não estava no topo e agora está. Caso esse elemento
                     * tabém tenha prioridade menor esse processo será realizado novamente até que se encontre um elemento
                     * na pilha que tenha prioridade igual ou maior que o elemento na string ou se a pilha ficar vaiza (nesse
                     * caso o elemento na string será empilhado);
                     */
                    i--;
                } else {
                    /* Se o operador na string tiver prioridade igual ao da pilha:
                     * Será desempilhado o operador da pilha e empilhado o da string
                     */
                    Infixa::pilha->Desempilhar(ch);
                    Infixa::pilha->Empilhar(op);
                    cout << ch;
                }
            break;
            case '+':
            case '-':
                //É exatamente o mesmo teste realizado para os operadores '/' e '*'
                if(prioridade > 2){
                    Infixa::pilha->Empilhar(op);
                } else if (prioridade < 2) {
                    Infixa::pilha->Desempilhar(ch);
                    cout << ch;
                    i--;
                } else {
                    Infixa::pilha->Desempilhar(ch);
                    Infixa::pilha->Empilhar(op);
                    cout << ch;
                }
                break;
            case '(':
                //Caso o operador na pilha seja uma apertura de parenteses não e necessário o teste de prioridade
                //E feito direto o empilhamento do operador na string;
                Infixa::pilha->Empilhar(op);
            break;
        }
    }
}


