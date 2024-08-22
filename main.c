#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "funcao.h"


int main() {
// Cria duas variáveis , uma de "ex " para armazenar expressão e a "vec " par armazenar os valores que a ex receber

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
   
// 1- Criar Pilhas 
char Pilhaoperador[100][20]; // Pilha de operadores
    char Pilhavalor[100][20]; // Pilha para valores
    int topooperador = -1;
    int topovalor = -1;
    int topovec = tamanhoPreenchido(vec, 100);
    char vecRemovido[20]; // Ajustado para armazenar strings
    char valorRemovido[2][20];
    char operadorRemovido[20];
    char novoValor[20]; // 


// Enquanto o elemento no topo da pilha de operadores não for um abre parênteses.
while(topovec >= 0){
    popVec(vec, &topovec, vecRemovido);
    if (strcmp(vecRemovido != "+-*/()")) { // Se é valor
            strcpy(Pilhavalor[++topovalor], vec[topovec]);
    
        } else if (find(vecRemovido, "+-*/)")) { // Se é operador
            strcpy(Pilhaoperador[++topooperador], vec[topovec]);
        }else{
     while (strcmp(Pilhaoperador[topooperador], "(") != 0)
{   
 popOperador(Pilhaoperador,&topooperador,operadorRemovido);
 popValor(Pilhavalor,&topovalor,valorRemovido);
 
    int valor1 = atoi(valorRemovido[1]);
    int valor2 = atoi(valorRemovido[0]);
    double resultado;
 // valor 1 , operador, valor 2
 if (strcmp(operadorRemovido, "+") == 0) {
        resultado = valor2 + valor1;
    } else if (strcmp(operadorRemovido, "-") == 0) {
        resultado = valor2 - valor1;
    } else if (strcmp(operadorRemovido, "*") == 0) {
        resultado = valor2 * valor1;
    } else if (strcmp(operadorRemovido, "/") == 0) {
        resultado = valor2 / valor1;
    }
    char novoValor = str(resultado);
   pushValor(Pilhavalor,&topovalor,novoValor);
   popVec(vec, &topovec, vecRemovido);
   

    }
}
}
while(Pilhaoperador >= 0)
{
popOperador(Pilhaoperador,&topooperador,operadorRemovido);
popValor(Pilhavalor,&topovalor,valorRemovido);
 int valor1 = atoi(valorRemovido[1]);
    int valor2 = atoi(valorRemovido[0]);
    double resultado;
 // valor 1 , operador, valor 2
 if (strcmp(operadorRemovido, "+") == 0) {
        resultado = valor2 + valor1;
    } else if (strcmp(operadorRemovido, "-") == 0) {
        resultado = valor2 - valor1;
    } else if (strcmp(operadorRemovido, "*") == 0) {
        resultado = valor2 * valor1;
    } else if (strcmp(operadorRemovido, "/") == 0) {
        resultado = valor2 / valor1;
    }
     intToStr((int)resultado, novoValor);
    pushValor(Pilhavalor,&topovalor,novoValor);
   
}
//Pilha de operadores
   printf("Pilha de Operadores:\n");
        for (int i = 0; i <= topooperador; i++) {
        printf("%s\n", Pilhaoperador[i]);
    }

// Mostrar a pilha de valores
    printf("\nPilha de Valores:\n");
        for (int i = 0; i <= topovalor; i++) {
        printf("%s\n", Pilhavalor[i]);
    }


}
