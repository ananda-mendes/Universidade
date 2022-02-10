/* ## Universidade Federal de Ouro Preto
## Docentes: Ananda Mendes Souza(19.1.4030) e Rômulo de Oliveira Carneiro(19.1.4107)
## Bacharelado em Ciência da Computação - Estrutura de Dados II */

#include "header.h"
#include "acessoSequencialIndexado.cpp"
#include "arvoreBinaria.cpp"
#include "arvoreB.cpp"
#include "arvoreBstar.cpp"
 
int main (int argc, char *argv[]) {
  int metodo, quantidade, situacao, chave;
  bool P;

  validaEntradaDeDados(argc, argv, metodo, quantidade, situacao, chave, P);
  
  //DEFININDO TAMANHO DA TABELA DE INDICES 
  int MAXTABELA = quantidade / ITENSPAGINA;
  TipoIndice tabela[MAXTABELA];

  
  if (situacao == 1) algoritmosDePesquisaExterna(CRESCENTE, quantidade, tabela, chave, metodo, P);
  else if (situacao == 2) algoritmosDePesquisaExterna(DECRESCENTE, quantidade, tabela, chave, metodo, P);
  else {
    if (metodo == 1) {
      cout << "O Acesso Sequencial Indexado exige que o arquivo esteja ordenado, não aceitando operações com arquivos embaralhados" << endl;
      exit(1);
    }
    algoritmosDePesquisaExterna(ALEATORIO, quantidade, tabela, chave, metodo, P);
  }

  return 0;
}

