#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "Document.h" 

int interface(){
	printf("1 - Criar Documento\n");
	printf("2 - Fila de Impressão\n");
	printf("3 - Imprimir Documento\n");
	printf("4 - Excluir Documento\n");
	printf("5 - Priorizar Documento\n");
	int opt;
	scanf(" %d",&opt);
	return opt;
}

void cadastrar_documento(List lst){
	char nome[100];
	int id, pgs, size;
	id = rand()%1000;
	printf("Nome do Documento: ");
	scanf(" %[^\n]s",nome);
	printf("Páginas do Documento: ");
	scanf(" %d",&pgs);
	size = rand()%200;
	new_Document(lst,id,nome,pgs,size);
}

void excluir(List lst){
	printf("Digite o Id do doc: ");
	int id;
	scanf(" %i", &id);
	excluir_Document(lst, busca_Document(lst, id));
}

void priorizar(List lst){
	printf("Digite o Id do doc: ");
	int id;
	scanf(" %i", &id);
	priorizar_Document(lst, busca_Document(lst, id));
}

int main(){
	List lst = new_List();
	
	do{
		switch(interface()){
			case 1: cadastrar_documento(lst);
					break;
			case 2: print_List(lst);
					break;
			case 3: imprimir_Document(lst);
					break;
			case 4: excluir(lst);
					break;
			case 5: priorizar(lst);
					break;
			case 0: return 0;
		}
		
	}while(1);
}
