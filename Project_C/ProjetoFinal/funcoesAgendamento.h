#ifndef FUNCOESAGENDAMENTO_H_INCLUDED
#define FUNCOESAGENDAMENTO_H_INCLUDED

#include "funcoesLeitura.h"
#include "tipoAgendamento.h"
#include "tipoMembro.h"
#include "enumsAgendamento.h"
#include "funcoesMembros.h"

#define LIMITE_MAXIMO_PCR 15





tipoAgendamento *adicionaAgendamento(tipoAgendamento *vetorAgendamentos, int *totalAgendamentos, tipoMembro vetorMembros[], int totalMembros);
tipoAgendamento lerDadosAgendamento(void);
void listaAgendamentos (tipoAgendamento *vetorAgendamentos, int totalAgendamentos);
void alterarDataAgendada(tipoAgendamento *vetorAgendamentos, int totalAgendamentos);
int procuraIndexAgendamentoPorDesignacaoUnica(tipoAgendamento *vetorAgendamentos, int totalAgendamentos, int designacaoUnica);
int registaResultado(tipoAgendamento *vetorAgendamentos, int *totalAgendamentos , int totalTestesRealizados, tipoMembro *vetorMembros, int totalMembros, tipoConfinamento **vetorConfinamento, int *totalConfinamento);
int verificaLimiteAgendamento(tipoAgendamento dados, tipoAgendamento *vetorAgendamentos, int totalAgendamentos);
void listarTestesRealizados(tipoAgendamento *vetorAgendamentos, int totalAgendamentos);
void mostraAgendamento(tipoAgendamento agendamento);
int qtdDeTestesRealizadosPorMembro(tipoAgendamento *vetorAgendamentos, int totalAgendamentos, int numeroUtente);
void informacaoDeUmTeste(tipoAgendamento *vetorAgendamentos, int totalAgendamentos, tipoMembro *vetorMembros, int totalMembros);
tipoAgendamento *adicionaAgendamentoDiretamente(tipoAgendamento *vetorAgendamentos, int *totalAgendamentos, tipoAgendamento novoAgendamento);

#endif // FUNCOESAGENDAMENTO_H_INCLUDED


