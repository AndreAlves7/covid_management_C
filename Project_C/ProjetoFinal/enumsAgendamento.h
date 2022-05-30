#ifndef ENUMSAGENDAMENTO_H_INCLUDED
#define ENUMSAGENDAMENTO_H_INCLUDED

enum tipoDeTeste {
    PCR = 1,
    Antigenio = 2
};

enum tipoDeResultado {
    Positivo = 1,
    Negativo = 2,
    Inconclusivo = 3
};

enum testeJaRealizado {
    Sim = 1,
    Nao = 2
};


const char* converteTipoDetesteParaString(int enumerator);
const char* converteTipoDeResultadoParaString(int enumerator);
const char* converteTesteJaRealizadoParaString(int enumerator);



#endif // ENUMSAGENDAMENTO_H_INCLUDED
