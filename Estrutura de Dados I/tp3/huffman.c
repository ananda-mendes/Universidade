#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "huffman.h"

/* Definição da árvore */
struct arvoreno
{
    int frequencia;
    byte c;
    ArvoreNo *esquerda;
    ArvoreNo *direita;
};

/* Definição da fila de prioridade (implementada como lista simplesmente encadeada) */
struct listano
{
    ArvoreNo *n;
    ListaNo *proximo;
};

struct lista
{
    ListaNo *head;
    int elementos;
};


char *strdup(const char *s)
{
    char *p = malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

// Função que faz alocação de memória e trata os ponteiros soltos acerca de nós da lista encadeada.
// Obs: cada nó da lista encadeada é conectado a um nó 'raiz' de árvore.
ListaNo *novoListaNo (ArvoreNo *nArv)
{
    // Aloca memória
    ListaNo *novo;
    if ( (novo = malloc(sizeof(*novo))) == NULL ) return NULL;

    // Adiciona a árvore ao nó
    novo->n = nArv;

    // Faz o campo próximo apontar para NULL
    novo->proximo = NULL;

    return novo;
}

// Função que faz alocação de memória e trata os ponteiros soltos acerca de nós da árvore
ArvoreNo *novoArvoreNo (byte c, int frequencia, ArvoreNo *esquerda, ArvoreNo *direita)
{
    // Aloca memória
    ArvoreNo *novo;

    if ( ( novo = malloc(sizeof(*novo)) ) == NULL ) return NULL;

    // Atribui na árvore os valores passados como parâmetro
    novo->c = c;
    novo->frequencia = frequencia;
    novo->esquerda = esquerda;
    novo->direita = direita;

    return novo;
}

// Função que um novo nó na lista encadeada que representa a fila de prioridade.
void insereLista(ListaNo *n, Lista *l)
{
    //verifica se a lista está vazia
    if (!l->head)
    {
        l->head = n;
    }
    else if (n->n->frequencia < l->head->n->frequencia)
    {
        n->proximo = l->head;
        l->head = n;
    }
    else
    {
        ListaNo *aux = l->head->proximo;
        ListaNo *aux2 = l->head;

        // Laço que percorre a lista e insere o nó na posição certa de acordo com sua frequência.
        while (aux && aux->n->frequencia <= n->n->frequencia)
        {
            aux2 = aux;
            aux = aux2->proximo;
        }

        // Se insere o nó na posição certa.
        aux2->proximo = n;
        n->proximo = aux;
    }

    // Incrementa quantidade de elementos
    l->elementos++;
}

// Função que 'solta' o nó apontado por 'head' da lista (o de menor frequência)
// (faz backup do nó e o desconecta da lista)
ArvoreNo *popMinLista(Lista *l)
{

    // Ponteiro auxilar que aponta para o primeiro nó da lista
    ListaNo *aux = l->head;

    // Ponteiro auxiliar que aponta para a árvore contida em aux (árvore do primeiro nó da lista)
    ArvoreNo *aux2 = aux->n;

    // Aponta o 'head' da lista para o segundo elemento dela
    l->head = aux->proximo;

    free(aux);
    aux = NULL;

    l->elementos--;

    return aux2;
}

// Função que conta a frequência de ocorrências dos bytes de um dado arquivo
void getByteFrequency(FILE *entrada, unsigned int *listaBytes)
{
    byte c;


    /*
	* fread retorna a quantidade de blocos lidos com sucesso
    * Faz a leitura de 1 bloco de tamanho 1 byte a partir do arquivo 'entrada'
    * e salva no espaco de memoria de 'c'.
    * Converte esse byte num valor decimal, acessa o bucket correspondente e incrementa o valor (frequência).
    *
    */
    while (fread(&c, 1, 1, entrada) >= 1)
    {
        listaBytes[(byte)c]++;
    }
    rewind(entrada); // "rebobina o arquivo"

}


// Função recursiva que percorre uma árvore de huffman e para ao encontrar o byte procurado (c)
bool pegaCodigo(ArvoreNo *n, byte c, char *buffer, int tamanho)
{

    // Caso base da recursão:
    // Se o nó for folha e o seu valor for o buscado, colocar o caractere terminal no buffer e encerrar
    if (!(n->esquerda || n->direita) && n->c == c)
    {
        buffer[tamanho] = '\0';
        return true;
    }
    else
    {
        bool encontrado = false;
        if (n->esquerda)
        {
            buffer[tamanho] = '0';

            // fazer recursão no nó esquerdo
            encontrado = pegaCodigo(n->esquerda, c, buffer, tamanho + 1);
        }

        if (!encontrado && n->direita)
        {
            buffer[tamanho] = '1';
            encontrado = pegaCodigo(n->direita, c, buffer, tamanho + 1);
        }
        if (!encontrado)
        {
            buffer[tamanho] = '\0';
        }
        return encontrado;
    }

}

ArvoreNo *BuildHuffmanTree(unsigned *listaBytes)
{
    // Lista com head apontando pra NULL e com campo 'elementos' valendo 0;
    Lista l = {NULL, 0};

    // Cada nó contém uma árvore.
    for (int i = 0; i < 256; i++)
    {
        if (listaBytes[i]) // Se existe ocorrência do byte
        {
            // Insere na lista 'l' um nó referente ao byte i e sua respectiva frequência (guardada em listaBytes[i]).
            // Faz os nós esquerdo e direito das árvores apontarem para NULL;
            insereLista(novoListaNo (novoArvoreNo (i, listaBytes[i], NULL, NULL)), &l);
        }
    }

    while (l.elementos > 1) 
    {
        // Nó esquerdo chama a função popMinLista() que vai na lista e pega a árvore fixada no primeiro nó
        // (que é a que contém a menor frequência)
        ArvoreNo *nodeEsquerdo = popMinLista(&l);

        // Pega o outro nó que tem menor frequência
        ArvoreNo *nodeDireito = popMinLista(&l);

        // Preenche com '#' o campo de caractere do nó da árvore.
        ArvoreNo *soma = novoArvoreNo('#', nodeEsquerdo->frequencia + nodeDireito->frequencia, nodeEsquerdo, nodeDireito);

        // Reinsere o nó 'soma' na lista l
        insereLista(novoListaNo(soma), &l);
    }

    return popMinLista(&l);
}

// Função que libera memória 
void FreeHuffmanTree(ArvoreNo *n)
{
    // Caso base da recursão, enquanto o nó não for NULL
    if (!n) return;
    else
    {
        ArvoreNo *esquerda = n->esquerda;
        ArvoreNo *direita = n->direita;
        free(n);
        FreeHuffmanTree(esquerda);
        FreeHuffmanTree(direita);
    }
}

// Função que faz bitmasking no byte lido e retorna um valor booleano confirmando sua existência
int geraBit(FILE *entrada, int posicao, byte *aux )
{
    // É hora de ler um bit?
    (posicao % 8 == 0) ? fread(aux, 1, 1, entrada) : NULL == NULL ;

    // Exclamação dupla converte para '1' (inteiro) se não for 0. Caso contrário, deixa como está (0)
    // Joga '1' na casa binária 'posicao' e vê se "bate" com o byte salvo em *aux do momento
    // percorre a árvore (esquerda e direita)
    return !!((*aux) & (1 << (posicao % 8)));
}

// Função para notificar ausência do arquivo. Encerra o programa em seguida.
void erroArquivo()
{
    printf("Arquivo nao encontrado\n");
    exit(0);
}

// Função que comprime um arquivo
void CompressFile(const char *arquivoEntrada, const char *arquivoSaida)
{

    clock_t inicio, final;
    double tempoGasto;
    inicio = clock();

    unsigned listaBytes[256] = {0};

    // Abre arquivo do parâmetro arquivoEntrada no modo leitura de binário
    FILE *entrada = fopen(arquivoEntrada, "rb");
    (!entrada) ? erroArquivo() : NULL == NULL ;

    // Abre arquivo do parâmetro arquivoSaida no modo escrita de binário
    FILE *saida = fopen(arquivoSaida, "wb");
    (!saida) ? erroArquivo() : NULL == NULL ;

    getByteFrequency(entrada, listaBytes);

    ArvoreNo *raiz = BuildHuffmanTree(listaBytes);

    fwrite(listaBytes, 256, sizeof(listaBytes[0]), saida);

    // Move o ponteiro do stream 'saida' para a posição posterior ao tamanho de um unsigned int
    fseek(saida, sizeof(unsigned int), SEEK_CUR);

    byte c;
    unsigned tamanho = 0;
    byte aux = 0;

    //fread retorna a quantidade de bytes lidos com sucesso
    while (fread(&c, 1, 1, entrada) >= 1)
    {

        // Cria um buffer vazio
        char buffer[1024] = {0};

        // Busca o código começando no nó 'raiz', utilizando o byte salvo em 'c', preenchendo 'buffer', desde o bucket deste último
        pegaCodigo(raiz, c, buffer, 0);

        for (char *i = buffer; *i; i++)
        {
            if (*i == '1')
            {
                aux = aux | (1 << (tamanho % 8));
            }

            tamanho++;
			
			// Escreve um byte no arquivo
            if (tamanho % 8 == 0)
            {
                fwrite(&aux, 1, 1, saida);
                aux = 0;
            }
        }
    }
    
    fwrite(&aux, 1, 1, saida);
    fseek(saida, 256 * sizeof(unsigned int), SEEK_SET);
    fwrite(&tamanho, 1, sizeof(unsigned), saida);

    final = clock();
    tempoGasto = (double)(final - inicio) / CLOCKS_PER_SEC;

    // Calcula tamanho dos arquivos
    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);

    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    FreeHuffmanTree(raiz);

    printf("Arquivo de entrada: %s (%g bytes)\nArquivo de saida: %s (%g bytes)\nTempo gasto: %gs\n", arquivoEntrada, tamanhoEntrada / 1000, arquivoSaida, tamanhoSaida / 1000, tempoGasto);
    printf("Taxa de compressao: %d%%\n", (int)((100 * tamanhoSaida) / tamanhoEntrada));

    fclose(entrada);
    fclose(saida);

}

