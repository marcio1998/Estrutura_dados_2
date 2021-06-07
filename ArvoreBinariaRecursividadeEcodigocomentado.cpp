#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

struct arvores{
	int dado;//variavel para receber um valor do tipo int.
	struct arvores *esquerda, *direita;// ponteiros da arvores, os ponteiros da esquerda e da direita
};

struct arvores *novoNo(int item){//função que aloca um novo nó na memoria.
	struct arvores *novo = (arvores *)malloc(sizeof(arvores));//linha de codigo que aloca a memoria do tamanho da struct.
	if(!novo){// if, caso a nova "caixa" não seja criada.
		printf("Memoria Cheia");
	}
	else{//caso a nova "caixa", seja criado, ou o novo nó da raiz.
		novo -> dado = item;// adicionar o valor a variável dado que esta na struct arvores.
		novo -> esquerda = novo -> direita = NULL;// estabelecendo NULL para os ponteiros esquerda e direita do novo no ou "caixa".
		return novo;	// retornanar o nó criado.
	}
}

void imprimirEmOrdem(struct arvores *raiz){// função para imprimir em ordem os valores que estão na árvore.
	if(raiz != NULL){// caso, raiz seja diferente de NULL o codigo executa.
			imprimirEmOrdem(raiz->esquerda);// chamada recursiva a esquerda da arvore.
			printf("\t %d", raiz->dado);// print para o valor contido onde o no esteja, pois, ele percorre a arvore.
			imprimirEmOrdem(raiz->direita);	// chamada recursiva a direita da arovore.
	}
}

struct arvores* inserir(struct arvores* no, int dado){
	if(no == NULL) return novoNo(dado);
	if(dado<=no->dado)
		no->esquerda = inserir(no->esquerda, dado);
	if(dado>=no->dado)
		no->direita = inserir(no->direita, dado);
	return no;	
}

int main(){
	int numeroAleatorio;
	clock_t t0_1,tf_1,t0_2,tf_2;
	double tempoGasto1, tempoGasto2, tempoTotal;
	struct arvores *raiz = NULL;
	srand( (unsigned)time(NULL) );
	numeroAleatorio = rand() % 1000000;
	raiz = inserir(raiz, numeroAleatorio);
	printf("\n Gerando Numeros Aleatorios");
	Sleep(4000);
	system("cls");
	t0_1 = clock();
	for(int i=0; i<=100000; i++){
		numeroAleatorio = rand() %10000000;
		printf("\t %i", numeroAleatorio);
		inserir(raiz,numeroAleatorio);
	}
	tf_1 = clock();
	tempoGasto1 = ((( (tf_1-t0_1) * 1000) / CLOCKS_PER_SEC)/ 1000);
	t0_2 = clock();
	imprimirEmOrdem(raiz);
	tf_2 = clock();
	tempoGasto2 = ((( (tf_2-t0_2) * 1000) / CLOCKS_PER_SEC)/ 1000);
	tempoTotal = tempoGasto1 + tempoGasto2;
	printf("\n Tempo de execucao para inserir em orde + "
	" imprimir em ordem = %.3f segundos", tempoTotal);
}
