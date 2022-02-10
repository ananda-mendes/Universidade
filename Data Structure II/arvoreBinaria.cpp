#include "header.h"

//CRIANDO UMA ÁRVORE VAZIA
bool criaArvoreBinaria (string caminho, int& numero_transferencias, int& numero_comparacoes) {
    FILE* entrada, *saida;
    //VARIÁVEL AUXILIAR PARA ESCRITA EM ARQUIVO
    ArvoreBinaria arvore_write;
    //VARIÁVEL AUXILIAR PARA LEITURA EM ARQUIVO
    TipoRegistro registro;
    //VARIÁVEL AUXILIAR PARA GUARDAR A POSIÇÃO E CHAVE DO NÓ INSERIDO
    TipoIndice indice; 
    indice.posicao = 0;
    bool insira = false;

    entrada = fopen(caminho.c_str(), "rb");

    saida = fopen("ArvoreBinariaExterna.bin", "w+b");
    if (entrada == NULL || saida == NULL) {
        return false;
    }

    while (fread(&registro, sizeof(TipoRegistro), 1, entrada) == 1){
        numero_transferencias++;
        //INICIALIZA AS FOLHAS DO NÓ A SER INSERIDO
        arvore_write.ponteiroDir = -1;
        arvore_write.ponteiroEsq = -1;

        arvore_write.registro = registro;
        //SALVA A CHAVE E POSIÇÃO DO NÓ A SER INSERIDO
        indice.chave = arvore_write.registro.chave;

        if (ftell(saida) != 0) {
            indice.posicao = ftell(entrada)/sizeof(ArvoreBinaria);

            //VOLTANDO COM O PONTEIRO PARA O INÍCIO DO ARQUIVO
            rewind(saida);

            //VERIFICA SE O ELEMENTO É UNICO NA ÁRVORE
            if (indice.posicao != 0) {
                insira = organizaArvoreBinaria(saida, &indice, numero_transferencias, numero_comparacoes);
            }

            //VOLTA O PONTEIRO DO ARQUIVO PRO FINAL PARA CONTINUAR A INSERÇÃO
            if (fseek(saida, sizeof(ArvoreBinaria)*(indice.posicao), SEEK_SET) != 0) {
                break;
            }
            
            //VERIFICA SE O ELEMENTO EXISTE NA ARVORE
            if(insira) {
                fwrite(&arvore_write, sizeof(ArvoreBinaria), 1, saida);
                numero_transferencias++;
            }
        }
        //SE FOR O PRIMEIRO ITEM DA ÁRVORE 
        else {
            fwrite(&arvore_write, sizeof(ArvoreBinaria), 1, saida);
            numero_transferencias++;
        }

    }
    fclose(entrada);
    fclose(saida);
    return true;
    
}


