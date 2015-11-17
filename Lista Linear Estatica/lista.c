#include <stdio.h>
#include <stdlib.h>
#define MAXL 100

typedef struct {
	int cod;
	char nome[40];
	char data_nasc[11];
	char email[40];
	char tel[14];
}T_Pessoa;

typedef struct {
	T_Pessoa Elem[MAXL];
	int Prim, Ult;
}Lista_e;

void Criar_Lista_Vazia(Lista_e *L){
	L->Prim = 0;
	L->Ult = L->Prim;
}

int Verifica_Lista_Vazia(Lista_e L){
	return(L.Prim==L.Ult);
}

int Verifica_Lista_Cheia(Lista_e L){
	return(L.Ult==MAXL);
}

void Insere_Elemento_Lista(Lista_e *L, T_Pessoa X){
	int P, A;

	if(Verifica_Lista_Cheia(*L))
		printf("Lista Cheia - Insere \n");
	else{
		P = L->Prim;
		while((P!=L->Ult)&&(X.cod>L->Elem[P].cod))
			P++;
		if ((P<L->Ult)&&(X.cod!=L->Elem[P].cod)){ //insere no meio da lista{
			for(A=L->Ult; A>P; A--)
				L->Elem[A] = L->Elem[A-1];
			L->Elem[P] = X;
			L->Ult++;
		}
		else if (P == L->Ult) {
			L->Elem[P]=X;
			L->Ult++;
		}
		else{
		printf("Código já existe - Substituindo\n");
     	L->Elem[P] = X;
    	}
	}

}


void Exibe_Elemento(T_Pessoa X){
	printf("\n-------------  Pessoa de Codigo: %3d ------------\n",X.cod);
	printf("|Nome:  %40s|\n",X.nome);
	printf("|Data de Nascimento:                 %11s|\n",X.data_nasc);
	printf("|E_Mail:  %38s|\n",X.email);
	printf("|Telefone:  %36s|\n",X.tel);
	printf("--------------- Final do registro ---------------\n"); 


}

void Exibe_Lista(Lista_e L){
	int P;
	if(Verifica_Lista_Vazia(L))
		printf("Lista Vazia - Exibe\n");
	else { 
		system("clear");
		printf("======= RELATORIO DOS ELEMENTOS DA LISTA ========");
		for(P=L.Prim; P<L.Ult;P++)
		Exibe_Elemento(L.Elem[P]);
		printf("========== FINAL DO RELATORIO DA LISTA ==========\n");
	}
}

int Consultar_Elemento(Lista_e L, T_Pessoa X){
	int P;
	if(Verifica_Lista_Vazia(L))
		return(-1);
	else {
		P = L.Prim;
		while((P!=L.Ult)&&(X.cod>L.Elem[P].cod))
			P++;
		if((P<L.Ult) && (X.cod == L.Elem[P].cod))
			return(P);
		else return(-1);
	}
}

void Remove_Elemento_Lista(Lista_e *L, T_Pessoa *X){
	int P,A;
	if(Verifica_Lista_Vazia(*L))
		printf("Lista Vazia - Remove \n");
	else{
		P = L->Prim;
		while((P!=L->Ult)&&(X->cod>L->Elem[P].cod))
			P++;
		if ((P<L->Ult-1)&&(X->cod==L->Elem[P].cod)){ //remover no meio da lista
 			*X = L->Elem[P];
			for(A=P; A<L->Ult; A++)
				L->Elem[A] = L->Elem[A+1];
			L->Ult--;
		}
		else if(P==L->Ult-1){
			*X = L->Elem[P];
			L->Ult--;
		}
		 else printf("Elemento nÃ£o encontrado na Lista - Remover\n");
	}
}
 
void alteraElemento(Lista_e *L, T_Pessoa *X){
int n = 1;
 while (n != 0){
	printf ("========= ALTERAR DADOS =========\n");
	printf ("|                               |\n");
	printf ("| 1. Altera Nome;               |\n");
	printf ("| 2. Altera Email;              |\n");
	printf ("| 3. Altera Data Nasc.;         |\n");
	printf ("| 4. Altera Telefone;           |\n");
	printf ("| 0. Sair.                      |\n");
	printf ("=================================\n\n");
	
	scanf ("%d", &n);
	
	switch (n){
		case 1:
			printf("\n -Entre com o Nome: ");
			scanf("%[^\n]s", X->nome);
			setbuf (stdin, NULL);
			break;
		case 2:
			printf("\n -Entre com o email: ");
			scanf("%s",X->email);
			break;
		case 3: 
			printf("\n -Entre com  Data de Nascimento: ");
			scanf("%s", X->data_nasc);
			break;
		case 4:
			printf("\n* Entre com o Telefone: ");
			scanf("%s", X->tel);
			break;
		case 0:
			break;
		default:
			printf ("Entre com um nÃºmero entre 0 e 5\n");
			getchar();
			break;
		}
		system ("clear");
	}
}
			

 void Ler_Elemento(T_Pessoa *X)
     { printf("***** Modulo de Leitura do Registro Pessoa *****\n");
       printf("\n* Entre com o codigo: ");
       scanf("%d",&X->cod);
       getchar();
       printf("\n* Entre com o Nome: ");
       gets(X->nome);
       printf("\n* Entre com o email: ");
       scanf("%s",X->email);
       printf("\n* Entre com o Telefone: ");
       scanf("%s", X->tel);
       printf("\n* Entre com  Data de Nascimento: ");
       scanf("%s", X->data_nasc);
   }
   

