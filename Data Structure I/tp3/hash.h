#ifndef FUNCOES_HPP
#define FUNCOES_HPP
#include "cadastro.h"
#include <stdbool.h>

typedef struct hash Hash;
typedef struct listano ListaNo;
typedef ListaNo* List;

Hash* criar_hash();
void THash_Inicia (Hash* hash, int listas);
int THash_insere (Hash* hash, char nome[50], int telefone, char funcao[50]);
int HashFunction (char nome[50]);
bool hash_atualiza (Hash* hash, char nome[50], int telefone, char funcao[50]);
bool hash_pesquisa (Hash* hash, char nome[50]);
bool buscar_dado (Hash* hash, char nome[50], Cadastro* c);
bool hash_remove (Hash* hash, char nome[50]);
void hash_imprimir (Hash* hash, char nome[50]);
void hash_delete (Hash* hash);

void inicio_lista (List* raiz);
ListaNo* criar_no (char nome[50], int telefone, char funcao[50]);
bool atualiza_no (ListaNo** no, char nome[50], int telefone, char funcao[50]);
bool inserir_no (ListaNo** no, char nome[50], int telefone, char funcao[50]);
bool verificar_no (ListaNo** raiz, char nome[50]);
bool buscar_no (ListaNo** no, char nome[50], Cadastro* c);
bool retira_no(ListaNo **pNo, char nome[50]);
void no_sucessor(ListaNo* pNo, ListaNo** pNoDir);

void deleta_lista(ListaNo** pNo);
void imprimir_lista(ListaNo** pNo);

#endif