bool organizaArvoreBinaria (FILE* saida, TipoIndice* indice, int& numero_transferencias, int& numero_comparacoes) {
    //VARIÁVEL AUXILIAR PARA LEITURA EM ARQUIVO
    ArvoreBinaria arvore_read;
    bool inseriu = false;
    //SALVA A POSIÇÃO DO NÓ PAI PARA SOBRESCREVER COM A POSIÇÃO DOS FILHOS
    TipoIndice aux;

    //SE NÓ PAI AINDA NÃO FOI ATRIBUÍDO AO NÓ INSERIDO, LÊ O PRIMEIRO ITEM
    while (!inseriu) {
        aux.posicao = ftell(saida);

        if (aux.posicao != 0) {
            aux.posicao = aux.posicao / sizeof(ArvoreBinaria);
        }

        if (fread(&arvore_read, sizeof(ArvoreBinaria), 1, saida) != 1) {
            numero_transferencias++;
            break;
        }

        if (indice->chave == arvore_read.registro.chave) {
            numero_comparacoes++;
            inseriu = false;
            break;
        }

        //VAI PARA DIREITA 
        if (indice->chave > arvore_read.registro.chave) {
            numero_comparacoes++;
            //VAI PARA DIREITA
            //NÓ NÃO ESTÁ OCUPADO
            if (arvore_read.ponteiroDir == -1) { 

                //SOBREESCREVE O -1 COM A POSIÇÃO DO FILHO
                arvore_read.ponteiroDir = indice->posicao;

                //POSICIONA O PONTEIRO DO ARQUIVO PARA SOBREESCREVER O NÓ PAI COM A POSIÇÃO DO FILHO
                fseek(saida, sizeof(ArvoreBinaria) * aux.posicao, SEEK_SET);

                fwrite (&arvore_read, sizeof(ArvoreBinaria), 1, saida);
                numero_transferencias++;
                inseriu = true;
                break;

            }
            //NÓ OCUPADO = POSICIONA O PONTEIRO NESSE NÓ E CHAMA RECURSIVAMENTE A FUNÇÃO PARA CONTINUAR PROCURANDO
            else {
                fseek(saida, sizeof(ArvoreBinaria) * arvore_read.ponteiroDir, SEEK_SET);
            }
        }
        else {
            //VAI PARA ESQUERDA
            if (indice->chave < arvore_read.registro.chave) {
                numero_comparacoes++;
                //VAI PARA ESQUERDA
                //NÓ NÃO ESTÁ OCUPADO
                if (arvore_read.ponteiroEsq == -1) {

                    //SOBREESCREVE O -1 COM A POSIÇÃO DO FILHO
                    arvore_read.ponteiroEsq = indice->posicao;

                    //POSICIONA O PONTEIRO DO ARQUIVO PARA SOBREESCREVER O NÓ PAI COM A POSIÇÃO DO FILHO
                    fseek(saida, sizeof(ArvoreBinaria) * aux.posicao, SEEK_SET);

                    fwrite(&arvore_read, sizeof(ArvoreBinaria), 1, saida);
                    numero_transferencias++;
                    inseriu = true;
                    break;
                }
                //NÓ OCUPADO = POSICIONA O PONTEIRO NESSE NÓ E CHAMA RECURSIVAMENTE A FUNÇÃO PARA CONTINUAR PROCURANDO
                else {
                    fseek(saida, sizeof(ArvoreBinaria) * arvore_read.ponteiroEsq, SEEK_SET);

                }
            }
            //SE CHEGOU ATÉ AQUI: ARQUIVO VAZIO OU CHAVE IGUAL JÁ NA ÁRVORE
        }
    }
    return inseriu;
}

void leArvore () {
    FILE* saida;
    saida = fopen("ArvoreBinariaExterna.bin", "r+b");
    ArvoreBinaria arvore_read;
    int cont = 0;

    while (fread(&arvore_read, sizeof(ArvoreBinaria), 1, saida) == 1) {
        cout << "[" << cont << "] - " << arvore_read.ponteiroEsq 
        << "|" << arvore_read.registro.chave 
        << "|" << arvore_read.ponteiroDir << endl;
        cont++;
    }
    fclose(saida);
}

int pesquisaArvoreBinaria(FILE* saida, TipoRegistro *registro, int& numero_transferencias, int& numero_comparacoes) {
    ArvoreBinaria arvore_read;

    while (fread(&arvore_read, sizeof(ArvoreBinaria), 1, saida) == 1) {
        numero_transferencias++;
        if (arvore_read.registro.chave == registro->chave) {
            numero_comparacoes++;
            *registro = arvore_read.registro;
            return 1;
        }
        else {
            if (registro->chave > arvore_read.registro.chave) {
                numero_comparacoes++;
                if (arvore_read.ponteiroDir != -1) {
                    fseek(saida, sizeof(ArvoreBinaria) * arvore_read.ponteiroDir, SEEK_SET);
                }
                else {
                    return 0;
                }
            }
            else {
                if (registro->chave < arvore_read.registro.chave) {
                    numero_comparacoes++;
                    if (arvore_read.ponteiroEsq != -1) {
                        fseek(saida, sizeof(ArvoreBinaria) * arvore_read.ponteiroEsq, SEEK_SET);
                    }
                    else {
                        return 0;
                    }
                    
                }
            }
        }
    }
    return 0;
} 