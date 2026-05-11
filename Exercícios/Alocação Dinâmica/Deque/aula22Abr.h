typedef struct TypeDocument{
	int id;
	char* nome;
	int pag;
	int size;
	struct TypeDocument* ant;
	struct TypeDocument* prox;
}TypeDocument;

typedef TypeDocument* Document;

typedef struct TypeList{
	Document head;
	Document tail;
	int size;
}TypeList;

typedef TypeList* List;

List new_List(){
	List new_l = malloc(sizeof(TypeList));
	new_l->head = NULL;
	new_l->tail = NULL;
	new_l->size = 0;
	return new_l;
}

void new_Document(List lst, int id, char* nome, int pag, int size){
	Document novo = malloc(sizeof(TypeDocument));
	novo->id = id;
	novo->nome = malloc(strlen(nome)+1);
	strcpy(novo->nome, nome);
	novo->pag = pag;
	novo->size = size;
	
	novo->prox = NULL;
	
	novo->ant = lst->tail;
	
	if(lst->tail)
		lst->tail->prox = novo;
	
	lst->tail = novo;
	
	if(!lst->head) lst->head = lst->tail;
	
	lst->size++;
}

void imprimir_Document(List lst){
	if(!lst->head) return;
	Document temp = lst->head->prox;
	free(lst->head->nome);
	free(lst->head);
	lst->head = temp;
	if(!lst->head) 
		lst->tail = NULL;
	lst->size--;
}

Document buscar_Document(List lst, int id){
	Document item = lst->head;
	while(item){
		if(item->id == id)
			return item;
		item = item->prox;
	}
	printf("Item não encontrado.\n\n");
	return NULL;
}


void excluir_Document(Document item, List lst){
	if(!item) return;
	
	if(lst->head == item){
		lst->head = item->prox;
		if(!lst->head){
			lst->tail = NULL;
		}else{
			lst->head->ant = NULL;
		}
		free(item->nome);
		free(item);
		lst->size--;
		return;
	}
	
	item->ant->prox = item->prox;
	if(item->prox){
		item->prox->ant = item->ant;
	}else{
		lst->tail = item->ant;
	}
	lst->size--;
}

void priorizar_Document(Document item, List lst){
	if(item == lst->head || !item) return;
	
	item->ant->prox = item->prox;
	if(item->prox){
		item->prox->ant = item->ant;
	}else{
		lst->tail = item->ant;
	}
	
	item->prox = lst->head;
	item->ant = NULL;
	lst->head = item;
}
