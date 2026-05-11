#include <stdlib.h>
#include <stdio.h>
#include <gconio.h>
#include "escalonador.h"

void interface(List processos){
	printf("Create: (K)ernel Process / (U)ser Process\n");
	printf("Actions: kil(L) Process / e(X)it Application\n");
	printf("%i Process\n\n", processos->processCont);
	printf("RUNNING\t\tTYPE\t\tPID\tINSTRUCTIONS\tDONE\n");
	
	printList(processos);
}

int main(){
	List processos = new_List();
	
	do{
		char opt;
		while(!kbhit(&opt)){
			
			interface(processos);
			executa(processos);
			system("sleep 1");
			system("clear");
		}
		
		switch(opt){
			case 'k': new_Processo(processos, KERNEL);
			break;
			case 'u': new_Processo(processos, USER);
			break;
			case 'l': excluirProcesso(processos, processos->execut->ant);
			break;
			case 'x': interface(processos); printf("\nFIM DO PROGRAMA"); return 0;
			break;
		}
	}while(1);
}
