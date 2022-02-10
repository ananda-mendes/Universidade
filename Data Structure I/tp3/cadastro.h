#ifndef CADASTRO_H
#define CADASTRO_H


typedef struct cadastro Cadastro;
Cadastro* criar_funcionario (char nome[50], int telefone, char funcao[50]);
int comparacao(char chave[50], Cadastro* c);
void copiar_dados(Cadastro* palavraRecebe, Cadastro* palavraDoa);
void deleta_dados(Cadastro* c);
void imprimir (Cadastro* c);
#endif
