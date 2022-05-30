#ifndef FUNCOESAUXILIARES_H_INCLUDED
#define FUNCOESAUXILIARES_H_INCLUDED


#include "funcoesLeitura.h"

int comparaDatas(tipoData data1, tipoData data2);
void escreveFichBin(tipoMembro *vetorMembros, int totalMembros, tipoAgendamento *vetorAgendamentos, int totalAgendamentos, tipoConfinamento *vetorConfinamentos, int totalConfinamentos);
tipoAgendamento *leFicheiroBin(tipoMembro *vetorMembros,int *totalMembros, tipoAgendamento *vetorAgendamentos, int *totalAgendamentos);
tipoConfinamento *leFicheiroConfinamento(tipoConfinamento *vetorConfinamentos, int *totalConfinamentos);
int menorValor(int a, int b);
void Logteste(tipoAgendamento agendamento, tipoMembro membro);


#endif // FUNCOESAUXILIARES_H_INCLUDED
