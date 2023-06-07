// TAD MORADOR

#ifndef MORADOR_H
#define MORADOR_H

#include "tarefa.h"
#include "alimento.h"

typedef struct morador Morador;

// funcoes principais
Morador* criaMorador (char nome[50], int idade, char curso[50], char apelido[50], int periodo, char status[20], char republica[50]);
void apagaMorador (Morador *m);
void lerMorador (Morador *m);
Morador* atualizaMorador (Morador *m, char nome[50], int idade, char curso[50], char apelido[50], int perido, char status[20], char republica[50]);

//get e set
char* getNomeMorador (Morador *m);
int getIdadeMorador(Morador *m);
char* getCursoMorador(Morador *m);
char* getApelidoMorador(Morador *m);
int getPeriodoMorador (Morador *m);
char* getStatusMorador(Morador *m);
Alimento** getAlimentosMorador(Morador *m);
Tarefa** getTarefasMorador(Morador *m); 
int getQntAlimentosMorador(Morador *m);
int getQntTarefasMorador(Morador *m);
char* getRepublicaMorador(Morador *m);

void setNomeMorador (Morador *m, char nome[50]);
void setIdadeMorador(Morador *m, int idade);
void setCursoMorador(Morador *m, char curso[50]);
void setApelidoMorador(Morador *m, char apelido[50]);
void setPeriodoMorador (Morador *m, int periodo);
void setStatusMorador(Morador *m, char status[20]);
void setAlimentosMorador(Morador *m, Alimento** a);
void setTarefasMorador(Morador *m, Tarefa** t); 
void setQntAlimentosMorador(Morador *m, int qntAlimentos);
void setQntTarefasMorador(Morador *m, int qntTarefas);
void setRepublicaMorador(Morador *m, char republica[50]);

#endif
