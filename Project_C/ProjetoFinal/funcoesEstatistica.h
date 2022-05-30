#ifndef FUNCOESESTATISTICA_H_INCLUDED
#define FUNCOESESTATISTICA_H_INCLUDED


void quantidadeDeCadaTipo(tipoMembro membros[], int totalDeMembros);
void tempoMedioDeCadaTesteRealizado(tipoAgendamento *vetorAgendamentos, int totalDeAgendamentos);
void membrosMenorQuantidadeTestesRealizados(tipoMembro *vetorMembros, int totalMembros, tipoAgendamento *vetorAgendamentos, int totalAgendamentos);
void membrosTestesRealizadosMaisRecentes(tipoAgendamento *vetorAgendamentos, int totalAgendamentos);
void percentagemInconclusivos(tipoAgendamento *vetorAgendamentos, int totalAgendamentos);

#endif // FUNCOESESTATISTICA_H_INCLUDED
