#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "alimento.h"
#include "tarefa.h"
#include "morador.h"
#include "republica.h"

void menuInicial(){
	printf("\n\nAgora, segundo as informações abaixo, digite o número do que deseja fazer\n");
	printf("1 - Criar \n");
	printf("2 - Editar\n");
	printf("3 - Deletar\n");
	printf("4 - Ler\n");
	printf("5 - Buscar\n");
	printf("6 - Ordenar\n");
	printf("-1 - Sair\n");
}

void menuOpcoes(){
	printf("1 - República\n");
	printf("2 - Morador\n");
	printf("3 - Tarefa\n");
	printf("4 - Alimento\n");
}

void mergeSortMorador(Morador **m, int min, int meio, int max){
	Morador **aux = malloc (20 * sizeof (Morador*));
	int metadeInf = min, metadeSup = meio+1, k = 0;

	while(metadeInf <= meio && metadeSup <= max){
		if(strcmp(getNomeMorador(m[metadeInf]), getNomeMorador(m[metadeSup])) > 0){
			aux[k++] = m[metadeSup++];
		}
		else{
			aux[k++] = m[metadeInf++];
		}
	}

	while(metadeInf <= meio){
		aux[k++] = m[metadeInf++];
	}

	while(metadeSup <= max){
		aux[k++] = m[metadeSup++];
	}
	
	// Copiando aux para m
	for(metadeInf = min, k = 0; metadeInf <= max; metadeInf++, k++){
		m[metadeInf] = aux[k];
	}
}

void dividirMorador(Morador **m, int min, int max){
	int meio;

	if(min < max){
		meio = (min + max)/2;
		dividirMorador(m, min, meio);
		dividirMorador(m, meio + 1, max);
		mergeSortMorador(m, min, meio, max);

	}
}

void mergeSortRepublica(Republica **r, int min, int meio, int max){
	Republica **aux = malloc (30 * sizeof (Republica*));
	int metadeInf = min, metadeSup = meio+1, k = 0;

	while(metadeInf <= meio && metadeSup <= max){
		if(strcmp(getNomeRepublica(r[metadeInf]), getNomeRepublica(r[metadeSup])) > 0){
			aux[k++] = r[metadeSup++];
		}
		else{
			aux[k++] = r[metadeInf++];
		}
	}

	while(metadeInf <= meio){
		aux[k++] = r[metadeInf++];
	}

	while(metadeSup <= max){
		aux[k++] = r[metadeSup++];
	}
	
	// Copiando aux para r
	for(metadeInf = min, k = 0; metadeInf <= max; metadeInf++, k++){
		r[metadeInf] = aux[k];
	}
}

void dividirRepublica(Republica **r, int min, int max){
	int meio;

	if(min < max){
		meio = (min + max)/2;
		dividirRepublica(r, min, meio);
		dividirRepublica(r, meio + 1, max);
		mergeSortRepublica(r, min, meio, max);

	}
}

void mergeSortTarefa(Tarefa **t, int min, int meio, int max){
	Tarefa **aux = malloc (20 * sizeof (Tarefa*));
	int metadeInf = min, metadeSup = meio+1, k = 0;

	while(metadeInf <= meio && metadeSup <= max){
		if(strcmp(getDescricaoTarefa(t[metadeInf]), getDescricaoTarefa(t[metadeSup])) > 0){
			aux[k++] = t[metadeSup++];
		}
		else{
			aux[k++] = t[metadeInf++];
		}
	}

	while(metadeInf <= meio){
		aux[k++] = t[metadeInf++];
	}

	while(metadeSup <= max){
		aux[k++] = t[metadeSup++];
	}
	
	// Copiando aux para t
	for(metadeInf = min, k = 0; metadeInf <= max; metadeInf++, k++){
		t[metadeInf] = aux[k];
	}
}

void dividirTarefa(Tarefa **t, int min, int max){
	int meio;

	if(min < max){
		meio = (min + max)/2;
		dividirTarefa(t, min, meio);
		dividirTarefa(t, meio + 1, max);
		mergeSortTarefa(t, min, meio, max);

	}
}

