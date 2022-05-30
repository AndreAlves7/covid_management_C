#include <stdio.h>

#include "enumsMembros.h"


// enum tipoDeMembro {
//     Estudante = 1,
//     Docente = 2,
//     Tecnico = 3
// };

// enum estadoConfinamento {
//     NaoConfinado = 1,
//     Quarentena = 2,
//     Isolamento = 3
// };
// enum doseVacina {
//     SemVacina = 0,
//     Dose1 = 1,
//     Dose2 = 2,
//     Dose3 = 3
// };

const char* converteTipoDeMembroParaString(int enumerator){
    const char* string;

    switch (enumerator)
    {
    case Estudante:
        string = "estudante";
        break;
    case Docente:
        string = "docente";
        break;
    case Tecnico:
        string = "tecnico";
        break;      
    }

    return string;

}


const char* converteEstadoConfinamentoParaString(int enumerator){

 const char* string;

    switch (enumerator)
    {

        break;    
    case NaoConfinado:
        string = "nao confinado";
        break;    
    
    case Quarentena:
        string = "quarentena";
        break;    
    
    case Isolamento:
        string = "isolamento";
        break;    
    }

    return string;

}

const char* converteDoseVacinaParaString(int enumerator){
    const char* string;

    switch (enumerator)
    {
    
    case SemVacina:
        string = "sem vacina";
        break;    
    
    case Dose1:
        string = "dose 1";
        break;    
    
    case Dose2:
        string = "dose 2";
        break;    
    
    case Dose3:
        string = "dose 3";
        break;    
    }

    return string;

}