void leArquivoLista(Lista_e *L){
	FILE*arq;
	T_Pessoa X;
	int n;
	arq = fopen ("pessoas.txt", "rt");
	if (arq != NULL){
		fscanf (arq, "%d", &n);
		while(n != 0){
			X.cod = n;
			fgets (X.nome, 40, arq);
			fscanf (arq, "%s", X.email );
			fscanf (arq, "%s", X.tel);
			fscanf (arq, "%s", X.data_nasc);
			Insere_Elemento_Lista(&L, X);	
			fscanf (arq, "¨%d", &n);
		}
	}
	else{
		printf ("Lista não encontrada - Leitura...\n");
	} 
	fclose(arq);
}

void escreveArquivoLista(Lista_e L){
	FILE*arq;
	int p;
	arq = fopen ("pessoas.txt", "w");
	if (Verifica_Lista_Vazia(L)){
		Fprintf("0\n");
	}
	else{
		for (p = L.Prim; p < L.Ult; p++){
			fprintf("%d\n", L.Elem[p].cod);
			fprintf("%s\n", L.Elem[p].nome);
			fprintf("%s\n", L.Elem[p].email);
			fprintf("%s\n", L.Elem[p].tel);
			fprintf("%s\n", L.Elem[p].data_nasc);
		}
		fprintf ("%d\n", 0);
	}
	fclose(arq);
}
     
 void Menu()
    {
		system("clear");
		printf("\n===================== MENU =====================\n");
		printf("| 1 - Insere Elemento na lista;                |\n");
		printf("| 2 - Remover Elemento da lista;               |\n");
		printf("| 3 - Consultar Elemento na lista              |\n");
		printf("| 4 - Exibir Elementos da lista                |\n");
		printf("| 5 - Alterar Elemento na lista                |\n");
		printf("| 6 - Sair.                                    |\n");
		printf("================================================\n");
		printf(" Opcao: ");
	}
 
int main()
 {
   T_Pessoa X, Y;
   Lista_e L;
   int op, p;
   Criar_Lista_Vazia(&L);
   leArquivoLista(&L);
   do { Menu();
        scanf("%d",&op);
	   switch(op) {
		   case 1: Ler_Elemento(&X);
		           Insere_Elemento_Lista(&L, X);
		          break;
		   case 2: printf("Entre com o CÃ³digo que deseja Remover: ");
		            scanf("%d",&X.cod);
		            Remove_Elemento_Lista(&L, &X);
		            printf("\n Removendo o elemento: \n");
		            Exibe_Elemento(X);
		            break;
		   case 3: printf("Entre com o CÃ³digo que deseja Consultar: ");
		            scanf("%d",&X.cod);
		            p = Consultar_Elemento(L,X);
		            if (p!=-1)
						
		              Exibe_Elemento(L.Elem[p]);
		             else printf("Elemento nÃ£o encontrado na lista - consulta");
		            break;
		   case 4: Exibe_Lista(L);
		            break;
		   case 5: printf("Entre com o CÃ³digo que deseja Alterar: ");
		            scanf("%d",&X.cod);
		            p = Consultar_Elemento(L, X);
		            if (p!= -1){
						printf ("\n Alterando o elemento:\n\n");
						Exibe_Elemento(X);
						printf ("\n");
					
						alteraElemento(&L, &X);
						Insere_Elemento_Lista(&L, X);
					}
					else {
						printf ("-Elemento nao existe -Alterar");
					}
		            break;
		   case 6: printf("Obrigado Por Usar nosso Progrma - ESS(R)\n");
		            break;
		   default: printf("Digite uma opção de 1 a 6 por favor \n");
		             break;
		  }
	    printf("\nDigite algo pra continuar.....\n");
	    char t[2];
	    scanf("%s",t);
	   
   } while(op!=6);
   
   escreveArquivoLista(L);
   return(0);
 }
