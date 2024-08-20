#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "funcao.h"


int main() {
// Cria duas variáveis , uma de "ex " para armazenar vetores e a "vec " par armazenar os valores que a ex receber

    char exp[100] = ""; // Guarda Expressão
    char vec[100][20] = {'\0'};// Guarda Vetor, expressão separada = pilha que armazena toda expressão

//Evita trazer lixo então limpa inicialmente 
    limpaVetor(vec, 100);
//Para preencher o vetor, cada item em uma posição
    strcpy(exp,"((22 + 5) * 2) / 3");
// Guarda expressão no vetor, ou seja, cada elemento em uma posição do vetor 
    stringParaVetor(exp, vec, 100);
// Mostrar o vetor 
    for(int i = 0; i < 100 && (strcmp(vec[i], "") !=  0); i++)
    {
        printf("%s\n", vec[i]);
    }
// 1-Chamar função que separa os elementos 
   stringParaVetor(exp, vec, 100);
// 2- Criar Pilhas Separar em Pilhas
char Pilhaoperador[100][20];// criar pilha de operadores
char Pilhavalor[100][20];// Pilha para guardar Valores
int topooperador = -1;
int topovalor = -1;

// 3- Separar em Pilhas os valores 
// Fazemos um for para pecorrer todo o vetor Vec, se ele for operador a pilha de operadores recebe esses valores na posição i 
// se for valor quem recebe é a pilha de valor 
    for (int i = 0; i < 100 && strcmp(vec[i], "") != 0; i++) {
        if (find(vec[i][0], "+-*/()")) { // Se é operador
            strcpy(Pilhaoperador[++topooperador], vec[i]);
        } else { // Se é valor
            strcpy(Pilhavalor[++topovalor], vec[i]);
        }
     }
// Mostrar pilha de Operadores
    printf("Pilha de Operadores:\n");
        for (int i = 0; i <= topooperador; i++) {
        printf("%s\n", Pilhaoperador[i]);
    }

// Mostrar a pilha de valores
    printf("\nPilha de Valores:\n");
        for (int i = 0; i <= topovalor; i++) {
        printf("%s\n", Pilhavalor[i]);
    }
// Enquanto o elemento no topo da pilha de operadores não for um abre parênteses.
    while (Pilhaoperador[topooperador] != "(") 
    {
      //  1 Retire o operador da pilha de operadores.
      char operadorRemovido;
      ipopOperador(Pilhaoperador[100][20], &topooperador, &operadorRemovido);
      char valorRemovido;
      popValor(Pilhavalor[100][20],&topovalor,&valorRemovido);
      


    }
}
