#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "funcoesLeitura.h"
#include "funcoesMembros.h"
#include "funcoesAgendamento.h"
#include "funcoesEstatistica.h"
#include "funcoesConfinamentos.h"
#include "funcoesAuxiliares.h"


char menuPrincipal(int totalMembros, int totalAgendamentos, int totalTestesRealizados, int totalDeVacinados);
char menuMembros(int totalMembros);
char menuAgendamentos(int totalAgendamentos);
char menuEstatisticas();
char menuConfinamentos(int totalConfinamentos);

int main(void)
{
    char opcaoMenuPrincipal, opcaoSubmenuMembros, opcaoSubmenuAgendamentos, opcaoSubmenuEstatisticas, opcaoSubmenuConfinamentos;


    tipoMembro vetorMembros[MAX_MEMBROS];
    tipoAgendamento *vetorAgendamentos;
    tipoConfinamento *vetorConfinamentos;
    int totalMembros;
    int totalAgendamentos;
    int totalTestesRealizados;
    int totalConfinamentos;
    int totalDeVacinados;

    // inicializa contadores
    totalMembros = 0;
    totalAgendamentos = 0;
    totalTestesRealizados = 0;
    totalConfinamentos = 0;
    totalDeVacinados = 0;

    // vetor dinamico
    vetorAgendamentos = NULL;
    vetorConfinamentos = NULL;


    do
    {
        totalDeVacinados = qtdDeMembrosVacinados(vetorMembros, totalMembros); //cuidado! apenas e atualizado no menu principal
        opcaoMenuPrincipal = menuPrincipal(totalMembros, totalAgendamentos, totalTestesRealizados, totalDeVacinados);

        switch (opcaoMenuPrincipal)
        {
        case '1': 
            do{
                opcaoSubmenuMembros = menuMembros(totalMembros);

                switch (opcaoSubmenuMembros)
                {
                case '1':
                    totalMembros = adicionarMembro(vetorMembros, totalMembros);
                    break;
                case '2':
                    listarMembros(vetorMembros, totalMembros, vetorAgendamentos, totalAgendamentos);
                    break;
                case '3':
                    atualizaDose(vetorMembros, totalMembros);
                    break;
                case '4':
                    vetorConfinamentos = atualizaEstadoConfinamento(vetorMembros, totalMembros, vetorConfinamentos, &totalConfinamentos);
                    break;
                default:
                    break;
                }
            }while(opcaoSubmenuMembros != 'S');
            break;

        case '2':
            do{
                opcaoSubmenuAgendamentos = menuAgendamentos(totalAgendamentos);

                switch (opcaoSubmenuAgendamentos)
                {
                 case '1':
                    vetorAgendamentos = adicionaAgendamento(vetorAgendamentos, &totalAgendamentos, vetorMembros, totalMembros);
                    break;
                case '2':
                    listaAgendamentos(vetorAgendamentos, totalAgendamentos);
                    break;
                case '3':
                    alterarDataAgendada(vetorAgendamentos, totalAgendamentos);
                    break;
                case '4':
                    totalTestesRealizados = registaResultado(vetorAgendamentos, &totalAgendamentos, totalTestesRealizados, vetorMembros , totalMembros, &vetorConfinamentos, &totalConfinamentos);
                    break;
                case '5':
                    listarTestesRealizados(vetorAgendamentos, totalAgendamentos);
                    break;
                case '6':
                    informacaoDeUmTeste(vetorAgendamentos, totalAgendamentos, vetorMembros, totalMembros);
                    break;   
                case '7':
                    membrosTestesRealizadosMaisRecentes(vetorAgendamentos, totalAgendamentos);
                    break;    
                }
            }while (opcaoSubmenuAgendamentos != 'S');
            break;    
        case '3':
            do{
                opcaoSubmenuEstatisticas = menuEstatisticas();

                switch (opcaoSubmenuEstatisticas)
                {
                case '1':
                    quantidadeDeCadaTipo(vetorMembros, totalMembros);
                    break;
                case '2':
                    tempoMedioDeCadaTesteRealizado(vetorAgendamentos, totalAgendamentos);    
                    break;
                case '3':
                    membrosMenorQuantidadeTestesRealizados(vetorMembros, totalMembros, vetorAgendamentos, totalAgendamentos);
                    break;    
                case '4':
                    membrosTestesRealizadosMaisRecentes(vetorAgendamentos, totalAgendamentos);
                    break;
                case '5':
                    percentagemInconclusivos(vetorAgendamentos, totalAgendamentos);
                    break;
                

                
                }
                
            }while(opcaoSubmenuEstatisticas != 'S');

            break;

        case '4':
            do{
                opcaoSubmenuConfinamentos = menuConfinamentos(totalConfinamentos);

                switch (opcaoSubmenuConfinamentos)
                {
                case '1':
                    listarConfinamentos(vetorConfinamentos, totalConfinamentos);
                    break;
                }

            }while(opcaoSubmenuConfinamentos != 'S');
            break; 

        case '5':
            escreveFichBin(vetorMembros, totalMembros, vetorAgendamentos, totalAgendamentos, vetorConfinamentos, totalConfinamentos);
            break;   
        case '6':
            vetorAgendamentos = leFicheiroBin(vetorMembros, &totalMembros, vetorAgendamentos, &totalAgendamentos);
            vetorConfinamentos = leFicheiroConfinamento(vetorConfinamentos, &totalConfinamentos);
            break;
        }

    }while(opcaoMenuPrincipal != 'S');

    free(vetorAgendamentos);
    free(vetorConfinamentos);

    return 0;

}



