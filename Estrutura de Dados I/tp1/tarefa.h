// TAD TAREFA

#ifndef TAREFA_H
#define TAREFA_H

typedef struct tarefa Tarefa;

// funcoes principais
Tarefa* criaTarefa (char descricao[50], int prazo, char pessoa[50]);
void apagaTarefa (Tarefa *t);
void lerTarefa (Tarefa *t);
Tarefa *atualizaTarefa (Tarefa *t, char descricao[50], int prazo, char pessoa[50]);

// get e set
char* getDescricaoTarefa (Tarefa *t);
int getPrazoTarefa(Tarefa *t);
char* getPessoaTarefa (Tarefa *t);

void setDescricaoTarefa(Tarefa *t, char descricao[50]);
void setPrazoTarefa(Tarefa *t, int prazo);
void setPessoaTarefa (Tarefa *t, char pessoa[50]);

#endif
