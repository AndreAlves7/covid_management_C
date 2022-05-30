#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#include "funcoesConfinamentos.h"


tipoConfinamento *adicionarConfinamento(tipoConfinamento *vetorConfinamentos, int *totalConfinamentos, tipoConfinamento confinamento){
    tipoConfinamento *paux;


    paux = vetorConfinamentos;


    vetorConfinamentos = realloc(vetorConfinamentos,(*totalConfinamentos+1)*sizeof(tipoConfinamento));
    if (vetorConfinamentos == NULL)
    {
        printf ("Erro - Impossivel aumentar o vetor");
        vetorConfinamentos = paux; 	/* restaura valor  */
    }
    else{
        vetorConfinamentos[*totalConfinamentos] = confinamento;
        (*totalConfinamentos)++;
    }


    return vetorConfinamentos;

}


void listarConfinamentos(tipoConfinamento *vetorConfinamentos, int totalConfinamentos){
    int i;

    if (totalConfinamentos != 0){
        for (i=0; i<totalConfinamentos; i++){
            printf("\nNumero de utente do membro: %d", vetorConfinamentos[i].numeroUtente);
            printf("\nData de Confinamento %02d/%02d/%4d", vetorConfinamentos[i].dataDeConfinamento.dia,vetorConfinamentos[i].dataDeConfinamento.mes, vetorConfinamentos[i].dataDeConfinamento.ano );
            printf("\nEstado do Confinamento: %s", converteEstadoConfinamentoParaString(vetorConfinamentos[i].estado));
            printf("\nEstado de duracao do confinamento: %d dias", vetorConfinamentos[i].tempoDeDuracao);
            printf("\n============================================");
        }
    }else{
        printf("Nao existem confinamentos.");
    }

    

}