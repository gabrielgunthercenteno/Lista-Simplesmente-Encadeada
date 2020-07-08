#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct lista{
	char   *nome;
	int    idade;
	char  *email;
	int telefone;
	struct lista *proximo;
};

typedef struct lista listas_t;
extern listas_t *principal;

//Funções para manusear os dados (irão retornar dados)
listas_t* inicia_dados(char *nome, int idade, char *email, int telefone);
listas_t* insere_dados(listas_t *dados, char *nome, int idade, char *email, int telefone);
listas_t* delbusca_dados(listas_t *dados, char *chave);
listas_t* deleta_dados(listas_t *dados, int nTipo);
int checa_vazio(listas_t *dados);

//Funções para mostrar dados
void exibe_dados(listas_t *dados);
void exibe_tamanho(listas_t *nova);
void busca_dados(listas_t *dados, char *chave);

//Funções do Menu
void criavazia(void);	//1
void insereinicio(void);	//2
void inserefim(void);	//3
void listavazia(void);	//4
void prielemento(void);	//5
void ultelemento(void);	//6
void exibe(void);	//7
void exibetam(void);	//8
void deletapri(void);	//9
void deleta(void);	//a
void delbusca(void);	//b
void busca(void);	//c



#endif // LISTA_H_INCLUDED