void mergeSortAlimento(Alimento **a, int min, int meio, int max){
	Alimento **aux = malloc (50 * sizeof (Alimento*));
	int metadeInf = min, metadeSup = meio+1, k = 0;

	while(metadeInf <= meio && metadeSup <= max){
		if(strcmp(getDescricaoAlimento(a[metadeInf]), getDescricaoAlimento(a[metadeSup])) > 0){
			aux[k++] = a[metadeSup++];
		}
		else{
			aux[k++] = a[metadeInf++];
		}
	}

	while(metadeInf <= meio){
		aux[k++] = a[metadeInf++];
	}

	while(metadeSup <= max){
		aux[k++] = a[metadeSup++];
	}
	
	// Copiando aux para a
	for(metadeInf = min, k = 0; metadeInf <= max; metadeInf++, k++){
		a[metadeInf] = aux[k];
	}
}

void dividirAlimento(Alimento **a, int min, int max){
	int meio;

	if(min < max){
		meio = (min + max)/2;
		dividirAlimento(a, min, meio);
		dividirAlimento(a, meio + 1, max);
		mergeSortAlimento(a, min, meio, max);

	}
}


int buscaBinariaRepublica (char *palavra, Republica **r, int max, int min) {
	int meio = (max + min)/2;
	if (max < 1) {
		return -1;
	}
	int x = strcmp(palavra, getNomeRepublica(r[meio]));
	if (x == 0) {
		return meio;
	}
	else if (x < 0) {
		return buscaBinariaRepublica (palavra, r, meio-1, min);
	}
	else {
		return buscaBinariaRepublica (palavra, r, max, meio+1);
	}
} 

int buscaBinariaMorador (char *palavra, Morador **m, int max, int min) {
	int meio = (max + min)/2;
	if (max < 1) {
		return -1;
	}
	int x = strcmp(palavra, getNomeMorador(m[meio]));
	if (x == 0) {
		return meio;
	}
	else if (x < 0) {
		return buscaBinariaMorador (palavra, m, meio-1, min);
	}
	else {
		return buscaBinariaMorador (palavra, m, max, meio+1);
	}
} 

int buscaBinariaTarefa (char *palavra, Tarefa **t, int max, int min) {
	int meio = (max + min)/2;
	if (max < 1) {
		return -1;
	}
	int x = strcmp(palavra, getDescricaoTarefa(t[meio]));
	if (x == 0) {
		return meio;
	}
	else if (x < 0) {
		return buscaBinariaTarefa (palavra, t, meio-1, min);
	}
	else {
		return buscaBinariaTarefa (palavra, t, max, meio+1);
	}
} 

int buscaBinariaAlimento (char *palavra, Alimento **a, int max, int min) {
	int meio = (max + min)/2;
	if (max < 1) {
		return -1;
	}
	int x = strcmp(palavra, getDescricaoAlimento(a[meio]));
	if (x == 0) {
		return meio;
	}
	else if (x < 0) {
		return buscaBinariaAlimento (palavra, a, meio-1, min);
	}
	else {
		return buscaBinariaAlimento (palavra, a, max, meio+1);
	}
} 

//BUSCA A REPUBLICA DE UM MORADOR ESPECIFICO
int buscaBinariaMoradorRep (char *palavra, Morador **m, int max, int min) {
	int meio = (max + min)/2;
	if (max < 1) {
		return -1;
	}
	int x = strcmp(palavra, getRepublicaMorador(m[meio]));
	if (x == 0) {
		return meio;
	}
	else if (x < 0) {
		return buscaBinariaMoradorRep (palavra, m, meio-1, min);
	}
	else {
		return buscaBinariaMoradorRep (palavra, m, max, meio+1);
	}
} 

//BUSCA UM ALIMENTO DE UM DONO ESPECIFICO
int buscaBinariaDonoAlimento (char *palavra, Alimento **a, int max, int min) {
	int meio = (max + min)/2;
	if (max < 1) {
		return -1;
	}
	int x = strcmp(palavra, getDonoAlimento(a[meio]));
	if (x == 0) {
		return meio;
	}
	else if (x < 0) {
		return buscaBinariaDonoAlimento (palavra, a, meio-1, min);
	}
	else {
		return buscaBinariaDonoAlimento (palavra, a, max, meio+1);
	}
} 

//BUSCA UMA TAREFA DE UM MORADOR ESPECIFICO
int buscaBinariaMoradorTarefa (char *palavra, Tarefa **t, int max, int min) {
	int meio = (max + min)/2;
	if (max < 1) {
		return -1;
	}
	int x = strcmp(palavra, getPessoaTarefa(t[meio]));
	if (x == 0) {
		return meio;
	}
	else if (x < 0) {
		return buscaBinariaMoradorTarefa (palavra, t, meio-1, min);
	}
	else {
		return buscaBinariaMoradorTarefa (palavra, t, max, meio+1);
	}
} 



