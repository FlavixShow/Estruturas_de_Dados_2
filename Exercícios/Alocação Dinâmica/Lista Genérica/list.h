#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct __List{
	Object head;
	Object tail;
	int size;
	void (*enqueue) (struct __List*, Object);
	void (*push) (struct __List*, Object);
	Object (*pop) (struct __List*);
	void (*print) (struct __List*);
	void (*delete) (struct __List*, int);
	Object (*get) (struct __List*, int);
	Object (*getPointer) (struct __List*, int);
	void (*clear) (struct __List*);
}__List;

typedef __List* List;

void list_push(List lst, Object obj){
	if(!lst || !obj) return;
	
	if(lst->head){
		obj->right = lst->head;
		lst->head->left = obj;
	}else{
		lst->tail = obj;
	}
	
	obj->left = NULL;
	
	lst->head = obj;
	lst->size++;
}

void list_enqueue(List lst, Object obj){
	if(!lst || !obj) return;
	
	obj->left = lst->tail;
	obj->right = NULL;
	
	if(lst->tail){
		lst->tail->right = obj;
	}
	
	if(!lst->head)
		lst->head = obj;
		
	lst->tail = obj;
	lst->size++;
}

Object list_pop(List lst){
	if(!lst || !lst->head) return NULL;
	
	Object popedObj = lst->head;
	
	if(popedObj->right){
		popedObj->right->left = NULL;
	}else{
		lst->tail = NULL;
	}
	lst->head = popedObj->right;
	
	popedObj->left = NULL;
	popedObj->right = NULL;
	
	return popedObj;
}

void list_clear(List lst){
	if(!lst) return;
	
	Object i = lst->head;
	while(i){
		Object prox = i->right;
		i->destroy(i);
		i = prox;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
}

void foreach(List lst, void (*f)(Object, void*), void* context){
	if(!lst) return;
	
	Object i = lst->head;
	while(i){
		f(i, context);
		i = i->right;
	}
}

void list_print(List lst){
	if(!lst) return;
	
	Object i = lst->head;
	while(i){
		i->print(i);
		i = i->right;
	}
}

void delete(List lst, int index){
	if(!lst || index < 0 || index > (lst->size-1)) return;
	
	Object i = lst->head;
	int cont = 0;
	while(i){
		if(cont == index){
			if(i->left){
				i->left->right = i->right;
			}else{
				lst->head = i->right;
			}
			if(i->right){
				i->right->left = i->left;
			}else{
				lst->tail = i->left;
			}
			
			i->destroy(i);
			return;
		}
		cont++;
		i = i->right;
	}
}

Object get(List lst, int index){
	if(!lst || index < 0 || index > (lst->size-1)) return NULL;
	
	Object i = lst->head;
	int cont = 0;
	while(i){
		if(cont == index){
			if(i->left){
				i->left->right = i->right;
			}else{
				lst->head = i->right;
			}
			if(i->right){
				i->right->left = i->left;
			}else{
				lst->tail = i->left;
			}
			
			return i;
		}
		cont++;
		i = i->right;
	}
	return NULL;
}


Object get_pointer(List lst, int index){
	if(!lst || index < 0 || index > (lst->size-1)) return NULL;
	
	Object i = lst->head;
	int cont = 0;
	while(i){
		if(cont == index)
			return i;
		
		cont++;
		i = i->right;
	}
	return NULL;
}

List new_List(){
	List newLst = malloc(sizeof(__List));
	newLst->head = NULL;
	newLst->tail = NULL;
	newLst->size = 0;
	newLst->enqueue = list_enqueue;
	newLst->push = list_push;
	newLst->pop = list_pop;
	newLst->print = list_print;
	newLst->delete = delete;
	newLst->get = get;
	newLst->getPointer = get_pointer;
	newLst->clear = list_clear;
	return newLst;
}

#endif
