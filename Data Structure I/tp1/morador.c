#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morador.h"
#include "tarefa.h"
#include "alimento.h"

struct morador {
	char nome[50];
	int idade;
	char curso[50];
	char apelido[50];
	int periodo;
	char status[20];
	Alimento **alimentos;
	Tarefa **tarefas;
	int qntAlimentos;
	int qntTarefas;
	char republica[50];
};

Morador * criaMorador (char nome[50], int idade, char curso[50], char apelido[50], int periodo, char status[20], char republica[50]) {
	Morador *m = malloc(sizeof(Morador));
	strcpy(m->nome, nome);
	m->idade = idade;
	strcpy(m->curso, curso);
	strcpy(m->apelido, apelido);
	m->periodo = periodo;
	strcpy(m->status, status);
	strcpy(m->republica, republica);
	return m;
}

void apagaMorador (Morador *m) {
	for(int i = 0; i < m->qntTarefas; i++){
		if(strcmp(getPessoaTarefa(m->tarefas[i]), getNomeMorador(m)) == 0){
			free(m->alimentos[i]);
		}
	}
	for(int i = 0; i < m->qntAlimentos; i++){
		if(strcmp(getDonoAlimento(m->alimentos[i]), getNomeMorador(m)) == 0){
			free(m->tarefas[i]);
		}
	}
	free(m);
}

Morador *atualizaMorador (Morador *m, char nome[50], int idade, char curso[50], char apelido[50], int periodo, char status[20], char republica[50]) {
	setNomeMorador (m, nome);
	setIdadeMorador (m, idade);
	setCursoMorador (m, curso);
	setApelidoMorador (m, apelido);
	setPeriodoMorador (m, periodo);
	setStatusMorador (m, status);
	setRepublicaMorador(m, republica);
	return m;
}


void lerMorador (Morador *m) {
	char excluido[8] = "EXCLUIDO";
	printf("\n\nMORADOR\n");
	printf("Nome: %s", getNomeMorador(m));
	printf("\nIdade: %d", getIdadeMorador(m));
	printf("\nCurso: %s", getCursoMorador(m));
	printf("\nApelido: %s", getApelidoMorador(m));
	printf("\nPeriodo: %d", getPeriodoMorador(m));
	printf("\nStatus: %s", getStatusMorador(m));
	printf("\nRepública: %s", getRepublicaMorador(m));
	printf("\nQuantidade de tarefas: %d", getQntTarefasMorador(m));
	printf("\nQuantidade de alimentos: %d", getQntAlimentosMorador(m));
	printf("\nTarefas:");
	for(int i = 0; i < m->qntTarefas; i++){
		if(strcmp(getPessoaTarefa(m->tarefas[i]), getNomeMorador(m)) == 0 && strcmp(getDescricaoTarefa(m->tarefas[i]), excluido) != 0){
			lerTarefa(m->tarefas[i]);
		}
	}
	printf("\n\nAlimentos:");
	for(int i = 0; i < m->qntAlimentos; i++){
		if(strcmp(getDonoAlimento(m->alimentos[i]), getNomeMorador(m)) == 0 && strcmp(getDescricaoAlimento(m->alimentos[i]), excluido) != 0){
			lerAlimento(m->alimentos[i]);
		}
	}
}


char* getNomeMorador (Morador *m) {
	return m->nome;
}

int getIdadeMorador (Morador *m) {
	return m->idade;
}

char* getCursoMorador (Morador *m) {
	return m->curso;
}

char* getApelidoMorador (Morador *m) {
	return m->apelido;
}

int getPeriodoMorador (Morador *m) {
	return m->periodo;
}

char* getStatusMorador (Morador *m) {
	return m->status;
}

Alimento** getAlimentosMorador(Morador *m){
	return m->alimentos;
}

Tarefa** getTarefasMorador(Morador *m){
	return m->tarefas;
}

int getQntAlimentosMorador(Morador *m){
	return m->qntAlimentos;
}

int getQntTarefasMorador(Morador *m){
	return m->qntTarefas;
}

char* getRepublicaMorador(Morador *m){
	return m->republica;
}




void setNomeMorador(Morador *m, char nome[50]) {
	strcpy (m->nome, nome);
}

void setIdadeMorador (Morador *m, int idade){
	m->idade = idade;
}

void setCursoMorador (Morador *m, char curso[50]){
	strcpy (m->curso, curso);
}

void setApelidoMorador (Morador *m, char apelido[50]){
	strcpy (m->apelido, apelido);
}

void setPeriodoMorador(Morador *m, int periodo){
	m->periodo = periodo;
}

void setStatusMorador (Morador *m, char status[20]){
	strcpy (m->status, status);
}

void setAlimentosMorador(Morador *m, Alimento** a){
	m->alimentos = a;
}

void setTarefasMorador(Morador *m, Tarefa** t){
	m->tarefas = t;
}

void setQntAlimentosMorador(Morador *m, int qntAlimentos){
	m->qntAlimentos = qntAlimentos;
}

void setQntTarefasMorador(Morador *m, int qntTarefas){
	m->qntTarefas = qntTarefas;
}

void setRepublicaMorador(Morador *m, char republica[50]){
	strcpy(m->republica, republica);
}

