#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

    int number;
    int vector[20];
    int count = 0;

    printf("Digite um numero inteiro de 1 a 50: ");
    scanf("%d", &number);

    if (number >= 1 && number <= 50) {
        for (int i = 1; i <= number; i++) {
            if (number % i == 0) {
                vector[count] = i;
                count++;
            }
        }
			
        if (count > 0) {
            printf("Valores divisiveis por %d:\n", number);
            for (int i = 0; i < count; i++) {
            	printf("%d ", vector[i]);
            }
            printf("\n");
        } else {
            printf("Nao possui divisores\n");
        }
    } else {
        printf("Numero invalido!\n");
    }

    return 0;
}

