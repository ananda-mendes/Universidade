#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "quadrado.h"
#include "losango.h"
#include "trapezio.h"
#include "times.h"
#include "fila.h"

void questao1 ();
void insereObjeto (Pilha*);
void atualizarObjeto (ListaNo*);

void questao2();
void questao3();


int main()
{
	int opcao;
	do {
	/*	printf ("\n1- Questao 1");
		printf ("\n2- Questao 2");
		printf ("\n3- Questao 3");
		printf ("\n0- Sair");
		printf ("\nEscolha uma opcao: "); */
		scanf ("%d", &opcao);
		switch (opcao) {
			case 1: 
				questao1();
				break;
			case 2: 
				questao2();
				break;
			case 3: 
				questao3();
				break; 
			default:
				break;
		}
	} while (opcao != 0);
	
	return 0;
}

void questao1() {
	Pilha* p = criarPilha ();
	
	
	int opcao;
	int retorno; 
	
	do {
	/*	printf ("\n1- Insere elemento na pilha");
		printf ("\n2- Remove elemento da pilha");
		printf ("\n3- Verifica se a pilha esta vazia");
		printf ("\n4- Esvaziar a pilha");
		printf ("\n5- Calcular area");
		printf ("\n6- Alterar objeto");
		printf ("\n0- Sair");
		printf ("\nEscolha uma opcao: "); */
		scanf ("%d", &opcao);
		
		switch (opcao) {
			case 1:
				insereObjeto (p);
				break;
			case 2:
				retorno = pilhaPop (p);
				if (retorno == 1) {
					printf ("\nRemovido com sucesso!\n");
				}
				else {
					printf ("\nNao foi possivel remover pois a pilha esta vazia\n");
				}
				break;
			case 3: 
				retorno = verificarPilha (p);
				if (retorno == 1) {
					printf ("\nA pilha esta vazia\n");
				}
				else {
					printf ("\nA pilha possui elementos\n");
				}
				break;
			case 4: {
				int aux=1;
				retorno = verificarPilha (p);
				while (retorno != 1 && aux != 0) {
					aux = pilhaPop (p);
					retorno = verificarPilha(p);
				}
				printf ("\nPilha esvaziada\n");
			}
				break;
			case 5:
				area(p);
				break;
			case 6: {
				atualizarObjeto (getProxPilha(p));
			}
				break;
			default: 
				break;
		}		
	} while (opcao != 0);
	liberarPilha (p);
}

//insere objeto na pilha 
void insereObjeto (Pilha* p) {
	int tipo;
/*	printf ("\n0- Quadrado");
	printf ("\n1- Losango");
	printf ("\n2- Trapezio");
	printf ("\nQual objeto deseja inserir? "); */
	scanf ("%d", &tipo);
	
	switch (tipo) {
		case 0: {
			float lado;
			//printf ("\nLado: ");
			scanf ("%f", &lado);
			
			Quadrado* q = criarQuadrado (lado);
			pilhaPush (p, tipo, q);
			
		}
			break;
		case 1: {
			float Dmaior, dMenor;
			//printf ("\nDiagonal maior: ");
			scanf ("%f", &Dmaior);
			//printf ("Diagonal menor: ");
			scanf ("%f", &dMenor);
			
			Losango* l = criarLosango (Dmaior, dMenor);
			pilhaPush (p, tipo, l);
		}
			break;
		case 2: {
			float Bmaior, bMenor, altura;
			//printf ("\nBase maior: ");
			scanf ("%f", &Bmaior);
			//printf ("Base menor: ");
			scanf ("%f", &bMenor);
			//printf ("Altura: ");
			scanf ("%f", &altura);
			
			Trapezio* t = criarTrapezio (Bmaior, bMenor, altura);
			pilhaPush (p, tipo, t);
		}
			break;
		default: 
			break;
	}
}

//atualiza o objeto que esta no topo
void atualizarObjeto (ListaNo* n) {
	switch (getObjetoPilha(n)) {
		case QUA: {
			float lado;
			//printf ("\nLado: ");
			scanf ("%f", &lado);
			
			Quadrado *q = (Quadrado*) getInfoPilha(n);
			setLadoQuadrado (q, lado);
		}
			break;
		case LOS: {
			float Dmaior, dMenor;
			//printf ("\nDiagonal maior: ");
			scanf ("%f", &Dmaior);
			//printf ("Diagonal menor: ");
			scanf ("%f", &dMenor);
			
			
			Losango* l = (Losango*) getInfoPilha(n);
			setDiagonalMaiorLosango (l, Dmaior);
			setDiagonalMenorLosango (l, dMenor);
		}
			break;
		case TRAP: {
			float Bmaior, bMenor, altura;
			//printf ("\nBase maior: ");
			scanf ("%f", &Bmaior);
			//printf ("Base menor: ");
			scanf ("%f", &bMenor);
			//printf ("Altura: ");
			scanf ("%f", &altura);
			
			Trapezio* t = (Trapezio*) getInfoPilha(n);
			setBaseMaiorTrapezio (t, Bmaior);
			setBaseMenorTrapezio (t, bMenor);
			setAlturaTrapezio (t, altura);
		}
			break;
		default:
			break;
	}
}

void questao2 () {
	int t; //numero de times
	int g; //jogos disputados
	
	scanf ("%d %d", &t, &g);
	
	while (t != 0 && g != 0) {
		if ((t < 1 || t > 28 || g < 0) && t != 0) {
			//printf ("\nEntrada invalida, digite novamente.\n");
			scanf ("%d %d", &t, &g);
			continue;
		}
		else {
			Times* times = criarTimes(t);
			lerResultados (times, t, g);
			imprimirClassificacao (times, t);
			scanf ("%d %d", &t, &g);
		}
	}
}

void questao3 () {
	int id;
	char descricao[50];
	int opcao;
	
	Fila* f = criarFila ();
	
	do {
	/*	printf ("\n1- Insere elemento\n");
		printf ("2- Retira elemento\n");
		printf ("3- Verifica se a fila esta vazia\n");
		printf ("4- Esvaziar fila\n");
		printf ("5- Imprimir conteudo da fila\n");
		printf ("0- Sair\n");
		printf ("Escolha uma opcao: "); */
		scanf ("%d", &opcao);
		switch (opcao) {
			case 1: {
		//		printf ("Digite um identificador e uma descricao: ");
				scanf ("%d\n", &id);
				fgets (descricao, 50, stdin);
				insereFila (f, id, descricao);
			}
				break;
			case 2: 
				retiraFila (f);
				break;
			case 3: {				
				int teste = verificaFila (f);
				if (teste == 1) {
					//printf ("\nFila vazia\n");
				}
				else {
					//printf ("\nA fila possui elementos\n");
				}
			}
				break;
			case 4: 
				liberaFila (f);
				break;
			case 5: 
				imprimirConteudo (f);
				break;
			default: 
				break;
		}
	} while (opcao != 0);
	
	
} 
