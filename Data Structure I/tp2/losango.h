#ifndef LOSANGO_H
#define LOSANGO_H

typedef struct losango Losango;

Losango* criarLosango (float D, float d);
void lerLosango (Losango* l);
Losango* atualizarLosango (Losango* l, float D, float d);
float areaLosango (Losango *l);

//GET E SET
float getDiagonalMaiorLosango (Losango* l);
float getDiagonalMenorLosango (Losango* l);

void setDiagonalMaiorLosango (Losango* l, float D);
void setDiagonalMenorLosango (Losango* l, float d);

#endif
