#include "header.h"

int pesquisaAcessoSequencial (TipoIndice tabela[], int tamanho, TipoRegistro *registro, FILE *arquivo, string situacao, int& numero_comparacoes, int& numero_transferencias) {
  TipoRegistro pagina[ITENSPAGINA];
  long deslocamento;
  int i = 0, quantItens;
  
  // PROCURA PELA PÁGINA ONDE O REGISTRO PODE SE ENCONTRAR
  //EM CASO DECRESCENTE O WHILE MUDA
  if (situacao == DECRESCENTE) {
    while(i < tamanho && tabela[i].chave >= registro->chave) {
      i++;
      numero_comparacoes++;
    }
  }
  else {
    while(i < tamanho && tabela[i].chave <= registro->chave) {
      i++;
      numero_comparacoes++;
    }
  }

  // CASO A CHAVE DESEJADA SEJA MENOR QUE A 1ª CHAVE, O REGISTRO NÃO EXISTE NO ARQUIVO
  if (i == 0) {
    return 0;
  }
  else {
    // A ÚLTIMA PÁGINA PODE NÃO ESTAR COMPLETA
    if (i < tamanho) {
      quantItens = ITENSPAGINA;
    }
    else {     
      fseek (arquivo, 0, SEEK_END);
      quantItens = (ftell(arquivo) / sizeof(TipoRegistro)) % ITENSPAGINA;
       if(quantItens == 0) {
         quantItens = ITENSPAGINA;
       }
    }

    // LÊ A PÁGINA DESEJADA DO ARQUIVO
    deslocamento = (tabela[i-1].posicao-1) * ITENSPAGINA * sizeof(TipoRegistro);
    fseek (arquivo, deslocamento, SEEK_SET);
    fread (&pagina, sizeof(TipoRegistro), quantItens, arquivo);
    numero_transferencias++;

    // PESQUISA SEQUENCIAL NA PÁGINA LIDA
    for (i = 0; i < quantItens; i++) {
      numero_comparacoes++;
      if (pagina[i].chave == registro->chave) {
        *registro = pagina[i]; 
        return 1;
      }
    }
    return 0;
  }
  return 0;
}