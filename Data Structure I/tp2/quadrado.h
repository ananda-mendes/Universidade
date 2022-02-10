#ifndef QUADRADO_H
#define QUADRADO_H

typedef struct quadrado Quadrado;

Quadrado* criarQuadrado (float l);
void lerQuadrado (Quadrado* q);
Quadrado* atualizarQuadrado (Quadrado* q, float l);
float areaQuadrado (Quadrado* q);

//GET E SET
float getLadoQuadrado (Quadrado* q);

void setLadoQuadrado (Quadrado* q, float lado);

#endif
