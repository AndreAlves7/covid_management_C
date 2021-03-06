#ifndef FUNCOESLEITURA_H_INCLUDED
#define FUNCOESLEITURA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int ano;
} tipoData;

/* Funcoes para leitura de dados */

void limpaBufferStdin(void);
int lerInteiro(int min, int max);
void lerString(char vetor[], int max);
tipoData lerData(void);


#endif // FUNCOESLEITURA_H_INCLUDED
