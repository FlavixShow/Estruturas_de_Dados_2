#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "microservices.h"



int interface(){
	int esc;
	
	do{
		printf("1 - Baixar Imagem\n2 - Excluir Imagem\n3 - Criar Container\n4 - Interromper Container\n5 - Iniciar Container\n6 - Excluir Container\n7 - Listar Imagem\n8 - Listar Containers\n0 - Encerrar Programa\nEscolha: ");
		scanf(" %i", &esc);
		if(esc < 0 || esc > 8) 
			alert("Entrada inválida.");
		
	}while(esc < 0 || esc > 8);
	return esc;
}



int main(){
	ImageList imageList = new_ImageList();
	do{
		switch(interface()){
			case 1: new_Image(imageList);
			break;
			case 2: excluirImagem(imageList);
			break;
			case 3: new_Container(imageList);
			break;
			case 4: stop_Container(imageList);
			break;
			case 5: init_Container(imageList);
			break;
			case 6: excluirContainer(imageList);
			break;
			case 7: divisa('=', 75); listarImagens(imageList); divisa('=', 75); alert("Listado.");;
			break;
			case 8: listarImagens(imageList)divisa('=', 75); if(listarContainer(buscarImagem(imageList))) alert("Listado.");
			break;
			case 0: printf("FIM DO PROGRAMA"); return 0;
			break;
		}
	}while(1);
	
}
