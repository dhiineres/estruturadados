/**
 * TAD - Lista Linear Estática
 * 
 * 1. Criar Lista Vazia
 * 2. Inserir Elemento da Lista
 * 3. Remover Elemento da Lista
 * 4. Alterar Elemento da Lista
 * 5. Exibir um Elemento da Lista
 * 6. Exibir Todos os Elementos da Lista
 * 7. Mostrar Antecessor de um Elemento
 * 8. Mostrar Sucessor de um Elemento
 * 9. Outras
 * ---------------------
 * X. Sair
 * ---------------------
 */
 
 //Código da Lista Estática:

#include <stdio.h>
#include <stdlib.h>
#define MAXL 100

typedef struct {
	int codigo;
	char nome[40];
	char email[40];
	char tel[16];
	char dataNasc[11];
}T_Pessoa;

typedef struct {
	T_Pessoa item[MAXL];
	int prim, ult;
}Lista_Est;

void CriaListaVazia (Lista_Est *L){
	L -> prim = 0;
	L -> ult = L -> prim;
}

int VerificaListaVazia(Lista_Est L){
	return (L.Prim==L.Ul

void InsereElementoLista(Lista_Est *L, T_Pessoa X){
	int P, A;
	if 
