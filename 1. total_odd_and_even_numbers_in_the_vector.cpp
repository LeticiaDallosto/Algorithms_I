#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
    
	int values[6], countpair=0, countodd=0;
    
	for (int i=0; i<6; i++) {
	   	printf ("\nDigite o valor: "); 
    	scanf ("%d", &values[i]);
		
    	if (values[i] % 2 == 0) {
			countpair++;
		} else {
			countodd++;
		}
	}
	
	printf ("\nRELATORIO DE VALORES\n\n");
	for (int i=0 ; i<6 ; i++) {
		printf ("\nValor %d: %d \n", i+1, values[i]);
	}
	
	printf ("\nTotal pares: %d\n", countpair);	
	printf ("\nTotal impares: %d\n", countodd);

	return 0;
}
 
