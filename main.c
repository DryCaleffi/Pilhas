
#include <stdio.h>
#include "funcao.h"
#include "pilha.h"

int main() {

    char exp[100] = "";
    char vec[100][20] = {'\0'};

    strcpy(exp,"(((25+3)*3+22-32)/2)");

    stringParaVetor(exp, vec, TAMANHO);

        for(int i = 0; i < 100 && (strcmp(vec[i], "") !=  0); i++)
        {
            printf("%s\n", vec[i]);
        }

    OperacaoResultado(vec);

        printf ("\nO resultado e %.2lf\n",pilhatopo_double());

    return 0;
}

