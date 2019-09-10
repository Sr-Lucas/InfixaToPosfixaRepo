#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Infixa.h"

using namespace std;

Infixa::Infixa()
{
    /* Ao criar um objeto 'Infixa' � instancioado um objeto 'Pilha' e sua instacia
     * � armazenada em um atributo do mesmo tipo na classe 'Infixa'.
     */
    Infixa::pilha = new Pilha(); //tenho acesso a essa inst�ncia em toda a classe por todos os m�todos
}

void Infixa::toPosfixa(char str[])
{
    //Vou usar para percorrer a string que foi passada para convers�o
    int i = 0;

    //Fluxo que ir� percorrer a string que foi passada para convers�o
    //Enquanto meu vetor n�o apontar para '\0' (final da string) o la�o n�o ser� parado
    while(str[i] != '\0') {
        //Teste respos�vel por exibir operandos na tela quando encontrados
        if(str[i] != '/' && str[i] != '*' && str[i] != '+' && str[i] != '-' && str[i] != '(' && str[i] != ')' && str[i] != '\0') {
            cout << str[i];
        }

        char c = '\0';

        //Se o caracter apontado pelo vetor n�o for um operando ele � um operador
        //Fa�o um switch para saber qual � o operador que o vetor estpa apontando
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

    //la�o respos�vel por exibir os operadores restantes na pilha caso a string acabe e a pilha ainda contiver operadores!
    while(!pilha->Vazia()) {
        char ch;
        pilha->Desempilhar(ch);

        if(ch != '(' && ch != ')') cout << ch;
    }
}

/* M�todo privado que auxilia o toPosfixa
 *
 */
void Infixa::checkPriority(int prioridade, char op, int &i) {
    char caracterTopo;
    char ch = '\0';

    //Capturo o operador no topo da pilha
    Infixa::pilha->Top(caracterTopo);

    //Se o operador no topo for um fechamento de parenteses ')':
    //E execultado um la�o que se repetira at� que seja encontrado uma abertura de par�nteses '('
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

    //S� � execultado caso n�o seja um fechamento de par�nteses
    /* Se a pilha estiver vazia ou o operador encontrado na string for uma abertura de par�nteses:
     * Este operador ser� diretamente empilhado;
     */
    if(Infixa::pilha->Vazia() || op == '(') {
    Infixa::pilha->Empilhar(op);
    } else {
        /* Caso o operador n�o seja uma abertura de par�nteses ou a pilha nao estiver vazia:
         * � feito um switch para saber qual o operador que est� no topo da pilha
         * Esse switch � feito para o teste de prioridade (se � o operador na string ou na pilha que tem prioridade)
         */
        switch(caracterTopo){
            //caso o topo seja '/' ou '*' (possuem a mesma prioridade)
            case '/':
            case '*':
                /* Se a prioridade recebida na fun�ao (prioridade do operador na string de opera��o infixa)
                 * For maior que a prioridade das opera��es '/' e '*': 3
                 *  - � empilhado o operador na pilha
                 */
                if(prioridade > 3){
                    Infixa::pilha->Empilhar(op);
                } else if(prioridade < 3) {
                    //Caso o operador na string tiver prioridade inferior ao da pilha e desempilhado o da pilha
                    Infixa::pilha->Desempilhar(ch);
                    //E direcionado para a saida o da pilha
                    cout << ch;
                    //Indice de controle do vetor que est� lendo a pilha e tirado de 1
                    /* Isso � feito pois ao sair dessa fun��o ele ser� acresentado de 1 novamente permanecendo
                     * no mesmo operador. Assim, quando voltar a est� fun��o podera ser testado novamente
                     * para um elemento que est�va empilhado mas n�o estava no topo e agora est�. Caso esse elemento
                     * tab�m tenha prioridade menor esse processo ser� realizado novamente at� que se encontre um elemento
                     * na pilha que tenha prioridade igual ou maior que o elemento na string ou se a pilha ficar vaiza (nesse
                     * caso o elemento na string ser� empilhado);
                     */
                    i--;
                } else {
                    /* Se o operador na string tiver prioridade igual ao da pilha:
                     * Ser� desempilhado o operador da pilha e empilhado o da string
                     */
                    Infixa::pilha->Desempilhar(ch);
                    Infixa::pilha->Empilhar(op);
                    cout << ch;
                }
            break;
            case '+':
            case '-':
                //� exatamente o mesmo teste realizado para os operadores '/' e '*'
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
                //Caso o operador na pilha seja uma apertura de parenteses n�o e necess�rio o teste de prioridade
                //E feito direto o empilhamento do operador na string;
                Infixa::pilha->Empilhar(op);
            break;
        }
    }
}


