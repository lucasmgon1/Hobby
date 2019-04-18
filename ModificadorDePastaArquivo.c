#include <stdio.h>
#include <stdlib.h>

int main(){
	int escolha, cont; 
	char frase [100];
	FILE *ponteiro;
	
	do{
		printf("\n\n\t\tDeseja criar uma pasta?                1 - SIM\n\n");
		printf("\t\tCriar arquivo txt dentro dessa pasta?  2 - SIM\n\n");
		printf("\t\tExibir arquivo de teste?               3 - SIM\n\n");
		printf("\t\tDeseja deletar a pasta se existir?     4 - SIM\n\n");
		printf("\t\tSair?				       5 - SIM\n\n\t\t");
		scanf("%d", &escolha);
		
		system("cls || clear");
		
			if (escolha == 1){
				
				printf("\t\t\a\aCriando uma pasta\n\n\t\t");
				system("md TESTE || mkdir TESTE");	
		
			}else if (escolha == 2){
				printf("Digite o texto: ");
				scanf("%s", &frase[100]);
				
				#ifdef linux
					ponteiro = fopen ("TESTE/Novo_Arquivo.txt", "w");
				
				#elif defined _WIN32
					ponteiro = fopen ("TESTE\\Novo Arquivo.txt", "w");
				#endif
			
				fprintf(ponteiro,"%s",frase);
				fclose(ponteiro);
				
				if(ponteiro == NULL){
					printf("\n\n\t\tArquivo não pode ser criado");
				}
		
			}else if(escolha == 3){
			
			//	#ifdef linux
					ponteiro = fopen ("TESTE/Novo_Arquivo.txt", "r");
				
			//	#elif defined _WIN32
			//		ponteiro = fopen ("TESTE\\Novo Arquivo.txt", "r");
			//	#endif
				
				if (ponteiro == NULL){
					printf("\n\n\t\tArquivo não pode ser aberto");
				}
			
				while (fgets(frase,1000, ponteiro) != NULL){ // sem usar o laco, ele não exibe a quebra de linha
					printf("\n\n\t\t%s\n\n\t\t", frase);
				}
				
				system("pause");
				fclose(ponteiro);
							
			}else if(escolha == 4){
				
				printf("\t\t\a\aApagar Pasta Teste\n\n\t\t");
				system("rd /s TESTE || rm TESTE"); // /s vai pedir a confirmação para excluir um arquivo que esteja dentro da pasta, senão não vai excluir			

			}else if (escolha == 5){
				printf("\n\n\t\tSaindo\n\n");
				getchar();
				return 0;
			
			}else{
				printf("\n\n\t\tO programa nao reconhece esse caracter\n\n");
				system("pause");
			}
			system("cls || clear");
			printf("\n\n\t\t1 - Continuar ou 2 - Sair\n\n\t\t");
			scanf("%d", &cont);
			system("cls || clear");
		}while(cont == 1 || cont != 2);
}
