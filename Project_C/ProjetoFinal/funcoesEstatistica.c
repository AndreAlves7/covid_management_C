#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "funcoesMembros.h"
#include "funcoesAuxiliares.h"
#include "funcoesAgendamento.h"


void quantidadeDeCadaTipo(tipoMembro membros[], int totalDeMembros){
    int i, cntEstudantes, cntDocentes, cntTecnicos;

    cntDocentes = 0;
    cntEstudantes = 0;
    cntTecnicos = 0;

    for (i=0; i<totalDeMembros; i++){
        switch (membros[i].membro)
        {
        case Estudante:
            cntEstudantes++;
            break;
        case Docente:
            cntDocentes++;
            break;
        case Tecnico:
            cntTecnicos++;
            break;         
        } 
    }

    printf("\ntotal de estudantes: %d", cntEstudantes);
    printf("\ntotal de Docentes: %d", cntDocentes);
    printf("\ntotal de Tecnicos: %d", cntTecnicos);

}

void tempoMedioDeCadaTesteRealizado(tipoAgendamento *vetorAgendamentos, int totalDeAgendamentos){
    int i, cntTestesRealizados, cntTotalDuracao;
    float media;

    cntTestesRealizados = 0;
    cntTotalDuracao = 0;

    for(i=0; i<totalDeAgendamentos;i++){
        if (vetorAgendamentos[i].jaRealizado == Sim){
            cntTestesRealizados++;
            cntTotalDuracao += vetorAgendamentos[i].tempoDeDuracao;
        }

    }

    if (cntTestesRealizados != 0){
        media = (float) cntTotalDuracao / cntTestesRealizados;

        printf("\nTempo medio de cada teste realizado: %.2f min",  media); 
    }else{
        printf("\nAinda nao ha testes realizados."); 
    }


}

void membrosMenorQuantidadeTestesRealizados(tipoMembro *vetorMembros, int totalMembros, tipoAgendamento *vetorAgendamentos, int totalAgendamentos){

    int i, j, menor, cnt;

    menor = totalAgendamentos + 1; //valor muito alto (impossivel de acontecer)

    for (i=0; i<totalMembros; i++){
        cnt = 0;
        for(j=0; j<totalAgendamentos;j++){
            if (vetorMembros[i].numeroUtente == vetorAgendamentos[j].numUtente){
                if(vetorAgendamentos[j].jaRealizado = Sim){
                    cnt++;
                }
            }
        }

        menor = menorValor(menor, cnt);

    }


    printf("membros com %d teste(s) feito(s)\n\n", menor);


    for (i=0; i<totalMembros; i++){
        cnt = 0;
        for(j=0; j<totalAgendamentos;j++){
            if (vetorMembros[i].numeroUtente == vetorAgendamentos[j].numUtente){
                if(vetorAgendamentos[j].jaRealizado = Sim){
                    cnt++;
                }
            }
        }

        if (cnt == menor){
            mostraMembro(vetorMembros[i]);
            printf("-------------------\n");
        }

    }

}


void membrosTestesRealizadosMaisRecentes(tipoAgendamento *vetorAgendamentos, int totalAgendamentos){
    int i, resultado, jaTemUmaMaisRecente=0;
    tipoData dataMaisRecente;



    for(i=0; i<totalAgendamentos;i++){
        if(vetorAgendamentos[i].jaRealizado = Sim){
            if(jaTemUmaMaisRecente){
                resultado = comparaDatas(vetorAgendamentos[i].dataRealizacao, dataMaisRecente);
            }else{
                resultado = comparaDatas(vetorAgendamentos[i].dataRealizacao, vetorAgendamentos[i].dataRealizacao);
                jaTemUmaMaisRecente = 1;
            }

            if(resultado == -1 || resultado == 0){
                dataMaisRecente = vetorAgendamentos[i].dataRealizacao;
            }
        }
    }


    for(i=0; i<totalAgendamentos;i++){
        if(vetorAgendamentos[i].jaRealizado = Sim){
            if(comparaDatas(vetorAgendamentos[i].dataRealizacao, dataMaisRecente) == 0){
                mostraAgendamento(vetorAgendamentos[i]);
            }
        }
    }





}



void percentagemInconclusivos(tipoAgendamento *vetorAgendamentos, int totalAgendamentos){
    int i, cnt=0,totalJaRealizados=0;
    float percentagem;

    for(i=0;i<totalAgendamentos;i++){
        if(vetorAgendamentos[i].jaRealizado == Sim){
            if(vetorAgendamentos[i].resultado == Inconclusivo){
                cnt++;
            }
            totalJaRealizados++;
        }
        

    }

    if(totalJaRealizados!=0){
        percentagem = ((float) cnt/totalJaRealizados)*100;
        printf("Percentagem de testes inconclusivos %.2f", percentagem);
    }

}
