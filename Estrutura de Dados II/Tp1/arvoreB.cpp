#include "header.h"

bool pesquisaArvoreB (TipoRegistro *registro, TipoApontador apontador,int& numero_comparacoes) {
  long i = 1;
  if (apontador == NULL) {
    cout << "TipoRegistro nao esta presente na arvore\n";
    return false;
  }

  // PESQUISA SEQUENCIAL PARA ENCONTRAR O INTERVALO DESEJADO
  while (i < apontador->quantItens && registro->chave > apontador->registro[i-1].chave) {
    i++;
    numero_comparacoes++;
  }
  // VERIFICA SE A CHAVE DESEJADA FOI LOCALIZADA
  if (registro->chave == apontador->registro[i-1].chave) {
    numero_comparacoes++;
    *registro = apontador->registro[i-1];
    return true;
  }
  // ATIVAÇÃO RECURSIVA DA PESQUISA EM UMA DAS SUBÁRVORES (ESQUERDA OU DIREITA)
  if (registro->chave < apontador->registro[i-1].chave){
    numero_comparacoes++;
    pesquisaArvoreB(registro, apontador->ponteiro[i-1], numero_comparacoes);
  }
  else pesquisaArvoreB(registro, apontador->ponteiro[i], numero_comparacoes);

}

void insereNaPagina (TipoApontador apontador, TipoRegistro registro, TipoApontador apontadorDireita, int& numero_comparacoes) {
  short NaoAchouPosicao;
  int k;
  k = apontador->quantItens;
  NaoAchouPosicao = (k > 0);

  while (NaoAchouPosicao) {
    if (registro.chave >= apontador->registro[k - 1].chave) {
      numero_comparacoes++;
      //NaoAchouPosicao == false;
      break;
    }
    apontador->registro[k] = apontador->registro[k -1];
    apontador->ponteiro[k + 1] = apontador->ponteiro[k];
    k--;
    if (k < 1) {
      NaoAchouPosicao = false;
    }
  }
  apontador->registro[k] = registro;
  apontador->ponteiro[k + 1] = apontadorDireita;
  apontador->quantItens++;
}

void ins(TipoRegistro registro, TipoApontador apontador, short *cresceu, TipoRegistro *regRetorno, TipoApontador *apRetorno, int& numero_comparacoes) {
  long i = 1;
  long j;
  TipoApontador ApTemp;
  if (apontador == NULL) {
    *cresceu = true;
    (*regRetorno) = registro;
    (*apRetorno) = NULL;
    return;
  }
  while (i < apontador->quantItens && registro.chave > apontador->registro[i - 1].chave) {
    numero_comparacoes++;
    i++;
  }
  if (registro.chave == apontador->registro[i - 1].chave) {
    numero_comparacoes++;
    //cout << "Erro: Registro ja esta presente\n";
    *cresceu = false;
    return;
  }

  if (registro.chave < apontador->registro[i - 1].chave) {
    numero_comparacoes++;
    i--;
  }

  ins(registro, apontador->ponteiro[i], cresceu, regRetorno, apRetorno, numero_comparacoes);

  if (!*cresceu) {
    return;
  }

  // PAGINA TEM ESPACO 
  if (apontador->quantItens < 2*ORDEM) { 
    insereNaPagina(apontador, *regRetorno, *apRetorno, numero_comparacoes);
    *cresceu = false;
    return;
  }

  // OVERFLOW: PAGINA TEM QUE SER DIVIDIDA 
  ApTemp = (TipoApontador)malloc(sizeof(TipoPagina));
  ApTemp->quantItens = 0;
  ApTemp->ponteiro[0] = NULL;

  if(i < ORDEM + 1) {
    insereNaPagina(ApTemp, apontador->registro[2*ORDEM - 1], apontador->ponteiro[2*ORDEM], numero_comparacoes);
    apontador->quantItens--;
    insereNaPagina(apontador, *regRetorno, *apRetorno, numero_comparacoes);
  }
  else insereNaPagina(ApTemp, *regRetorno, *apRetorno, numero_comparacoes);
  for(j = ORDEM + 2; j <= 2*ORDEM; j++) {
    insereNaPagina(ApTemp, apontador->registro[j - 1], apontador->ponteiro[j], numero_comparacoes);
  }
  apontador->quantItens = ORDEM;
  ApTemp->ponteiro[0] = apontador->ponteiro[ORDEM + 1];
  *regRetorno = apontador->registro[ORDEM];
  *apRetorno = ApTemp; 
  
}

void insereArvoreB (TipoRegistro registro, TipoApontador *apontador, int& numero_comparacoes) {
  short cresceu;
  TipoRegistro regRetorno;
  TipoPagina *apRetorno, *apTemp;

  ins(registro, *apontador, &cresceu, &regRetorno, &apRetorno, numero_comparacoes);

  // ARVORE CRESCE NA ALTURA DA RAIZ
  if (cresceu) { 
    apTemp = (TipoPagina*)malloc(sizeof(TipoPagina));
    apTemp->quantItens = 1;
    apTemp->registro[0] = regRetorno;
    apTemp->ponteiro[1] = apRetorno;
    apTemp->ponteiro[0] = *apontador;
    *apontador = apTemp;
  }
}
