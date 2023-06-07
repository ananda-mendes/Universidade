// TAD ALIMENTO

#ifndef ALIMENTO_H
#define ALIMENTO_H


typedef struct alimento Alimento;

// Funções principais

Alimento* criaAlimento(char descricao[100], char validade[10], char localizacao[50], char dono[50]);
void apagaAlimento(Alimento *a);
Alimento* atualizaAlimento(Alimento *a, char descricao[100], char validade[10], char localizacao[50], char dono[50]);
void lerAlimento(Alimento *a);

//Get e Set

char* getDescricaoAlimento(Alimento *a);
char* getValidadeAlimento(Alimento *a);
char* getLocalizacaoAlimento(Alimento *a);
char* getDonoAlimento (Alimento *a);

void setDescricaoAlimento(Alimento *a, char descricao[100]);
void setValidadeAlimento(Alimento *a, char validade[10]);
void setLocalizacaoAlimento(Alimento *a, char localizacao[50]);
void setDonoAlimento (Alimento *a, char dono[50]);

#endif
