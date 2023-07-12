/* Giuliano Pereira, Let�cia Dall Osto e Tha�se F. Machado Souto */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

char escolha_sim_ou_nao(){
    char escolha;
    do {
		printf("  + [S]  Sim                                                      +\n");
	    printf("  + [N]  N�o                                                      +\n");
	    
	    scanf(" %c", &escolha);
	    escolha = toupper(escolha);
	    	    	      
	    if (escolha != 'S' && escolha != 'N') {
	    	printf("Valor inv�lido, redigite!\n");
    	}
    	
  	} while ((escolha != 'S') && (escolha != 'N'));
  	
  	return escolha;
}

char escolha_modo_doacao(){
    char modo_doacao;
    do {
		printf("  + [R]  Recorrente                                               +\n");
	    printf("  + [P]  Pontual                                                  +\n");
	
	    scanf(" %c", &modo_doacao);
	    modo_doacao = toupper(modo_doacao);
	   	    	    
	    if (modo_doacao != 'R' && modo_doacao != 'P') {
	    	printf("Valor inv�lido, redigite!\n");
	    }
	    
	} while ((modo_doacao != 'R') && (modo_doacao != 'P'));
      
    return modo_doacao;
}

int mostra_menu_instituicoes(){
    int instituicao;
    char entrada[10];
    do {
		printf("  + Para qual institui��o voc� deseja fazer a doa��o?	       	  +\n");
	    printf("  + [1] IAPC - Instituto de Amparo �s Pessoas com C�ncer          +\n");
	    printf("  + [2] APAE - Associa��o de Pais e Amigos dos Excepcionais       +\n");
	    printf("  + [3] SOAMA - Sociedade Amigos dos Animais                      +\n");
	
	    scanf("%s", entrada);
        if (strcmp(entrada, "1") == 0) {
            instituicao = 1;
        } else if (strcmp(entrada, "2") == 0) {
            instituicao = 2;
        } else if (strcmp(entrada, "3") == 0) {
            instituicao = 3;
        } else {
            printf("Valor inv�lido, redigite!\n");
            continue;
        }
    } while (instituicao < 1 || instituicao > 3);
    
	return instituicao;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
    
	int cont_doacao = 1;
	float IAPC  = 0.0 , APAE  = 0.0, SOAMA = 0.0, valor_total = 0.0, media_doacao = 0.0;    
    while (true){
        char escolha;
    	char modo_doacao;
		int instituicao, n_meses = 1;
        float valor_doacao;

        printf("  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
        printf("  +----+---+---+---+  Sistema de Gest�o de Doa��es ---+---+---+---+\n");
        printf("  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
        printf("  + Voc� deseja fazer doa��es recorrentes ou uma doa��o pontual?  +\n");
        
        modo_doacao = escolha_modo_doacao();
      
        do {
		
			if (modo_doacao == 'R') {
	         	printf("  + Por quantos meses?                                            +\n");
	        	scanf("%d", &n_meses);
	        	
				if (n_meses <= 0 || n_meses > 12) {
					printf("Valor inv�lido, redigite!\n");
				}
	        }
				
		} while (n_meses <= 0 || n_meses > 12);
		
        do {
		
			printf("  + Digite o Valor da doa��o:                                     +\n");
	        scanf("%f", &valor_doacao);
	        
	        if (valor_doacao <= 0) {
	        	printf("Valor inv�lido, redigite!\n");
			}
        
    	} while (valor_doacao <= 0);
    	
        valor_total = valor_total + valor_doacao * n_meses;

        printf("  + Voc� deseja dividir o valor da doa��o igualmente para as institui��es associadas ao programa? \n");
        escolha = escolha_sim_ou_nao();

        if(escolha == 'N'){
          instituicao = mostra_menu_instituicoes();
          
        	switch (instituicao) {
				case 1:
					IAPC = IAPC + valor_doacao * n_meses;
        			break;
        		case 2:
        			APAE = APAE + valor_doacao * n_meses;
        			break;
        		case 3:
        			SOAMA = SOAMA + valor_doacao * n_meses;
        			break;
        	}
        
            } else {
            float quantia = valor_doacao / 3.0;
            IAPC = IAPC + quantia * n_meses; 
            APAE = APAE + quantia * n_meses;
            SOAMA = SOAMA + quantia * n_meses;
        }
        
	    printf("  + Voc� deseja fazer uma nova doa��o? \n");
	    escolha = escolha_sim_ou_nao();
	    
		if(escolha == 'N') break;
		cont_doacao++;
	}
	
	printf("\nQuantidade de doa��es: %d", cont_doacao);
	printf("\nM�dia de valor das doa��es: R$%.2f", valor_total/cont_doacao);
	printf("\nValor total arrecadado: R$%.2f", valor_total);
	printf("\nTotal de arrecada��es IAPC: R$%.2f, representando %.2f ", IAPC, ((IAPC/valor_total)*100));
	printf("\nTotal de arrecada��es APAE: R$%.2f, representando %.2f ", APAE, ((APAE/valor_total)*100));
	printf("\nTotal de arrecada��es SOAMA: R$%.2f representando %.2f ", SOAMA, ((SOAMA/valor_total)*100));
	
}


