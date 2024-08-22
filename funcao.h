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
//Função pop vec
void popVec (char vec[][200], int *topovec, char *vecRemovido)
{
if (*topovec >= 0) { // Verifica se a pilha não está vazia
        strcpy(vecRemovido, vec[*topovec]); // Copia o operador do topo
        (*topovec)--; // Diminui o índice do topo, efetivamente removendo o operador
    } else {
        strcpy(vecRemovido, ""); // Se a pilha estiver vazia, retorna uma string vazia
    }
}
void popOperador(char Pilhaoperador[][20], int *topooperador, char *operadorRemovido) {
    if (*topooperador >= 0) {
        strcpy(operadorRemovido, Pilhaoperador[*topooperador]);
        (*topooperador)--;
    } else {
        strcpy(operadorRemovido, "");
    }
}

void popValor(char Pilhavalor[][20], int *topovalor, char valorRemovido[2][20]) {
    for (int i = 0; i < 2; i++) {
        if (*topovalor >= 0) {
            strcpy(valorRemovido[i], Pilhavalor[*topovalor]);
            (*topovalor)--;
        } else {
            strcpy(valorRemovido[i], "");
        }
    }
}
//Função para pegar os valor removidos e faz a equação entre eles 
void popValorEquacao(char Pilhavalor[100][20], int *topovalor, char Pilhaoperador[100][20], int *topooperador) {
    char valorRemovido[2][20];
    char operadorRemovido[20];

    popOperador(Pilhaoperador, topooperador, operadorRemovido);
    popValor(Pilhavalor,topovalor, valorRemovido);

    printf("Valores: %s, %s\n", valorRemovido[0], valorRemovido[1]);
    printf("Operador: %s\n", operadorRemovido);
}


int tamanhoPreenchido(char vec[][20], int tamanhoTotal) {
    int tamanho = 0;
    for (int i = 0; i < tamanhoTotal; i++) {
        if (strcmp(vec[i], "") != 0) {
            tamanho++;
        } else {
            break;
        }
    }
    return tamanho;
}

void pushOperador(char Pilhaoperador[][20], int *topooperador, const char *novoOperador) {
    // Incrementa o topo e insere o novo operador na pilha
    (*topooperador)++;
    strcpy(Pilhaoperador[*topooperador], novoOperador);
}

void pushValor(char Pilhavalor[][20], int *topovalor, const char novoValor[20]) {
    // Incrementa o topo e insere o novo valor na pilha
    (*topovalor)++;
    strcpy(Pilhavalor[*topovalor], novoValor);
}
void intToStr(int num, char *str) {
    sprintf(str, "%d", num);
}

