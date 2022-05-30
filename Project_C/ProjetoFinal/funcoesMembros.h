#ifndef FUNCOESMEMBROS_H_INCLUDED
#define FUNCOESMEMBROS_H_INCLUDED

#include "funcoesLeitura.h"
#include "tipoMembro.h"
#include "tipoConfinamento.h"
#include "enumsMembros.h"
#include "funcoesConfinamentos.h"
#include "funcoesAgendamento.h"


#define MAX_MEMBROS 200



int adicionarMembro(tipoMembro vetorMembros[], int totalMembros);
tipoMembro lerDadosMembro(void);
void listarMembros(tipoMembro vetorMembros[], int totalMembros, tipoAgendamento *vetorAgendamentos, int totalAgendamentos);
void atualizaDose(tipoMembro vetorMembros[], int totalMembros);
int procuraIndexMembroPorNDeUtente(tipoMembro vetorMembros[], int totalMembros, int numeroDeUtenteAProcurar);
tipoConfinamento *atualizaEstadoConfinamento(tipoMembro vetorMembros[], int totalMembros, tipoConfinamento *vetorConfinamentos, int *totalConfinamentos);
int qtdDeMembrosVacinados(tipoMembro vetorMembros[], int totalMembros);
void mostraMembro(tipoMembro membro);
void mostraInfoAdicional(tipoAgendamento *vetorAgendamentos, int totalAgendamentos, int numeroUtente);


#endif // FUNCOESMEMBROS_H_INCLUDED
