typedef struct Doc{
	char* nome;
	int pag;
	int tam;
	struct Doc* prox;
}Doc;

Doc* new_doc(Doc* prox){
	Doc* doc = malloc(sizeof(Doc));
	
	char nome[1000];
	printf("Digite o nome: ");
	scanf(" %[^\n]s", nome);
	doc->nome = malloc(strlen(nome)+1);
	strcpy(doc->nome, nome);
	
	printf("Digite a quant. de pag.: ");
	scanf(" %i", &doc->pag);

	printf("Digite o tamanho: ");
	scanf(" %i", &doc->tam);
	
	doc->prox = prox;
	return doc;
}

void listar_docs(Doc* doc){
	while(doc){
		printf("Nome: %s, Pag: %i, Tam: %i\n\n", doc->nome, doc->pag, doc->tam);
		doc = doc->prox;
	}
}


