#ifndef PILHA_H
#define PILHA_H

typedef struct listano ListaNo;
typedef struct pilha Pilha;
typedef enum identificador Identificador;

enum identificador {
	QUA,
	LOS,
	TRAP
};

Pilha* criarPilha ();
void pilhaPush (Pilha* p, int objeto, void* info);
int pilhaPop (Pilha* p);
int verificarPilha (Pilha *p);
void liberarPilha (Pilha* p);

void area (Pilha* p);

//GET E SET
Identificador getObjetoPilha (ListaNo* n);
void* getInfoPilha (ListaNo* n);
ListaNo* getProxPilha (Pilha* p);

#endif
