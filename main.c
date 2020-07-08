#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPA_TELA system("cls")
#define BUFFER 64
#include "lista.h"

int checa_vazio(listas_t *dados)
{

	if (dados == NULL)
	{
		printf("Lista vazia!\n");
		getchar();
		return 1;
	}
	else
		return 0;
}
int main(void)
{
	char escolha;
	int chave = 0;
	do {

		LIMPA_TELA;
		printf("\nAGENDA ELETRONICA\n\n");
		printf("Escolha uma opcao: \n");
		printf("<1> - Criar lista vazia\n");
		if (chave == 1)
		{
			printf("<2> - Inserir no Inicio de uma lista\n");
			printf("<3> - Inserir no Fim de uma lista\n");
		}

		printf("<4> - Lista Vazia...\n");
		if (chave == 1)
		{
			printf("<5> - Exibir dados do primeiro elemento\n");
			printf("<6> - Exibir dados do ultimo elemento\n");
			printf("<7> - Exibir todos os valores da Lista\n");
			printf("<8> - Exibir o tamanho da Lista\n");
			printf("<9> - Eliminar primeiro elemento\n");
			printf("<a> - Eliminar ultimo elemento\n");
			printf("<b> - Eliminar elemento buscado\n");
			printf("<c> - Busca Dados\n");
		}

		printf("<d> - Sair\n\n");
		printf("Sua escolha: ");
		scanf("%c", &escolha);
		if ((chave == 0) && ((escolha != '1') && (escolha != 'd') && (escolha != '4')))
			escolha = 'z';
		switch (escolha)
		{
			case '1':
				chave = 1;
				criavazia();
				break;
			case '2':
				insereinicio();
				break;
			case '3':
				if (principal != NULL){
					inserefim();
					}
				else{
					insereinicio();
					}
				break;
			case '4':
				listavazia();
				break;
			case '5':
				prielemento();
				break;
			case '6':
				ultelemento();
				break;
			case '7':
				exibe();
				break;
			case '8':
				exibetam();
				break;
			case '9':
				deletapri();
				break;
			case 'a':
				deleta();
				break;
			case 'b':
				delbusca();
				break;
			case 'c':
				busca();
				break;
			case 'd':
				printf("Obrigado por utilizar a agenda eletronica!\n");
				exit(0);
				break;
			default:
				printf("Digite uma opcao valida (pressione -Enter- p/ continuar)!\n");
				getchar();
				break;
		}
		getchar();
	}

	while (escolha > 0);
	return 0;
}

