#include <stdio.h>
#include <stdlib.h>
#define MAX 5

main(){
	int idade;
	int i;
	int escolha;
	
	int vet[MAX];
	int vet2[MAX];
	int ultimo=0;									//PARA USO DO VETOR DE IDADE NORMAL
	int primeiro=0;
	int total=0;
	
	
	int cont=1;
	int ultimo2=0;
	int primeiro2=0;								//PARA USO DO VETOR PREFERENCIAL
	int total2=0;
	int cont2=100;									//CONT 100 PARA DIFERENCIAR FILAS
	
	
	for(i=0;i<MAX;i++){
		vet[i]=NULL;
	}									
	for(i=0;i<MAX;i++){
	vet2[i]=NULL;
	}
	
	for(;;){
		printf("1- Inserir, 2- Remover, 3- Listar  \n");
		scanf("%d", &escolha);
		
		if(escolha==1){
			printf("Qual a idade da pessoa? ");
			scanf("%d", &idade);
			if(idade<60){
				if(total<MAX){
					if(ultimo==(MAX-1)){													 		//SE FOR O ULTIMO ELEMENTO, APONTA PRO PROXIMO IR NO LUGAR 0
						vet[ultimo]=cont;
						ultimo=0;
						printf("Usuario senha numero %d  \n\n", cont);
						total++;
						cont++;
					}else{
						vet[ultimo]=cont;
						ultimo++;
						total++;
						printf("Usuario senha numero %d \n \n", cont);
						cont++; 
					}
				}else if(total=MAX){
					printf("Vetor cheio! \n\n");
				}	
				
			}else if(idade>60){
				if(total2<MAX){
					if(ultimo2==(MAX-1)){
						vet2[ultimo2]=cont2;
						ultimo2=0;
						printf("Usuario senha n %d  \n\n", cont2);
						total2++;
						cont2++;
					}else{
						vet2[ultimo2]=cont2;
						ultimo2++;
						total2++;
						printf("Usuario senha n %d \n \n", cont2);
						cont2++; 
					}
				}else if(total2=MAX){
					printf("Vetor cheio! \n\n");
				}	
				
		}
		
		
		}else if(escolha==3){
			printf("\nFila normal: ");
			for(i=0;i<MAX;i++){
			printf("%d ,", vet[i]);
			}
			printf("\n");
			printf("Fila preferencial: ");
			for(i=0;i<MAX;i++){
			printf("%d ,", vet2[i]);
			}
			printf("\n\n\n");
			
			
			
		}else if(escolha==2){
			if(total2==0){
				if(total==0){
					printf("Vetor vazio!! \n\n");
				}else if (primeiro==(MAX-1)){
					vet[primeiro]=NULL;
					primeiro=0;			
					total--;
					printf("Usuario removido com sucesso! \n\n");
				}else{
				vet[primeiro]=NULL;
				primeiro++;
				total--;
				printf("Usuario removido com sucesso! \n\n");
				}
				
			}else{
					if(total2==0){
					printf("Vetor vazio!! \n\n");
				}else if (primeiro2==(MAX-1)){
					vet2[primeiro2]=NULL;
					primeiro2=0;			
					total2--;
					printf("Usuario removido! \n\n");
				}else{
				vet2[primeiro2]=NULL;
				primeiro2++;
				total2--;
				printf("Usuario removido! \n\n");
				}
			}
		}
	}
}
