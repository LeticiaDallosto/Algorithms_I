/* Giuliano Pereira, Letícia Dall Osto e Thaíse F. Machado Souto */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

char escolha_sim_ou_nao(){
    char escolha;
    do {
		printf("  + [S]  Sim                                                      +\n");
	    printf("  + [N]  Não                                                      +\n");
	    
	    scanf(" %c", &escolha);
	    escolha = toupper(escolha);
	    	    	      
	    if (escolha != 'S' && escolha != 'N') {
	    	printf("Valor inválido, redigite!\n");
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
	    	printf("Valor inválido, redigite!\n");
	    }
	    
	} while ((modo_doacao != 'R') && (modo_doacao != 'P'));
      
    return modo_doacao;
}

int mostra_menu_instituicoes(){
    int instituicao;
    char entrada[10];
    do {
		printf("  + Para qual instituição você deseja fazer a doação?	       	  +\n");
	    printf("  + [1] IAPC - Instituto de Amparo às Pessoas com Câncer          +\n");
	    printf("  + [2] APAE - Associação de Pais e Amigos dos Excepcionais       +\n");
	    printf("  + [3] SOAMA - Sociedade Amigos dos Animais                      +\n");
	
	    scanf("%s", entrada);
        if (strcmp(entrada, "1") == 0) {
            instituicao = 1;
        } else if (strcmp(entrada, "2") == 0) {
            instituicao = 2;
        } else if (strcmp(entrada, "3") == 0) {
            instituicao = 3;
        } else {
            printf("Valor inválido, redigite!\n");
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
        printf("  +----+---+---+---+  Sistema de Gestão de Doações ---+---+---+---+\n");
        printf("  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
        printf("  + Você deseja fazer doações recorrentes ou uma doação pontual?  +\n");
        
        modo_doacao = escolha_modo_doacao();
      
        do {
		
			if (modo_doacao == 'R') {
	         	printf("  + Por quantos meses?                                            +\n");
	        	scanf("%d", &n_meses);
	        	
				if (n_meses <= 0 || n_meses > 12) {
					printf("Valor inválido, redigite!\n");
				}
	        }
				
		} while (n_meses <= 0 || n_meses > 12);
		
        do {
		
			printf("  + Digite o Valor da doação:                                     +\n");
	        scanf("%f", &valor_doacao);
	        
	        if (valor_doacao <= 0) {
	        	printf("Valor inválido, redigite!\n");
			}
        
    	} while (valor_doacao <= 0);
    	
        valor_total = valor_total + valor_doacao * n_meses;

        printf("  + Você deseja dividir o valor da doação igualmente para as instituições associadas ao programa? \n");
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
        
	    printf("  + Você deseja fazer uma nova doação? \n");
	    escolha = escolha_sim_ou_nao();
	    
		if(escolha == 'N') break;
		cont_doacao++;
	}
	
	printf("\nQuantidade de doações: %d", cont_doacao);
	printf("\nMédia de valor das doações: R$%.2f", valor_total/cont_doacao);
	printf("\nValor total arrecadado: R$%.2f", valor_total);
	printf("\nTotal de arrecadações IAPC: R$%.2f, representando %.2f ", IAPC, ((IAPC/valor_total)*100));
	printf("\nTotal de arrecadações APAE: R$%.2f, representando %.2f ", APAE, ((APAE/valor_total)*100));
	printf("\nTotal de arrecadações SOAMA: R$%.2f representando %.2f ", SOAMA, ((SOAMA/valor_total)*100));
	
}


