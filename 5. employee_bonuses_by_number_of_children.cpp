#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int employees;
	char classification[4]= {'A', 'B', 'C', 'D'};
	float total_bonus[4] = {0.0, 0.0, 0.0, 0.0};
	float count_employees[4] = {0.0, 0.0, 0.0, 0.0};
		   
	do {
        printf("\nDigite a quantidade de funcionarios (maximo 100): ");
        scanf("%d", &employees);
        if ((employees <=0 ) || (employees > 100)) {
        	printf("Quantidade invalida, redigite. ");	
		}
    } while ((employees <= 0) || (employees > 100));
    
    float wage[employees], bonus [employees];
    int i, children [employees];
    char placing[employees];
    
	for (i = 0; i < employees; i++) {
	    printf("\nDigite o salario do funcionario: ");
	        scanf("%f", &wage[i]);
	    printf("Digite a quantidade de filhos do funcionario: ");
	        scanf("%d", &children[i]);
	    
		if (wage[i] <= 1000.00) {
			placing[i] = 'D';
			bonus[i] = 20.00 * children[i];
			total_bonus[3] += bonus[i];
			count_employees[3]++;
		} else if ((wage[i] > 1000.00) && (wage[i] <= 2000.00)){
			placing[i] = 'C';
			bonus[i] = 15.00 * children[i];
			total_bonus[2] += bonus[i];
			count_employees[2]++;
		} else if ((wage[i] > 2000.00) && (wage[i] <= 3000.00)){
			placing[i] = 'B';
			bonus[i] = 10.00 * children[i];
			total_bonus[1] += bonus[i];
			count_employees[1]++;
		} else {
			placing[i] = 'A';
			bonus[i] = 5.00 * children[i];
			total_bonus[0] += bonus[i];
			count_employees[0]++;
		}
		
		printf ("\nRELATORIO DO FUNCIONARIO");
		printf ("\nClassificacao: % c ", placing[i]);
		printf ("\nBonus: %.2f \n\n", bonus[i]);
		
	}
	
	
	printf ("\nRELAT�RIO FINAL POR CLASSIFICA��O");
	for (i = 0; i < 4; i++) {
		float percent = 100 * count_employees[i] / employees;
		printf ("\n CLASSIFICACAO: %c |  Bonus total: %.2f  |  Percentual na empresa: %.2f %", classification[i], total_bonus[i], percent);
	}
	
	return 0;
}


	
 	


    


