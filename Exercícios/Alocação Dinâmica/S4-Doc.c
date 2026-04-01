#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char* nome;
	int paginas;
	int tam;
}Document;

Document* new_document(char* nome, int pag, int tam){
	Document* doc = (Document*)malloc(sizeof(Document));
	doc->nome = (char*)malloc(strlen(nome)+1);
	strcpy(doc->nome, nome);
	doc->paginas = pag;
	doc->tam = tam;
	return doc;
}

void print_document(Document* doc){
	printf("Nome: %s\nPágina: %i\nTamanho: %i", doc->nome, doc->paginas, doc->tam);
}

int main(){
	Document* doc = new_document("doc.pdf", 5, 180);
	print_document(doc);
	free(doc);
}
