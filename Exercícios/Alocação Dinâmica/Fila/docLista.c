#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Doc{
	char* nome;
	struct Doc* prox;
}Doc;

int interface(){
	int esc;
	do{
		printf("1 - Add Doc. Fila\n2 - Add Doc. prioritário\n3 - Print Doc\n4 - Excluir um Doc\n5 - Listar docs\n0 - Encerrar Programa\nEscolha: ");
		scanf(" %i", &esc);	
		system("clear");	
	}while(esc < 0 || esc > 5);
	return esc;
}

char* strInput(char* msg){
	char text[500];
	printf("%s", msg);
	scanf(" %[^\n]s", text);
	char* pont = (char*)malloc(strlen(text)+1);
	strcpy(pont, text);
	return pont;
}

Doc* new_doc(Doc* tail){
	Doc* doc = (Doc*)malloc(sizeof(Doc));
	doc->nome = strInput("Digite o nome do Doc: ");

	doc->prox = NULL;
	if(tail)
		tail->prox = doc;
	
	return doc;
}

Doc* new_docPriori(Doc* head){
	Doc* doc = (Doc*)malloc(sizeof(Doc));
	doc->nome = strInput("Digite o nome do Doc: ");
	
	doc->prox = head;

	return doc;
}

/*Doc* print_doc(Doc* head){
	if(!head) return NULL;
	Doc* temp = head->prox;
	free(head);
	return temp;
}*/

void print_doc(Doc** pont_h){
	if(!(*pont_h)) return;
	Doc* temp = (*pont_h)->prox;
	free(*pont_h);
	*pont_h = temp;
}

void excluir_doc(Doc** lst, Doc** tail){
	
	char doc_nome[500];
	printf("Nome do Doc: ");
	scanf(" %[^\n]s", doc_nome);


	Doc* ant = *lst;
	int cont = 0;
	while(*lst){
		if(!strcmp(doc_nome, (*lst)->nome)){
			if(!cont){
				Doc* temp = (*lst)->prox;				
				free(*lst);
				*lst = temp;
				return;
			}
			
			if(*lst == *tail){
				*lst = NULL;
				*tail = NULL;
				return;
			}
			ant->prox = (*lst)->prox;
			free(*lst);
			return;
		}
		ant = *lst;
		*lst = (*lst)->prox;
		cont++;
	}
}


void listar_docs(Doc* lst){
	while(lst){
		printf("%s\n\n", lst->nome);
		lst = lst->prox;
	}
}

int main(){
	Doc* head = NULL;
	Doc* tail = NULL;

	do{
		switch(interface()){
			case 1: tail = new_doc(tail); if(!head) head = tail;
			break;
			case 2: if(!head){
						tail = new_doc(tail); 
						if(!head) head = tail;
					}else{ 
						head = new_docPriori(head);
					}
			break;
			case 3: print_doc(&head);//head = print_doc(head);
			break;
			case 4: excluir_doc(&head, &tail);
			break;
			case 5: listar_docs(head);
			break;
			case 0:printf("FIM DO PROGRAMA"); return 0;
			break;
		}
	}while(1);
	
}
