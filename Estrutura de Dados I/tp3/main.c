//Ananda Mendes Souza 19.1.4030


#include "huffman.h"
#include "hash.h"
#include "cadastro.h"
#define listas 26
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

void questao1 ();
void questao2 ();
int main()
{
	questao1 ();
	questao1();
    questao2 ();
    return 0;
}

void questao1 () {
	int opcao;
	char nome[50];
	scanf ("%d", &opcao);
	scanf ("%s", nome);
	if (opcao == 1)
        CompressFile(nome, "huffman.bin");

    else if (opcao == 2) {
        if (strstr(nome, ".bin"))
            DecompressFile(nome, "huffman.txt");

        else
			printf ("Erro ao ler o arquivo\n");
    } else {
		printf ("Opcao invalida\n");
	}
}

void questao2 () {
	Hash* hash= criar_hash();
	Cadastro* c;
	THash_Inicia (hash,listas);
	int op;
	char nome[50], funcao[50];
	int telefone;
	do{
		/* printf ("\nMENU DE ACESSO \n");
		printf ("1 - Insercao\n");
		printf ("2 - Remocao\n");
		printf ("3 - Buscar por letra\n");
		printf ("4 - Buscar por nome\n");
		printf ("5 - Atualizar dados\n");
		printf ("0 - Sair\n");
		printf ("Opcao: "); */
		scanf ("%d", &op);
		switch (op){
			case 1:
				//printf ("\nDigite nome do funcionario: ");
				scanf ("%s", nome);
				//printf ("\nDigite telefone: ");
				scanf ("%d", &telefone);
				//printf ("\nDigite funcao: ");
				scanf ("%s", funcao);
				c = criar_funcionario (nome,telefone,funcao);
				//transforma a primeira letra em maiuscula
				nome[0]=toupper(nome[0]);
				
				if(THash_insere(hash,nome,telefone,funcao)) {
					printf ("\nFuncionario inserido\n");
				}
				else {
					printf ("\nFuncionario ja existe\n");
				}
				break;
			case 2:
				//printf ("\nDigite nome do funcionario: ");
				scanf ("%s", nome);
	        	nome[0] = toupper(nome[0]);
				if(hash_remove (hash,nome)) {
					printf ("\nFuncionario excluido com sucesso\n");
				}
				else {
					printf ("\nFuncionario nao encontrado\n");
				}
				break;
			case 3:
				//printf ("\nDigite uma letra: ");
				scanf ("%c", nome);
		        nome[0]=toupper(nome[0]);
				hash_imprimir (hash,nome);
				break;

			case 4:
				//printf ("\nDigite nome do funcionário: ");
				scanf ("%s", nome);
		        nome[0]=toupper(nome[0]);
				if(buscar_dado(hash,nome,c))
					imprimir(c);
				else
					printf ("\nFuncionario nao encontrado\n");
				break;

			case 5:
				//printf ("\nDigite nome do funcionario: ");
				scanf ("%s", nome);
				printf ("\nDigite telefone: ");
				scanf ("%d", &telefone);
				printf ("\nDigite funcao: ");
				scanf ("%s", funcao);
		        nome[0]=toupper(nome[0]);
				if(hash_atualiza(hash,nome,telefone,funcao))
					printf ("\nAtualizado com sucesso\n");
				else
					printf ("\nFuncionário não encontrado\n");
				break;
		}
	}while (op!=0);
	hash_delete(hash);
	deleta_dados (c);
}
