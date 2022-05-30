#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#include "funcoesLeitura.h"
#include "funcoesMembros.h"
#include "funcoesAgendamento.h"
#include "funcoesAuxiliares.h"



tipoAgendamento *adicionaAgendamento(tipoAgendamento *vetorAgendamentos, int *totalAgendamentos, tipoMembro vetorMembros[], int totalMembros){
    int valido, numUtente, pos;
    tipoAgendamento dados, *paux;


    paux = vetorAgendamentos;


    printf("Numero de utente (1 a 9999): ");
    numUtente = lerInteiro(1,9999);

    pos = procuraIndexMembroPorNDeUtente(vetorMembros, totalMembros, numUtente);

    if(pos == -1){
        printf("Membro nao encontrado");
    }else{
        vetorAgendamentos = realloc(vetorAgendamentos,(*totalAgendamentos+1)*sizeof(tipoAgendamento));
        if (vetorAgendamentos == NULL)
        {
            printf ("Erro - Impossivel aumentar o vetor");
            vetorAgendamentos = paux; 	/* restaura valor  */
        }
        else{
            
            dados= lerDadosAgendamento();
            dados.designacao = *totalAgendamentos+1;
            dados.numUtente = numUtente;

            //verificar se e possivel adicionar agendamento (<15 testes PCR)
            valido = verificaLimiteAgendamento(dados, vetorAgendamentos, *totalAgendamentos);

            if (!valido){
                printf("O limite de testes diarios PCR para a data inserida foi excedido !");
            }else{
                vetorAgendamentos[*totalAgendamentos] = dados;
                (*totalAgendamentos)++;
            }
        }
    }


    return vetorAgendamentos;

}


tipoAgendamento *adicionaAgendamentoDiretamente(tipoAgendamento *vetorAgendamentos, int *totalAgendamentos, tipoAgendamento novoAgendamento){
    int valido, numUtente, pos;
    tipoAgendamento dados, *paux;


    paux = vetorAgendamentos;


    vetorAgendamentos = realloc(vetorAgendamentos,(*totalAgendamentos+1)*sizeof(tipoAgendamento));
    if (vetorAgendamentos == NULL)
    {
        printf ("Erro - Impossivel aumentar o vetor");
        vetorAgendamentos = paux; 	/* restaura valor  */
    }else{
        vetorAgendamentos[*totalAgendamentos] = novoAgendamento;
        (*totalAgendamentos)++;
    }

    return vetorAgendamentos;
}

/*
    Agendar a realização de um teste, considerando que num determinado dia se
    poderão efetuar, no máximo, 15 testes do tipo PCR. 

    -> 0 -> invalido
    -> 1 -> valido

*/
int verificaLimiteAgendamento(tipoAgendamento dados, tipoAgendamento *vetorAgendamentos, int totalAgendamentos){
    int i, mesmoDia=0, valido=0;

    if (dados.teste == PCR){
        for(i=0; i<totalAgendamentos; i++){
            if(vetorAgendamentos[i].teste == PCR){
                if (comparaDatas(dados.dataRealizacao, vetorAgendamentos[i].dataRealizacao) == 0){
                    mesmoDia++;
                }
            }        
        }

        if (mesmoDia == LIMITE_MAXIMO_PCR){
            valido = 0;
        }else{
            valido = 1;
        }

    }else{
        valido = 1;
    }
    
    return valido;

}

tipoAgendamento lerDadosAgendamento(void){

    tipoAgendamento dadosAgendamento;

    // Inserir designacao dinamicamente
    // printf("Designacao (1 a 9999): ");
    // dadosAgendamento.designacao = lerInteiro(1,9999);

    // printf("NUmero de utente (1 a 9999): ");
    // dadosAgendamento.numUtente = lerInteiro(1,9999);

    printf("Tipo de teste: (%d)PCR, (%d) antigenio ", PCR, Antigenio);
    dadosAgendamento.teste = lerInteiro(PCR, Antigenio);

    printf("Data da realizacao: ");
    dadosAgendamento.dataRealizacao = lerData();

    dadosAgendamento.jaRealizado = Nao;

    return dadosAgendamento;

}

void listaAgendamentos(tipoAgendamento *vetorAgendamentos, int totalAgendamentos)
{
    int i, existemAgendamentosNaoRealizados = 0;

    if (totalAgendamentos == 0)
    {
        printf("\n Nao existem agendamentos !!");
    }
    else
    {
        for (i=0; i<totalAgendamentos; i++){
            if (vetorAgendamentos[i].jaRealizado == Nao){
                mostraAgendamento(vetorAgendamentos[i]);
            
                existemAgendamentosNaoRealizados = 1;
            }

        }

        // os testes dos agendamentos ja foram todos realizados
        if(!existemAgendamentosNaoRealizados){
            printf("\n Nao existem agendamentos !!");
        }
    }

}

