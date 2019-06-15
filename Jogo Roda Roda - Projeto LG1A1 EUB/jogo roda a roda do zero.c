#include <stdio.h> //SÓ VIADO JOGA ESSA PORRA
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//STRUCTS//

typedef struct{
	char pista[17];
	int qtd;
	char vetpalavras[3][17];
} 
cadastro;

//VARIÁVEIS GLOBAIS//

cadastro cdstr;
char opcao;


void gravaDados (void){
	
	FILE *arq;
	
	arq = fopen ("palavras.dat", "a"); // Abre um arquivo texto para gravação e leitura. 
								   	   // Os dados serão adicionados no fim do arquivo se ele já existir, 
									   // ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
	if (arq == NULL){ // caso o arquivo dê erro
		system("cls");
		printf("Ocorreu um erro ao gravar dados no arquivo PALAVRAS.DAT");
	}
		else{
			fwrite(&cdstr, sizeof(cdstr), 1, arq);
	}
	fclose(arq);
}

void leDados (void){

	system("cls");
	printf("===============================================\n");
	printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
	printf("===============================================\n");
	printf("  	   								     	   \n");
	printf("	    2. Consultar Palavras		\n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("===============================================\n\n");
	printf("VOCE ESCOLHEU A OPCAO DE CONSULTAR PALAVRAS!   \n");
	printf("Pressione ENTER para continuar.");
	getch();
	system("cls");
	
	printf("===============================================\n");				
	printf("	   BANCO DE DADOS DE PALAVRAS		       \n");
	printf("===============================================\n"); 
	FILE * arq; 
	
	arq = fopen ("palavras.dat", "r");
	
	if (arq == NULL){
		system("cls");
		printf("Ocorreu um erro ao ler o arquivo PALAVRAS.DAT");
	}
		else{
			while(!feof(arq)){ // Enquanto não houver o término do arquivo 
				fread(&cdstr, sizeof(cdstr), 1, arq); // É lido todo o arquivo
					if(!feof(arq)){	// se não houver o término do arquivo, faça:
						printf("\nPISTA:[%16s]", cdstr.pista);
						printf("   QTD:[%2d]", cdstr.qtd);
						printf("	   PALAVRAS:[%16s] [%16s] [%16s]", cdstr.vetpalavras[0], cdstr.vetpalavras[1], cdstr.vetpalavras[2]);
						
					}
			}		
		}
	printf("\n\nPressione ENTER para voltar ao MENU PRINCIPAL.");
	getch();
}

void cadastraDados (void){
	
	system("cls");
	
	printf("===============================================\n");
	printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
	printf("===============================================\n");
	printf("  	    1. Cadastrar Palavras		\n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("===============================================\n\n");
	printf("VOCE ESCOLHEU A OPCAO DE CADASTRO!\n");
	printf("Pressione ENTER para continuar.");
	getch();
	
	system ("cls");
	
	int i;
	
	printf("===============================================\n");
	printf("	   CADASTRO DE PALAVRAS     		       \n");
	printf("===============================================\n");
	printf("Digite a pista da(s) palavra(s): ");
	fflush(stdin);
	gets(cdstr.pista);
	
	printf("\nInforme a quantidade de palavras a serem cadastradas: ");
	scanf("%d", &cdstr.qtd);
	fflush(stdin);
	
	for (i=0; i<cdstr.qtd; i++){
		printf("Digite a %da palavra: ", i + 1);
		gets(cdstr.vetpalavras[i]);
	}
	
	gravaDados();
	
	getch();
}

void admin (void){
	
	system("cls");
	
	do{
		printf("===============================================\n");
		printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
		printf("===============================================\n");
		printf("  	    1. Cadastrar Palavras		\n");
		printf("	    2. Consultar Palavras		\n");
		printf("	    3. Jogar					\n");
		printf("	    S. Sair						\n");
		printf("===============================================\n\n");
		printf("Escolha uma opcao: ");
		opcao = getch();
			
	} while(opcao != 's' && opcao != 'S' && opcao != '1' && opcao != '2' && opcao != '3');
	
	switch(opcao){
		
		case '1':
		{
			cadastraDados();
		}
		break;
		
		case '2':
		{
			leDados();
		}
		break;
		
		case 'S':
		{
			printf("Voce decidiu sair. O jogo foi encerrado.");
			exit (0);
		}
		break;
		
		case 's':
		{
			printf("Voce decidiu sair. O jogo foi encerrado.");
			exit (0);
		}
		break;	
	}
}

main(){
	do{
		admin();
	} while (opcao != 'S' && opcao != 's');
}
