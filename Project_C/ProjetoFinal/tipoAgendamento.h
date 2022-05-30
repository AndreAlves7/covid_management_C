#ifndef TIPOAGENDAMENTO_H_INCLUDED
#define TIPOAGENDAMENTO_H_INCLUDED

#include "funcoesLeitura.h"
#include "enumsAgendamento.h"

typedef struct
{
    int designacao;
    int numUtente;
    enum tipoDeTeste teste;
    tipoData dataRealizacao;
    enum testeJaRealizado jaRealizado;

    // estes campos apenas sao preenchidos quando o teste for realizado
    int tempoDeDuracao;  /*Minutos*/
    int horaColheita;
    enum tipoDeResultado resultado;
} tipoAgendamento;

#endif // TIPOAGENDAMENTO_H_INCLUDED
