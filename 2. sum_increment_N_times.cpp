#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
    
	int A, N, sum=0, i;
	
	printf ("\nDigite o valor de A: ");
	scanf ("%d", &A);

	do {
        printf("Digite o valor de N (maior que zero): ");
        scanf("%d", &N);
    } while (N <= 0);
	
    for (i = A; i < A + N; i++) {
        sum += i;
    }

    printf("A soma dos %d numeros a partir de %d : %d\n", N, A, sum);

    return 0;
}
	


