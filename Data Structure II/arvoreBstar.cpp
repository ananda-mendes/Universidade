#include "header.h"

void InsereNaPagina (Apontador apontador, int registro, Apontador apontadorDireita, int& numero_comparacoes) {
  short NaoAchouPosicao;
  int k;
  k = apontador->IntOrExt.Interna.quantItensInt;
  //VARIÁVEL QUE MANTÉM O CONTROLE DA POSIÇÃO CORRENTE
  NaoAchouPosicao = (k > 0);

  while(NaoAchouPosicao) {
    if (registro >= apontador->IntOrExt.Interna.chave[k-1]) {
      numero_comparacoes++;
      break;
    }
    //COLOCA O REGISTRO E O APONTADOR NUMA POSIÇÃOA FRENTE 
    //("arreda" para a direita)
    apontador->IntOrExt.Interna.chave[k] = apontador->IntOrExt.Interna.chave[k-1];
    apontador->IntOrExt.Interna.ponteiro[k+1] = apontador->IntOrExt.Interna.ponteiro[k];
    k--;
    if (k < 1) {
      NaoAchouPosicao = false;
    }
  }

  //ACHOU POSIÇÃO
  apontador->IntOrExt.Interna.chave[k] = registro;
  apontador->IntOrExt.Interna.ponteiro[k+1] = apontadorDireita;
  apontador->IntOrExt.Interna.quantItensInt++;
  return;
}

