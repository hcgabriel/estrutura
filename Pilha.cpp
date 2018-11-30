#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main(){
	
	int escolha;
	int pilha[4];
	int valor;
	int j=0;
	int i=0;	
	
	for(;;){
	printf("1- Inserir, 2- Remover, 3- Listar  \n");
	scanf("%i", &escolha);
	printf("\n");
				
	 	if(escolha==1){
	 		if(i==MAX){
    			printf("Pilha esta cheia\n");
			}
    		else{
				printf("Digite o valor que voce deseja inserir\n");
	    		scanf("%i",&pilha[i]);
	    		printf("\n");
    			i++;	
    		}
    	} 

		
		if(escolha==2){	
			pilha[i-1]=0;
			i--;
		}
		
		if(escolha==3){
			for(j=0;j<i;j++){
			printf("%d", pilha[j]);
			printf("\n");
			}
		}
    }
}
