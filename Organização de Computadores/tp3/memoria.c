#include "memoria.h"
//#include "tp1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct memoria{
	int endBloco;
	int palavras[4];
	int nAcessos;
	int atualizado; //0 é falso e 1 é verdadeiro
	
};

struct taxas{
	int Miss_c1, Hit_c1;
	int Miss_c2, Hit_c2;
	int Miss_c3, Hit_c3;
	int Miss_ram, Hit_ram;
	int Hit_hd;
	long long int custo;
};

//varios blocos
Memoria** alocarMemoria(int tamanho){
	Memoria** memoria = malloc (tamanho * sizeof (Memoria*));

	for(int i = 0; i < tamanho; i++){
		memoria[i] = malloc (sizeof (Memoria));;
		memoria[i]->endBloco = -1;
		for(int j = 0; j < TAM_BLOCO; j++) {
			memoria[i]->palavras[j] = 0;
		}
		memoria[i]->nAcessos = 0;
		memoria[i]->atualizado = 0;
	}

	return memoria;
}

//apenas um bloco
Memoria* alocarVetor(){
	Memoria* memoria = malloc (1 * sizeof (Memoria));

	memoria[0].endBloco = -1;
	for(int i = 0; i < TAM_BLOCO; i++)
		memoria[0].palavras[i] = 0;
	memoria[0].nAcessos = 0;
	memoria[0].atualizado = 0;

	return memoria;
}

Taxas* criarTaxas(){
	Taxas* taxas = malloc (sizeof (Taxas));

	taxas->Miss_c1 = 0;
	taxas->Hit_c1 = 0;
	taxas->Miss_c2 = 0;
	taxas->Hit_c2 = 0;
	taxas->Miss_c3 = 0;
	taxas->Hit_c3 = 0;
	taxas->Hit_ram = 0;
	taxas->Miss_ram = 0;
	taxas->Hit_hd = 0;
	taxas->custo = 0;

	return taxas;
}

void preencherRam(Memoria** ram){
	srand(time(NULL));
	for(int i = 0; i < TAM_RAM; i++){
		for(int j = 0; j < TAM_BLOCO; j++)
			ram[i]->palavras[j] = rand() % 10;
	}
}

void criarArquivo () {
	Memoria HD;
	FILE* bin = fopen ("instrucoesBin.txt", "wb");

	for(int i = 0; i < TAM_HD; i++){
		HD.endBloco = rand() % 100;
	
		for(int i = 0; i < TAM_BLOCO; i++) {
			HD.palavras[i] = 1 + rand() % 10;
		}
		HD.nAcessos = 0;
		HD.atualizado = 0;

		fwrite ((char*)&HD, sizeof(Memoria),1, bin);
	}
	fclose(bin);
}
    
int buscarCache(Endereco* e, Memoria** cache, int tam_cache){ 
	//verifica a existencia do endereco para cada bloco dentro de uma cache
	for(int i = 0; i < tam_cache; i++) {
		if(cache[i]->endBloco == getEndBloco(e)){
			setAcesso(cache[i], 1);
			return i;
		}
	}
	return -1;
}

void insereCache(int valor, Memoria** memoria, Endereco* e){

	for(int i = 0; i < TAM_C1; i++){
		if(memoria[i]->endBloco == getEndBloco(e)){
			memoria[i]->palavras[getEndPalavra(e)] = valor;
			memoria[i]->nAcessos = 0;
			memoria[i]->atualizado = 1;
			break;
		}
	}
}

void trocarCache(int endBloco, Memoria** cOrigem, int tam_cOrigem, Memoria** cDestino, int tam_cDestino){
	int indice = 0; 
	int menorAcesso = cDestino[0]->nAcessos;
	
	for(int i = 0; i < tam_cDestino; i++){
		if(cDestino[i]->endBloco == -1){
			indice = i;
			break;
		} 
		else if(cDestino[i]->nAcessos < menorAcesso){
			menorAcesso = cDestino[i]->nAcessos;
			indice = i;
		} 
	}

	for(int i = 0; i < tam_cOrigem; i++){
		if(cOrigem[i]->endBloco == endBloco){
			Memoria* aux;
			aux = cDestino[indice];
			cDestino[indice] = cOrigem[i];
			cOrigem[i] = aux;
			cDestino[indice]->nAcessos = 0;
			cDestino[indice]->atualizado = 0;
			break;
		}
	}
}

