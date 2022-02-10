#include "cadastro.h"
#include <string.h>
#include <stdio.h> 
#include <stdlib.h>

struct cadastro {
	char nome[50];
	int telefone;
	char funcao[50];
};

//cria um cadastro de um funcionário
Cadastro* criar_funcionario (char nome[50], int telefone, char funcao[50]){
	Cadastro* aux= malloc (sizeof (Cadastro));
	strcpy (aux->nome, nome);
	aux->telefone=telefone;
	strcpy (aux->funcao, funcao);
	return aux;
}

//compara o nome do funcionario
int comparacao (char chave[50], Cadastro* c){
    if(strcmp (chave, c->nome) < 0) {
		return -1;
	} else if (strcmp (chave, c->nome) > 0) {
		return 1;
    }
    return 0;
}

void copiar_dados (Cadastro* palavraRecebe, Cadastro* palavraDoa){
	strcpy (palavraRecebe->nome,palavraDoa->nome);
    palavraRecebe->telefone = palavraDoa->telefone;
    strcpy (palavraRecebe->funcao, palavraDoa->funcao);
}

void deleta_dados (Cadastro* c){
  free(c);
}

void imprimir (Cadastro* c){
	printf ("\nNome: %s", c->nome);
	printf ("\nTelefone: %d", c->telefone);
	printf ("\nFuncao: %s\n", c->funcao);
}