/*
    mostra agendamentos, realizados e nao realizados
*/
void mostraAgendamento(tipoAgendamento agendamento){
    printf("Designacao: %d\n", agendamento.designacao);
    printf("Numero Utente: %d\n", agendamento.numUtente);
    printf("tipo de teste: %s\n", converteTipoDetesteParaString(agendamento.teste));
    printf("Data realizacao: %02d/%02d/%4d\n\n", agendamento.dataRealizacao.dia, agendamento.dataRealizacao.mes, agendamento.dataRealizacao.ano);

    if (agendamento.jaRealizado == Sim){
        printf("Tempo de duracao: %d\n", agendamento.tempoDeDuracao);
        printf("Hora da colheita (minutos): %d\n", agendamento.horaColheita);
        switch (agendamento.resultado)
        {
        case Positivo:
            printf("resultado: Positivo\n");
            break;
        case Negativo:
            printf("resultado: Positivo\n");
            break;
        case Inconclusivo:
            printf("resultado: Inconclusivo\n");
            break;        
        }
    }

    printf("------------------------\n");
}

void alterarDataAgendada(tipoAgendamento *vetorAgendamentos, int totalAgendamentos){
    int designacaoUnica, pos, valido;
    tipoData data;
    tipoAgendamento aux;

    printf("Insira a designacao do teste que quer alterar: ");
    designacaoUnica = lerInteiro(1,9999);

    pos = procuraIndexAgendamentoPorDesignacaoUnica(vetorAgendamentos, totalAgendamentos, designacaoUnica);

    if (pos != -1){
        if (vetorAgendamentos[pos].jaRealizado == Sim){
            printf("\nNao e possivel alterar a data porque o teste ja foi realizado.");
        }else{
            printf("Nova data de realizacao: ");
            data = lerData();

            //TODO verificar se a data e diferente
            // verificar se e possivel alterar a data
            aux = vetorAgendamentos[pos];
            aux.dataRealizacao = data;
            //verificar se e possivel adicionar agendamento (<15 testes PCR)
            valido = verificaLimiteAgendamento(aux, vetorAgendamentos, totalAgendamentos);
            if (valido){
                vetorAgendamentos[pos].dataRealizacao = data;
            }else{
                printf("O limite de testes diarios PCR para a data inserida foi excedido !");
            }
        }

    }else{
        printf("nao foi encontrado nenhum agendamento com a designacao inserida.");
    }



}

int registaResultado(tipoAgendamento *vetorAgendamentos, int *totalAgendamentos , int totalTestesRealizados, tipoMembro *vetorMembros, int totalMembros, tipoConfinamento **vetorConfinamento, int *totalConfinamento){
    int designacaoUnica, pos1, pos2, valido;
    tipoAgendamento novoAgendamento;
    tipoConfinamento novoConfinamento;

    printf("Insira a designacao do agendamento que quer registar o resultado: ");
    designacaoUnica = lerInteiro(1,9999);

    pos1 = procuraIndexAgendamentoPorDesignacaoUnica(vetorAgendamentos, *totalAgendamentos, designacaoUnica);

    
    if (pos1 != -1){

        if (vetorAgendamentos[pos1].jaRealizado == Sim){
            printf("\nJa foi registado um resultado.");
        }else{
            printf("tempo de duracao: ");
            vetorAgendamentos[pos1].tempoDeDuracao = lerInteiro(1, 300); //5h

            printf("Hora da colheita (minutos): ");
            vetorAgendamentos[pos1].horaColheita = lerInteiro(0, 24);

            printf("resultado: (%d)Positivo, (%d)Negativo, (%d)inconclusivo: ", Positivo, Negativo, Inconclusivo);
            vetorAgendamentos[pos1].resultado = lerInteiro(Positivo, Inconclusivo);

            vetorAgendamentos[pos1].jaRealizado = Sim; //marca o agendamento como realizado

            totalTestesRealizados++;



            if(vetorAgendamentos[pos1].resultado == Inconclusivo || (vetorAgendamentos[pos1].resultado == Positivo && vetorAgendamentos[pos1].teste == Antigenio)){
                printf("Escolha uma data para podermos marcar um teste do tipo PCR");

                novoAgendamento.designacao = *totalAgendamentos + 1;
                novoAgendamento.jaRealizado = Nao;
                novoAgendamento.numUtente = vetorAgendamentos[pos1].numUtente;
                novoAgendamento.teste = PCR;

                do{
                    novoAgendamento.dataRealizacao = lerData();
                    valido = verificaLimiteAgendamento(novoAgendamento, vetorAgendamentos, *totalAgendamentos);
                }while(!valido);

                vetorAgendamentos = adicionaAgendamentoDiretamente(vetorAgendamentos, totalAgendamentos, novoAgendamento);
                printf("\nNovo agendamento Inserido!");

            }

            if (vetorAgendamentos[pos1].resultado == Positivo){
                pos2 = procuraIndexMembroPorNDeUtente(vetorMembros, totalMembros, vetorAgendamentos[pos1].numUtente);
                if(pos2 != -1){ 
                    vetorMembros[pos2].estado = Isolamento;//coloca o membro em isolamento

                    novoConfinamento.estado = Isolamento;
                    novoConfinamento.dataDeConfinamento = vetorAgendamentos[pos1].dataRealizacao;
                    novoConfinamento.numeroUtente = vetorAgendamentos[pos1].numUtente;
                    printf("\nInsira o tempo de duracao(em dias) do confinamento: (1-30) ");
                    novoConfinamento.tempoDeDuracao = lerInteiro(1,30);
                    *vetorConfinamento = adicionarConfinamento(*vetorConfinamento, totalConfinamento, novoConfinamento);
                }
            }

            if(vetorAgendamentos[pos1].resultado == Inconclusivo){
                pos2 = procuraIndexMembroPorNDeUtente(vetorMembros, totalMembros, vetorAgendamentos[pos1].numUtente);
                if(pos2 != -1){ 
                    vetorMembros[pos2].estado = Quarentena;//coloca o membro em quarentena

                    novoConfinamento.estado = Quarentena;
                    novoConfinamento.dataDeConfinamento = vetorAgendamentos[pos1].dataRealizacao;
                    novoConfinamento.numeroUtente = vetorAgendamentos[pos1].numUtente;
                    printf("\nInsira o tempo de duracao(em dias) do confinamento: (1-30) ");
                    novoConfinamento.tempoDeDuracao = lerInteiro(1,30);
                    *vetorConfinamento = adicionarConfinamento(*vetorConfinamento, totalConfinamento, novoConfinamento);
                }
            }
        }

        Logteste(vetorAgendamentos[pos1], vetorMembros[pos2]);
        



    }else{
        printf("nao foi encontrado nenhum agendamento com a designacao inserida.");
    }


    return totalTestesRealizados;

}


