#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 
int max = 10;          
int tamanho = 0;          
 

struct no 
{
	int dado;
	int valor;
	struct no *esquerda;
	struct no *direita;
};
 

struct arvore_binaria 
{
	struct no *comeco;
	
};
 
struct arvore_binaria *vetor;
 
void inserir_elemento(struct no *arvore, struct no *item);
struct no* achar(struct no *arvore, int dado);
void mostrar_arvore(struct no *arvore);
 

int codigo_hash(int dado)
{
	return (dado % max);
}
 
void adicionar(int dado, int valor)
{
	int indice = codigo_hash(dado);
 
	
	struct no *arvore = (struct no*) vetor[indice].comeco;
 
	
	struct no *novo_item = (struct no*) malloc(sizeof(struct no));
	novo_item->dado = dado;
	novo_item->valor = valor;
	novo_item->esquerda = NULL;
	novo_item->direita = NULL;
 
	if (arvore == NULL) 
        {
		 
		printf("Inserting %d (dado) \n", dado);
		vetor[indice].comeco = novo_item;
		tamanho++;
 
	}
	else {
		 
		struct no *temp = achar(arvore, dado);
		if (temp == NULL) 
                {
			 
			printf("Inserting %d(dado) \n", dado, valor);
			inserir_elemento(arvore, novo_item);
			size++;
 
		}
		else 
                {
			
			temp->valor = valor;
 
		}
	}
 
}
 
 

struct no* achar(struct no *arvore, int dado)
{
	if (arvore == NULL) 
        {
		return NULL;
	}
	if (arvore->dado == dado)
        {
		return arvore;
	}
	else if (dado < arvore->dado)
        {
		return achar(arvore->esquerda, dado);
	}
	else 
        {
		return achar(arvore->direita, dado);
	}
 
}
 
void inserir_elemento(struct no *arvore, struct no *item)
{
	if (item->dado < arvore->dado)
        {
		if (arvore->esquerda == NULL)
                {
			arvore->esquerda = item;
			return;
		}
		else 
                {
			inserir_elemento(arvore->esquerda, item);
			return;
		}
	}
	else if (item->dado > arvore->dado)
        {
		if (arvore->direita == NULL)
                {
			arvore->direita = item;
			return;
		}
		else
                {
			inserir_elemento(arvore->direita, item);
			return;
		}
	}
}
 

void mostrar(){
	int i = 0;
	for(i = 0; i < max; i++) 
        {
		struct no *arvore = vetor[i].comeco;
		if (arvore == NULL)
                {
			printf("\n Elemento da Tabela Hash de Indice [%d] nao possui valores \n", i);
		}
		else
                {
			printf("\n Elemento da Tabela Hash de indice [%d] Tem os valores:  \t", i);
			mostrar_arvore(arvore);
		}
	}
}
 
void mostrar_arvore(struct no *arvore)
{
    	if (arvore == NULL)
        {
        	return;
    	}
    	printf("%d  \t", arvore->dado);
 
    	if (arvore->esquerda != NULL)
        {
        	mostrar_arvore(arvore->esquerda);
    	}
    	if (arvore->direita != NULL)
        {
        	mostrar_arvore(arvore->direita);
    	}
 
}
 

void inicializar()
{
    	int i = 0;
    	for(i = 0; i < max; i++)
        {
        	vetor[i].comeco = NULL;
    	}
 
}
 
/* returns the size of hash table */
int tamanho_da_tabelahash()
{
	return size;
}
 
main()
{
    int escolha, dado, valor, n, c;
	
 
	vetor = (struct arvore_binaria*)malloc(max * sizeof(struct arvore_binaria*));
	inicializar();
 
	do {
		printf("Tabela Hash com Arvore Binaria\n\n");
		printf("MENU-: \n1.Inserir Elementos" 
                              "\n2.Verificar tamanho da tabela hash" 
                              "\n3.Mostrar tabela"
		       "\n\n Escolha:");
 
 		scanf("%d", &escolha);
 
		switch(escolha) 
                {
 
		case 1:
 
		      printf("Inserir Elemento na tabela Hash\n");
		      printf("Valor:\t");
		      scanf("%d", &dado);
		      valor = dado;
		      adicionar(dado, valor);
 
		      break;
 
		case 2:
 
		      n = tamanho_da_tabelahash();
		      printf("Tamanho :%d\n", n);
		      break;
 
		case 3:
 
		      mostrar();
		      break;
 
 
		default:
 
		       printf("Entrada Não Reconhecida\n");
 
		}
 
		printf("\n Para continuar: (pressione 1) \t");
		scanf("%d", &c);
 
	}while(escolha);
 
	getch();
 
 
}
