#include <stdio.h>

#include "enumsAgendamento.h"


// enum tipoDeTeste {
//     PCR = 1,
//     Antigenio = 2
// };

// enum tipoDeResultado {
//     Positivo = 1,
//     Negativo = 2,
//     Inconclusivo = 3
// };

// enum testeJaRealizado {
//     Sim = 1,
//     Nao = 2
// };

const char* converteTipoDetesteParaString(int enumerator){
    const char* string;

    switch (enumerator)
    {
    case PCR:
        string = "PCR";
        break;
    case Antigenio:
        string = "antigenio";
        break;  
    }

    return string;

}


const char* converteTipoDeResultadoParaString(int enumerator){

 const char* string;

    switch (enumerator)
    {
    case Positivo:
        string = "positivo";
        break;    
    
    case Negativo:
        string = "negativo";
        break;    
    
    case Inconclusivo:
        string = "inconclusivo";
        break;    
    }

    return string;

}

const char* converteTesteJaRealizadoParaString(int enumerator){
    const char* string;

    switch (enumerator)
    {
    
    case Sim:
        string = "Sim";
        break;    
    
    case Nao:
        string = "Nao";
        break;    
    }

    return string;

}
