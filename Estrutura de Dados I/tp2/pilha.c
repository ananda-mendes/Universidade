#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "quadrado.h"
#include "losango.h"
#include "trapezio.h"


struct listano {
	Identificador objeto;
	void* info;
	ListaNo* prox;
};

struct pilha {
	ListaNo* prim;
};

//criar pilha vazia
Pilha* criarPilha () {
	Pilha* p = malloc (sizeof (Pilha));
	p->prim = NULL;
	return p;
}

//funcao para adicionar no topo de acordo com o objeto
void pilhaPush (Pilha *p, int objeto, void* info) {
	ListaNo* n = malloc (sizeof(ListaNo));
	n->info = info;
	switch (objeto) {
		case 0: 
			n->objeto = QUA;
			break;
		case 1:
			n->objeto = LOS;
			break;
		case 2: 
			n->objeto = TRAP;
			break;
		default: 
			break;
		
	}
	n->prox = p->prim;
	p->prim = n;
}
	
	
//funcao para retirar do topo
int pilhaPop (Pilha *p) {
	//verifica se a pilha está vazia
	if(verificarPilha(p) != 1){
		ListaNo* n = p->prim;
		p->prim = n->prox; 
		free(n); 
		return 1;
	} 
	return 0;
}

//verifica se a pilha esta vazia
int verificarPilha (Pilha* p) {
	return (p->prim == NULL);
}

//libera toda a estrutura da pilha
void liberarPilha (Pilha* p) {
	ListaNo* n = p->prim;
	while (n != NULL) {
		ListaNo* t =  n->prox;
		free(n);
		n = t;
	}
	free(p);
}

//funcao para calculo da area
void area (Pilha* p) {
	for (ListaNo* n = p->prim; n != NULL; n = n->prox) { 
		switch (n->objeto) {
			case QUA: {
				Quadrado* q = n->info; //conversao do ponteiro generico em um ponteiro especifico do objeto
				printf ("\nArea quadrado = %.2f\n", areaQuadrado (q));
			}
				break;
			
			case LOS: {
				Losango* l = (Losango*) n->info;
				printf ("\nArea Losango = %.2f\n", areaLosango(l));
			}
				break;
			
			case TRAP: {
				Trapezio* t = (Trapezio*) n->info;
				printf ("\nArea Trapezio = %.2f\n", areaTrapezio(t));
			}
				break;
			default: 
				break;
			
		}
	}
}

void* getInfoPilha (ListaNo* n) {
	return n->info;
}

Identificador getObjetoPilha (ListaNo* n) {
	return n->objeto;
}

ListaNo* getProxPilha (Pilha* p) {
	return p->prim;
}
	
