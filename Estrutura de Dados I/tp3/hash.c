#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char TChave [26];

struct listano {
	Cadastro* c;
	ListaNo *esq, *dir;
};
	
struct hash {
	int n; // numero de itens na hash
	int listas; // tamanho do array de listas
	List* v; // array de listas
};


Hash* criar_hash(){
	Hash *h = malloc (sizeof(Hash));
	return h;
}

//inicia a hash
void THash_Inicia (Hash* hash, int listas){
	hash->n=0;
	hash->listas=listas;
	hash->v = malloc (listas * sizeof(List));
	for (int i=0; i<listas; i++)
		inicio_lista (&(hash->v[i]));
}

//função para inserir um funcionario na hash
int THash_insere (Hash* hash, char nome[50], int telefone, char funcao[50]){
	if(!hash_pesquisa(hash,nome)){
		inserir_no (&hash->v[HashFunction(nome)],nome,telefone,funcao);
		hash->n++;
		return 1;
	}
	return 0;
}

//determina a posição no vetor que o dado ira entrar
int HashFunction (char nome[50]){
	int aux=nome[0];
	return aux%65;
}

//funcao para atualizar
bool hash_atualiza (Hash* hash, char nome[50], int telefone, char funcao[50]){
	return atualiza_no (&(hash->v[HashFunction(nome)]),nome,telefone,funcao);
}

//verifica se o funcionario ja existe
bool hash_pesquisa (Hash* hash, char nome[50]){
	if(verificar_no (&hash->v[HashFunction(nome)],nome))
		return true;
	return false;
}

//pesquisa um dado da hash
bool buscar_dado (Hash* hash, char nome[50], Cadastro* c){
	return buscar_no (&hash->v[HashFunction(nome)],nome,c);
}

//remove um funcionario na hash
bool hash_remove (Hash* hash, char nome[50]){
	if(retira_no(&hash->v[HashFunction(nome)],nome)){
		hash->n--;
		return true;
	}
	return false;
}

//imprime
void hash_imprimir (Hash* hash, char nome[50]){
	imprimir_lista (&hash->v[HashFunction(nome)]);
}

//deleta a hash
void hash_delete (Hash* hash){
	for (int i=0; i<26; i++)
		deleta_lista (&hash->v[i]);
	free (hash);
}

//inicia a arvore
void inicio_lista (List* raiz){
	*raiz=NULL;
}

//cria um no na lista
ListaNo* criar_no (char nome[50], int telefone, char funcao[50]){
	ListaNo* novo= malloc (sizeof (ListaNo));
	novo->c= criar_funcionario(nome,telefone,funcao);
	novo->esq=NULL;
	novo->dir=NULL;
	return novo;
}

//atualiza um dado na arvore
bool atualiza_no (ListaNo** no, char nome[50], int telefone, char funcao[50]){
	if(*no==NULL) {
		return false;
	} else if((comparacao(nome,(*no)->c))==0){
   		(*no)->c= criar_funcionario(nome,telefone,funcao);
		return true;
	}
	if((comparacao(nome,(*no)->c))<0) {
		return atualiza_no(&((*no)->esq),nome,telefone,funcao);
	} 
	else if((comparacao(nome,(*no)->c))>0) {
		return atualiza_no(&((*no)->dir),nome,telefone,funcao);
	}
	return false;
	
}

//insere um funcionario
bool inserir_no (ListaNo** no, char nome[50], int telefone, char funcao[50]){
	if(*no==NULL){
		*no= criar_no(nome,telefone,funcao);
		return true;
	}
	if(comparacao(nome,(*no)->c)<0) {
		return inserir_no(&((*no)->esq),nome,telefone,funcao);
	}
	if(comparacao(nome,(*no)->c)>0) {
		return inserir_no(&((*no)->dir),nome,telefone,funcao);
	}
	return false;
}

//verifica se existe o funcionario
bool verificar_no (ListaNo** raiz, char nome[50]){
	if(*raiz==NULL) {
		return false;
	}
	if(comparacao(nome,(*raiz)->c)<0) {
		return verificar_no(&(*raiz)->esq, nome);
	}
	if(comparacao(nome,(*raiz)->c)>0) {
		return verificar_no(&(*raiz)->dir, nome);
	}
	return false;
}

//busca um funcionario
bool buscar_no (ListaNo** no, char nome[50], Cadastro* c){ 
	if(*no==NULL) {
		return false;
	}
	if(comparacao(nome,(*no)->c)<0) {
		return buscar_no(&(*no)->esq, nome,c);
	}
	if(comparacao(nome,(*no)->c)>0) {
		return buscar_no(&(*no)->dir, nome,c);
	}
	copiar_dados(c, (*no)->c);
	return true;
}

//retira um funcionario
bool retira_no(ListaNo **pNo, char nome[50]){
	ListaNo* pAuxNo;

	if(*pNo==NULL) {
		return false;
	}
	if(comparacao(nome,(*pNo)->c)<0) {
		return retira_no(&((*pNo)->esq), nome);
	}
	if(comparacao(nome,(*pNo)->c)>0) { 
		return retira_no(&((*pNo)->dir), nome);
	}

	if((*pNo)->esq==NULL && (*pNo)->dir==NULL){
		deleta_dados((*pNo)->c);
		free (*pNo);
		(*pNo)=NULL;
		return true;
	}

	if((*pNo)->esq != NULL && (*pNo)->dir == NULL){
		pAuxNo=(*pNo);
		(*pNo)=(*pNo)->esq;
		deleta_dados(pAuxNo->c);
		free (pAuxNo);
		return true;
	}

	if((*pNo)->esq==NULL && (*pNo)->dir!=NULL){
		pAuxNo=(*pNo);
		(*pNo)=(*pNo)->dir;
		deleta_dados(pAuxNo->c);
		free (pAuxNo);
		return true;
	}

	no_sucessor(*pNo, &(*pNo)->dir);
	return true;
}

void no_sucessor(ListaNo* pNo, ListaNo** pNoDir){
	ListaNo* auxNo;
	if(((*pNoDir)->esq)!=NULL){
		no_sucessor(pNo,&((*pNoDir)->esq));
		return;
	}
	copiar_dados(pNo->c,(*pNoDir)->c);
	auxNo=*pNoDir;
	(*pNoDir)=(*pNoDir)->dir;
	deleta_dados(auxNo->c);
	free (auxNo);
}

void deleta_lista(ListaNo** pNo){
	if(*pNo==NULL) 
		return;
	deleta_lista(&((*pNo)->esq));
	deleta_lista(&((*pNo)->dir));
	deleta_dados(((*pNo)->c));
	free (*pNo);
}

void imprimir_lista(ListaNo** pNo){
	if(*pNo==NULL) return;
	imprimir_lista(&((*pNo)->esq));
	imprimir ((*pNo)->c);
	imprimir_lista(&((*pNo)->dir));
}















			
	
