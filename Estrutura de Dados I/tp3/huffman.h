#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdbool.h>

typedef struct arvoreno ArvoreNo;
typedef struct listano ListaNo;
typedef struct lista Lista;

// Definição do tipo de dados 'byte'
typedef unsigned char byte;

char *strdup(const char *s);
ListaNo *novoListaNo (ArvoreNo *nArv);
ArvoreNo *novoArvoreNo (byte c, int frequencia, ArvoreNo *esquerda, ArvoreNo *direita);
void insereLista(ListaNo *n, Lista *l);
ArvoreNo *popMinLista(Lista *l);
void getByteFrequency(FILE *entrada, unsigned int *listaBytes);
bool pegaCodigo(ArvoreNo *n, byte c, char *buffer, int tamanho);
ArvoreNo *BuildHuffmanTree(unsigned *listaBytes);
void FreeHuffmanTree(ArvoreNo *n);
int geraBit(FILE *entrada, int posicao, byte *aux );
void erroArquivo();
void CompressFile(const char *arquivoEntrada, const char *arquivoSaida);
void DecompressFile(const char *arquivoEntrada, const char *arquivoSaida);

#endif
