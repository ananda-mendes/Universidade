#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alimento.h"

struct alimento{
	char descricao[100];
	char validade[10];
	char localizacao[50];
	char dono[50];
};

Alimento* criaAlimento(char descricao[100], char validade[10], char localizacao[50], char dono[50]){
	Alimento *a = malloc(sizeof(Alimento));
	strcpy (a->descricao, descricao);
	strcpy (a->validade, validade);
	strcpy (a->localizacao, localizacao);
	strcpy (a->dono, dono);
	return a;
}

void apagaAlimento(Alimento *a){
	free(a);
}

Alimento* atualizaAlimento(Alimento *a, char descricao[100], char validade[10], char localizacao[50], char dono[50]){
	setDescricaoAlimento(a, descricao);
	setValidadeAlimento(a, validade);
	setLocalizacaoAlimento(a, localizacao);
	setDonoAlimento (a, dono);
	return a;
}

void lerAlimento(Alimento *a){
	printf("\n\nALIMENTO\n");
	printf("Descrição: %s", getDescricaoAlimento(a));
	printf("\nValidade: %s", getValidadeAlimento(a));
	printf("\nLocalização: %s", getLocalizacaoAlimento(a));
	printf ("\nDono: %s", getDonoAlimento (a));
}

char* getDescricaoAlimento(Alimento *a){
	return a->descricao;
}

char* getValidadeAlimento(Alimento *a){
	return a->validade;
}

char* getLocalizacaoAlimento(Alimento *a){
	return a->localizacao;
}
char* getDonoAlimento (Alimento *a) {
	return a->dono;
}

void setDescricaoAlimento(Alimento *a, char descricao[100]){
	strcpy (a->descricao, descricao);
}

void setValidadeAlimento(Alimento *a, char validade[10]){
	strcpy (a->validade, validade);
}

void setLocalizacaoAlimento(Alimento *a, char localizacao[50]){
	strcpy (a->localizacao, localizacao);
}

void setDonoAlimento (Alimento *a, char dono[50]) {
	strcpy (a->dono, dono);
}
