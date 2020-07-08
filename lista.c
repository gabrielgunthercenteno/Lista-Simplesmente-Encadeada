#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPA_TELA system("cls")
#define BUFFER 64
#include "lista.h"

listas_t *principal = NULL;

void criavazia(void)
{
	char   *nome;
	char  *email;
	int    idade;
	int telefone;

	nome  = (char*) malloc(BUFFER);
    email = (char*) malloc(BUFFER);

	printf("\n\nDigite o Nome: \n----> ");
	scanf("%s",nome);
	printf("\n");

	printf("\n\nDigite o E-mail: \n----> ");
	scanf("%s",email);
	printf("\n");

	printf("Digite a Idade: \n----> ");
	scanf("%d",&idade);
	printf("\n");

	printf("Digite o Telefone: \n----> ");
	scanf("%d",&telefone);
	printf("\n");

	principal = inicia_dados(nome, idade, email, telefone);
}


listas_t* inicia_dados(char *nome, int idade, char *email, int telefone)
{
	listas_t * novo;

	novo  = (listas_t*) malloc(sizeof(listas_t));

	novo->nome = (char*) malloc(strlen(nome) + 1);
	  strncpy(novo->nome, nome, strlen(nome) + 1);

    novo->email = (char*) malloc(strlen(email) + 1);
     strncpy(novo->email, email, strlen(email) + 1);

	novo->idade = idade;

	novo->telefone = telefone;

	novo->proximo = NULL;
	return novo;
}
void insereinicio(void)
{
	char   *nome;
	char  *email;
	int    idade;
	int telefone;

	nome  = (char*) malloc(BUFFER);
	email = (char*) malloc(BUFFER);

	printf("\n\nDigite o Nome: \n----> ");
	scanf("%s",nome);
	printf("\n");

	printf("\n\nDigite o E-mail: \n----> ");
	scanf("%s",email);
	printf("\n");

	printf("Digite a Idade: \n----> ");
	scanf("%d",&idade);
	printf("\n");

	printf("Digite  Telefone: \n----> ");
	scanf("%d",&telefone);
	printf("\n");

	principal = insere_dados(principal, nome, idade, email, telefone);
}
listas_t* insere_dados(listas_t *dados, char *nome, int idade, char *email, int telefone)
{
	listas_t * inicio;

	inicio = (listas_t*) malloc(sizeof(listas_t));

	inicio->nome = (char*) malloc(strlen(nome) + 1);
	  strncpy(inicio->nome, nome, strlen(nome) + 1);

    inicio->email = (char*) malloc(strlen(email) + 1);
     strncpy(inicio->email, email, strlen(email) + 1);

	inicio->idade = idade;

	inicio->telefone = telefone;

	inicio->proximo = dados;
	return inicio;
}
void inserefim(void)
{
	char   *nome;
	char  *email;
	int    idade;
	int telefone;

	nome  = (char*) malloc(BUFFER);
	email = (char*) malloc(BUFFER);

	printf("\n\nDigite o Nome: \n----> ");
	scanf("%s",nome);
	printf("\n");

	printf("\n\nDigite o E-mail: \n----> ");
	scanf("%s",email);
	printf("\n");

	printf("Digite a Idade: \n----> ");
	scanf("%d",&idade);
	printf("\n");

	printf("Digite o Telefone: \n----> ");
	scanf("%d",&telefone);
	printf("\n");

	listas_t *final, *aux;

	final = (listas_t*) malloc(sizeof(listas_t));

	final->nome = (char*) malloc(strlen(nome) + 1);
	  strncpy(final->nome, nome, strlen(nome) + 1);

	final->email = (char*) malloc(strlen(email) + 1);
	  strncpy(final->email, email, strlen(email) + 1);

	final->idade = idade;

	final->telefone = telefone;

	final->proximo = NULL;

	aux = principal;

	while (aux->proximo != NULL)
	{
	    aux = aux->proximo;
	}
	aux->proximo =  NULL;
	aux->proximo = final;
}
void listavazia(void)
{
	if (principal == NULL)
		printf("\n\nLista esta Vazia!\n\n ");
	else
		printf("\n\nLista nao esta Vazia!\n\n ");
	getchar();
}
void prielemento(void)
{
	printf("------------------------\n");
	printf("Nome: %s\n",principal->nome);
	printf("E-mail: %s\n",principal->email);
	printf("Idade: %d\n",principal->idade);
		printf("Telefone: %d\n",principal->telefone);
	printf("------------------------\n");
	getchar();
}
void ultelemento(void)
{
	listas_t *aux = principal;

	while (aux->proximo != NULL)
	{
		aux = aux->proximo;
	}

	printf("------------------------\n");
	printf("Nome: %s\n",aux->nome);
	printf("E-mail: %s\n",aux->email);
	printf("Idade: %d\n",aux->idade);
	printf("Telefone: %d\n",aux->telefone);
	printf("------------------------\n");
	getchar();
}
void exibe(void)
{
	if (!checa_vazio(principal))
		exibe_dados(principal);
}
void exibe_dados(listas_t *dados)
{
	printf("Cadastro:\n\n");
	printf("------------------------\n");

	for (; dados != NULL; dados = dados->proximo)
	{
		printf("Nome: %s\n",dados->nome);
		printf("E-mail: %s\n",dados->email);
		printf("Idade: %d\n",dados->idade);
		printf("Telefone: %d\n",dados->telefone);
		printf("------------------------\n");
	}
	getchar();
}
void exibetam(void)
{
	if (!checa_vazio(principal))
		exibe_tamanho(principal);
}
void exibe_tamanho(listas_t *nova)
{
	int aux = 0, tamanho = 0;
	printf("\n------------------------\n");

	for (; nova != NULL; nova = nova->proximo)
	{
		aux++;
		tamanho += sizeof(nova);
	}
	printf("Total de Elementos: %d\nTamanho Total: %d bytes\n", aux, tamanho);
	printf(stdout, "------------------------\n");
	getchar();
}
void deletapri(void)
{
	if (!checa_vazio(principal))
		principal = deleta_dados(principal, 1);
}
void deleta(void)
{
	if (!checa_vazio(principal))
		principal = deleta_dados(principal, 2);
}
listas_t* deleta_dados(listas_t *dados, int nTipo)
{
	if (nTipo == 1)
	{
		listas_t * novo;
		novo = dados->proximo;
		free(dados->nome);
		free(dados);
		printf("O primeiro registro foi deletado  com sucesso.\n");
		getchar();
		return novo;
	}
	if (nTipo == 2)
	{
		listas_t *novo = dados, *aux = dados;
		if (novo->proximo == NULL)
		{
			free(novo);
			aux = NULL;
		}
		else
		{
			while (novo->proximo != NULL)
			{
				novo = novo->proximo;
			}
			while (aux->proximo != novo)
			{
				aux = aux->proximo;
			}
			free(novo);
			aux->proximo = NULL;
		}
		printf("O ultimo registro foi deletado com sucesso.\n");
		getchar();
		return aux;
	}
}
void delbusca(void)
{
	char *chave;
	if (!checa_vazio(principal))
	{
		chave = (char*) malloc(BUFFER);
		printf("Digite o nome para buscar: \n--> ");
		scanf("%s", chave);
		principal = delbusca_dados(principal, chave);
	}
}
listas_t* delbusca_dados(listas_t *dados, char *chave)
{
	int achou = 0, cont = 0;
	listas_t *juntou, *aux, *nova = dados;
	for (; nova != NULL; nova = nova->proximo)
	{
		if (strcmp(chave, nova->nome) == 0)
		{
			achou = 1;
			cont++;
		}
	}

	if (achou == 1)
	{
		int ind = 0;
		for (ind = 0; ind < cont; ind++)
		{
			if (strcmp(chave, dados->nome) == 0)
			{
				aux = dados;
				dados = dados->proximo;
				free(aux);
			}
			else
			{
				aux = dados;
				while (strcmp(chave, aux->nome) != 0)
				{
					aux = aux->proximo;
				}

				juntou = dados;
				while (juntou->proximo != aux)
				{
					juntou = juntou->proximo;
				}
				juntou->proximo = aux->proximo;
				free(aux);
			}
		}
		printf("Excluido.\n");
	}
	else
		printf("Nenhum resultado encontrado.\n");
	getchar();
	return dados;
}
void busca(void)
{
	char *chave;
	if (!checa_vazio(principal))
	{
		chave = (char*) malloc(BUFFER);
		printf("Digite o nome para buscar: \n--> ");
		scanf("%s", chave);
		busca_dados(principal, chave);
	}
}
void busca_dados(listas_t *dados, char *chave)
{
	int achou = 0;
	printf("Cadastro:\n\n");
	for (; dados != NULL; dados = dados->proximo)
	{
		if (strcmp(chave, dados->nome) == 0)
		{
			printf("------------------------\n");
			printf("Nome: %s\n", dados->nome);
			printf("E-mail: %s\n",dados->email);
			printf("Idade: %d\n", dados->idade);
			printf("Telefone: %d\n", dados->telefone);
			printf("------------------------\n");
			achou++;
		}
	}
	if (achou == 0)
		printf("Nenhum resultado encontrado.\n");
	else
		printf("Foram encontrado(s) %d registro(s).\n", achou);
	getchar();
}
