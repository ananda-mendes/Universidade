#include "header.h"

int main () {
  srand(unsigned(time(NULL)));

  criadorDeArquivo(100, CRESCENTE);
  criadorDeArquivo(1000, CRESCENTE);
  criadorDeArquivo(10000, CRESCENTE);
  criadorDeArquivo(100000, CRESCENTE);
  criadorDeArquivo(1000000, CRESCENTE);
  criadorDeArquivo(100, DECRESCENTE);
  criadorDeArquivo(1000, DECRESCENTE);
  criadorDeArquivo(10000, DECRESCENTE);
  criadorDeArquivo(100000, DECRESCENTE);
  criadorDeArquivo(1000000, DECRESCENTE);  
  criadorDeArquivo(100, ALEATORIO);
  criadorDeArquivo(1000, ALEATORIO);
  criadorDeArquivo(10000, ALEATORIO);
  criadorDeArquivo(100000, ALEATORIO);
  criadorDeArquivo(1000000, ALEATORIO);

  return 0;
}

int criadorDeArquivo (int numRegistros, string cresDecresAlea) {
  FILE* arq;
  TipoRegistro registro;
  int i, j, aux;
  
  //CRIANDO UM NOME PADRONIZADO PARA TODOS OS ARQUIVOS: REGISTROS + CRESCENTE/DECRESCENTE/ALETORIO + QUANTIDADE
  string arquivo = "registros"+ cresDecresAlea + to_string(numRegistros) + ".bin";

  if ((arq = fopen(arquivo.c_str(), "w+b")) == NULL) {
      return 0;
  }
  
    if (cresDecresAlea == CRESCENTE){
      for (i = 0; i < numRegistros; i++) {
        registro.chave = i;
        registro.dado1 = rand() % numRegistros;
        for (j = 0; j < 500; j++) {
          aux = 97 + rand() % 26;
          registro.dado2[j] = static_cast<char>(aux);
        }
        fwrite(&registro, sizeof(TipoRegistro), 1, arq);
      }
    }
    else if (cresDecresAlea == DECRESCENTE){
      for (i = numRegistros-1; i >= 0; i--) {
        registro.chave = i;
        registro.dado1 = rand() % numRegistros;
        for (j = 0; j < 500; j++) {
          aux = 97 + rand() % 26;
          registro.dado2[j] = static_cast<char>(aux);
        }
        fwrite(&registro, sizeof(TipoRegistro), 1, arq);
      }
    }
    else if (cresDecresAlea == ALEATORIO){
      for (i = 0; i < numRegistros; i++) {
        registro.chave = rand() % numRegistros;
        registro.dado1 = rand() % numRegistros;
        for (j = 0; j < 500; j++){
          aux = 97 + rand() % 26;
          registro.dado2[j] = static_cast<char>(aux);
        }
        fwrite(&registro, sizeof(TipoRegistro), 1, arq);
      }
    }
  
  fclose(arq);
  return 1;
}
