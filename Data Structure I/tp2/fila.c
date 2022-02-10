#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fila.h"

struct fila {
	ListaNo* prim;
	ListaNo* ult;
};

struct listano {
	int identificador;
	char descricao[50];
	clock_t tempo;
	ListaNo* prox;
};

//cria uma fila vazia
Fila* criarFila () {
	Fila* f = malloc (sizeof (Fila));
	f->prim = NULL;
	f->ult = NULL;
	return f;
}

//insere na ultima posicao da fila
void insereFila (Fila* f, int v, char descricao[50]) {
	ListaNo* n = malloc (sizeof (ListaNo));
	n->identificador = v; //armazena o identificador
	n->prox = NULL;
	strcpy (n->descricao, descricao);
	n->tempo = clock();
	if (f->ult != NULL) { //verifica se a fila nao estava vazia
		f->ult->prox = n;
	}
	else { //fila estava vazia
		f->prim = n;
	}
	f->ult = n; //fila aponta para novo elemento
}

//retira o primeiro elemento da fila, ou seja, o que tem maior tempo de espera
void retiraFila (Fila* f) {
	ListaNo* t = f->prim;
	int v = t->identificador;
	f->prim = t->prox;
	if (f->prim == NULL) { //verifica se a fila ficou vazia
		f->ult = NULL;
	}
	free (t);
}

//verifica se a fila esta vazia
int verificaFila (Fila* f) {
	return (f->prim == NULL);
}

//libera a estrutura toda da fila
void liberaFila (Fila* f) {
	ListaNo* n = f->prim;
	while (n != NULL) {
		ListaNo* t = n->prox;
		free (n);
		n = t;
	}
	free (f);
}

//funcao para imprimir o conteudo 
void imprimirConteudo (Fila* f) {
	printf ("\nConteudo da fila: \n\n");
	for (ListaNo* n = f->prim; n != NULL; n = n->prox) {
		printf ("Descricao = %s", n->descricao);
		printf ("Identificador = %d\n", n->identificador);
		//o tempo da sempre zero pois todo o processo e muito rapido
		printf ("Tempo = %f\n", (((float)clock()-n->tempo)*1000)/CLOCKS_PER_SEC); 
	}
}
