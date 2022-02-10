#include <stdio.h>
#include <stdlib.h>

void montarMemoriaDados (int *RAM);
void montarSomaSub (int **memoriaInstrucoes);
void maquina (int *RAM, int **memoriaInstrucoes);
int multiplicar (int multiplicando, int multiplicador, int *RAM);
int dividir (int dividendo, int divisor, int *RAM);
int potencia (int *RAM, int base, int expoente);
//void raizquadrada (int *RAM, int num, double quadrado, int **memoriaInstrucoes);
void fibonacci (int *RAM, int aux, int ant);
void fatorial (int *RAM, int num);
int areaTriangulo (int base, int altura, int *RAM);
void areaQuadrado (int lado, int *RAM);
void areaCirculo (int raio, int *RAM);
void areaRetangulo (int base, int altura, int *RAM);
void areaLosango (int dMaior, int dMenor, int *RAM);
void areaTrapezio (int bMaior, int bMenor, int altura, int *RAM);
void volumeQuadrado (int lado, int *RAM);
void volumeCirculoAproximado (int raio, int *RAM);
void velocidadeMedia (int distancia, int tempo, int *RAM);
void distancia (int velocidade, int tempo, int *RAM);


int main()
{
	int *RAM = malloc (100*sizeof(int));
	int **memoriaInstrucoes = malloc (1000 * sizeof (int*));
	for (int i=0; i < 1000; i++)
	{
		memoriaInstrucoes[i] = malloc (4 * sizeof (int));
	}
	montarMemoriaDados(RAM); //prencher a memoria com numeros aleatorios
	montarSomaSub(memoriaInstrucoes);
	
	//realiza soma e sub
	maquina(RAM, memoriaInstrucoes);
	
	//recebendo resultado da multiplicacao
	int mult = multiplicar (77,333, RAM);
	printf ("Multiplicando %d\n\n", mult);
	
	//recebendo resultado da divisao
	int div = dividir (50, 5, RAM);
	printf ("Dividindo %d\n\n", div);
	
	
	//recebendo resultado da exponenciacao
	int pot=potencia (RAM, 2,5);
	printf ("Potencia %d\n\n", pot);
	//raizquadrada (RAM, 9, 0.5, memoriaInstrucoes);
	
	fibonacci (RAM, 0, 1);
	
	fatorial (RAM, 5);
	
	int resp = areaTriangulo (4, 2, RAM);
	printf ("Area do Triangulo %d\n\n", resp);
	
	areaQuadrado (4, RAM);
	
	areaCirculo (5, RAM);
	
	areaRetangulo (4, 5, RAM);
	
	areaLosango (3, 2, RAM);
	
	areaTrapezio (2, 2, 3, RAM);
	
	volumeQuadrado (2, RAM);
	
	volumeCirculoAproximado (3, RAM);
	
	velocidadeMedia (100, 2, RAM);
	
	distancia (50, 2, RAM);
	
	return 0;
}


void montarMemoriaDados(int *RAM) {
	for(int i=0; i<100; i++){
		RAM[i] = rand () % 101;
	}
}


void montarSomaSub (int **memoriaInstrucoes) {
	//0 => opcode => somar
	//1 => opcode => subtrair
	//2 => opcode => salvar
	//-1 => halt		
	
	for (int i=0; i<999; i++){
		memoriaInstrucoes[i][0] = rand () % 2;
		memoriaInstrucoes[i][1] = rand () % 100;
		memoriaInstrucoes[i][2] = rand () % 100;
		memoriaInstrucoes[i][3] = rand () % 100;
	}

	//inserindo a ultima instrucao do programa como halt
	
	memoriaInstrucoes[999][0] =-1;
	memoriaInstrucoes[999][1] = -1;
	memoriaInstrucoes[999][2] = -1;
	memoriaInstrucoes[999][3] = -1;

}


void maquina(int *RAM, int **memoriaInstrucoes){
	int opcode = 10000000;
	int pc = 0;
	while (opcode != -1) 
	{
		opcode = memoriaInstrucoes[pc][0];
		switch (opcode) {
			//levar para RAM
			case 0: {
				//somar
				int end1 = memoriaInstrucoes[pc][1]; 
				int end2 = memoriaInstrucoes[pc][2]; 
				int end3 = memoriaInstrucoes[pc][3]; 
				
				//realizandoa operacao
				int soma = RAM[end1] + RAM[end2];
				//salvando resultado na RAM
				RAM[end3] = soma;
				
				//printf ("Somando %d\n", soma);
				break;
			}
			case 1:{
				//subtrair
				int end1 = memoriaInstrucoes[pc][1]; 
				int end2 = memoriaInstrucoes[pc][2]; 
				int end3 = memoriaInstrucoes[pc][3]; 
			
				//realizando a operacao
				int sub = RAM[end1] - RAM[end2];
				
				//salvando resultado na RAM
				RAM[end3] = sub;
				
				//printf ("Subtraindo %d\n", sub);
				
				break;
			}
			case 2: {
				RAM[memoriaInstrucoes[pc][2]] = memoriaInstrucoes[pc][1]; //levando pra RAM
				break;
			}
		}	
		pc++;
	}
}

