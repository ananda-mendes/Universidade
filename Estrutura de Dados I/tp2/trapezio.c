#include <stdio.h>
#include <stdlib.h>
#include "trapezio.h"

struct trapezio {
	float B; //Base maior 
	float b; //Base menor
	float h; //Altura
};

Trapezio* criarTrapezio (float B, float b, float h) {
	Trapezio* t = malloc (sizeof (Trapezio));
	t->B = B;
	t->b = b;
	t->h = h;
	return t;
}

void lerTrapezio (Trapezio* t) {
	printf ("\nTrapezio: \n");
	printf ("\nBase maior: %f\n", getBaseMaiorTrapezio (t));
	printf ("\nBase menor: %f\n", getBaseMenorTrapezio (t));
	printf ("\nAltura: %f\n", getAlturaTrapezio (t));
}

Trapezio* atualizarTrapezio (Trapezio* t, float B, float b, float h) {
	setBaseMaiorTrapezio (t, B);
	setBaseMenorTrapezio (t, b);
	setAlturaTrapezio (t, h);
	return t;
}

float areaTrapezio (Trapezio* t) {
	float a;
	a = ((t->B + t->b) * (t->h))/2;
	return a;
}

float getBaseMaiorTrapezio (Trapezio* t) {
	return t->B;
}

float getBaseMenorTrapezio (Trapezio* t) {
	return t->b;
}

float getAlturaTrapezio (Trapezio* t) {
	return t->h;
}

void setBaseMaiorTrapezio (Trapezio* t, float B) {
	t->B = B;
}

void setBaseMenorTrapezio (Trapezio* t, float b) {
	t->b = b;
}

void setAlturaTrapezio (Trapezio* t, float h) {
	t->h = h;
}

