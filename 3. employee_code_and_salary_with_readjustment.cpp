#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
			
	int i, code[5];
	float wage[5];

	for (i = 0; i < 5; i++){
	printf ("Digite o codigo do funcionario: ");
	scanf ("%d", &code[i]);
	printf ("Digite o salario do funcionario: ");
	scanf ("%f", &wage[i]);
	}
		
	printf("\nFuncionarios que possuem salario maior de R$2.500,00\n");
	for (i = 0; i < 5; i++) {
		if (wage[i] > 2500) {
			printf ("O codigo do funcionario: %d, e o salario do funcionario: %.2f \n", code[i], wage[i]);
		}
	}
	
	printf("\nAumento funcionarios que possuem salario menor de R$1.200,00\n");
	for (i = 0; i < 5; i++) {
		if (wage[i] < 1200) {
			wage[i] = wage[i] * 1.2;
			printf ("O codigo do funcionario: %d, e o salario ajustado do funcionario: %.2f \n", code[i], wage[i]);
		}
	}
		
	return 0;
}
	
	
