#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "macro.h"

typedef struct __Player{
	int id;
	char* nome;
	int hp;
}__Player;

typedef __Player* Player;

typedef struct __Item{
	int id;
	char nome[100];
	int power;
	char type[100];
}__Item;

typedef __Item* Item;

typedef struct ItemSetContext{
	char nome[100];
	int power;
	char type[100];
}ItemSetContext;

void print_Player(Object obj){
	if(!obj) return;
	Player ent = obj->item;
	printf("Id: %i, Nome: %s, HP: %i\n", ent->id, ent->nome, ent->hp);
}
void print_Item(Object obj){
	if(!obj) return;
	Item ent = obj->item;
	printf("Id: %i, Nome: %s, Power: %i, Tipo: %s\n", ent->id, ent->nome, ent->power, ent->type);
}


void destroy_Player(Object obj){
	if(!obj || !obj->item) return;
	
	Player p = obj->item;
	if(!p->nome) return;
	free(p->nome);
	
	free(obj->item);
	free(obj);
}

ItemSetContext setItemContext(char* nome, int power, char* type){
	ItemSetContext context;
	strcpy(context.nome, nome);
	context.power = 23;
	strcpy(context.type, type);
	
	return context;
}

void setItem(Object obj, void* context){
	if(!obj) return;
	Item item = obj->item;
	ItemSetContext* item_context = (ItemSetContext*)context;
	printf("%i", item_context->power);
	strcpy(item->nome, item_context->nome);
	item->power = item_context->power;
	strcpy(item->type, item_context->type);
}

Object new_Player(int id, char nome[], int hp){
	Player newPlay = malloc(sizeof(__Player));
	newPlay->id = id;
	
	newPlay->nome = malloc(strlen(nome)+1);
	
	strcpy(newPlay->nome, nome);
	newPlay->hp = hp;
	Object obj = new_Object();
	obj->item = newPlay;
	obj->print = print_Player;
	obj->set = NULL;
	obj->destroy = destroy_Player;
	return obj;
}

Object new_Item(int id, char nome[], int hp, char type[]){
	Item newItem = malloc(sizeof(__Item));
	newItem->id = id;
	strcpy(newItem->nome, nome);
	strcpy(newItem->type, type);
	newItem->power = hp;
	Object obj = new(Object);
	obj->item = newItem;
	obj->print = print_Item;
	obj->set = setItem;
	return obj;
}

#endif
