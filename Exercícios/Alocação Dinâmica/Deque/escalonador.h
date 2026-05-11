enum tipo_processo {KERNEL, USER};

typedef struct TypeProcesso{
	int pid;
	int tipo;
	int quantInst;
	int InstructCont;
	struct TypeProcesso* ant;
	struct TypeProcesso* prox;
}TypeProcesso;

typedef TypeProcesso* Processo;

typedef struct TypeList{
	Processo head;
	Processo tail;
	Processo ultKernel;
	Processo execut;
	int processCont;
	int proxId;
}TypeList;

typedef TypeList* List;

List new_List(){
	List nova = malloc(sizeof(TypeList));
	
	nova->head = NULL;
	nova->tail = NULL;
	nova->ultKernel = NULL;
	nova->execut = NULL;
	nova->processCont = 0;
	nova->proxId = 0;
	
	return nova;
}

void new_Processo(List lst, int tipo){
	Processo novo = malloc(sizeof(TypeProcesso));
	novo->pid = lst->proxId + 100;
	novo->quantInst = 2 + rand() % 15;
	novo->InstructCont = 0;
	
	if(tipo == USER){
		novo->tipo = USER;
		novo->ant = lst->tail;
		novo->prox = NULL;
		if(lst->tail)
			lst->tail->prox = novo;
			
		lst->tail = novo;
	}else{
		novo->tipo = KERNEL;
		
		if(!lst->ultKernel){
			novo->prox = lst->head;
			if(lst->head)
				lst->head->ant = novo;
			novo->ant = NULL;
			lst->head = novo;
			lst->ultKernel = novo;
			if(!lst->tail)
				lst->tail = novo;
		}else{
			novo->ant = lst->ultKernel;
			novo->prox = lst->ultKernel->prox;
			
			
			if(lst->ultKernel->prox)
				lst->ultKernel->prox->ant = novo;
				
			lst->ultKernel->prox = novo;
			
			if(lst->tail == lst->ultKernel){
				lst->ultKernel->prox = novo;
				lst->tail = novo;
			}
				
			lst->ultKernel = novo;
		}
	}
	
	if(!lst->head) 
		lst->head = novo;
		
	lst->execut = novo;
	lst->processCont++;
	lst->proxId++;
}

void printList(List lst){
	Processo head = lst->head;
	while(head){
		if(head == lst->execut){
			printf("*\t\t");
		}else{
			printf(" \t\t");
		}
			
		if(head->tipo == USER){
			printf("USER\t\t");
		}else{
			printf("KERNEL\t\t");

		}
		printf("%i\t%i\t\t%i\n", head->pid, head->quantInst, head->InstructCont);
		
		head = head->prox;
	}
	
}

void excluirProcesso(List lst, Processo target){
	
	if(target == lst->head){
		if(target->prox)
			target->prox->ant = NULL;
			
		lst->head = target->prox;
	}else{
		target->ant->prox = target->prox;
	}
	
	if(target->prox){
		target->prox->ant = target->ant;
	}else{
		lst->tail = target->ant;
	}
	
	if(target == lst->ultKernel){
		lst->ultKernel = target->ant;
	}
	lst->processCont--;
	free(target);
}

void executa(List lst){
	if(!lst->execut) return;
	
	Processo prox = lst->execut->prox;
	lst->execut->InstructCont++;
	
	if(lst->execut->InstructCont == lst->execut->quantInst){
		excluirProcesso(lst, lst->execut);
	}
	
	if(!prox){
		lst->execut = lst->head;
		return;
	}
	lst->execut = prox;
}

