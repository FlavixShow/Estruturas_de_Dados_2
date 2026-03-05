#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define QUANT 50

void preencheArray(int vetor[]){
	for(int i = 0; i < QUANT; i++){
		vetor[i] = 1 + rand() % QUANT;
	}
}

void printArray(int vetor[]){
	for(int i = 0; i < QUANT; i++){
		printf("%i ", vetor[i]);
	}
}

int somaValoresArray(int vetor[]){
	int soma = 0;
	
	for(int i = 0; i < QUANT; i++){
		soma += vetor[i];
	}
	return soma;
}

int main(){
	int vetor[QUANT];
	preencheArray(vetor);
	printArray(vetor);
	printf("\n\n");
	printf("Soma de todos os valores: %i", somaValoresArray(vetor));
	
}