// Função que descomprime um arquivo utilizando a compressão de huffman
void DecompressFile(const char *arquivoEntrada, const char *arquivoSaida)
{

    clock_t inicio, final;
    double tempoGasto;
    inicio = clock();

    unsigned listaBytes[256] = {0};

    FILE *entrada = fopen(arquivoEntrada, "rb");
    (!entrada) ? erroArquivo() : NULL == NULL ;

    FILE *saida = fopen(arquivoSaida, "wb");
    (!saida) ? erroArquivo() : NULL == NULL ;

    // Lê a lista de frequência que encontra-se nos primeiros 256 bytes do arquivo
    fread(listaBytes, 256, sizeof(listaBytes[0]), entrada);

    // Constrói árvore
    ArvoreNo *raiz = BuildHuffmanTree(listaBytes);

    // Lê o valor dessa posição do stream para dentro da variável tamanho
    unsigned tamanho;
    fread(&tamanho, 1, sizeof(tamanho), entrada);

    unsigned posicao = 0;
    byte aux = 0;

    while (posicao < tamanho)
    {
        // Salvando o ArvoreNo que encontramos
        ArvoreNo *noAtual = raiz;

        // Enquanto noAtual não for folha
        while ( noAtual->esquerda || noAtual->direita )
        {
            noAtual = geraBit(entrada, posicao++, &aux) ? noAtual->direita : noAtual->esquerda;
        }

        fwrite(&(noAtual->c), 1, 1, saida);
    }

    FreeHuffmanTree(raiz);

    final = clock();
    tempoGasto = (double)(final - inicio) / CLOCKS_PER_SEC;

    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);

    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    printf("Arquivo de entrada: %s (%g bytes)\nArquivo de saida: %s (%g bytes)\nTempo gasto: %gs\n", arquivoEntrada, tamanhoEntrada / 1000, arquivoSaida, tamanhoSaida / 1000, tempoGasto);
    printf("Taxa de descompressao: %d%%\n", (int)((100 * tamanhoSaida) / tamanhoEntrada));

    fclose(saida);
    fclose(entrada);
}