int main(){
	setlocale(LC_ALL, "Portuguese");
	int x = 0;
	int opcao;
	int editar;
	char excluido[8] = "EXCLUIDO";
	
	//variaveis referentes a morador
	Morador **m = malloc (20 * sizeof (Morador*));
	char nome[50], curso[50], apelido[50], status[20], republica[50];
	int idade, periodo;
	int contM = 0;
	
	//variaveis referentes a alimentos
	Alimento **a = malloc (50 * sizeof (Alimento*));;
	char descricao[100];
	char validade[10];
	char localizacao[50];
	char dono[50];
	int contA = 0;
	int *contAli = calloc(20, sizeof(int));
	
	//variaveis referentes a tarefas
	Tarefa **t = malloc (20 * sizeof (Tarefa*));
	char descricaoT[50];
	int prazo;
	char pessoa[50];
	int contT = 0;
	int *contTar = calloc(20, sizeof(int));
	
	//variaveis referentes a republica
	Republica **r = malloc (30 * sizeof (Republica*));
	char nomeR[50];
	char endereco[100];
	int telefone;
	int qntComodos;
	int contR = 0;
	int *contMR = calloc(30, sizeof(int));
	int *aux = calloc (30, sizeof (int));
	
	//variaveis necessarias para apagar republica
	int teste;
	int teste1;
	int teste2;
	int teste3;
	
	
	//variavel necessaria para busca
	char chave[50];
	int pos;

	printf("BEM VINDO AO SISTEMA DE ADMINISTRAÇÃO DE REPÚBLICAS\n");
	printf("Neste sistema, você tem a possibilidade de coordenar a quantidade desejada de repúblicas, assim como também seus moradores, tarefas e alimentos.");
	printf("\nAVISO: Sistema com limite de 20 moradores, 30 repúblicas, 20 tarefas e 50 alimentos!");

	while(x != -1){ 
		menuInicial();
		printf ("Digite uma opção: ");
		scanf("%d", &x);
		
		if(x != -1){
			printf("\n");
			switch(x){
			//CRIAR
			case 1:
				printf("O que deseja criar?\n");
				menuOpcoes();
				printf ("Digite uma opção: ");
				scanf ("%d", &opcao);
				switch(opcao){
					case 1:
					printf("\nDigite as informações da república:\n");
					printf ("Nome: ");
					scanf ("%s", nomeR);
					printf ("Endereço (Use _ no lugar de espaço): ");
					scanf ("%s", endereco);
					printf ("Telefone: ");
					scanf ("%d", &telefone);
					printf ("Quantidade de comodos: ");
					scanf ("%d", &qntComodos);
					
					r[contR] = criaRepublica (nomeR, endereco, telefone, qntComodos);
					contR++;
					break;

					case 2:
					printf("\nDigite as informações do morador:\n");
					printf ("Nome: ");
					scanf ("%s", nome);
					printf ("Idade: ");
					scanf ("%d", &idade);
					printf ("Curso: ");
					scanf ("%s", curso);
					printf ("Apelido: ");
					scanf ("%s", apelido);
					printf ("Periodo: ");
					scanf ("%d", &periodo);
					printf ("Status: ");
					scanf ("%s", status);
					printf("Republica: ");
					scanf("%s", republica);
					m[contM] = criaMorador (nome, idade, curso, apelido, periodo, status, republica);
					contM++;
					dividirRepublica(r, 0, contR-1);
					pos = buscaBinariaRepublica(republica, r, contR, 0);
					if(pos != -1){
						// Republica existe
						contMR[pos]++;
						setMoradoresRepublica(r[pos], m);
					}
					break;

					case 3:
					printf("\nDigite as informações da tarefa:\n");
					printf ("Descrição: "); 
					scanf ("%s", descricaoT);
					printf ("Prazo (dias): ");
					scanf ("%d", &prazo);
					printf ("Quem vai fazer: ");
					scanf ("%s", pessoa);
					
					t[contT] = criaTarefa (descricaoT, prazo, pessoa);
					contT++;
					dividirMorador(m, 0, contM-1);
					pos = buscaBinariaMorador (pessoa, m, contM, 0);
					if(pos != -1){
						// Morador existe
						contTar[pos]++;
						setTarefasMorador(m[pos], t);
					}

					break;

					case 4:
					printf("\nDigite as informações do alimento:\n");
					printf ("Descrição: ");
					scanf ("%s", descricao);
					printf ("Validade: ");
					scanf ("%s", validade);
					printf ("Localização: ");
					scanf ("%s", localizacao);
					printf ("Dono: ");
					scanf ("%s", dono);
					
					a[contA] = criaAlimento (descricao, validade, localizacao, dono);
					contA++;
					dividirMorador(m, 0, contM-1);
					pos = buscaBinariaMorador (dono, m, contM, 0);
					if(pos != -1){
						// Morador existe
						contAli[pos]++;
						setAlimentosMorador(m[pos], a);
					}
					break;
				}
			break;
			
			
			//EDITAR
			case 2:
				printf("\nO que deseja editar?\n");
				menuOpcoes();
				printf ("Digite uma opção: ");
				scanf ("%d", &opcao);
				switch(opcao){
					case 1:
					printf ("Digite o nome da República que deseja editar: ");
					scanf ("%s", chave);
					dividirRepublica(r, 0, contR-1);
					pos = buscaBinariaRepublica(chave, r, contR, 0);
					if (pos == -1) {
						printf ("República não encontrada\n");
					}
					else {
						printf("\nDigite o que deseja editar da república:\n");
						printf("1 - Nome\n");
						printf("2 - Endereço\n");
						printf("3 - Telefone\n");
						printf("4 - Quantidade de Comodos\n");
						printf ("Digite uma opção: ");
						scanf ("%d", &editar);
						if (editar == 1) {
							printf ("Digite o nome: ");
							scanf ("%s", nomeR);
							setNomeRepublica (r[pos], nomeR);
						}
						else if (editar == 2) {
							printf ("Digite o endereço (Use _ no lugar de espaço): ");
							scanf ("%s", endereco);
							setEnderecoRepublica (r[pos], endereco);
						}
						else if (editar == 3) {
							printf ("Digite o telefone: ");
							scanf ("%d", &telefone);
							setTelefoneRepublica (r[pos], telefone);
						}
						else if (editar == 4) {
							printf ("Digite a quantidade de comodos: ");
							scanf ("%d", &qntComodos);
							setQntComodosRepublica (r[pos], qntComodos);
						}
						else {
							printf ("Comando inexistente, por favor digite outro conforme informado.\n");
						}
					}
					
					break;

					case 2:
					printf ("Digite o nome do Morador que deseja editar: ");
					scanf ("%s", chave);
					dividirMorador(m, 0, contM-1);
					pos = buscaBinariaMorador (chave, m, contM, 0);
					if (pos == -1) {
						printf ("Morador não encontrado\n");
					}
					else {
						printf("\nDigite o que deseja editar do morador:\n");
						printf("1 - Nome\n");
						printf("2 - Idade\n");
						printf("3 - Curso\n");
						printf("4 - Apelido\n");
						printf ("5 - Período\n");
						printf ("6 - Status\n");
						printf("7 - República\n");
						printf ("Digite uma opção: ");
						scanf ("%d", &editar);
						if (editar == 1) {
							printf ("Digite o nome: ");
							scanf ("%s", nomeR);
							setNomeMorador (m[pos], nome);
						}
						else if (editar == 2) {
							printf ("Digite a idade: ");
							scanf ("%d", &idade);
							setIdadeMorador (m[pos], idade);
						}
						else if (editar == 3) {
							printf ("Digite o curso: ");
							scanf ("%s", curso);
							setCursoMorador (m[pos], curso);
						}
						else if (editar == 4) {
							printf ("Digite o apelido: ");
							scanf ("%s", apelido);
							setApelidoMorador (m[pos], apelido);
						}
						else if (editar == 5) {
							printf ("Digite o período: ");
							scanf ("%d", &periodo);
							setPeriodoMorador (m[pos], periodo);
						}
						else if (editar == 6) {
							printf ("Digite o status: ");
							scanf ("%s", status);
							setStatusMorador (m[pos], status);
						}
						else if(editar == 50){
							printf("Digite a república: ");
							scanf("%s", republica);
							setRepublicaMorador(m[pos], republica);
						}
						else {
							printf ("Comando inexistente, por favor digite outro conforme informado.\n");
						}
					}
					
					break;

					case 3:
					printf ("Digite o nome da tarefa que deseja editar: ");
					scanf ("%s", chave);
					dividirTarefa(t, 0, contT-1);
					pos = buscaBinariaTarefa (chave, t, contT, 0);
					if (pos == -1) {
						printf ("Tarefa não encontrada\n");
					}
					else {
						printf("\nDigite o que deseja editar da tarefa:\n");
						printf("1 - Descrição\n");
						printf("2 - Prazo\n");
						printf ("3 - Pessoa\n");
						printf ("Digite uma opção: ");
						scanf ("%d", &editar);
						if (editar == 1) {
							printf ("Digite a descrição: ");
							scanf ("%s", descricaoT);
							setDescricaoTarefa (t[pos], descricaoT);
						}
						else if (editar == 2) {
							printf ("Digite o prazo: ");
							scanf ("%d", &prazo);
							setPrazoTarefa (t[pos], prazo);
						}
						else if (editar == 3) {
							printf ("Digite quem vai fazer: ");
							scanf ("%s", pessoa);
							setPessoaTarefa (t[pos], pessoa);
						}
						else {
							printf ("Comando inexistente, por favor digite outro conforme informado.\n");
						}
					}
					break;

					case 4:
					printf ("Digite o nome do alimento que deseja editar: ");
					scanf ("%s", chave);
					dividirAlimento(a, 0, contA-1);
					pos = buscaBinariaAlimento (chave, a, contA, 0);
					if (pos == -1) {
						printf ("Alimento não encontrado\n");
					}
					else {
						printf("\nDigite o que deseja editar do alimento:\n");
						printf("1 - Descrição\n");
						printf("2 - Data de validade\n");
						printf("3 - Localização\n");
						printf ("4 - Dono\n");
						printf ("Digite uma opção: ");
						scanf ("%d", &editar);
						if (editar == 1) {
							printf ("Digite a descrição: ");
							scanf ("%s", descricao);
							setDescricaoAlimento (a[pos], descricao);
						}
						else if (editar == 2) {
							printf ("Digite a data de validade: ");
							scanf ("%s", validade);
							setValidadeAlimento (a[pos], validade);
						}
						else if (editar == 3) {
							printf ("Digite a localização: ");
							scanf ("%s", localizacao);
							setLocalizacaoAlimento (a[pos], localizacao);
						}
						else if (editar == 4) {
							printf ("Digite o dono: ");
							scanf ("%s", dono);
							setDonoAlimento (a[pos], dono);
						}
						else {
							printf ("Comando inexistente, por favor digite outro conforme informado.\n");
						}
					}
					

					break;
				}
			break;
			
			
			//DELETAR	
			case 3:
				printf("\nO que deseja deletar?\n");
				menuOpcoes();
				printf ("Digite uma opcao: ");
				scanf ("%d", &opcao);
				switch(opcao){
					case 1:
					printf ("Qual república deseja apagar? ");
					scanf ("%s", chave);
					dividirRepublica(r, 0, contR-1);
					pos = buscaBinariaRepublica(chave, r, contR, 0);
					if (pos == -1) {
						printf ("República não encontrada\n");
					}
					else {
						aux = contMR;
						for(int i = 0; i < contMR[pos]; i++){
							teste = buscaBinariaMoradorRep (getNomeRepublica(r[pos]), m, contM, 0);
							if(teste != -1) {
								for(int j = 0; j < contA; j++){
									teste1 = buscaBinariaDonoAlimento (getNomeMorador (m[pos]), a, contA, 0);
									if (teste1 != -1) {
										setDescricaoAlimento(a[j], excluido);
										contAli[i]--;
									}
								}

								for(int j = 0; j < contT; j++){
									teste2 = buscaBinariaMoradorTarefa (getNomeMorador (m[pos]), t, contT, 0);
									if (teste2 != -1) {
										setDescricaoTarefa(t[j], excluido);
										contTar[i]--;
									}
								}
								
								for (int j = 0; j < contM; j++) {
									teste3 = buscaBinariaMoradorRep (getNomeRepublica (r[pos]), m, contM, 0);
									if (teste3 != -1) {
										setNomeMorador(m[j], excluido);
										aux[pos]--;
									}
								}
								
							}
						}
						setNomeRepublica(r[pos], excluido);
					}
				
					break;

					case 2:
					printf ("Qual morador deseja apagar? ");
					scanf ("%s", chave);
					dividirMorador(m, 0, contM-1);
					pos = buscaBinariaMorador(chave, m, contM, 0);
					if (pos == -1) {
						printf ("Morador não encontrado\n");
					}
					else {
						for(int j = 0; j < contA; j++){
							if(strcmp(getDonoAlimento(a[j]), getNomeMorador(m[pos])) == 0){
								setDescricaoAlimento(a[j], excluido);
								contAli[pos]--;
							}
						}
						
						for(int j = 0; j < contT; j++){
							if(strcmp(getPessoaTarefa(t[j]), getNomeMorador(m[pos])) == 0){
								setDescricaoTarefa(t[j], excluido);
								contTar[pos]--;
							}
						}
	
						setNomeMorador(m[pos], excluido);
					}
					break;

					case 3:
					printf ("Qual tarefa deseja apagar? ");
					scanf ("%s", chave);
					dividirTarefa(t, 0, contT-1);
					pos = buscaBinariaTarefa(chave, t, contT, 0);
					if (pos == -1) {
						printf ("Tarefa não encontrada\n");
					}
					else {
						//apagaTarefa(t[pos]);
						setDescricaoTarefa(t[pos], excluido);
						for(int j = 0; j < contM; j++){
							if(strcmp(getPessoaTarefa(t[pos]), getNomeMorador(m[j])) == 0){
								contTar[j]--;
							}
						}
					}

					break;

					case 4:
					printf ("Qual alimento deseja apagar? ");
					scanf ("%s", chave);
					dividirAlimento(a, 0, contA-1);
					pos = buscaBinariaAlimento(chave, a, contA, 0);
					if (pos == -1) {
						printf ("Alimento não encontrado\n");
					}
					else {
						//apagaAlimento(a[pos]);
						setDescricaoAlimento(a[pos], excluido);
						for(int j = 0; j < contM; j++){
							if(strcmp(getDonoAlimento(a[pos]), getNomeMorador(m[j])) == 0){
								contAli[j]--;
							}
						}
					}

					break;
				}
			break;
			
			
			//LER
			case 4:
				printf("\nO que deseja ler?\n");
				menuOpcoes();
				printf ("Digite uma opção: ");
				scanf ("%d", &opcao);
				switch(opcao){
					case 1:
					for (int i=0; i < contR; i++) {
						if(strcmp(getNomeRepublica(r[i]), excluido) != 0){
							lerRepublica(r[i]);
						}
					}
					break;

					case 2:
					for (int i = 0; i < contM; i++) {
						if(strcmp(getNomeMorador(m[i]), excluido) != 0){
							lerMorador(m[i]);
						}	
					}
					
					break;

					case 3:
					for (int i=0; i < contT; i++) {
						if(strcmp(getDescricaoTarefa(t[i]), excluido) != 0){
							lerTarefa(t[i]);
						}
					}
					break;

					case 4:
					for (int i=0; i < contA; i++) {
						if(strcmp(getDescricaoAlimento(a[i]), excluido) != 0){
							lerAlimento(a[i]);
						}
					}

					break;
				}
				
			break;
			
			
			//BUSCAR
			case 5:
				printf("\nO que deseja buscar?\n");
				menuOpcoes();
				printf ("Digite uma opção: ");
				scanf ("%d", &opcao);
				switch(opcao){
					case 1:
					printf ("Digite o nome da república que deseja buscar: ");
					scanf ("%s", chave); 
					dividirRepublica(r, 0, contR-1);
					pos = buscaBinariaRepublica(chave, r, contR, 0);
					if (pos == -1) {
						printf ("República não encontrada\n");
					}
					else {
						printf ("República encontrada:");
						lerRepublica(r[pos]);
					}
					break;

					case 2:
					printf ("Digite o nome do morador que deseja buscar: ");
					scanf ("%s", chave); 
					dividirMorador(m, 0, contM-1);
					pos = buscaBinariaMorador (chave, m, contM,0);
					if (pos == -1) {
						printf ("Morador não encontrado\n");
					}
					else {
						printf ("Morador encontrado:");
						lerMorador(m[pos]);
					}
					
			
					break;

					case 3:
					printf ("Digite o nome da tarefa que deseja buscar: ");
					scanf ("%s", chave); 
					dividirTarefa(t, 0, contT-1);
					pos = buscaBinariaTarefa(chave, t, contT, 0);
					if (pos == -1) {
						printf ("Tarefa não encontrada\n");
					}
					else {
						printf ("Tarefa encontrada:");
						lerTarefa(t[pos]);
					}
					

					break;

					case 4:
					printf ("Digite o nome do alimento que deseja buscar: ");
					scanf ("%s", chave); 
					dividirAlimento(a, 0, contA-1);
					pos = buscaBinariaAlimento (chave, a, contA, 0);
					if (pos == -1) {
						printf ("Alimento não encontrado\n");
					}
					else {
						printf ("Alimento encontrado:");
						lerAlimento(a[pos]);
					}

					break;
				}
			break;
			
			
			//ORDENAR
			case 6:
				printf("\nO que deseja ordenar?\n");
				menuOpcoes();
				printf("Digite uma opção: ");
				scanf ("%d", &opcao);
				switch(opcao){
					case 1:
					printf("Ordenando repúblicas em ordem alfabética:\n");
					dividirRepublica(r, 0, contR-1);
					for (int i=0; i < contR; i++) {
						if(strcmp(getNomeRepublica(r[i]), excluido) != 0){
							lerRepublica(r[i]);
						}
					}
					break;

					case 2:
					printf("Ordenando moradores em ordem alfabética:\n");
					dividirMorador(m, 0, contM-1);
					for (int i = 0; i < contM; i++) {
						if(strcmp(getNomeMorador(m[i]), excluido) != 0){
							lerMorador(m[i]);
						}
					}
					break;

					case 3:
					printf("Ordenando tarefas em ordem alfabética:\n");
					dividirTarefa(t, 0, contT-1);
					for (int i=0; i < contT; i++) {
						if(strcmp(getDescricaoTarefa(t[i]), excluido) != 0){
							lerTarefa(t[i]);
						}
					}
					break;

					case 4:
					printf("Ordenando alimentos em ordem alfabética:\n");
					dividirAlimento(a, 0, contA-1);
					for (int i=0; i < contA; i++) {
						if(strcmp(getDescricaoAlimento(a[i]), excluido) != 0){
							lerAlimento(a[i]);
						}
					}
					break;
				}
				
			break;

			default:
				printf("Comando inexistente, por favor digite outro conforme informado.\n");
			break;
			}
		}

		// Atualizando os contadores e os moradores com informações que podem ter sido criadas depois
		for(int i = 0; i < contM; i++){
			
			// Atualizando as republicas com moradores que foram criados antes delas
			for(int j = 0; j < contR; j++){
				dividirRepublica(r, 0, contR-1);
				pos = buscaBinariaRepublica(getNomeRepublica(r[j]), r, contR, 0);
				if(strcmp(getNomeRepublica(r[j]), getRepublicaMorador(m[i])) == 0 && contMR[pos] <= 0){
					contMR[pos]++;
					setMoradoresRepublica(r[pos], m);
				}
			}

			// Atualizando os moradores com tarefas e alimentos que foram criados antes deles
			for(int j = 0; j < contT; j++){
				dividirMorador(m, 0, contM-1);
				pos = buscaBinariaMorador (pessoa, m, contM, 0);
				if(strcmp(getPessoaTarefa(t[j]), getNomeMorador(m[i])) == 0 && contTar[pos] <= 0){
					contTar[pos]++;
					setTarefasMorador(m[pos], t);
				}
			}

			for(int j = 0; j < contA; j++){
				dividirMorador(m, 0, contM-1);
				pos = buscaBinariaMorador (dono, m, contM, 0);
				if(strcmp(getDonoAlimento(a[j]), getNomeMorador(m[i])) == 0 && contAli[pos] <= 0){
					contAli[pos]++;
					setAlimentosMorador(m[pos], a);
				}
			}	
			setQntAlimentosMorador(m[i], contAli[i]);
			setQntTarefasMorador(m[i], contTar[i]);
			setQntMoradoresRepublica(r[i], contMR[i]);
		}
		
	}

	// FREEs
	/*for(int i = 0; i < 20; i++){
		free(m[i]);
		free(t[i]);
	}
	for(int i = 0; i < 30; i++){
		free(r[i]);
	}
	for(int i = 0; i < 50; i++){
		free(a[i]);
	}
	free(m);
	free(t);
	free(r);
	free(a);*/

	return 0;
}

