#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "macro.h"
#include "node.h"
#include "list.h"
#include "entidade.h"


void print(Object obj){
	obj->print(obj);
}

int main(){
	List lst = new(List);
	for(int i = 0; i < 5; i++){
		char nome[100];
		char nome2[100];
		sprintf(nome, "%s%i", "nome", i*1);
		sprintf(nome2, "%s%i", "nome", i*2);
		Object e1 = new(Player, i, nome, 110);
		Object e2 = new(Item, 2, nome2, 1010, "espada");
		lst->push(lst, e1);
		lst->enqueue(lst, e2);
	}
	//foreach(lst, (void*) print, NULL);
	lst->print(lst);
	
	Object g2 = lst->getPointer(lst, 9);
	
	Object obj = list_pop(lst);
	printf("\n\n");
	obj->print(obj);
	printf("\n\n");
	
	Object e3 = new_Player(14, "teste", 200);
	
	lst->push(lst, e3);
	//foreach(lst, (void*) print, NULL);
	//lst->print(lst);

	lst->delete(lst, 3);
	//list_clear(lst);
	Object g1 = lst->get(lst, 4);
	//foreach(lst, (void*) print, NULL);
	lst->print(lst);
	printf("\n\n");
	g1->print(g1);

	Object e4 = new_Player(16, "teste", 300);

	lst->enqueue(lst, e4);
	printf("\n\n");

	
	
	//foreach(lst, (void*) print, NULL);
	lst->print(lst);
	printf("\n\n");
	if(g2)
		g2->print(g2);
	//ItemSetContext context = setItemContext("Misericórdia", 23, "Adaga");
	//printf("%s%i%s\n", context.nome, context.power, context.type);
	//(g2)
	//	g2->set(g2, &context);
	if(g2){
		g2->print(g2);
	}else{
		printf("apagou");
	}
		
	
	printf("\n\n");
	lst->print(lst);

}
