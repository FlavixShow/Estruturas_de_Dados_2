#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Doc{
	char* nome;
	struct Doc* prox;
}Doc;

typedef struct{
	Doc* head;
	Doc* tail;
	int size;
}TypeList;

typedef TypeList* List;

int interface(){
	int esc;
	do{
		printf("1 - Add Doc. na Fila\n2 - Fila de Impressão\n3 - Imprimir Doc.\n4 - Excluir Doc.\n5 - Add. Doc. Prioritário\n0 - Encerrar Programa\nEscolha: ");
		scanf(" %i", &esc);	
		system("clear");	
	}while(esc < 0 || esc > 5);
	return esc;
}

List new_list(){
	List new = malloc(sizeof(List));
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return new;
}

char* strInput(char* msg){
	char text[500];
	printf("%s", msg);
	scanf(" %[^\n]s", text);
	char* pont = (char*)malloc(strlen(text)+1);
	strcpy(pont, text);
	return pont;
}

void new_doc(List fila){
	Doc* doc = (Doc*)malloc(sizeof(Doc));
	doc->nome = strInput("Digite o nome do Doc: ");
	doc->prox = NULL;
	
	if(fila->tail){
		fila->tail->prox = doc;
	}
	
	fila->tail = doc;
	if(!fila->head) 
		fila->head = fila->tail;
		
	fila->size++;
}

void listar_fila(List fila){
	Doc* lst = fila->head;
	while(lst){
		printf("%s\n\n", lst->nome);
		lst = lst->prox;
	}
	printf("Quant. de Docs: %i\n\n", fila->size);
}

void imprimir_doc(List fila){
	printf("Doc '%s' impresso.\n\n", fila->head->nome);
	
	Doc* temp = fila->head->prox;
	free(fila->head);
	fila->head = temp;
	
	if(!fila->head) 
		fila->tail = NULL;
	
	fila->size--;
}

void excluir_doc(List fila){
	char* doc_nome = strInput("Nome do Doc: ");

	Doc* lst = fila->head;	
	Doc* ant = lst;
	
	int cont = 0;
	while(lst){
		if(!strcmp(doc_nome, lst->nome)){
			if(!cont){
				if(!lst->prox) fila->tail = NULL;
				fila->head = lst->prox;
				fila->size--;
				free(lst);
				return;
			}
			ant->prox = lst->prox;
			free(lst);
			fila->size--;
			return;
		}
		ant = lst;
		lst = lst->prox;
		cont++;
	}
	free(doc_nome);
}

void priorizar_doc(List fila){
	Doc* ult = fila->tail;
	new_doc(fila);
	if(!ult) return;
	
	fila->tail->prox = fila->head;
	fila->head = fila->tail;
	fila->tail = ult;
}

int main(){
	List fila = new_list();
	do{
		switch(interface()){
			case 1: new_doc(fila);
			break;
			case 2: listar_fila(fila);
			break;
			case 3: imprimir_doc(fila);
			break;
			case 4: excluir_doc(fila);
			break;
			case 5: priorizar_doc(fila);
			break;
			case 0:printf("FIM DO PROGRAMA"); return 0;
			break;
		}
	}while(1);
}
