#ifndef TIMES_H
#define TIMES_H

typedef struct times Times;

Times* criarTimes(int t);
void lerResultados (Times* times, int t, int g);
void imprimirClassificacao(Times* times, int t);

void mergeSortPontos (Times* times, int t);
void mergeSortSaldo (Times* times, int pos_inicial, int pos_final);
void mergeSortGolsMarcados (Times* times, int pos_inicial, int pos_final);

void mergeSort_ordenaPontos (Times* times, int esq, int dir);
void mergeSort_ordenaSaldo (Times* times, int esq, int dir);
void mergeSort_ordenaGolsMarcados (Times* times, int esq, int dir);

void mergeSort_intercalaPontos (Times* times, int esq, int meio, int dir);
void mergeSort_intercalaSaldo (Times* times, int esq, int meio, int dir);
void mergeSort_intercalaGolsMarcados (Times* times, int esq, int meio, int dir);

#endif
