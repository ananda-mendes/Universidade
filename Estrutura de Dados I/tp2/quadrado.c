#include <stdio.h>
#include <stdlib.h>
#include "quadrado.h"

struct quadrado {
	float lado; 
};

Quadrado* criarQuadrado (float l) {
	Quadrado* q = malloc (sizeof (Quadrado));
	q->lado = l;
	return q;
}

void lerQuadrado (Quadrado* q) {
	printf ("\nQuadrado: \n");
	printf ("Tamanho do lado: %f\n", getLadoQuadrado(q));
}

Quadrado* atualizarQuadrado (Quadrado* q, float l) {
	setLadoQuadrado (q, l);
	return q;
}

float areaQuadrado (Quadrado *q) {
	float a; 
	a = (q->lado) * (q->lado);
	return a;
}

float getLadoQuadrado (Quadrado* q) {
	return q->lado;
}

void setLadoQuadrado (Quadrado* q, float l) {
	q->lado = l;
}

