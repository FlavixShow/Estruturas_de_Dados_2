#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "aula22Abr.h" 

int interface(){
	printf("1 - Criar Documento\n");
	printf("2 - Fila de Impressão\n");
	printf("3 - Imprimir Documento\n");
	printf("4 - Excluir Documento\n");
	printf("5 - Priorizar Documento\n");
	printf("0 - Encerrar programa\n");
	int opt;
	scanf(" %d",&opt);
	return opt;
}
void cadastrar_Document(List lst){
	int id = rand()%1000;
	
	char nome[500];
	printf("Digite o nome: ");
	scanf(" %s[^\n]", nome);
	
	int pag;
	printf("Paginas: ");
	scanf(" %i", &pag);
	
	int size = rand()%100;
	
	new_Document(lst, id, nome, pag, size);
}

void print_List(List lst){
	Document item = lst->head;
	while(item){
		printf("%i  %s  %i  %i\n\n", item->id, item->nome, item->pag, item->size);
		item = item->prox;
	}
	printf("List Size: %i\n\n", lst->size);
}

void excluir(List lst){
	print_List(lst);
	
	int id;
	printf("Digite o id do item: ");
	scanf(" %i", &id);
	excluir_Document(buscar_Document(lst, id), lst);
}

void priorizar(List lst){
	print_List(lst);
	
	int id;
	printf("Digite o id do item: ");
	scanf(" %i", &id);
	priorizar_Document(buscar_Document(lst, id), lst);
}

int main(){
	List lst = new_List();
	
	do{
		switch(interface()){
			case 1: cadastrar_Document(lst);
					break;
			case 2: print_List(lst);
					break;
			case 3: imprimir_Document(lst);
					break;
			case 4: excluir(lst);
					break;
			case 5: priorizar(lst);
					break;
			case 0: printf("FIM DO PROGRAMA"); return 0;
					break;
		}
	}while(1);
}