void trocarRam(int endBloco, Memoria** ram, int tam_ram, Memoria** cDestino, int tam_cDestino){
	int indice = 0;
	int menorAcesso = cDestino[0]->nAcessos;

	for(int i = 0; i < tam_cDestino; i++){
		if(cDestino[i]->endBloco == -1){
			indice = i;
			break;
		} 
		else if((cDestino[i]->nAcessos) < menorAcesso){
			menorAcesso = cDestino[i]->nAcessos;
			indice = i;
		} 
		
	}
	if(cDestino[indice]->atualizado == 1){
		Memoria* aux;
		aux = cDestino[indice];
		cDestino[indice] = ram[endBloco];
		ram[endBloco] = aux;
		setEndBlocoM(cDestino[indice], endBloco);
		for(int k = 0; k < TAM_BLOCO; k++){
			setPalavra(cDestino[indice], k, getPalavra(ram[endBloco], k));
		}
		setAcesso(cDestino[indice], 0);
	} else {
		setEndBlocoM(cDestino[indice], endBloco);
		for(int k = 0; k < TAM_BLOCO; k++){
			setPalavra(cDestino[indice], k, getPalavra(ram[endBloco], k));
		}
		setAcesso(cDestino[indice], 0);
	}
}

void trocarHd (int endBloco, Memoria** ram, int tam_ram) {
	int indice = 0;
	int menorAcesso = ram[0]->nAcessos;
	FILE* HD;
	int w0, w1, w2, w3;
	int r0, r1, r2, r3;

	HD = fopen("instrucoesBin.txt", "rb");
	long desloc = endBloco * sizeof(int) * 4;
	fseek(HD, desloc, SEEK_SET);
	fread(&w0, sizeof(int), 1, HD);
	fread(&w1, sizeof(int), 1, HD);
	fread(&w2, sizeof(int), 1, HD);
	fread(&w3, sizeof(int), 1, HD);
	rewind(HD);
	fclose(HD);
	
	for(int i = 0; i < tam_ram; i++){
		if(ram[i]->endBloco == -1){
			indice = i;
			break;
		} else if(ram[i]->endBloco < menorAcesso){
			menorAcesso = ram[i]->nAcessos;
			indice = i;
		} 
	}
    
    if(ram[indice]->atualizado){
		HD = fopen("instrucoesBin.txt", "wb");
		long desloc = endBloco * sizeof(int) * 4;
		fseek(HD, desloc, 0);
		r0 = ram[indice]->palavras[0];
		r1 = ram[indice]->palavras[1];
		r2 = ram[indice]->palavras[2];
		r3 = ram[indice]->palavras[3];
		fwrite(&r0, sizeof(int), 1,HD);
		fwrite(&r1, sizeof(int), 1, HD);
		fwrite(&r2, sizeof(int), 1, HD);
		fwrite(&r3, sizeof(int), 1, HD);
		rewind(HD);
		fclose(HD);

	} else {
		ram[indice]->endBloco = endBloco;
		ram[indice]->palavras[0] = w0;
		ram[indice]->palavras[1] = w1;
		ram[indice]->palavras[2] = w2;
		ram[indice]->palavras[3] = w3;
		setAcesso(ram[indice], 0);
	}
}
Memoria* MMU(Memoria** c1, Memoria** c2, Memoria** c3, Memoria** ram, Endereco* e, Taxas* taxas){
	if(buscarCache(e, c1, TAM_C1) != -1){
		setHitC1(taxas, taxas->Hit_c1);
	} else if(buscarCache(e, c2, TAM_C2) != -1){
		setMissC1(taxas, taxas->Miss_c1);
		setHitC2(taxas, taxas->Hit_c2);
		trocarCache(getEndBloco(e), c2, TAM_C2, c1, TAM_C1);
	} else if(buscarCache(e, c3, TAM_C3) != -1){
		setMissC1(taxas, taxas->Miss_c1);
		setMissC2(taxas, taxas->Miss_c2);
		setHitC3(taxas, taxas->Hit_c3);
		trocarCache(getEndBloco(e), c3, TAM_C3, c2, TAM_C2);
		trocarCache(getEndBloco(e), c2, TAM_C2, c1, TAM_C1);
	} else if (buscarCache(e, ram, TAM_RAM) != -1) {
		setMissC1(taxas, taxas->Miss_c1);
		setMissC2(taxas, taxas->Miss_c2);
		setMissC3(taxas, taxas->Miss_c3);
		setHitRam (taxas, taxas->Hit_ram);
		
		trocarRam(getEndBloco(e), ram, TAM_RAM, c3, TAM_C3);
		trocarCache(getEndBloco(e), c3, TAM_C3, c2, TAM_C2);
		trocarCache(getEndBloco(e), c2, TAM_C2, c1, TAM_C1);
	}
	else {
		setMissC1(taxas, taxas->Miss_c1);
		setMissC2(taxas, taxas->Miss_c2);
		setMissC3(taxas, taxas->Miss_c3);
		setMissRam (taxas, taxas->Miss_ram);
		setHitHd (taxas, taxas->Hit_hd);
		
		trocarHd (getEndBloco (e), ram, TAM_RAM);
		trocarRam(getEndBloco(e), ram, TAM_RAM, c3, TAM_C3);
		trocarCache(getEndBloco(e), c3, TAM_C3, c2, TAM_C2);
		trocarCache(getEndBloco(e), c2, TAM_C2, c1, TAM_C1);
	}
	return c1[buscarCache(e, c1, TAM_C1)];
}

