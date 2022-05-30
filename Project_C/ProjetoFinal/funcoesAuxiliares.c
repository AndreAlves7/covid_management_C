#include <stdio.h>
#include <stdlib.h>


#include "funcoesLeitura.h"
#include "tipoMembro.h"
#include "tipoConfinamento.h"
#include "tipoAgendamento.h"

/*
    0 -> as datas sao iguais
    1 -> a data1 e superior a data2
    -1 -> a data2 e superior a data1

    exemplos de utilizacao

        tipoData data1;
        tipoData data2;

        data1= (tipoData) {1,2,2022};
        data2= (tipoData) {1,2,2021};

        printf("maior data->%d", comparaDatas(data1, data2));

        --> maior data->1
*/

int comparaDatas(tipoData data1, tipoData data2){

    int maior = -1;

    if (data1.ano > data2.ano){
        maior = 1;
    }else{
        if (data1.ano < data2.ano){
            maior = -1;
        }else{ //anos iguais
            if (data1.mes > data2.mes){
                maior = 1;
            }else{
               if (data1.mes < data2.mes){
                maior = -1;
               }else{ //mes igual
                    if (data1.dia > data2.dia){
                        maior = 1;
                    }else{
                        if (data1.dia < data2.dia){
                            maior = -1;
                        }else{ //ano, mes e dias iguais
                            maior = 0;
                        }
                    }
               }
            }
        }
    }

    return maior;

}



void escreveFichBin(tipoMembro *vetorMembros, int totalMembros, tipoAgendamento *vetorAgendamentos, int totalAgendamentos, tipoConfinamento *vetorConfinamentos, int totalConfinamentos){
    FILE *fichMembros, *fichAgendamentos, *fichConfinamentos;
    fichMembros = fopen("membros.dat", "wb");
    fichAgendamentos = fopen("agendamentos.dat", "wb");
    fichConfinamentos = fopen("confinamentos.dat", "wb");
    
    //ocorreu um erro a abrir todos os ficheiros
    if (fichMembros == NULL || fichAgendamentos==NULL || fichConfinamentos== NULL) {
        printf("Impossivel abrir ficheiro");
    }
    else{
        //guarda membros
        fwrite(&totalMembros, sizeof(int), 1, fichMembros);
        fwrite(vetorMembros, sizeof(tipoMembro), totalMembros, fichMembros);
        fclose(fichMembros);

        //guarda Agendamentos
        fwrite(&totalAgendamentos, sizeof(int), 1, fichAgendamentos);
        fwrite(vetorAgendamentos, sizeof(tipoAgendamento), totalAgendamentos, fichAgendamentos);
        fclose(fichAgendamentos);

        //guarda Confinamentos
        fwrite(&totalConfinamentos, sizeof(int), 1, fichConfinamentos);
        fwrite(vetorConfinamentos, sizeof(tipoConfinamento), totalConfinamentos, fichConfinamentos);
        fclose(fichConfinamentos);
    }
} 


tipoAgendamento *leFicheiroBin(tipoMembro *vetorMembros,int *totalMembros, tipoAgendamento *vetorAgendamentos, int *totalAgendamentos)
{

    FILE *fichMembros, *fichAgendamentos;

    fichMembros = fopen("membros.dat", "rb");
    fichAgendamentos = fopen("agendamentos.dat", "rb");
    if (fichMembros == NULL || fichAgendamentos == NULL)
    {
        printf ("Erro ao abrir ficheiro");
        *totalMembros = 0;
        *totalAgendamentos=0;
    }
    else
    {
        fread(&(*totalMembros), sizeof(int), 1, fichMembros);
        fread(vetorMembros,sizeof(tipoMembro), *totalMembros, fichMembros);
        
        
        fread(&(*totalAgendamentos), sizeof(int), 1, fichAgendamentos);

        vetorAgendamentos= realloc(vetorAgendamentos,(*totalAgendamentos)*sizeof(tipoAgendamento));
        if (vetorAgendamentos==NULL && *totalAgendamentos!=0)
        {
            printf ("Erro - Impossivel criar vetor dinamico");
            *totalMembros = 0;
            *totalAgendamentos=0;
        }
        else  		 /* Obtem dados do agendamento e armazena no vetor */
        {
            fread(vetorAgendamentos, sizeof(tipoAgendamento), *totalAgendamentos, fichAgendamentos);
        }
        fclose(fichMembros);
        fclose(fichAgendamentos);
    }
    return vetorAgendamentos;
}

tipoConfinamento *leFicheiroConfinamento(tipoConfinamento *vetorConfinamentos, int *totalConfinamentos){
    FILE *fichConfinamento;

    fichConfinamento = fopen("confinamentos.dat", "rb");

    if (fichConfinamento == NULL)
    {
        printf ("Erro ao abrir ficheiro");
        *totalConfinamentos=0;
    }
    else
    {        
        
        fread(&(*totalConfinamentos), sizeof(int), 1, fichConfinamento);

        vetorConfinamentos= realloc(vetorConfinamentos,(*totalConfinamentos)*sizeof(tipoConfinamento));
        if (vetorConfinamentos==NULL && *totalConfinamentos!=0)
        {
            printf ("Erro - Impossivel criar vetor dinamico");
            *totalConfinamentos=0;
        }
        else  		 /* Obtem dados do agendamento e armazena no vetor */
        {
            fread(vetorConfinamentos, sizeof(tipoConfinamento), *totalConfinamentos, fichConfinamento);
        }
        fclose(fichConfinamento);
    }
    return vetorConfinamentos;

}


int menorValor(int a, int b){
    int menor;
    if (a < b){
        menor = a;
    }else{
        menor = b;
    }

    return menor;
}

void Logteste(tipoAgendamento agendamento, tipoMembro membro)
{
    FILE *ficheiro;

    ficheiro = fopen("log.txt", "a");
    if (ficheiro == NULL)
    {
        printf ("Erro ao abrir ficheiro");
    }
    else
    {
        fprintf(ficheiro, "\n Nome Utilizador: %s", membro.nome);
        fprintf(ficheiro, "\n Tipo Membro: %s", converteTipoDeMembroParaString(membro.membro));
        fprintf(ficheiro, "\n Estado Vacinacao: %s", converteEstadoConfinamentoParaString(membro.estado));


        fprintf(ficheiro, "\nDesignacao: %d", agendamento.designacao);
        fprintf(ficheiro, "\nNumero Utente: %d", agendamento.numUtente);
        fprintf(ficheiro, "\ntipo de teste: %d", agendamento.teste);
        fprintf(ficheiro, "\nData realizacao: %02d/%02d/%4d\n", agendamento.dataRealizacao.dia, agendamento.dataRealizacao.mes, agendamento.dataRealizacao.ano);


        fprintf(ficheiro, "Tempo de duracao: %d\n", agendamento.tempoDeDuracao);
        fprintf(ficheiro, "Hora da colheita (minutos): %d\n", agendamento.horaColheita);
        switch (agendamento.resultado)
        {
            case Positivo:
                fprintf(ficheiro, "resultado: Positivo\n");
                break;
            case Negativo:
                fprintf(ficheiro, "resultado: Positivo\n");
                break;
            case Inconclusivo:
                fprintf(ficheiro, "resultado: Inconclusivo\n");
                break;        
            }

        fprintf(ficheiro,"-------------------------------");
   
        fclose(ficheiro);
    }
}
