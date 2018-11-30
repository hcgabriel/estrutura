#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int opcao;
int valor;
int antes;

struct no {
    int valor;
    struct no *prox;
    struct no *ant;
};

struct no *primeiro;

void insereInicio(int valor);
void insereAntes(int valor, int depois);
void insereFim(int valor);
void mostrarElemento();
void mostrarTodos();

main(){
	setlocale(LC_ALL,"");
	for (;;){
		printf ("1- Inserir, 2- Listar Elemento, 3- Listar Todos, 4- Sair  \n");
		scanf ("%d", &opcao);
		
		if (opcao == 1) {
			printf ("\nDigite o valor: ");
			scanf ("%d", &valor);
			printf ("\n1 - Inserir %d no in�cio", valor);
			printf ("\n2 - Inserir %d antes de algum elemento", valor);
			printf ("\n3 - Inserir %d no fim", valor);
			printf ("\nDigite: ");
			scanf ("%d", &opcao);
			
			if (opcao == 1) {
				insereInicio(valor);
				system("cls");
				printf ("\n%d foi inserido!\n", valor);
			}else if (opcao == 2) {
				printf ("\nDeseja inserir antes de qual valor?");
				printf ("\nDigite: ");
				scanf ("%d", &antes);
				insereAntes(valor, antes);
			} else if (opcao == 3) {
				insereFim(valor);
				system("cls");
				printf ("\n%d foi inserido!\n", valor);
			} else {
				printf ("\nOp��o inv�lida!");
			}
			
			
		} else if (opcao == 3) {
			mostrarElemento();
		} else if (opcao == 4){
			mostrarTodos();
		} else if (opcao == 5) {
			exit(0);
		} else {
			printf ("\nOp��o inv�lida!");
		}
	}
}

void insereInicio(int valor){
	
	struct no *NovoNo, *aux;
	NovoNo = (struct no*)malloc(sizeof(struct no));
	NovoNo -> valor = valor;
	
	/* Se primeiro igual a NULL ent�o � o primeiro elemento a ser adicionado
	* ent�o prox e ant ser�o apontados para ele mesmo
	*/
	
	if (primeiro == NULL) {
		NovoNo -> prox = NovoNo;
		NovoNo -> ant = NovoNo;
		primeiro = NovoNo;
		
	} else { // se n�o for primeiro elemento
		aux = primeiro -> ant;
		NovoNo -> ant = aux;
		NovoNo -> prox = primeiro;
		primeiro -> ant = NovoNo;
		aux -> prox = NovoNo;
		primeiro = NovoNo;
	}
	
}

void insereFim(int valor){
	struct no *NovoNo, *aux;
	NovoNo = (struct no*)malloc(sizeof(struct no));
	NovoNo -> valor = valor;
	
	// se n�o existir nenhum elemento
	if (primeiro == NULL) {
		NovoNo -> prox = NovoNo;
		NovoNo -> ant = NovoNo;
		primeiro = NovoNo;
	} else {
		aux = primeiro -> ant;
		NovoNo -> prox = primeiro;
		NovoNo -> ant = aux;
		primeiro -> ant = NovoNo;
		aux -> prox = NovoNo;
	}
 
}

void insereAntes(int valor, int antes) {

	struct no *NovoNo, *aux, *pAux;
	
	// Verifica se lista est� vazia
	if (primeiro == NULL) {
		printf ("\nLista est� v�zia");
		main();
	}
	
	/* se valor deve ser inserido antes do valor do primeiro elemento
	* chama a fun��o insereInicio
	*/
	if (antes == primeiro -> valor) {
		insereInicio(valor);
		system("cls");
		printf ("\n%d foi inserido!", valor);
		main();
		
	}
	
	// verifica��o se elemento antes existe ou n�o
	aux = primeiro;
	while (aux != NULL && aux -> valor != antes) {
		pAux = aux;
		aux = aux -> prox;
		
		// se aux � igual a primeiro ent�o n�o h� elemento igual a vari�vel antes
		if (aux == primeiro) {
			
			system("cls");
			printf ("\n%d n�o existe!\n", antes);
			main();
		}
	}
	
	NovoNo = (struct no*)malloc(sizeof(struct no));
	NovoNo -> valor = valor;
	NovoNo -> ant = pAux;
	NovoNo -> prox = aux;
	
	pAux -> prox = NovoNo;
	aux -> ant = NovoNo;
	
	system("cls");
	printf ("\n%d foi inserido!\n", valor);

}


void mostrarElemento(){
	struct no *temporario = primeiro;
	system("cls");
	
	if (temporario == NULL) {
		printf ("\nLista est� vazia!\n");
		main();
	}
	
	printf ("\nPrimeiro elemento: %d\n", temporario -> valor);
	
	for (;;) {
		
		printf ("\n1 - Pr�ximo");
		printf ("\n2 - Anterior");
		printf ("\n3 - Sair");
		printf ("\nO que voc� escolhe?: ");
		scanf ("%d", &opcao);
		system("cls");
		
		if (opcao == 1) {
			temporario = temporario -> prox;
			printf ("\n ------> %d", temporario -> valor);
			
		} else if (opcao == 2){
			temporario = temporario -> ant;
			printf ("\n ------> %d", temporario -> valor);
		} else if (opcao == 3) {
			main();
		} else {
			printf ("\n Op��o inv�lida!");
		}
	}
}

void mostrarTodos() {
	system("cls");
	struct no* temporario = primeiro;
	
	if (primeiro == NULL) {
		printf ("\nLista est� vazia!\n");
		
	} else {
		printf ("\n");
		printf (" |%d| ", temporario -> valor);
		if (temporario -> prox == temporario) {
			printf("\n");
			main();
		} else {
			temporario = temporario -> prox;
		}
		do {
			printf (" |%d| ", temporario -> valor);
			temporario = temporario -> prox;
			if (temporario == primeiro) {
				break;
			}
			
		} while (temporario -> prox != NULL);
		printf ("\n");
	}
	
}
