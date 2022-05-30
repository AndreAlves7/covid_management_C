#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "funcoesLeitura.h"
#include "tipoMembro.h"
#include "funcoesConfinamentos.h"
#include "funcoesMembros.h"
#include "enumsMembros.h"
#include "funcoesAgendamento.h"


int adicionarMembro(tipoMembro vetorMembros[], int totalMembros){
    tipoMembro dados;
    int pos;

    if (totalMembros == MAX_MEMBROS){
        printf("Impossivel acrescentar novos membros");
    }
    else{
        dados=lerDadosMembro();

        // verifica se ja existe um membro com o nmr de utente inserido
        pos = procuraIndexMembroPorNDeUtente(vetorMembros, totalMembros, dados.numeroUtente);

        if(pos == -1){
            vetorMembros[totalMembros] = dados;
            totalMembros++;
        }else{
            printf("Ja existe um membro com o Numero de utente inserido.");
        }

        
    }
    return totalMembros;

}

tipoMembro lerDadosMembro(void){

    tipoMembro dadosMembro;

    printf("Numero de Utente (1 a 9999): ");
    dadosMembro.numeroUtente = lerInteiro(1,9999);

    printf("Nome: ");
    lerString(dadosMembro.nome, 50);

    printf("Tipo do Membro: (%d) estudante, (%d) docente, (%d) tecnico: ", Estudante, Docente, Tecnico);
    dadosMembro.membro = lerInteiro(Estudante, Tecnico);


    printf("Data de nascimento: ");
    dadosMembro.dataNascimento = lerData();

    // printf("Estado de confinamento: (%d) nao confinado, (%d) quarentena, (%d) isolamento profilatico: ", NaoConfinado, Quarentena, Isolamento);
    // dadosMembro.estado = lerInteiro(NaoConfinado, Isolamento);
    dadosMembro.estado = NaoConfinado; //por defeito o estado e nao confinado

    printf("Estado da vacina: (%d) sem vacina, (%d) dose 1,(%d) dose 2,(%d) dose 3: ", SemVacina, Dose1, Dose2, Dose3);
    dadosMembro.dose = lerInteiro(SemVacina, Dose3);

    if (dadosMembro.dose != SemVacina){
        printf("Data da ultima vacina: ");
        dadosMembro.dataVacina = lerData();
    }


    return dadosMembro;

}


void mostraMembro(tipoMembro membro){
        printf("numero utente-> %d\n", membro.numeroUtente);
        printf("nome-> %s \n", membro.nome);
        printf("data de Nascimento %02d/%02d/%4d\n", membro.dataNascimento.dia,membro.dataNascimento.mes, membro.dataNascimento.ano );
        
        printf("tipo membro-> %s \n", converteTipoDeMembroParaString(membro.membro));
        printf("doseVacina-> %s \n", converteDoseVacinaParaString(membro.dose));
        printf("Estado confinamento-> %s \n", converteEstadoConfinamentoParaString(membro.estado));
        if (membro.dose != SemVacina){
            printf("data da ultima vacina %02d/%02d/%4d\n", membro.dataVacina.dia,membro.dataVacina.mes, membro.dataVacina.ano );
        }

}

void mostraInfoAdicional(tipoAgendamento *vetorAgendamentos, int totalAgendamentos, int numeroUtente){
    int i, cntTestesRealizados=0, temTestesAgendados=0;
    int qtdDeTestesRealizados;

    qtdDeTestesRealizados = qtdDeTestesRealizadosPorMembro(vetorAgendamentos, totalAgendamentos, numeroUtente);

    printf("\nquantidade de testes realizados-> %d", qtdDeTestesRealizados);

    printf("\n\n-----Testes agendados-----");
    for(i=0; i<totalAgendamentos; i++){
        if (vetorAgendamentos[i].numUtente == numeroUtente){ //agendamentos do numeroUtente
           if(vetorAgendamentos[i].jaRealizado == Nao){
                temTestesAgendados = 1;
                printf("\ntipo de teste-> %s", converteTipoDetesteParaString(vetorAgendamentos[i].teste));
                printf("\nData realizacao: %02d/%02d/%4d\n\n", vetorAgendamentos[i].dataRealizacao.dia, vetorAgendamentos[i].dataRealizacao.mes, vetorAgendamentos[i].dataRealizacao.ano);
                printf("===================================");

           }

        }
    }

    if (!temTestesAgendados){
        printf("\nO membro nao tem testes agendados!!");
    }

    printf("\n-----Testes agendados-----");
    printf("\n============================================");

}