int multiplicar (int multiplicando, int multiplicador, int *RAM) {
	//multiplicar
	int **memoriaInstrucoesMult = malloc((multiplicador + 3) * sizeof (int*));
	for (int i=0; i < multiplicador+3; i++)
	{
		memoriaInstrucoesMult[i] = malloc (4 * sizeof(int));
	}
	
	memoriaInstrucoesMult[0][0] = 2;			//LEVAR PARA ram
	memoriaInstrucoesMult[0][1] = multiplicando;
	memoriaInstrucoesMult[0][2] = 0;		 	//RAM[0]
	memoriaInstrucoesMult[0][3] = -1;				
	//RAM[MULTIPLICANDO, LIXO1, LIXO2, LIXO...., LIXO99]
	
	memoriaInstrucoesMult[1][0] = 2;			//LEVAR PARA ram
	memoriaInstrucoesMult[1][1] = 0;
	memoriaInstrucoesMult[1][2] = 1; 			//RAM[1]
	memoriaInstrucoesMult[1][3] = -1;				
	//RAM[MULTIPLICANDO, 0, LIXO2, LIXO...., LIXO99]
	
	
	for(int i=0; i < multiplicador; i++){
		memoriaInstrucoesMult[i+2][0] = 0;         //opcode para ser sempre soma
		memoriaInstrucoesMult[i+2][1] = 0;         //RAM[0]
		memoriaInstrucoesMult[i+2][2] = 1;         //RAM[1]
		memoriaInstrucoesMult[i+2][3] = 1;         //RAM[1]
	}
	
	memoriaInstrucoesMult[multiplicador+2][0] = -1; 
	memoriaInstrucoesMult[multiplicador+2][1] = -1;       //opcode para sair
	memoriaInstrucoesMult[multiplicador+2][2] = -1;         
	memoriaInstrucoesMult[multiplicador+2][3] = -1;   



	//realizando a operacao
	maquina (RAM, memoriaInstrucoesMult);
	int resultado = RAM[1];
	for (int i=0; i < multiplicador+3; i++) {
		free(memoriaInstrucoesMult[i]);
	}
	free(memoriaInstrucoesMult);
	return resultado;
}

int dividir (int dividendo, int divisor, int *RAM) {
	//dividir
	
	int **memoriaInstrucoesDiv = malloc (4* sizeof (int*));
	for (int i=0; i < 4; i++)
	{
		memoriaInstrucoesDiv[i] = malloc (4 * sizeof(int));
	}
	
	memoriaInstrucoesDiv[0][0] = 2;			//LEVAR PARA ram
	memoriaInstrucoesDiv[0][1] = dividendo;
	memoriaInstrucoesDiv[0][2] = 0; 		//RAM[0]
	memoriaInstrucoesDiv[0][3] = -1;				
	//RAM[DIVIDENDO, LIXO1, LIXO2, LIXO...., LIXO99]
	
	
	memoriaInstrucoesDiv[1][0] = 2;			//LEVAR PARA ram
	memoriaInstrucoesDiv[1][1] = divisor;
	memoriaInstrucoesDiv[1][2] = 1; 		//RAM[1]
	memoriaInstrucoesDiv[1][3] = -1;				
	//RAM[DIVIDENDO, DIVISOR, LIXO2, LIXO...., LIXO99]
	

	memoriaInstrucoesDiv[2][0] = 1;         //opcode para ser sempre subtracao
	memoriaInstrucoesDiv[2][1] = 0;         //RAM[0]
	memoriaInstrucoesDiv[2][2] = 1;         //RAM[1]
	memoriaInstrucoesDiv[2][3] = 0;         //RAM[0]


	memoriaInstrucoesDiv[3][0] = -1;         //opcode para sair
	memoriaInstrucoesDiv[3][1] = -1;         
	memoriaInstrucoesDiv[3][2] = -1;         
	memoriaInstrucoesDiv[3][3] = -1;   

	
	maquina (RAM, memoriaInstrucoesDiv);
	int end1 = memoriaInstrucoesDiv[0][2];
	int end2 = memoriaInstrucoesDiv[2][3];
	
	//realizando a operacao
	int cont=1; 			//começa em 1 pois já chamou maquina uma vez
	while (RAM[end1] > 0)
	{
		cont++;
		memoriaInstrucoesDiv[0][1] = RAM[end2];
		maquina (RAM, memoriaInstrucoesDiv);
	}
	for (int i=0; i < 4; i++)
	{
		free(memoriaInstrucoesDiv[i]);
	}
	free (memoriaInstrucoesDiv);
	return cont;
}

int potencia (int *RAM, int base, int expoente) {
	//potencia
	//realizando operacao
	RAM[1] = multiplicar (base,base,RAM);
	for (int i=0; i < expoente-2; i++) 
	{
		RAM[1] = multiplicar (base,RAM[1],RAM);
		
		
	}
	return RAM[1];
	
	
}

/*void raizquadrada (int *RAM, int num) {
	int result = potencia (RAM, num);
	printf ("Raiz Quadrada %d\n", result);
}
*/
	