void algoritmosDePesquisaExterna(string situacao, int quantidade, TipoIndice* tabela, int chave, int metodo, bool P){
  FILE* arquivo;
  int posicao = 0, contador=0;
  TipoRegistro registro;

  int numero_transferencias = 0, numero_comparacoes_pesquisa = 0, numero_comparacoes_insercao = 0;
  double tempo_pesquisa, tempo_insercao;
  clock_t start_tempo, stop_tempo;

  //ABRINDO OS ARQUIVOS PRÉ-CRIADOS PELO GERADOR QUE SE ENCONTRAM NA PASTA
  string caminho = "./arquivosDeRegistro/registros"+ situacao + to_string(quantidade) + ".bin";
  
  if((arquivo = fopen(caminho.c_str(), "rb")) == NULL) {
    exit(1);
  }  

  // ACESSO SEQUENCIAL INDEXADO
  if (metodo == 1) {
    // SISTEMA DE PAGINACAO
    start_tempo = clock();
    while(fread(&registro, sizeof(registro), 1, arquivo) == 1) {
      contador++;
      numero_transferencias++;
      if (contador % ITENSPAGINA == 1){
        tabela[posicao].chave = registro.chave;
        tabela[posicao].posicao = posicao + 1;
        posicao++;
      }
    }
    stop_tempo = clock(); 
    tempo_insercao = ((double)(stop_tempo - start_tempo) / CLOCKS_PER_SEC);

    fflush(stdout);

    //PASSA A CHAVE A SER PESQUISADA PARA O REGISTRO QUE SERÁ ENVIADO PRA PESQUISA
    registro.chave = chave;
    
    start_tempo = clock();
    if(pesquisaAcessoSequencial(tabela, posicao, &registro, arquivo, situacao, numero_comparacoes_pesquisa, numero_transferencias)) {
      cout << "Chave localizada: " << registro.chave << endl << endl; 
    }
    else {
      cout << "Chave nao localizada" << endl;
    }
    stop_tempo = clock(); 
    tempo_pesquisa = ((double)(stop_tempo - start_tempo) / CLOCKS_PER_SEC);  
  }

  // ARVORE BINARIA
  else if (metodo == 2) {
    FILE* saida;
    
    start_tempo = clock();
    if (!criaArvoreBinaria(caminho, numero_transferencias, numero_comparacoes_insercao)) {
      exit(1);
    }
    saida = fopen("ArvoreBinariaExterna.bin", "r+b");
    stop_tempo = clock();
    tempo_insercao = ((double)(stop_tempo - start_tempo) / CLOCKS_PER_SEC);

    //PASSA A CHAVE A SER PESQUISADA PARA O REGISTRO QUE SERÁ ENVIADO PRA PESQUISA
    registro.chave = chave;
    //leArvore();
    start_tempo = clock();
    if (pesquisaArvoreBinaria(saida, &registro, numero_transferencias, numero_comparacoes_pesquisa)) {
      cout << "Chave localizada: " << registro.chave << endl << endl; 
    }
    else {
      cout << "Chave nao localizada" << endl;
    }
    stop_tempo = clock(); 
    tempo_pesquisa = ((double)(stop_tempo - start_tempo) / CLOCKS_PER_SEC);

  }

  // ARVORE B
  else if (metodo == 3) {
    TipoApontador arvoreB = NULL;

    rewind(arquivo);

    start_tempo = clock();
    while(fread(&registro, sizeof(registro), 1, arquivo) == 1) {
      numero_transferencias++;
      insereArvoreB(registro, &arvoreB, numero_comparacoes_insercao);
    }
    stop_tempo = clock();
    tempo_insercao = ((double)(stop_tempo - start_tempo) / CLOCKS_PER_SEC);

    //PASSA A CHAVE A SER PESQUISADA PARA O REGISTRO QUE SERÁ ENVIADO PRA PESQUISA
    registro.chave = chave;

    start_tempo = clock();
    
    if (pesquisaArvoreB(&registro, arvoreB, numero_comparacoes_pesquisa) != false) {
      cout << "Chave localizada: " << registro.chave << endl << endl; 
    }
    else {
      cout << "Chave nao localizada" << endl << endl;
    }
    stop_tempo = clock();
    tempo_pesquisa = ((double)(stop_tempo - start_tempo) / CLOCKS_PER_SEC);
  } 

  //CHAMANDO A FUNÇÃO PESQUISA POR ARVORE B*
  else if (metodo == 4) {
    Apontador arvoreBstar = NULL;
    rewind (arquivo);
    
    start_tempo = clock();
    while(fread(&registro, sizeof(registro), 1, arquivo) == 1) {
      numero_transferencias++;
      InsereArvoreBStar(&registro, &arvoreBstar, numero_comparacoes_insercao);
    }
    
    stop_tempo = clock();
    tempo_insercao = ((double)(stop_tempo - start_tempo) / CLOCKS_PER_SEC);

    //PASSA A CHAVE A SER PESQUISADA PARA O REGISTRO QUE SERÁ ENVIADO PRA PESQUISA
    registro.chave = chave;

    start_tempo = clock();
   
    if ( pesquisaArvoreBStar(&registro, arvoreBstar, numero_comparacoes_pesquisa) != false) {
      cout << "Chave localizada: " << registro.chave << endl << endl; 
    }
    else {
      cout << "Chave nao localizada" << endl << endl;
    }

    stop_tempo = clock();
    tempo_pesquisa = ((double)(stop_tempo - start_tempo) / CLOCKS_PER_SEC);
  } 

  cout << "Tempo de Inserção: " << fixed << setprecision(6) << tempo_insercao << " Segundos" << endl;
  cout << "Numero de Comparacoes (Inserção): " << numero_comparacoes_insercao << endl << endl;
  cout << "Tempo de Pesquisa: " << fixed << setprecision(6) << tempo_pesquisa << " Segundos" << endl;
  cout << "Numero de Comparacoes (Pesquisa): " << numero_comparacoes_pesquisa << endl << endl;
  cout << "Numero de Transferências: " << numero_transferencias << endl;
  
  if(P==1) {
    fseek(arquivo, 0, 0);
    cout << "\nChaves consideradas durante a pesquisa:  " << endl;
    while(feof(arquivo) != true){
      fread(&registro, sizeof(TipoRegistro), 1, arquivo);
      cout << registro.chave << " ";
    }
    cout << endl;
  }

  fclose(arquivo);
}

void validaEntradaDeDados(int argc, char **argv, int& metodo, int& quantidade, int& situacao, int& chave, bool& P) {
  if(argc < 5 || argc > 6) {
    exit(1);
  }
  
  if(argc == 6 && strcmp(argv[5], "p") == 0) {
    P = 1; 
  }
  
  // TRANSFORMANDO OS ARGUMENTOS EM INTEIROS
  metodo = atoi(argv[1]);
  quantidade = atoi(argv[2]);
  situacao = atoi(argv[3]);
  chave = atoi(argv[4]);
  
  
  if (strcmp(argv[0], "pesquisa") == 1) {
    cout << "Pesquisa invalida" << endl;
    exit(1);
  }
  if (metodo < 1 || metodo > 4) {
    cout << "Metodo invalido" << endl;
    exit(1);
  }
  
  if (situacao < 1 || situacao > 3) {
    cout << "Situacao invalida" << endl;
    exit(1);
  }

  if (quantidade != 100 && quantidade != 1000 && quantidade != 10000 && quantidade != 100000 && quantidade != 1000000) {
    cout << "Quantidade invalida" << endl;
    exit(1);
  }

  if (chave < 0 || chave >= quantidade) {
    cout << "Chave invalida" << endl;
    exit(1);
  }
}
