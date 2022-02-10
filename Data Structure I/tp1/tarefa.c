#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefa.h"

struct tarefa {
	char descricao[50];
	int prazo;
	char pessoa[50];
};

Tarefa *criaTarefa (char descricao[50], int prazo, char pessoa[50]) {
	Tarefa *t = malloc(sizeof(Tarefa));
	strcpy (t->descricao, descricao);
	t->prazo = prazo;
	strcpy (t->pessoa, pessoa);
	return t;
}

void apagaTarefa (Tarefa *t){
	free(t);
}

void lerTarefa (Tarefa *t) {
	printf("\n\nTAREFA\n");
	printf ("Descrição: %s", getDescricaoTarefa(t));
	printf ("\nPrazo: %d", getPrazoTarefa(t));
	printf ("\nPessoa: %s", getPessoaTarefa (t));
}

Tarefa *atualizaTarefa (Tarefa *t, char descricao[50], int prazo, char pessoa[50]) {
	setDescricaoTarefa (t, descricao);
	setPrazoTarefa (t, prazo);
	setPessoaTarefa (t, pessoa);
	return t;
}

char* getDescricaoTarefa (Tarefa *t) {
	return t->descricao;
}

int getPrazoTarefa (Tarefa *t) {
	return t->prazo;
}

char* getPessoaTarefa (Tarefa *t) {
	return t->pessoa;
}

void setDescricaoTarefa (Tarefa *t, char descricao[50]) {
	strcpy (t->descricao, descricao);
}

void setPrazoTarefa (Tarefa *t, int prazo) {
	t->prazo = prazo;
}

void setPessoaTarefa (Tarefa *t, char pessoa[50]) {
	strcpy (t->pessoa, pessoa);
}

