#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


int main () {
    setlocale(LC_ALL, "Portuguese");
	
	int i, code[10], count_readjustment = 0, count_n_readjustment = 0;
	float cost[10], readjustment, sum = 0;
    
    for (i = 0; i < 10; i++) {
	    printf("\nDigite o codigo do produto: ");
	        scanf("%d", &code[i]);
	    printf("Digite o preco do produto: ");
	        scanf("%f", &cost[i]);
    
		if ((code[i] % 2 == 0) && (cost[i] > 100)) {
			readjustment = cost[i] * 1.3;
			count_readjustment++;
		} else if (code[i] % 2 == 0) {
			readjustment = cost[i] * 1.2;	
			count_readjustment++;
		} else if (cost[i] > 100) {
			readjustment = cost[i] * 1.15;	
			count_readjustment++;
		} else {
			readjustment = cost[i];
			count_n_readjustment++;
		}
		cost[i] = readjustment;
		sum = sum + cost[i];
	}
		
	printf ("\n\nRELATORIO DO REAJUSTE\n");
	for (i = 0; i < 10; i++) {
		printf ("\n Codigo do %dº produto : %d  |  Reajuste do %dº produto : %.2f \n", i+1, code[i], i+1, cost[i]);
	}
	
	printf ("\n\nRELATORIO QUANTIDADE DE PRODUTOS COM OU SEM REAJUSTE\n");	
	printf ("\nTotal de produtos COM reajuste: %d\n", count_readjustment);	
	printf ("\nTotal de produtos SEM reajuste: %d\n", count_n_readjustment);
	
	printf ("\n\nRELATORIO DA MEDIA DOS PRECOS APOS ATUALIZACAO DOS REAJUSTES\n");	
	printf ("\nA media de preco dos produtos reajustados e de R$ %.2f\n", (sum/10));
	
	return 0;
			
	}
	


