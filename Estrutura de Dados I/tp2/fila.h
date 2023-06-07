#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;
typedef struct listano ListaNo;

Fila* criarFila ();
void insereFila (Fila* f, int v, char descricao[50]);
void retiraFila (Fila* f);
int verificaFila (Fila* f);
void liberaFila (Fila* f);
void imprimirConteudo (Fila* f);

#endif