void Ins (TipoRegistro* registro, Apontador apontador, short *cresceu, TipoRegistro *regRetorno, Apontador *apRetorno, short *Cresceu_No, int& numero_comparacoes) {
  long i = 1;
  long j;
  Apontador ApTemp;
  Apontador novo=nullptr;

  TipoRegistro aux;

  if (apontador->Pt == Externa) {
    //SE ENTROU QUER DIZER QUE CHEGOU AO ÚLTIMO NÍVEL
    //VERIFICA SE TEM ESPAÇO NA PÁGINA E TENTA INSERIR NA PÁGINA EXTERNA
    if (apontador->IntOrExt.Externa.quantItensExt < (3*ORDEM)) {
      InsereNaFolha (registro, apontador, numero_comparacoes);
      *cresceu = false;
      *Cresceu_No = false;
      //NÃO PRECISA CRESCER NÍVEL NEM DIVIDIR
    }
    else {
      //SEPARANDO UM NÓ EM DOIS
      //SOBE PRO PAI A CÓPIA DA CHAVE E DIVIDE
      //regRetorno VAI SALVAR A CHAVE DO PAI
      //ApRetorno VAI SALVAR O NOVO NÓ A DIREITA
      novo = (Pagina*)malloc(sizeof(Pagina));
      novo->Pt = Externa;
      novo->IntOrExt.Externa.quantItensExt=0;
      aux = apontador->IntOrExt.Externa.registro[(3*ORDEM)-1];

      //COLOCA O ÚLTIMO ELEMENTO NA PÁGINA A DIREITA
      InsereNaFolha(&aux, novo, numero_comparacoes);

      //DECREMENTA O NÚMERO DE ITENS DESSA PÁGINA
      apontador->IntOrExt.Externa.quantItensExt--;

      //INSERE O NOVO
      bool inseriu = InsereNaFolha(registro, apontador, numero_comparacoes);

      if (!inseriu) {
        apontador->IntOrExt.Externa.quantItensExt++;
        delete novo;
        *cresceu = false;
        *Cresceu_No = false;
        return;
      }

      //PASSA METADE PARA NOVA FOLHA
      for (int i = (3*ORDEM)/2; i < (3*ORDEM); i++) {
        InsereNaFolha(&(apontador->IntOrExt.Externa.registro[i]), novo, numero_comparacoes);
        apontador->IntOrExt.Externa.quantItensExt--;
      }

      regRetorno->chave = novo->IntOrExt.Externa.registro[0].chave;
      *apRetorno = novo;
      apontador->IntOrExt.Externa.prox = novo;
      novo->IntOrExt.Externa.prox = nullptr;

      //APÓS INSERIR NA ÁRVORE O NOVO REGISTRO, A CHAVE QUE PRECISA SUBIR PARA O NÓ PAI PRECISA SER INSERIDA NA ÁRVORE
      registro->chave = novo->IntOrExt.Externa.registro[0].chave;
      //DIVIDIU O NÓ FOLHA
      *Cresceu_No = true;
      return;
    }
  }
  else {
    //SE A PÁGINA FOR INTERNA
    while (i < apontador->IntOrExt.Interna.quantItensInt && registro->chave > apontador->IntOrExt.Interna.chave[i-1]) {
      numero_comparacoes++;
      i++;
    }

    //VERIFICAR DENTRO DO NÓ FOLHA PARA VER SE AINDA EXISTE 
    if (registro->chave == apontador->IntOrExt.Interna.chave[i - 1]) {
      numero_comparacoes++;
      *cresceu = false;
      *Cresceu_No =false;
      return;
    }

    if (registro->chave < apontador->IntOrExt.Interna.chave[i - 1]) {
      numero_comparacoes++;
      i--;
    }

    //ENCONTRA O LUGAR ONDE A CHAVE DEVE ENTRAR
    //ENTRA SE A PRÓXIMA PÁGINA FOR INTERNA    
    if(!*Cresceu_No) {
      Ins(registro, apontador->IntOrExt.Interna.ponteiro[i], cresceu, regRetorno, apRetorno,Cresceu_No, numero_comparacoes);

      if (!*cresceu && !*Cresceu_No) return;
      //VERIFICA SE A PÁGINATEM ESPAÇO
      if (apontador->IntOrExt.Interna.quantItensInt < 2*ORDEM) {
        InsereNaPagina(apontador, regRetorno->chave, *apRetorno, numero_comparacoes);
        *cresceu = false;
        *Cresceu_No =false;
        return;
      }

      //A PÁGINA ESTÁ CHEIA E DEVE SER DIVIDIDA
      ApTemp = (Apontador) malloc (sizeof(Pagina));
      ApTemp->Pt = Interna;
      ApTemp->IntOrExt.Interna.quantItensInt = 0;
      ApTemp->IntOrExt.Interna.ponteiro[0] = nullptr;

      if (i < ((2*ORDEM)/2) + 1) {
        InsereNaPagina(ApTemp, apontador->IntOrExt.Interna.chave[(2*ORDEM) - 1], apontador->IntOrExt.Interna.ponteiro[2*ORDEM], numero_comparacoes);
        apontador->IntOrExt.Interna.quantItensInt--;
        InsereNaPagina(apontador, regRetorno->chave, *apRetorno, numero_comparacoes);
      }
      else {
        InsereNaPagina(ApTemp, regRetorno->chave, *apRetorno, numero_comparacoes);
      }

      for (j = ((2*ORDEM)/2) + 2; j <= 2*ORDEM; j++) {
        InsereNaPagina(ApTemp, apontador->IntOrExt.Interna.chave[j-1], apontador->IntOrExt.Interna.ponteiro[j], numero_comparacoes);
      }

      apontador->IntOrExt.Interna.quantItensInt = (2*ORDEM)/2;
      ApTemp->IntOrExt.Interna.ponteiro[0] = apontador->IntOrExt.Interna.ponteiro[((2*ORDEM)/2) + 1];
      regRetorno->chave= apontador->IntOrExt.Interna.chave[(2*ORDEM)/2];

      *apRetorno = ApTemp;
      *cresceu = true;
      *Cresceu_No = false;
      return;
    }
  }
}

void InsereArvoreBStar (TipoRegistro* registro, Apontador* apontador, int& numero_comparacoes) {
  short cresceu = 0;
  short cresceu_No = 0;

  TipoRegistro regRetorno;
  Pagina *apRetorno = nullptr;
  Pagina *ApTemp = nullptr;
  bool nova = false;

  if (*apontador == NULL) {
    //ALOCA A PRIMEIRA PÁGINA
    ApTemp = (Pagina*)malloc(sizeof(Pagina));
    ApTemp->Pt = Externa;
    ApTemp->IntOrExt.Externa.quantItensExt = 0;
    ApTemp->IntOrExt.Externa.prox = nullptr;

    InsereNaFolha(registro, ApTemp, numero_comparacoes);
    *apontador = ApTemp;
    return;
  }
  else {
    if ((*apontador)->Pt == Externa) {
      nova = true;
    }
    Ins(registro, *apontador, &cresceu, &regRetorno, &apRetorno, &cresceu_No, numero_comparacoes);
  }

  //VERIFICA SE É O PRIMEIRO NÓ A SER CRIADO
  if ((cresceu_No && nova) || cresceu) {
    ApTemp = (Pagina*) malloc(sizeof(Pagina));
    ApTemp->Pt = Interna;
    ApTemp->IntOrExt.Interna.quantItensInt = 1;
    ApTemp->IntOrExt.Interna.chave[0] = regRetorno.chave;
    ApTemp->IntOrExt.Interna.ponteiro[0] = *apontador;
    ApTemp->IntOrExt.Interna.ponteiro[1] = apRetorno;

    *apontador = ApTemp;

    return;
  }
}

