#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tarefa.h"
#include "morador.h"
#include "alimento.h"
#include "republica.h"

struct republica{
	char nome[50];
	char endereco[100];
	int telefone;
	int qntComodos;
	int qntMoradores;
	Morador** moradores;
};

Republica* criaRepublica (char nome[50], char endereco[100], int telefone, int qntComodos) {
	Republica *r = malloc(sizeof(Republica));
	strcpy(r->nome, nome);
	strcpy(r->endereco, endereco);
	r->telefone = telefone;
	r->qntComodos = qntComodos;
	return r;
}

Republica* atualizaRepublica (Republica *r, char nome[50], char endereco[100], int telefone, int qntComodos) {
	setNomeRepublica (r, nome);
	setEnderecoRepublica (r, endereco);
	setTelefoneRepublica (r, telefone);
	setQntComodosRepublica (r, qntComodos);
	return r;
}

void apagaRepublica (Republica *r){
	for(int i = 0; i < r->qntMoradores; i++){
		if(strcmp(getNomeRepublica(r), getRepublicaMorador(r->moradores[i])) == 0){
			apagaMorador(r->moradores[i]);
		}
	}
	free(r);
}

void lerRepublica (Republica *r){
	char excluido[8] = "EXCLUIDO";
	printf("\n\nREPÚBLICA\n");
	printf("Nome: %s", getNomeRepublica(r));
	printf("\nEndereço: %s", getEnderecoRepublica(r));
	printf("\nTelefone: %d", getTelefoneRepublica(r));
	printf("\nQuantidade de comôdos: %d", getQntComodosRepublica(r));
	
	printf("\nMoradores:");
	for(int i = 0; i < r->qntMoradores; i++){
		if(strcmp(getNomeRepublica(r), getRepublicaMorador(r->moradores[i])) == 0 && strcmp(getNomeMorador(r->moradores[i]), excluido) != 0){
			lerMorador(r->moradores[i]);
		}
	}

	printf ("\n");
}


void setNomeRepublica (Republica *r, char nome[50]){
	strcpy(r->nome, nome);
}

void setEnderecoRepublica (Republica *r, char endereco[100]){
	strcpy(r->endereco, endereco);
}

void setTelefoneRepublica (Republica *r, int telefone){
	r->telefone = telefone;
}

void setQntComodosRepublica (Republica *r, int qntComodos){
	r->qntComodos = qntComodos;
}

void setMoradoresRepublica (Republica *r, Morador** moradores){
	r->moradores = moradores;
}

void setQntMoradoresRepublica(Republica *r, int qntMoradores){
	r->qntMoradores = qntMoradores;
}


char* getNomeRepublica (Republica *r){
	return r->nome;
}

char* getEnderecoRepublica (Republica *r){
	return r->endereco;
}

int getTelefoneRepublica (Republica *r){
	return r->telefone;
}

int getQntComodosRepublica (Republica *r){
	return r->qntComodos;
}

Morador** getMoradoresRepublica (Republica *r){
	return r->moradores;
}

Morador* getMoradorRepublica (Republica *r, int pos){
	return r->moradores[pos];
}

int getQntMoradoresRepublica (Republica *r){
	return r->qntMoradores;
}
