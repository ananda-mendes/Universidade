#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "times.h"

struct times {
	char nome[16];
	int qtdJogos;
	int golsMarcados;
	int golsSofridos;
	int pontos;
};

//Cria um vetor de times 
Times* criarTimes (int t) {
	Times* times = malloc (t * sizeof (Times));
	for (int i=0; i < t; i++) {
		scanf ("%s", times[i].nome);
		times[i].qtdJogos = 0;
		times[i].golsMarcados = 0;
		times[i].golsSofridos = 0;
		times[i].pontos = 0;
	}
	return times;
}

//ler os resultados e guarda nas variaveis especificas
void lerResultados (Times* times, int t, int g) {
	char time1[16], time2[16];
	int golsT1, golsT2;
	char travessao; 
	for (int i=0; i < g; i++) {
		scanf ("%s %d %c %d %s", time1, &golsT1, &travessao, &golsT2, time2);
		for (int j=0; j < t; j++) {
			if (strcmp (time1,times[j].nome) == 0) {
				times[j].qtdJogos++;
				times[j].golsMarcados += golsT1;
				times[j].golsSofridos += golsT2;
				if (golsT1 > golsT2) {
					times[j].pontos += 3;
				}
				else if (golsT1 == golsT2) {
					times[j].pontos += 1;
				}
			}
			if (strcmp (time2, times[j].nome) == 0) {
				times[j].qtdJogos++;
				times[j].golsMarcados += golsT2;
				times[j].golsSofridos += golsT1;
				if (golsT2 > golsT1) {
					times[j].pontos += 3;
				}
				else if (golsT2 == golsT1) {
					times[j].pontos += 1;
				}
			}
		}
	}
}

