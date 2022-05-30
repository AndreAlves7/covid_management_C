#ifndef FUNCOESCONFINAMENTOS_H_INCLUDED
#define FUNCOESCONFINAMENTOS_H_INCLUDED

#include "funcoesLeitura.h"
#include "funcoesMembros.h"
#include "funcoesConfinamentos.h"
#include "enumsMembros.h"


#include "funcoesConfinamentos.h"
#include "funcoesAgendamento.h"




tipoConfinamento *adicionarConfinamento(tipoConfinamento *vetorConfinamentos, int *totalConfinamentos, tipoConfinamento confinamento);
void listarConfinamentos(tipoConfinamento *vetorConfinamentos, int totalConfinamentos);


#endif // FUNCOESCONFINAMENTOS_H_INCLUDED
