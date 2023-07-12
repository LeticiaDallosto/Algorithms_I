#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
			
	int A[5];
	
	for ( int i = 0; i < 5; i++) {
		printf ("Digite o valor: ");
		scanf ("%d", &A[i]);
	}

	for ( int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (A[i] < A[j]) {
				int aux = A[i];
				A[i] = A[j];
				A[j] = aux;
			}
		}
	}

	printf("\nORDEM CRESCENTE");
	for ( int i = 0; i < 5; i++) {
		printf("\n%d", A[i]);
	}

	for ( int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (A[i] > A[j]) {
				int aux = A[i];
				A[i] = A[j];
				A[j] = aux;
			}
		}
	}

	printf("\nORDEM DECRESCENTE");
	for ( int i = 0; i < 5; i++) {
		printf("\n%d", A[i]);
	}
	
	return 0;

}
