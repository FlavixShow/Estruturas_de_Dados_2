#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define QUANT 20

void preencheArray(int vetor[]){
	for(int i = 0; i < QUANT; i++){
		vetor[i] = 1 + rand() % 100;
	}
}

void printArray(int vetor[]){
	for(int i = 0; i < QUANT; i++){
		printf("%i ", vetor[i]);
	}
}

int maiorValor(int vetor[], int i, int maior){
	
	if(i > QUANT-1) return vetor[maior];
	
	if(vetor[maior] >= vetor[i])
		return maiorValor(vetor, i+1, maior);
	
	return maiorValor(vetor, i+1, i);
}

int main(){
	srand(time(NULL));
	int vetor[QUANT];
	preencheArray(vetor);
	printArray(vetor);
	printf("\n\n");
	printf("Maior valor: %i", maiorValor(vetor, 0, 0));
}