//imprime a classificacao
void imprimirClassificacao (Times* times, int t) {	
	//funcoes de ordenar por pontos
	mergeSortPontos (times, t);
	
	double porcentagem;
	printf ("\n");

	for (int i = 0; i < t; i++) {
		for (int j = i+1; j <= t; j++) {
			//se os pontos forem iguais ordena por saldo
			if (times[i].pontos == times[j].pontos) {
				mergeSortSaldo (times, i, t-j+1);
				//se saldo for igual ordena por gols marcados
				if ((times[i].golsMarcados - times[i].golsSofridos) == (times[j].golsMarcados - times[j].golsSofridos)) {
					mergeSortGolsMarcados (times, i, j+1); 
					
				} 
			} 
		}
	}
	
	for (int i=0; i < t; i++) {
		for (int j = i+1; j <= t; j++) {
			//verifica se o time jogou ou nao 
			if (times[i].qtdJogos != 0) {
				porcentagem = (times[i].pontos * 100.0)/(times[i].qtdJogos*3.0);
				if (times[i].pontos == times[j].pontos && times[i].qtdJogos == times[j].qtdJogos && times[i].golsMarcados == times[j].golsMarcados && times[i].golsSofridos == times[j].golsSofridos &&  (times[i].golsMarcados - times[i].golsSofridos) == (times[j].golsMarcados - times[j].golsSofridos)) {
					//se tudo for igual imprime por ordem alfabetica
					if (strcmp (times[i].nome, times[j].nome) < 0) { 
						printf ("%d.\t%20s",i+1, times[i].nome);	
						printf ("\t%2d %2d %2d %2d %2d %6.2lf\n", times[i].pontos, times[i].qtdJogos, times[i].golsMarcados, times[i].golsSofridos, times[i].golsMarcados - times[i].golsSofridos, porcentagem);
					
						printf ("\t%20s", times[j].nome);	
						printf ("\t%2d %2d %2d %2d %2d %6.2lf\n", times[j].pontos, times[j].qtdJogos, times[j].golsMarcados, times[j].golsSofridos, times[j].golsMarcados - times[j].golsSofridos, porcentagem);
						i++;
						break;
					}
					else  {
						printf ("%d.\t%20s",i+1, times[j].nome);	
						printf ("\t%2d %2d %2d %2d %2d %6.2lf\n", times[j].pontos, times[j].qtdJogos, times[j].golsMarcados, times[j].golsSofridos, times[j].golsMarcados - times[j].golsSofridos, porcentagem);
					
						printf ("\t%20s", times[i].nome);	
						printf ("\t%2d %2d %2d %2d %2d %6.2lf\n", times[i].pontos, times[i].qtdJogos, times[i].golsMarcados, times[i].golsSofridos, times[i].golsMarcados - times[i].golsSofridos, porcentagem);
						i++;
						break;
					} 
				}
				else {
					printf ("%d.\t%20s",i+1, times[i].nome);	
					printf ("\t%2d %2d %2d %2d %2d %6.2lf\n", times[i].pontos, times[i].qtdJogos, times[i].golsMarcados, times[i].golsSofridos, times[i].golsMarcados - times[i].golsSofridos, porcentagem);
					break;
				} 
			}
			else {
				if (times[i].pontos == times[j].pontos && times[i].qtdJogos == times[j].qtdJogos && times[i].golsMarcados == times[j].golsMarcados && times[i].golsSofridos == times[j].golsSofridos &&  (times[i].golsMarcados - times[i].golsSofridos) == (times[j].golsMarcados - times[j].golsSofridos)) {
					//se tudo for igual imprime por ordem alfabetica
					if (strcmp (times[i].nome, times[j].nome) < 0) { 
						printf ("%d.\t%20s",i+1, times[i].nome);	
						printf ("\t%2d %2d %2d %2d %2d    N/A\n", times[i].pontos, times[i].qtdJogos, times[i].golsMarcados, times[i].golsSofridos, times[i].golsMarcados - times[i].golsSofridos);
					
						printf ("\t%20s", times[j].nome);	
						printf ("\t%2d %2d %2d %2d %2d    N/A\n", times[j].pontos, times[j].qtdJogos, times[j].golsMarcados, times[j].golsSofridos, times[j].golsMarcados - times[j].golsSofridos);
						i++;
						return;
					}
					else  {
						printf ("%d.\t%20s",i+1, times[j].nome);	
						printf ("\t%2d %2d %2d %2d %2d   N/A\n", times[j].pontos, times[j].qtdJogos, times[j].golsMarcados, times[j].golsSofridos, times[j].golsMarcados - times[j].golsSofridos);
					
						printf ("\t%20s", times[i].nome);	
						printf ("\t%2d %2d %2d %2d %2d    N/A\n", times[i].pontos, times[i].qtdJogos, times[i].golsMarcados, times[i].golsSofridos, times[i].golsMarcados - times[i].golsSofridos);
						i++;
						break;
					} 
				}
				else {
					printf ("%d.\t%20s",i+1, times[i].nome);	
					printf ("\t%2d %2d %2d %2d %2d    N/A\n", times[i].pontos, times[i].qtdJogos, times[i].golsMarcados, times[i].golsSofridos, times[i].golsMarcados - times[i].golsSofridos);
					break;
				}
			}
		
		}
	} 
	
}


//Ordena de forma decrescente os times de acordo com os pontos
void mergeSortPontos (Times* times, int t) {
	mergeSort_ordenaPontos (times, 0, t-1);
}
void mergeSort_ordenaPontos (Times* times, int esq , int dir) {
	if (esq >= dir) {
		return;
	}
	int meio = (esq + dir)/2;
	mergeSort_ordenaPontos (times, esq, meio);
	mergeSort_ordenaPontos (times, meio+1, dir);
	mergeSort_intercalaPontos (times, esq, meio, dir);
	return;
}
void mergeSort_intercalaPontos (Times* times, int esq, int meio, int dir) {
	int i, j, k;
	int a_tam = meio - esq +1;
	int b_tam = dir - meio;
	Times* a =  malloc (a_tam * sizeof (Times));
	Times* b =  malloc (b_tam * sizeof (Times));
	for (i = 0; i < a_tam; i ++) {
		a[i] = times[i+esq];
	}
	for (i = 0; i < b_tam; i ++) {
		b[i] = times[i+ meio+1];
	}
	for (i = 0, j = 0, k = esq; k <= dir; k++) {
		if (i == a_tam) {
			times[k] = b[j++];
		}
		else if (j == b_tam) {
		
			times[k] = a[i++];
		}
		else if (a[i].pontos > b[j].pontos ) {
			times[k] = a[i++];
		}
		else {
			times[k] = b[j++];
		}
	}
	free (a);
	free (b); 
}

