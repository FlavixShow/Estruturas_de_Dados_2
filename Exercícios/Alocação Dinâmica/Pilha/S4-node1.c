#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "S4-Node1.h"

int interface(){
	int esc;
	do{
		printf("1 - Cadastrar Veículos\n2 - Listar Veículos\n3 - Listar Pelo Tipo\n4 - Encerrar Programa\n");
		scanf(" %i", &esc);	
		system("clear");	
	}while(esc < 1 || esc > 4);
	return esc;
	
}

int main(){
	Veiculo* veic = NULL;
	do{
		switch(interface()){
			case 1: veic = new_veiculo(veic);
			break;
			case 2: listarVeiculos(veic);
			break;
			case 3: buscarVeiculosTipo(veic);
			break;
			case 4: printf("FIM DO PROGRAMA"); return 0;
			break;
		}
	}while(1);
}
