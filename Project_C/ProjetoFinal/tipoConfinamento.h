#ifndef TIPOCONFINAMENTO_H_INCLUDED
#define TIPOCONFINAMENTO_H_INCLUDED

#include "funcoesLeitura.h"
#include "enumsMembros.h"

typedef struct
{
    int numeroUtente;
    tipoData dataDeConfinamento;
    int tempoDeDuracao; //dias
    enum estadoConfinamento estado;
} tipoConfinamento;

#endif // TIPOCONFINAMENTO_H_INCLUDED