void fibonacci (int *RAM, int aux, int ant) {
	//fibonacci
	int **memoriaInstrucoesFib = malloc (4 *sizeof (int*));
	for (int i=0; i < 4; i++) {
		memoriaInstrucoesFib[i] = malloc (4 * sizeof(int));
	}
	
	memoriaInstrucoesFib[0][0] = 2;			//LEVAR PARA ram
	memoriaInstrucoesFib[0][1] = aux;
	memoriaInstrucoesFib[0][2] = 0;			//NA POSIÇÃO RAM[0]	
	memoriaInstrucoesFib[0][3] = -1;				
	//RAM[AUX, LIXO1, LIXO2, LIXO...., LIXO99]
	
	memoriaInstrucoesFib[1][0] = 2;			//LEVAR PARA ram
	memoriaInstrucoesFib[1][1] = ant; 		//anterior
	memoriaInstrucoesFib[1][2] = 1;			//NA POSIÇÃO RAM[1]
	memoriaInstrucoesFib[1][3] = -1;				
	//RAM[AUX, ANT, LIXO2, LIXO...., LIXO99]

	memoriaInstrucoesFib[2][0] = 0; 		// para ser tudo soma
	memoriaInstrucoesFib[2][1] = 0; 		//pega da RAM[0]
	memoriaInstrucoesFib[2][2] = 1;			//pega da RAM[1]
	memoriaInstrucoesFib[2][3] = 3;			//armazena o resultado na RAM[3]

	memoriaInstrucoesFib[3][0] = -1;	 	//HALT
	memoriaInstrucoesFib[3][1] = -1; 
	memoriaInstrucoesFib[3][2] = -1;
	memoriaInstrucoesFib[3][3] = -1;	


	maquina (RAM, memoriaInstrucoesFib);
	int end1 = memoriaInstrucoesFib[0][2];
	int end2 = memoriaInstrucoesFib[1][2];
	int end3 = memoriaInstrucoesFib[2][3];
	for (int i = 0; i <= 10; i++) {
		if (RAM[end1] == 0) {
			printf ("Fibonacci %d\n", RAM[end1]);
		}
		printf ("Fibonacci %d\n", RAM[end2]);
		memoriaInstrucoesFib[0][1] = RAM[end2];
		memoriaInstrucoesFib[1][1] = RAM[end3];
		maquina (RAM, memoriaInstrucoesFib);
	}
	for (int i=0; i < 4; i++) {
		free(memoriaInstrucoesFib[i]);
	}
	free (memoriaInstrucoesFib);
}

void fatorial (int *RAM, int num) {
	int fat = 1;
	for (int i=num; i > 0; i--) {
		fat = multiplicar (fat,i, RAM);
	}
	printf ("\nFatorial de %d: %d\n\n", num, fat);
}

int areaTriangulo (int base, int altura, int *RAM) {
	int resp = multiplicar (base, altura, RAM);
	resp = dividir (resp,2,RAM);
	return resp;
}

void areaQuadrado (int lado, int *RAM) {
	int a = multiplicar (lado, lado, RAM);
	printf ("Area do Quadrado %d\n\n", a);
}

void areaCirculo (int raio, int *RAM) {
	int pi = 3;
	raio = potencia (RAM,raio,2);
	int ac = multiplicar (pi, raio, RAM);
	printf ("Area do Circulo %d\n\n", ac);
}

void areaRetangulo (int base, int altura, int *RAM) {
	int ar = multiplicar (base, altura, RAM);
	printf ("Area do Retangulo %d\n\n", ar);
}

void areaLosango (int dMaior, int dMenor, int *RAM) {
	int resultado = multiplicar (dMaior, dMenor, RAM);
	resultado = dividir (resultado, 2, RAM);
	printf ("Area do Losango %d\n\n", resultado);
}

void areaTrapezio (int bMaior, int bMenor, int altura, int *RAM) {
	int resp = areaTriangulo (bMaior+bMenor, altura, RAM);
	printf ("Area do Trapezio %d\n\n", resp);
}

void volumeQuadrado (int lado, int *RAM) {
	int resp = multiplicar (lado, lado, RAM);
	resp = multiplicar (resp, lado, RAM);
	printf ("Volume do Quadrado %d\n\n", resp);
}

void volumeCirculoAproximado (int raio, int *RAM) {
	const int pi = 3;
	int r = multiplicar (raio, raio, RAM);
	r = multiplicar (r, raio, RAM);
	int resultado = multiplicar (pi, r, RAM);
	resultado = multiplicar (resultado, 4, RAM);
	resultado = dividir (resultado, 3, RAM);
	printf ("Volume do Circulo %d\n\n", resultado);
}

void velocidadeMedia (int distancia, int tempo, int *RAM) {
	int v = dividir (distancia, tempo, RAM);
	printf ("Velocidade media %d\n\n", v);
}

void distancia (int velocidade, int tempo, int *RAM) {
	int d = multiplicar (velocidade, tempo, RAM);
	printf ("Distancia %d\n\n", d);
}



