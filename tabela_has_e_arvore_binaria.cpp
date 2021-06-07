#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int max = 10; // determinar a capacidade da tabela hash
int size = 0;

// struct para guardar dados na arvore binaria.

struct arvore{
	int dado;
	int valor;
	struct arvore *esquerda;
	struct arvore *direita;
};

//Struct para guardar uma arvore binaria em cada indice da tabela hash.
struct arvore_binaria{
	struct arvore *comeco; // aponta para raiz de cada arvore	
};

struct arvore_binaria *vetor;

void inserir_elemento(struct arvore *arvore, struct arvore *item);
void mostrar_arvore(struct arvore *arvore);
struct arvore *procurar(struct arvore *arvore, int dado);
int menu (void);// função utilizada para criação de um menu com as opções do que o software realiza. ela é do tipo int pois retornará um valor.
void opcao (int op);/*Funçao do tipo void que não retorna nada, pois, so ativa o switch case e seleciona a opção e a função que aquela opção usará o paramentro */
int opt;
	int escolha,dado,valor,n,c;
int vetor_teste_1[16] = {18, 4, 8 ,1, 3, 7, 12, 15, 11, 6, 5, 2, 13, 10, 9, 17};
int vetor_teste_2[16] = {8, 4, 13, 1, 3, 7, 12, 15, 11, 6, 5, 2, 18, 10, 9, 17};
int vetor_teste_3[16] = {7, 5, 93, 77, 3, 39, 14, 775, 12, 1, 73, 377, 2, 95,53};
int vetor_teste_4[16] = {7, 9, 78, 18, 1, 797, 98, 3, 79, 21, 97, 2, 25, 49, 897};
int vetor_teste_5[16] = {8, 1, 11, 2, 81, 111, 16, 5, 811, 20, 3, 10, 102, 81, 21};
//função para achar o indice em que a arvore será armazenada na tabela hash.
int codigo_hash(int dado){
	return (dado%max);
}

void adicionar(int dado, int valor){
	printf("valor = %d e dado = %d",dado,valor);
	printf("teste adicionar");
	int indice = codigo_hash(dado);
	printf("teste adicionar 1");
	//extrair a arvore apartir de apartir de um indice.
	struct arvore *arvores = (struct arvore*)vetor[indice].comeco;
	printf("teste adicionar 2");
	//criando um item para ser inserido na tabela hash.
	struct arvore *novo_item = (struct arvore*)malloc(sizeof(struct arvore));
	printf("teste adicionar3");
	novo_item -> dado = dado;
	novo_item -> valor = valor;
	novo_item -> esquerda = NULL;
	novo_item -> direita = NULL;
	printf("teste adicionar 4");
	
	if(arvores == NULL){
		// indice da tabela hash esta sem um arvore.
		printf("Inserido o dado", dado);
		vetor[indice].comeco = novo_item;
		size++;
		
	}
	else{
		// ja possui uma arvore no indice da tabela.
		struct arvore *temp = procurar(arvores,dado);
		if(temp == NULL){
			//adicionar o dado em uma arvore ja existente.
			printf("\n Inserido o dado %d", dado);
			inserir_elemento(arvores,novo_item);
			size++;
			return;
		}
		else{
			//o dado ka existe é precisa atualizar a arvore.
			temp->valor = valor;
			return;
		}
		
	}
}

//função para achar um dado na arvore.

struct arvore *procurar(struct arvore *arvore, int dado){
	if(arvore == NULL){
		return NULL;
	}
	if(arvore->dado == dado){
		return arvore;
	}
	else if(dado < arvore->dado){
		return procurar(arvore->esquerda,dado);
	}
	else{
		return procurar(arvore->direita,dado);
	}
}

//função para adicionar um novo no em uma arvore binaria existente
void inserir_elemento(struct arvore *arvore, struct arvore *item){
	if(item->dado < arvore -> dado){
		if(arvore->esquerda == NULL){
			arvore->esquerda = item;
			return;
		}
		else{
			inserir_elemento(arvore->esquerda,item);
			return; 
		}
	}	
	else if(item->dado > arvore->dado){
		if(arvore->direita == NULL){
			arvore->direita = item;
			return;
		}
		else{
			inserir_elemento(arvore->direita, item);
			return;
		}
	}
}

// mostrar conteudo da tabela hash
void mostrar(){
	int i = 0;
	for(i =0; i < max; i++){
		struct arvore *arvore = vetor[i].comeco;
		if(arvore == NULL){
			printf(" \n Indice  %d não apresenta nenhuma arvore \n", i );
		}
		else{
			printf("\n Indice %d apresenta uma arvore \n", i);
			mostrar_arvore(arvore);
		}
	}
}

//função para mostrar a arvore.
void mostrar_arvore(struct arvore *arvore){
	if(arvore == NULL){
		return;
	}
	printf(" \t %d", arvore->dado);
	if(arvore->esquerda != NULL){
		mostrar_arvore(arvore->esquerda);
	}
	if(arvore->direita != NULL){
		mostrar_arvore(arvore->direita);
	}
}

//função para inicializar a tabelahsh.
void iniciar(){
	int i = 0;
	for(i=0;i<max;i++){
		vetor[i].comeco = NULL;
	}
}

//função para retornar o tamanho da tabelahas.
int tamanho_tabela_hash(){
	return size;
}
  int main (void){
  	printf("teste");
	vetor = (struct arvore_binaria*)malloc(sizeof(max * sizeof(struct arvore_binaria*)));
	iniciar();
	do{
		opt = menu();
		opcao(opt); 
	}while(opt);
}

int menu(void){
	printf("\n Para adcionar numeros digite 1. \n Para ver os numeros aperte 2. Para ordenar aperte 3.");
	printf ("\n Digite sua opcao:");
	scanf("%d", &opt);
	return opt;
}

void opcao (int op){ 
	switch(op){
		case 1:
			printf("Inserting element in Hash Table\n");
		      printf("Enter key and value-:\t");
		      scanf("%d", &dado);
		      printf("Teste 2");
		      valor = dado;
		      printf("teste 3");
		      adicionar(dado, valor);
		      printf("teste 4");
		      system("cls");
				break;
			
	   case 2:
	   		n = tamanho_tabela_hash();
				printf("\n O tamanho da tabela hash é de: %d",n);
				break;
	   		
	   	case 3:
	   			mostrar();
				break;
	}
	
}
