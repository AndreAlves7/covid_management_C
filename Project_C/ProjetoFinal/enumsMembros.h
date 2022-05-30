#ifndef ENUMSMEMBROS_H_INCLUDED
#define ENUMSMEMBROS_H_INCLUDED


enum tipoDeMembro {
    Estudante = 1,
    Docente = 2,
    Tecnico = 3
};

enum estadoConfinamento {
    NaoConfinado = 1,
    Quarentena = 2,
    Isolamento = 3
};
enum doseVacina {
    SemVacina = 0,
    Dose1 = 1,
    Dose2 = 2,
    Dose3 = 3
};


const char* converteTipoDeMembroParaString(int enumerator);
const char* converteDoseVacinaParaString(int enumerator);
const char* converteEstadoConfinamentoParaString(int enumerator);

#endif // ENUMSMEMBROS_H_INCLUDED