void listarMembros(tipoMembro vetorMembros[], int totalMembros, tipoAgendamento *vetorAgendamentos, int totalAgendamentos){
    int i;

    if(totalMembros == 0){
        printf("Nao ha membros pra listar!");
    }
    for (i=0; i<totalMembros; i++){
        mostraMembro(vetorMembros[i]);
        mostraInfoAdicional(vetorAgendamentos, totalAgendamentos, vetorMembros[i].numeroUtente);
        printf("\n\n");

    }
}

void atualizaDose(tipoMembro vetorMembros[], int totalMembros){
    int numeroDeUtenteAProcurar, pos = 0;

    if (totalMembros > 0){
        printf("insira o numero do utente: (1 a 9999):");
        numeroDeUtenteAProcurar = lerInteiro(1, 9999);
        pos = procuraIndexMembroPorNDeUtente(vetorMembros, totalMembros, numeroDeUtenteAProcurar);

        if (pos == -1){
            printf("Nao foi encontrado nenhum utente com o numero de utente inserido. \n");
        }else{
            printf("Estado da vacina: (%d) sem vacina, (%d) dose 1,(%d) dose 2,(%d) dose 3: ", SemVacina, Dose1, Dose2, Dose3);
            vetorMembros[pos].dose = lerInteiro(SemVacina, Dose3);

            if (vetorMembros[pos].dose != SemVacina){
                printf("Data da ultima vacina: ");
                vetorMembros[pos].dataVacina = lerData();
            }
            

        }

    }else{
        printf("Nao existem membros!");
    }

}

tipoConfinamento *atualizaEstadoConfinamento(tipoMembro vetorMembros[], int totalMembros, tipoConfinamento *vetorConfinamentos, int *totalConfinamentos){
    int numeroDeUtenteAProcurar, pos = 0, tempoDeDuracaoConfinamento;
    tipoData dataConfinamento;
    tipoConfinamento novoConfinamento;


    if (totalMembros > 0){
        printf("insira o numero do utente: (1 a 9999):");
        numeroDeUtenteAProcurar = lerInteiro(1, 9999);
        pos = procuraIndexMembroPorNDeUtente(vetorMembros, totalMembros, numeroDeUtenteAProcurar);

         if (pos == -1){
            printf("Nao foi encontrado nenhum utente com o numero de utente inserido. \n");
        }else{
            printf("Estado de confinamento: (%d) nao confinado, (%d) quarentena, (%d) isolamento profilatico: ", NaoConfinado, Quarentena, Isolamento);
            vetorMembros[pos].estado = lerInteiro(NaoConfinado, Isolamento);

            if (vetorMembros[pos].estado == Isolamento || vetorMembros[pos].estado == Quarentena){
                printf("\nInsira a data de confinamento: ");
                dataConfinamento = lerData();
                
                printf("\nInsira o tempo de duracao(em dias): (1-30):");
                tempoDeDuracaoConfinamento = lerInteiro(1, 30);



                // inserir confinamento

                novoConfinamento.dataDeConfinamento = dataConfinamento;
                novoConfinamento.estado = vetorMembros[pos].estado;
                novoConfinamento.numeroUtente = numeroDeUtenteAProcurar;
                novoConfinamento.tempoDeDuracao = tempoDeDuracaoConfinamento;
                
                vetorConfinamentos =  adicionarConfinamento(vetorConfinamentos, totalConfinamentos, novoConfinamento);
                
           }
        }
    }else{
        printf("Nao existem membros.");
    }

    return vetorConfinamentos;
}


int procuraIndexMembroPorNDeUtente(tipoMembro vetorMembros[], int totalMembros, int numeroDeUtenteAProcurar){
    int i = 0, pos = -1;

    for (i=0; i<totalMembros; i++){
        if (vetorMembros[i].numeroUtente == numeroDeUtenteAProcurar){
            pos = i;
            break; // nao precisa de procurar mais pq o numero de utente e unico
        }
    }

    return pos;
}

int qtdDeMembrosVacinados(tipoMembro vetorMembros[], int totalMembros){
   int i = 0, cnt = 0;

    for (i=0; i<totalMembros; i++){
        if (vetorMembros[i].dose != SemVacina){
            cnt++;
        }
    }

    return cnt;

}
