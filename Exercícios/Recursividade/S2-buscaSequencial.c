#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define QUANT 10

void preencheArray(int vetor[]){
	for(int i = 0; i < QUANT; i++){
		vetor[i] = 1 + rand() % 50;
	}
}

void printArray(int vetor[]){
	for(int i = 0; i < QUANT; i++){
		printf("%i ", vetor[i]);
	}
}

int buscaValor(int vetor[], int i, int valor){
	if(!(i-1)) return -1;
	if(vetor[i] == valor) return i;
	return buscaValor(vetor, i-1, valor);
}

int main(){
	srand(time(NULL));
	int vetor[QUANT];
	
	int valor = 20;
	
	preencheArray(vetor);
	printArray(vetor);
	printf("\n\n");
	printf("Índice do valor: %i", buscaValor(vetor, QUANT, valor));
}
