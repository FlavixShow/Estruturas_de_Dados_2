#ifndef NODE_H
#define NODE_H

typedef struct Node{
	void* item;
	struct Node* left;
	struct Node* right;
	void (*print)(struct Node*);
	void (*set)(struct Node*, void*);
	void (*destroy)(struct Node*);
}Node;

typedef Node* Object;

void destroy(Object obj){
	if(!obj) return;
	
	if(obj->item)
		free(obj->item);
	
	free(obj);
}

Object new_Object(){
	Object newObj = malloc(sizeof(Node));
	newObj->item = NULL;
	newObj->left = NULL;
	newObj->right = NULL;
	newObj->print = NULL;
	newObj->set = NULL;
	newObj->destroy = destroy;
	return newObj;
}

#endif
