#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iomanip>
#include <cstring>
#include <ctime>

//DECLARAÇÕES DE USO GERAL
#define ITENSPAGINA 4
#define ORDEM 2

#define CRESCENTE "Crescente"
#define DECRESCENTE "Decrescente"
#define ALEATORIO "Aleatorio"

using namespace std;

typedef struct {
  int posicao;
  int chave;
} TipoIndice;

typedef struct {
  int chave;
  long int dado1;
  char dado2[501];
} TipoRegistro;

void validaEntradaDeDados(int argc, char **argv, int& metodo, int& quantidade, int& situacao, int& chave, bool& P);
void algoritmosDePesquisaExterna(string situacao, int quantidade, TipoIndice* tabela, int chave, int metodo, bool P);

//FUNÇÃO NECESSÁRIA PARA GERADOR
int criadorDeArquivo (int numRegistros, string cresDecresAlea);

//FUNÇÃO NECESSÁRIA PARA ARQUIVO SEQUENCIAL
int pesquisaAcessoSequencial(TipoIndice tabela[], int tamanho, TipoRegistro *item, FILE *arquivo, string situacao, int& numero_comparacoes, int& numero_transferencias);

// STRUCTS E FUNÇÕES NECESSÁRIAS PARA ÁRVORE BINÁRIA 
typedef struct No {
  TipoRegistro registro;
  long long int ponteiroEsq, ponteiroDir;
} TipoNo;

typedef TipoNo ArvoreBinaria;

bool criaArvoreBinaria (string caminho, int& numero_transferencias, int& numero_comparacoes);
bool organizaArvoreBinaria (FILE* saida, TipoIndice *indice, int& numero_transferencias, int& numero_comparacoes);
int pesquisaArvoreBinaria(FILE* saida, TipoRegistro *registro, int& numero_transferencias, int& numero_comparacoes);

// STRUCTS E FUNÇÕES NECESSÁRIAS PARA ÁRVORE B 
typedef struct TipoPagina *TipoApontador;

typedef struct TipoPagina {
  short quantItens;
  TipoRegistro registro[2*ORDEM];
  TipoApontador ponteiro[2*ORDEM + 1];
} TipoPagina;

bool pesquisaArvoreB (TipoRegistro *registro, TipoApontador apontador, int& numero_comparacoes);
void insereNaPagina (TipoApontador apontador, TipoRegistro registro, TipoApontador apontadorDireita, int& numero_comparacoes);
void ins(TipoRegistro registro, TipoApontador apontador, short *cresceu, TipoRegistro *regRetorno, TipoApontador *apRetorno, int& numero_comparacoes);
void insereArvoreB (TipoRegistro registro, TipoApontador *apontador, int& numero_comparacoes);

// STRUCTS E FUNÇÕES NECESSÁRIAS PARA ÁRVORE B*
typedef enum {Interna, Externa} TipoIntExt;

typedef struct Pagina* Apontador;

typedef struct Pagina {
  TipoIntExt Pt;
  union {
    struct {
      int quantItensInt;
      int chave[2*ORDEM];
      Apontador ponteiro[2*ORDEM + 1];
    } Interna;
    struct {
      int quantItensExt;
      TipoRegistro registro[3*ORDEM];
      Apontador prox;
    } Externa;
  } IntOrExt;
} Pagina;

void InsereNaPagina (Apontador apontador, int registro, Apontador apontadorDireita, int& numero_comparacoes); // IGUAL ARVORE B
void Ins (TipoRegistro* registro, Apontador apontador, short *cresceu, TipoRegistro *regRetorno, Apontador *apRetorno, short *Cresceu_No, int& numero_comparacoes);
void InsereArvoreBStar (TipoRegistro registro, Apontador* apontador, int& numero_comparacoes);
bool InsereNaFolha (TipoRegistro* registro, Apontador novaPagina, int& numero_comparacoes);
void imprimeBStar (Apontador arvore);
bool pesquisaArvoreBStar(TipoRegistro *registro, Apontador apontador, int& numero_comparacoes);

#endif