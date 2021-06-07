#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef struct arvores{
	int dado;
	struct arvores *esquerda, *direita;
};

struct arvores *novoNo(int item){
	struct arvores *novo = (arvores *)malloc(sizeof(arvores));
	novo -> dado = item;
	novo -> esquerda = novo -> direita = NULL;
	return novo;
}

void imprimirEmOrdem(struct arvores *raiz){
	/*if(raiz == NULL){
		printf("Arvore Vazia");
	}*/
	if(raiz != NULL){
			imprimirEmOrdem(raiz->esquerda);
			printf("\t %d", raiz->dado);
			imprimirEmOrdem(raiz->direita);	
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
	numeroAleatorio = rand() % 1000000;
	raiz = inserir(raiz, numeroAleatorio);
	printf("\n Gerando Numeros Aleatorios");
	Sleep(4000);
	system("cls");
	t0_1 = clock();
	for(int i=0; i<=100000; i++){
		numeroAleatorio = rand() %1000000;
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