void processador(Instrucao** inst, Memoria** Cache1, Memoria** Cache2, Memoria** Cache3, Memoria** RAM, Taxas* taxas){
	int conteudoUm, conteudoDois, conteudoTres = 0, indice = 0, random;
	int cont = 0;
	Memoria* dadoMemoriaEnd1 = alocarVetor();
	Memoria* dadoMemoriaEnd2 = alocarVetor();
	Memoria* dadoMemoriaEnd3 = alocarVetor();
	clock_t Ticks[2];
    Ticks[0] = clock();
    
	while(getOpcode(inst[indice]) != -1){
		switch(getOpcode(inst[indice])){
			case 0:
				dadoMemoriaEnd1 = MMU(Cache1, Cache2, Cache3, RAM, getAdd1(inst[indice]), taxas);
				dadoMemoriaEnd2 = MMU(Cache1, Cache2, Cache3, RAM, getAdd2(inst[indice]), taxas);
				dadoMemoriaEnd3 = MMU(Cache1, Cache2, Cache3, RAM, getAdd3(inst[indice]), taxas);
				
				conteudoUm = getPalavra(dadoMemoriaEnd1, getEndPalavra(getAdd1(inst[indice])));
				conteudoDois = getPalavra(dadoMemoriaEnd2, getEndPalavra(getAdd2(inst[indice])));
				conteudoTres = getPalavra(dadoMemoriaEnd3, getEndPalavra(getAdd3(inst[indice])));
				
				conteudoTres = conteudoUm + conteudoDois;

				insereCache(conteudoTres, Cache1, getAdd3(inst[indice]));

				//printf("\n\tSOMA: %d + %d = %d", conteudoUm, conteudoDois, operacao);
				break;
			case 1:
				dadoMemoriaEnd1 = MMU(Cache1, Cache2, Cache3, RAM, getAdd1(inst[indice]), taxas);
				dadoMemoriaEnd2 = MMU(Cache1, Cache2, Cache3, RAM, getAdd2(inst[indice]), taxas);
				dadoMemoriaEnd3 = MMU(Cache1, Cache2, Cache3, RAM, getAdd3(inst[indice]), taxas);
				
				conteudoUm = getPalavra(dadoMemoriaEnd1, getEndPalavra(getAdd1(inst[indice])));
				conteudoDois = getPalavra(dadoMemoriaEnd2, getEndPalavra(getAdd2(inst[indice])));
				
				conteudoTres = conteudoUm - conteudoDois;
				

				insereCache(conteudoTres, Cache1, getAdd3(inst[indice]));

				//printf("\n\tSUB: %d - %d = %d", conteudoUm, conteudoDois, operacao);
				break;
			default: 
				break;
		}
			random = rand() % 10;
			if(random <= 1) {
				Memoria* dadosMemoriaEnd3 = alocarVetor();
				Instrucao** instru = alocaInstrucao(30);
				lerInterrupcoes(instru);
				
				int Conteudo1, Conteudo2, Conteudo3 = 0, indice1 = 0;
				
				while(getOpcode(inst[indice1]) != -1){
					switch(getOpcode(inst[indice1])){
						case 0:

							dadosMemoriaEnd3 = MMU(Cache1, Cache2, Cache3, RAM, getAdd3(inst[indice1]), taxas);
							Conteudo1 = rand() % 10;
							Conteudo2 = rand() % 10;
							Conteudo3 = getPalavra(dadosMemoriaEnd3, getEndPalavra(getAdd3(inst[indice1])));
							Conteudo3 = Conteudo1 * Conteudo2;
							insereCache(Conteudo3, Cache1, getAdd1(inst[indice1]));
							printf("%d x %d = %d\n", Conteudo1, Conteudo2, Conteudo3);				
							
							break;
						case 1:
							dadosMemoriaEnd3 = MMU(Cache1, Cache2, Cache3, RAM, getAdd3(inst[indice1]), taxas);
							Conteudo1 = rand() % 10;
							Conteudo2 = rand() % 10;
							Conteudo3 = getPalavra(dadosMemoriaEnd3, getEndPalavra(getAdd3(inst[indice1])));
							Conteudo3 = Conteudo1 - Conteudo2;
							insereCache(Conteudo3, Cache1, getAdd1(inst[indice1]));
							printf("%d - %d = %d\n", Conteudo1, Conteudo2, Conteudo3);	
							
							break;
						default:
							break;
					}
					indice1++;
					cont++;
				}
		}

		indice++;
	}
	
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nTempo gasto: %g ms.\n", Tempo);
    printf("Para um total de %d repeticoes\n", cont);
	liberarVetor(dadoMemoriaEnd1);
	liberarVetor(dadoMemoriaEnd2);
}

