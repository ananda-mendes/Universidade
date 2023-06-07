#include "memoria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	Instrucao** inst = alocaInstrucao(TAM_INST_GERADOR);
	lerInstrucao(inst);
	criarArquivo();
	Taxas* taxas = criarTaxas();

	Memoria** RAM = alocarMemoria(TAM_RAM);
	Memoria** cacheUm = alocarMemoria(TAM_C1);
	Memoria** cacheDois = alocarMemoria(TAM_C2);
	Memoria** cacheTres = alocarMemoria(TAM_C3);

	//preencherRam(RAM);
	processador(inst, cacheUm, cacheDois, cacheTres, RAM, taxas);

	limpaMemoria(cacheUm, TAM_C1);
	limpaMemoria(cacheDois, TAM_C2);
	limpaMemoria(cacheTres, TAM_C3);

	printf("\n\tCACHE HIT CACHE 1: %d", getHitC1(taxas));
	printf("\t\tCACHE MISS CACHE 1: %d\n", getMissC1(taxas));
	printf("\tCACHE HIT CACHE 2: %d", getHitC2(taxas));
	printf("\t\tCACHE MISS CACHE 2: %d\n", getMissC2(taxas));
	printf("\tCACHE HIT CACHE 3: %d", getHitC3(taxas));
	printf("\t\tCACHE MISS CACHE 3: %d\n", getMissC3(taxas));
	printf ("\tCACHE HIT RAM: %d\n", getHitRam (taxas));
	printf("\tCACHE HIT HD: %d\n", getHitHd(taxas));
	printf("\n\tTOTAL DE HIT: %d", getHitC1(taxas) + getHitC2(taxas) + getHitC3(taxas) + getHitRam (taxas) + getHitHd(taxas));
	printf("\tTOTAL DE MISS: %d\n", getMissC1(taxas) + getMissC2(taxas) + getMissC3(taxas) + getMissRam(taxas));
	
	liberarMemoria(cacheUm, TAM_C1);
	liberarMemoria(cacheDois, TAM_C2);
	liberarMemoria(cacheTres, TAM_C3);
	liberarMemoria(RAM, TAM_RAM);
	return 0;
}
