#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define QUANT 10

void preencheArray(int vetor[]){
	for(int i = 0; i < QUANT; i++){
		vetor[i] = 1 + rand() % 50;
	}
}

void ordenaArray(int vetor[]){
	for(int i = 1; i < QUANT; i++){
		int temp = vetor[i];
		int j = i - 1;
			
		while(j >= 0 && temp < vetor[j]){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = temp;
	}
}

void printArray(int vetor[]){
	for(int i = 0; i < QUANT; i++){
		printf("%i ", vetor[i]);
	}
}

int buscaValor(int vetor[], int valor, int inicio, int fim){

	if(inicio == fim) return -1;

	int meio = (inicio+fim)/2;
	
	if(valor == vetor[meio]) 
		return meio;
	if(valor > vetor[meio])
		return buscaValor(vetor, valor, meio+1, fim);
		
	return buscaValor(vetor, valor, inicio, meio);
}

int main(){
	srand(time(NULL));
	int vetor[QUANT];
	
	int valor = 20;
	
	preencheArray(vetor);
	printArray(vetor);
	printf("\n");
	ordenaArray(vetor);
	printArray(vetor);
	printf("\n\n");
	printf("Índice do valor: %i", buscaValor(vetor, valor, 0, QUANT-1));
}
