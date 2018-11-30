#include <stdlib.h>
#include <stdio.h>

struct no{
		int cor=0;
		int tamanho=0;
		int incid=0;
		int flag=0;
	};
	
	struct no grafo[8][8];

int qualMaior(no[8][8]) {
	int maior=0;
	int i=0;
	
	for(i=0;i<8;i++){
		if(((grafo[i][i].tamanho)>=maior)&&(grafo[i][i].flag==0)){
			maior = i;
		}
	}
		grafo[maior][maior].flag = 1;
		return maior;
}


main(){
	

	int i=0;
	int j=0;
	int cor=0;
	int maiorGraf=0;
	int maiorCor=0;
	
	
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			system("cls");
			printf("Qual a incidencia o no %d tem no no %d? ", i+1, j+1);
			scanf(" %d", &grafo[i][j].incid);
			if(grafo[i][j].incid>0){
				grafo[i][i].tamanho++;
			}
		}
	}
	
	printf("\nA matriz de incidencia do grafo e:\n");
	
	for(i=0;i<8;i++){
		printf("O no %d do grafo tem incidencias: ", i+1);
		for(j=0;j<8;j++){
			printf("%d ", grafo[i][j].incid);
		}
		printf("\n");
	}
	
	
		for(i=0;i<8;i++){
			maiorGraf = qualMaior(grafo);
			j=0;
			
			for(j=0;j<8;j++){
				if((grafo[maiorGraf][maiorGraf].cor==grafo[j][j].cor)&&(grafo[maiorGraf][j].incid>0)&&(maiorGraf!=j)){
					cor++;
					j=0;
					grafo[maiorGraf][maiorGraf].cor=cor;
				}
				if(cor>maiorCor){
				maiorCor=cor;
				}
			}
		
			cor=0;
		}
		
	
	for(i=0;i<8;i++){
			printf("\nA cor do no %d e %d", i, grafo[i][i].cor);
	}
	
	
	
	printf("\nA quantidade necessaria de cores para pintar esse grafo de forma que duas cores identicas nao se encostem e %d", maiorCor+1);
	
	return 0;
	
}
