#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
//Adryelle Caroline de Souza Calefi

//A função verifica se op1 tem a mesma ou maior precedência que op2,(precedencia é a ordem que vai ser realizado as contas, 
//ou seja na aritimetica o / tem mais valor que +) retornando false se op2 for um parêntese ou se op1 for multiplicação/divisão e 
//op2 for adição/subtração. Caso contrário, retorna true.

bool mesmaOuMaiorPrecedencia(char op1, char op2) {
    if(op2 == '(' || op2 == ')')
    {
        return false;
    }
    if((op1 == '*' || op1 == '/') &&
       (op2 == '+' || op2 == '-'))
    {
        return false;
    }
    else
    {
        return true;
    }
}
//A função percorre uma string procurando por um caractere específico. Se encontrar, retorna true; caso contrário, retorna false.

bool find(char letra, char *str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == letra)
        {
            return true;
        }
    }
    return false;
}
// Função que separa o que é vetor e o que é string
void stringParaVetor(char *line, char vec[][20], int tamanho)
{
    char trab[tamanho];
    char operacoes[] = "+-*/()";
    char letra;
    bool numero = false;
    bool str = false;
    int vecI = 0;
    int aux = 0;
    strcpy(trab, "");

    for(int i = 0; i < tamanho; i++)
    {
        letra = line[i];
        if((isdigit(letra) || letra=='.')  && !str)
        {
            if(!numero)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                }
            // Numero guarda os valores
                numero = true;
            // Str guarda operadores
                str = false;
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
        }
        else if(letra == ' ')
        {
            if(!str)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                    numero = false;
                    str = false;
                }
            }
        }
    // FIND - ele verifica se a pilha está vazia e zera ela apenas 
        else if(find(letra, operacoes) != 0)
        {
            if(strlen(trab)!=0)
            {
                strcpy(vec[vecI++],trab);
                strcpy(trab, "");
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
            strcpy(vec[vecI++],trab);
            strcpy(trab, "");
            numero = false;
            str = false;
        }
    }
    if(strlen(trab)!=0)
    {
        strcpy(vec[vecI++],trab);
    }
}
// Limpa o vetor 
void limpaVetor(char v[][20], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        strcpy(v[i], "");
    }
}
// Função para pegar o operador
char operadorRemovido;
void ipopOperador(char Pilhaoperador[100][20], int *topooperador, char *operadorRemovdo) {
    if (*topooperador >= 0) { // Verifica se a pilha não está vazia
        strcpy(operadorRemovido, Pilhaoperador[*topooperador]); // Copia o operador do topo
        (*topooperador)--; // Diminui o índice do topo, efetivamente removendo o operador
    } else {
        strcpy(operadorRemovido, ""); // Se a pilha estiver vazia, retorna uma string vazia
    }
}

//Função para pegar valores
void popValor(char Pilhavalor[100][20], int *topovalor, char *valorRemovido) {
    if (*topovalor >= 0) { // Verifica se a pilha não está vazia
        strcpy(valorRemovido, Pilhavalor[*topovalor]); // Copia o valor do topo
        (*topovalor)--; // Diminui o índice do topo, efetivamente removendo o valor
    } else {
        strcpy(valorRemovido, ""); // Se a pilha estiver vazia, retorna uma string vazia
    }
}