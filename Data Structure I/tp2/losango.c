#include <stdio.h>
#include <stdlib.h>
#include "losango.h"

struct losango {
	float D; //Diagonal maior
	float d; //Diagonal menor
};

Losango* criarLosango (float D, float d) {
	Losango *l = malloc (sizeof (Losango));
	l->D = D;
	l->d = d;
	return l;
}

void lerLosango (Losango* l) {
	printf ("\nLosango: \n");
	printf ("\nDiagonal maior: %f\n", getDiagonalMaiorLosango (l));
	printf ("\nDiagonal menor: %f\n", getDiagonalMenorLosango (l));
}

Losango* atualizarLosango (Losango* l, float D, float d) {
	setDiagonalMaiorLosango (l, D);
	setDiagonalMenorLosango (l, d);
	return l;
}

float areaLosango (Losango* l) {
	float a;
	a = ((l->D) * (l->d))/2;
	return a;
}

float getDiagonalMaiorLosango (Losango* l) {
	return l->D;
}

float getDiagonalMenorLosango (Losango* l){
	return l->d;
}

void setDiagonalMaiorLosango (Losango* l, float D) {
	l->D = D;
}

void setDiagonalMenorLosango (Losango* l, float d) {
	l->d = d;
}
