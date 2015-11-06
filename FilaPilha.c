#include <stdio.h>
#define max 300


typedef struct {
	int codigo;
	char nome[40];
	char email[40];
	char tel[16];
	char dataNasc[11];
} TPessoa;

typedef struct {
	TPessoa x[300];
	int fim, inicio, total;
}TFila;

typedef struct {
	TPessoa x[300];
	int topo;
}TPilha;

void CriarFilaVazia (TFila F){
	F->inicio = 0;
	F->fim = F->inicio;
	F->total = 0;
}

void CriarPilhaVazia (TPilha P){
	F->topo = 0
}

int VerificaFilaCheia(TFila F) {
	return (((F.fim + 1) % max) == F.inicio);
}

int VerificaFilaVazia(TFila F){
	return (F.fimj == F.inicio);
}

FilaEncInverterFila(TFila F){
	TFila FA;
	TPessoa X;
	TPilha P;
	
	CriarFilaVazia(&FA);
	CriarPilhaVazia(&P);
	
	while (!VerificarFilaVazia (F)){
		Desenfileirar (&F, &X);
		Enfileirar (&FA, X);
	}
	
	while (!VerificarPilhaVazia (P)){
		Desempilhar(&P, &X);
		Enfileirar (&FA, X);
	}
	
	return (FA);
}
	
	
	
	
