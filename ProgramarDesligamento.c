#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//Ajustar Cores do terminal
	system("setterm -foreground white -background blue || color 71");
	
	unsigned short int opc;
	int ret2;	//Dependendo da IDE, pode mostrar que não esta em uso essa variavel
	int tempo;
	char desligar[100];
	
	do{
		system("clear || cls");
		
		printf("\t*********************************************************\n"
			   "\t*		1 - Programar Desligamento		*\n"
			   "\t*		2 - Sobre				*\n"
			   "\t*		0 - Sair		  		*\n"
			   "\t*********************************************************\n\t");
		scanf("%hu", &opc);
		
		switch(opc){
			case 1:
				
				printf ("\tDigite os minutos:\n\t");	//E/S dos minutos a desligar
				scanf("%d", &tempo);
				tempo *=60;
				
				#ifdef linux
					ret2 = sprintf(desligar, "sudo shutdown -h +%d", tempo);
					ret2 = system(desligar);
				
				#elif defined _WIN32
					ret2 = sprintf(desligar, "shutdown -s -t %d", tempo); //formata a string desligar
					printf("ret2 = %d\n", ret2);	//exibe o valor de retorno da função sprintf
					ret2 = system(desligar);	//usa system() para executar o comando formatado com a função sprintf()				
				#endif
			break;
			
			case 2:
				system("clear || cls");
				printf("\n\n\t\t 2017 - Lucas Matheus Gonçalves\n"
					   "\t\tEste programa é um software livre.\n"
					   "\t\tVocê pode redistribuí-lo e/ou modificá-lo de acordo\n" 
					   "\t\tcom os termos da Licença do repositório no GitHub.\n" 
					   "\n"
					   "\t\tEste programa é distribuído na esperança de que seja útil,\n"
					   "\t\tmas sem qualquer garantia;\n\n"
					   "\t\tBrasil, 31 de Dezembro de 2017");
				system("pause || sleep 3000");
			break;
		}
		
	}while(opc !=1 && opc != 2 && opc !=3 && opc !=0);
	return 0;
}
