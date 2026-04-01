#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define QUANT 10

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

int somaValoresArray(int vetor[], int quant){
	if(quant-1 < 0){
		return 0;
	}
	return vetor[quant-1] + somaValoresArray(vetor, quant-1);
}

int main(){
	int vetor[QUANT];
	preencheArray(vetor);
	printArray(vetor);
	printf("\n\n");
	printf("Soma de todos os valores: %i", somaValoresArray(vetor, QUANT));
	
}