//ordena de forma decrescente os times de acordo com o saldo
void mergeSortSaldo(Times* times, int pos_inicial, int pos_final) {
	mergeSort_ordenaSaldo (times, pos_inicial, pos_final-1);
}
void mergeSort_ordenaSaldo (Times* times, int esq , int dir) {
	if (esq >= dir) {
		return;
	}
	int meio = (esq + dir)/2;
	mergeSort_ordenaSaldo (times, esq, meio);
	mergeSort_ordenaSaldo (times, meio+1, dir);
	mergeSort_intercalaSaldo (times, esq, meio, dir);
	return;
}
void mergeSort_intercalaSaldo (Times* times, int esq, int meio, int dir) {
	int i, j, k;
	int a_tam = meio - esq +1;
	int b_tam = dir - meio;
	Times* a =  malloc (a_tam * sizeof (Times));
	Times* b =  malloc (b_tam * sizeof (Times));
	for (i = 0; i < a_tam; i ++) {
		a[i] = times[i+esq];
	}
	for (i = 0; i < b_tam; i ++) {
		b[i] = times[i+ meio+1];
	}
	for (i = 0, j = 0, k = esq; k <= dir; k++) {
		if (i == a_tam) {
			times[k] = b[j++];
		}
		else if (j == b_tam) {
		
			times[k] = a[i++];
		}
		else if ((a[i].golsMarcados - a[i].golsSofridos) > (b[j].golsMarcados - b[j].golsSofridos) ) {
			times[k] = a[i++];
		}
		else {
			times[k] = b[j++];
		}
	}
	free (a);
	free (b); 
}



//ordena de forma decrescente os times de acordo com os gols marcados
void mergeSortGolsMarcados(Times* times, int pos_inicial, int pos_final) {
	mergeSort_ordenaGolsMarcados (times, pos_inicial, pos_final-1);
}
void mergeSort_ordenaGolsMarcados (Times* times, int esq , int dir) {
	if (esq >= dir) {
		return;
	}
	int meio = (esq + dir)/2;
	mergeSort_ordenaGolsMarcados (times, esq, meio);
	mergeSort_ordenaGolsMarcados (times, meio+1, dir);
	mergeSort_intercalaGolsMarcados (times, esq, meio, dir);
	return;
}
void mergeSort_intercalaGolsMarcados (Times* times, int esq, int meio, int dir) {
	int i, j, k;
	int a_tam = meio - esq +1;
	int b_tam = dir - meio;
	Times* a =  malloc (a_tam * sizeof (Times));
	Times* b =  malloc (b_tam * sizeof (Times));
	for (i = 0; i < a_tam; i ++) {
		a[i] = times[i+esq];
	}
	for (i = 0; i < b_tam; i ++) {
		b[i] = times[i+ meio+1];
	}
	for (i = 0, j = 0, k = esq; k <= dir; k++) {
		if (i == a_tam) {
			times[k] = b[j++];
		}
		else if (j == b_tam) {
		
			times[k] = a[i++];
		}
		else if (a[i].golsMarcados > b[j].golsMarcados ) {
			times[k] = a[i++];
		}
		else {
			times[k] = b[j++];
		}
	}
	free (a);
	free (b); 
}