bool InsereNaFolha (TipoRegistro* registro, Apontador NovaPagina, int& numero_comparacoes) {
  int quantItens = NovaPagina->IntOrExt.Externa.quantItensExt;
  int k = 0;
  int i = 0;

  while (registro->chave > NovaPagina->IntOrExt.Externa.registro[i].chave && i < quantItens) {
    numero_comparacoes++;
    i++;
  }

  if(registro->chave == NovaPagina->IntOrExt.Externa.registro[i].chave && quantItens != 0) {
    numero_comparacoes++;
    return false;
  }

  if (i < quantItens) {
    k = quantItens;
    while (k >= 0 && k > i) {
      NovaPagina->IntOrExt.Externa.registro[k] = NovaPagina->IntOrExt.Externa.registro[k-1];
      k--;
    }
    //INSERE NA POSIÇÃO i
    NovaPagina->IntOrExt.Externa.registro[i] = *registro;
  }
  else {
    //INSERE NO FINAL
    NovaPagina->IntOrExt.Externa.registro[i] = *registro;
  }

  NovaPagina->IntOrExt.Externa.quantItensExt++;

  return true;
}

void imprimeBStar (Apontador arvore) {
  int i = 0;
  Apontador aux;

  if(arvore == NULL) {
    return;
  }

  if (arvore->Pt == Interna) {
    while (i <= arvore->IntOrExt.Interna.quantItensInt) {
      imprimeBStar(arvore->IntOrExt.Interna.ponteiro[i]);
      if (i != arvore->IntOrExt.Interna.quantItensInt) {
        //cout << arvore->IntOrExt.Interna.chave[i] << endl;
      }
      i++;
    }
  }
  else {
    aux = arvore;
    for (int j = 0; j < aux->IntOrExt.Externa.quantItensExt; j++) {
      cout << aux->IntOrExt.Externa.registro[j].chave << endl;
    }
  }
}

bool pesquisaArvoreBStar(TipoRegistro *registro, Apontador apontador, int& numero_comparacoes) {
  int i;
  if (apontador->Pt == Interna) {
    i = 1;

    //PESQUISA SEQUENCIAL NA PÁGINA INTERNA
    while (i < apontador->IntOrExt.Interna.quantItensInt && registro->chave > apontador->IntOrExt.Interna.chave[i-1]) {
      numero_comparacoes++;
      i++;
    }

    // ATIVAÇÃO RECURSIVA EM UMA DAS SUBÁRVORES: A PESQUISA SÓ PARA AO ENCONTRAR UMA PÁGINA FOLHA
    if (registro->chave < apontador->IntOrExt.Interna.chave[i-1]) {
      numero_comparacoes++;
      pesquisaArvoreBStar(registro, apontador->IntOrExt.Interna.ponteiro[i - 1], numero_comparacoes);
    }
    else 
      pesquisaArvoreBStar(registro, apontador->IntOrExt.Interna.ponteiro[i], numero_comparacoes);
  }

  i = 1;

  // PESQUISA SEQUENCIAL NA PÁGINA FOLHA
  while (i < apontador->IntOrExt.Externa.quantItensExt && registro->chave > apontador->IntOrExt.Externa.registro[i - 1].chave) {
    numero_comparacoes++;
    i++;
  }
  // VERIFICA SE A CHAVE DESEJADA FOI LOCALIZADA
  if (registro->chave == apontador->IntOrExt.Externa.registro[i - 1].chave) {
    numero_comparacoes++;
    *registro = apontador->IntOrExt.Externa.registro[i - 1];
    return true;
  }
  else if (apontador->IntOrExt.Externa.registro == NULL) {
    cout << "TipoRegistro nao esta presente na arvore" << endl;
    return false;
  }
}
