#include "tBiopsia.h"

struct biopsia {
    char nomePaciente[100];
    char nomeMedico[100];
    char CRM[20];
    char data[11];  // Data no formato dd/mm/aaaa
    tLesoes *lesoes;            // Outros campos conforme necessário
};