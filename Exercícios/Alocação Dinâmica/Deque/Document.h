typedef struct TypeDocument{
	char* nome;
	int id;
	int paginas;
	int bytes;
	struct TypeDocument* prox;
	struct TypeDocument* ant;
}TypeDocument;

typedef TypeDocument* Document;

typedef struct TypeList{
	Document head;
	Document tail;
	int size;
}TypeList;

typedef TypeList* List;

List new_List(){
	List nova = malloc(sizeof(TypeList));
	nova->head = NULL;
	nova->tail = NULL;
	nova->size = 0;
	return nova;
}

Document new_Document(List lst, int id, char nome[],int pgs, int size){
	Document novo = malloc(sizeof(TypeDocument));
	novo->prox = NULL;
	
	novo->ant = lst->tail;
	if(lst->tail)
		lst->tail->prox = novo;
		
	novo->id = id;
	novo->paginas = pgs;
	novo->bytes = size;
	novo->nome = malloc(strlen(nome+1));
	strcpy(novo->nome,nome);
	
	lst->tail = novo;
	if(!lst->head)
		lst->head = novo;
	
	lst->size++;
	return novo;
}

void print_Document(Document d){
	printf("%d\t%s\t%d\t%d\n",d->id,d->nome,d->paginas,d->bytes);
}

void print_List(List l){
	Document i = l->head;
	while(i){
		print_Document(i);
		i = i->prox;
	}
}

void imprimir_Document(List lst){
	if(!lst->head) return;
	printf("Documento - %s - impresso!\n\n", lst->head->nome);
	
	if(lst->head == lst->tail){
		free(lst->head);
		lst->head = NULL;
		lst->tail = NULL;
		return;
	}
	
	lst->head = lst->head->prox;
	free(lst->head->ant);
	lst->head->ant = NULL;
}

Document busca_Document(List lst, int id){
	Document lst_inicio = lst->head;
	while(lst_inicio){
		if(lst_inicio->id == id){
			return lst_inicio;
		}
		lst_inicio = lst_inicio->prox;
	}
	printf("Não encontrado.");
	return NULL;
}

void excluir_Document(List lst, Document doc){
	if(!doc) return;
	
	if(lst->head == doc){
		lst->head = doc->prox;
		if(!lst->head){
			lst->tail = NULL;
			free(doc);
			return;
		}
		lst->head->ant = NULL;
		free(doc);
		return;
	}

	doc->ant->prox = doc->prox;
	if(doc->prox){
		doc->prox->ant = doc->ant;
	}else{
		lst->tail = doc->ant;
	}
	free(doc);
}

void priorizar_Document(List lst, Document doc){
	if(lst->head == doc || !doc) return;
	
	doc->ant->prox = doc->prox;
	if(doc->prox){
		doc->prox->ant = doc->ant;
	}else{
		lst->tail = doc->ant;
	}
	
	doc->prox = lst->head;
	doc->ant = NULL;
	lst->head = doc;
}