int procuraIndexAgendamentoPorDesignacaoUnica(tipoAgendamento *vetorAgendamentos, int totalAgendamentos, int designacaoUnica){
    int i = 0, pos = -1;

    for (i=0; i<totalAgendamentos; i++){
        if (vetorAgendamentos[i].designacao == designacaoUnica){
            pos = i;
            break;
        }
    }

    return pos;
}


void listarTestesRealizados(tipoAgendamento *vetorAgendamentos, int totalAgendamentos){
    int i, existemTestesJaRealizados = 0;

    for(i=0; i<totalAgendamentos; i++){
        if (vetorAgendamentos[i].jaRealizado == Sim){
            mostraAgendamento(vetorAgendamentos[i]);

            existemTestesJaRealizados = 1;
        }

    }

    if(!existemTestesJaRealizados){
        printf("\nNao existem testes realizados.");
    }
}


int qtdDeTestesRealizadosPorMembro(tipoAgendamento *vetorAgendamentos, int totalAgendamentos, int numeroUtente){
 int i, cntTestesRealizados=0;

    for(i=0; i<totalAgendamentos; i++){
        if (vetorAgendamentos[i].numUtente == numeroUtente){ //agendamentos do numeroUtente
            if (vetorAgendamentos[i].jaRealizado == Sim){
                cntTestesRealizados++;
            }
        }
    }

    return cntTestesRealizados;
}

void informacaoDeUmTeste(tipoAgendamento *vetorAgendamentos, int totalAgendamentos, tipoMembro *vetorMembros, int totalMembros){
    int designacaoUnica, pos, i, numUtente, cntPositivos=0;

    printf("Insira a designacao do teste: ");
    designacaoUnica = lerInteiro(1,9999);

    pos = procuraIndexAgendamentoPorDesignacaoUnica(vetorAgendamentos, totalAgendamentos, designacaoUnica);

    if (pos == -1){
        printf("Nao existe nenhum teste com a designacao inserida.");
    }else{
        if(vetorAgendamentos[pos].jaRealizado == Sim){
            mostraAgendamento(vetorAgendamentos[pos]);
            
            for(i=0; i<totalMembros; i++){
                if(vetorMembros[i].numeroUtente == vetorAgendamentos[pos].numUtente){
                    numUtente = vetorMembros[i].numeroUtente;
                    printf("\nnome: %s", vetorMembros[i].nome);
                    printf("\ntipo de membro: %s", converteTipoDeMembroParaString(vetorMembros[i].membro));
                }
            }

            for(i=0; i<totalAgendamentos; i++){
                if(vetorAgendamentos[i].numUtente == numUtente){
                    if(vetorAgendamentos[i].jaRealizado == Sim){
                        if(vetorAgendamentos[i].resultado == Positivo){
                            cntPositivos++;
                        }
                    }
                }
            }

            printf("\nTestes positivos: %d", cntPositivos);
        }else{
            printf("O teste ainda nao foi realizado. Registe o resultado primeiro ou Liste os agendamentos para obter mais info.");
        }

        

    }

}