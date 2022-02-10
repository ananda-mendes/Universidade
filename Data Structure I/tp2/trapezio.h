#ifndef TRAPEZIO_H
#define TRAPEZIO_H

typedef struct trapezio Trapezio;

Trapezio* criarTrapezio (float B, float b, float h);
void lerTrapezio (Trapezio* t);
Trapezio* atualizarTrapezio (Trapezio* t, float B, float b, float h);
float areaTrapezio (Trapezio* t);

//GET E SET
float getBaseMaiorTrapezio (Trapezio* t);
float getBaseMenorTrapezio (Trapezio* t);
float getAlturaTrapezio (Trapezio* t);

void setBaseMaiorTrapezio (Trapezio* t, float B);
void setBaseMenorTrapezio (Trapezio* t, float b);
void setAlturaTrapezio (Trapezio* t, float h);
#endif
