#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "doc.h"

int interface(){
	int esc;
	do{
		printf("1 - Criar Documento\n2 - Listar Documentos\n3 - Encerrar Programa\n");
		scanf(" %i", &esc);	
		system("clear");	
	}while(esc < 1 || esc > 3);
	return esc;
}

int main(){
	Doc* doc = NULL;
	do{
		switch(interface()){
			case 1: doc = new_doc(doc);
			break;
			case 2: listar_docs(doc);
			break;
			case 3: printf("FIM DO PROGRAMA"); return 0;
			break;
		}
	}while(1);
}
