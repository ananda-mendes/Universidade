// TAD REPUBLICA

//Struct: Nome, Endereço, Telefone, Comodos, Moradores, Tarefas, Alimentos, NumMoradores


#ifndef REPUBLICA_H
#define REPUBLICA_H

#include "tarefa.h"
#include "morador.h"
#include "alimento.h"

typedef struct republica Republica;

// Funções Principais
Republica* criaRepublica (char nome[50], char endereco[100], int telefone, int qntComodos);
Republica* atualizaRepublica (Republica *r, char nome[50], char endereco[100], int telefone, int qntComodos);
void apagaRepublica (Republica *r);
void lerRepublica (Republica *r);

// Get e Set
char* getNomeRepublica (Republica *r);
char* getEnderecoRepublica (Republica *r);
int getTelefoneRepublica (Republica *r);
int getQntComodosRepublica (Republica *r);
int getQntMoradoresRepublica (Republica *r);
Morador** getMoradoresRepublica (Republica *r);
Morador* getMoradorRepublica(Republica *r, int pos);

void setNomeRepublica (Republica *r, char nome[50]);
void setEnderecoRepublica (Republica *r, char endereco[100]);
void setTelefoneRepublica (Republica *r, int telefone);
void setQntComodosRepublica (Republica *r, int qntComodos);
void setQntMoradoresRepublica (Republica *r, int qntMoradores);
void setMoradoresRepublica (Republica *r, Morador** moradores);

#endif