char menuPrincipal(int totalMembros, int totalAgendamentos, int totalTestesRealizados, int totalDeVacinados){
    char op;
    int agendamentosSemResulado;

    agendamentosSemResulado = totalAgendamentos - totalTestesRealizados;

    printf("\n\n\n********* Menu Principal ********* \n");
    printf("total de membros: %d \t total de agendamentos: %d\n", totalMembros, agendamentosSemResulado);
    printf("total de testes realizados: %d \t total de vacinados: %d\n", totalTestesRealizados, totalDeVacinados);
    printf("\n 1 - Membros");
    printf("\n 2 - Agendamentos");
    printf("\n 3 - Estatistica");
    printf("\n 4 - Confinamentos");
    printf("\n 5 - Gravar dados em ficheiro");
    printf("\n 6 - Ler dados de ficheiro");
    printf("\n S - Sair");
    printf("\n \t\t Opcao (1, 2, 3, 4, 5, 6, S ) --> ");

    op = getchar();
    op = toupper(op);
    limpaBufferStdin();

    return op; 	/* Devolve opcao selecionada pelo utilizador */
}

char menuMembros(int totalMembros){
    char op;


    printf("\n\n\n********* Menu Membros ********* \n");
    printf("\n 1 - Acrescenta Membro");
    printf("\n 2 - Lista Membros");
    printf("\n 3 - Atualiza estado de vacinacao");
    printf("\n 4 - Atualiza estado de confinamento");
    printf("\n S - Sair");
    printf("\n \t\t Opcao (1, 2, 3, 3, 4, S ) --> ");

    op = getchar();
    op = toupper(op);
    limpaBufferStdin();

    return op; 	/* Devolve opcao selecionada pelo utilizador */
}

char menuAgendamentos(int totalAgendamentos){
    char op;


    printf("\n\n\n********* Menu Agendamentos ********* \n");
    printf("\n 1 - Adicionar Agendamento");
    printf("\n 2 - Listar Agendamentos");
    printf("\n 3 - Alterar data de agendamento");
    printf("\n 4 - Registar resultado");
    printf("\n 5 - Listar testes realizados");
    printf("\n 6 - informacao de um teste");
    printf("\n S - Sair");
    printf("\n \t\t Opcao (1, 2, 3, 3, 4, 5, 6, S ) --> ");

    op = getchar();
    op = toupper(op);
    limpaBufferStdin();

    return op; 	/* Devolve opcao selecionada pelo utilizador */
}

char menuEstatisticas(){
    char op;

    printf("\n\n\n********* Menu Estatisticas ********* \n");
    printf("\n 1 - Qtd. de cada tipo de membro");
    printf("\n 2 - Tempo medio de duracao de cada teste");
    printf("\n 3 - Membro(s) com a Menor quantidade de testes realizados");
    printf("\n 4 - Teste mais recente realizado");
    printf("\n 5 - Percentagem testes inconclusivos");
    printf("\n S - Sair");
    printf("\n \t\t Opcao (1, 2, 3, 3, 4, S ) --> ");

    op = getchar();
    op = toupper(op);
    limpaBufferStdin();

    return op; 	/* Devolve opcao selecionada pelo utilizador */
}

char menuConfinamentos(int totalConfinamentos){
    char op;

    printf("\n\n\n********* Menu Confinamentos ********* \n");
    printf("total de confinamentos: %d \t ", totalConfinamentos);
    printf("\n 1 - Listar Confinamentos");
    printf("\n S - Sair");
    printf("\n \t\t Opcao (1, S ) --> ");

    op = getchar();
    op = toupper(op);
    limpaBufferStdin();

    return op; 	/* Devolve opcao selecionada pelo utilizador */
}
