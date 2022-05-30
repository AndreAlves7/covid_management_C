#ifndef TIPOMEMBRO_H_INCLUDED
#define TIPOMEMBRO_H_INCLUDED

#include "funcoesLeitura.h"
#include "enumsMembros.h"

typedef struct
{
    int numeroUtente;
    char nome[50];
    tipoData dataNascimento;
    enum tipoDeMembro membro;
    enum doseVacina dose;
    enum estadoConfinamento estado;
    tipoData dataVacina;
} tipoMembro;

#endif // TIPOMEMBRO_H_INCLUDED