void limpaMemoria(Memoria** memoria, int tamanho){
	for(int i = 0; i < tamanho; i++){
		memoria[i]->endBloco = -1;
		for(int j = 0; j < TAM_BLOCO; j++)
			memoria[i]->palavras[j] = 0;
		memoria[i]->nAcessos = 0;
	}
}

void liberarMemoria(Memoria** memoria, int tamanho){
	for(int i = 0; i < tamanho; i++){
		free (memoria[i]);
	}
	free (memoria);
}

void liberarVetor(Memoria* memoria){
	free (memoria);
}


// GET E SET
int getEndBlocoM (Memoria* memoria){
	return memoria->endBloco;
}

int getPalavra(Memoria* memoria, int indicePalavra){
	return memoria->palavras[indicePalavra];
}

int getAcesso(Memoria* memoria){
	return memoria->nAcessos;
}

int getAtualizado(Memoria* memoria){
	return memoria->atualizado;
}

void setEndBlocoM (Memoria* memoria, int endBloco){
	memoria->endBloco = endBloco;
}

void setPalavra(Memoria* memoria, int indicePalavra, int palavra){
	memoria->palavras[indicePalavra] = palavra;
}

void setAcesso(Memoria* memoria, int nAcessos){
	memoria->nAcessos += nAcessos;
}

void setAtualizado(Memoria* memoria, int atualizado){
	memoria->atualizado = atualizado;
}

int getHitC1(Taxas* taxas){
	return taxas->Hit_c1;
}

int getMissC1(Taxas* taxas){
	return taxas->Miss_c1;
}

int getHitC2(Taxas* taxas){
	return taxas->Hit_c2;
}

int getMissC2(Taxas* taxas){
	return taxas->Miss_c2;
}

int getHitC3(Taxas* taxas){
	return taxas->Hit_c3;
}

int getMissC3(Taxas* taxas){
	return taxas->Miss_c3;
}

int getHitRam (Taxas* taxas) {
	return taxas->Hit_ram;
} 

int getMissRam (Taxas* taxas) {
	return taxas->Miss_ram;
}

int getHitHd (Taxas* taxas) {
	return taxas->Hit_hd;
}

int getCusto(Taxas* taxas){
	return taxas->custo;
}

void setHitC1(Taxas* taxas, int Hit_c1){
	taxas->Hit_c1++;
}

void setMissC1(Taxas* taxas, int Miss_c1){
	taxas->Miss_c1++;
}

void setHitC2(Taxas* taxas, int Hit_c2){
	taxas->Hit_c2++;
}

void setMissC2(Taxas* taxas, int Miss_c2){
	taxas->Miss_c2++;
}

void setHitC3(Taxas* taxas, int Hit_c3){
	taxas->Hit_c3++;
}

void setMissC3(Taxas* taxas, int Miss_c3){
	taxas->Miss_c3++;
}

void setHitRam (Taxas* taxas, int Hit_ram) {
	taxas->Hit_ram++;
} 

void setMissRam (Taxas* taxas, int Miss_ram) {
	taxas->Miss_ram++;
}

void setHitHd (Taxas* taxas, int Hit_hd) {
	taxas->Hit_hd++;
}

void setCusto(Taxas* taxas, int custo){
	taxas->custo += custo;
}
