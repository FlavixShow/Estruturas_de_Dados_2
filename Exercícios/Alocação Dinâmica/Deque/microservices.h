enum {RUN, STOP};

typedef struct TypeContainer{
	int id;
	char* nome;
	int status;
	struct TypeContainer* prox;
	struct TypeContainer* ant;
}TypeContainer;

typedef TypeContainer* Container;

typedef struct TypeImage{
	int id;
	char* nome;
	int size;
	Container head;
	Container tail;
	struct TypeImage* prox;
	struct TypeImage* ant;
	int idCont;
	int susp;
}TypeImage;

typedef TypeImage* Image;


typedef struct TypeImageList{
	Image head;
	Image tail;
	int size;
	int idCont;
}TypeImageList;

typedef TypeImageList* ImageList;

ImageList new_ImageList(){
	ImageList novo = malloc(sizeof(TypeImageList));
	novo->head = NULL;
	novo->tail = NULL;
	novo->size = 0;
	novo->idCont = 0;
	return novo;
}

void alert(char texto[]){
	printf("%s Pressione ENTER...\n", texto);
	while(getchar() != '\n');
	getchar();
	system("clear");
}

char* strInput(){
	char nome[500];
	scanf(" %[^\n]s", nome);
	char* temp = malloc(sizeof(strlen(nome)+1));
	strcpy(temp, nome);
	return temp;
}

void divisa(char simb, int quant){
	for(int i = 0; i < quant; i++){
		printf("%c", simb);
	}
	printf("\n\n");
}

void new_Image(ImageList imgL){
	Image img = malloc(sizeof(TypeImage));
	img->id = imgL->idCont+1;
	
	printf("Digite o nome: ");
	img->nome = strInput();
	
	img->size = 0;
	
	img->head = NULL;
	img->tail = NULL;
	
	img->ant = imgL->tail;
	img->prox = NULL;
	if(imgL->tail)
		imgL->tail->prox = img;
	
	imgL->tail = img;
	
	if(!imgL->head)
		imgL->head = img;
		
	imgL->idCont++;
	imgL->size++;
	system("clear");
}

void listarImagens(ImageList imgL){
	Image inicio = imgL->head;
	while(inicio){
		printf("ID: %i\t\tNome: %s\t\tSize: %i\n\n", inicio->id, inicio->nome, inicio->size);
		inicio = inicio->prox;
	}
	printf("\n");
	
}

Image buscarImagem(ImageList imgL){
	printf("Selecione o ID da Imagem: ");
	int id;
	scanf(" %i", &id);
	
	Image inicio = imgL->head;
	while(inicio){
		if(inicio->id == id)
			return inicio;
		inicio = inicio->prox;
	}
	alert("Imagem Inexistente.");
	return NULL;
}

void new_Container(ImageList imgL){
	listarImagens(imgL);
	Image img = buscarImagem(imgL);
	if(!img) return;
	
	Container container = malloc(sizeof(TypeContainer));
	container->id = img->idCont+1;
	printf("Digite o nome: ");
	container->nome = strInput();
	container->prox = NULL;
	container->status = RUN;
	
	container->ant = img->tail;
	
	if(img->tail)
		img->tail->prox = container;

	if(!img->head)
		img->head = container;
		
	img->tail = container;
	
	img->idCont++;
	img->size++;
	system("clear");
}

int listarContainer(Image img){
	if(!img) return 0;
	Container inicio = img->head;
	while(inicio){
		printf("Container -> ID: %i\t\tNome: %s\t\tStatus: ", inicio->id, inicio->nome);
		if(inicio->status == RUN){
			printf("Executando\n\n");
		}else{
			printf("Suspenso\n\n");
		}
		inicio = inicio->prox;
	}
	return 1;
}

Container buscarContainer(Image img){
	if(!img) return NULL;
	printf("Selecione o ID do Container: ");
	int id;
	scanf(" %i", &id);
	
	Container inicio = img->head;
	while(inicio){
		if(inicio->id == id)
			return inicio;
		inicio = inicio->prox;
	}
	alert("Container Inexistente.");
	return NULL;
}

void stop_Container(ImageList imgL){
	//listar tudo
	Image inicio = imgL->head;
	while(inicio){
		divisa('=', 75);
		printf("Imagem -> ID: %i, Nome: %s, Size: %i\n\n", inicio->id, inicio->nome, inicio->size);
		listarContainer(inicio);
		inicio = inicio->prox;
	}
	divisa('=', 75);

	Image img = buscarImagem(imgL);
	Container con = buscarContainer(img);
	
	if(con){
		con->status = STOP;
		img->susp++;
		alert("Container suspenso.");
	}
}

void listarContainerSuspenso(Image img){
	Container inicio = img->head;
	while(inicio){
		if(inicio->status == STOP){
			printf("Container -> ID: %i\t\tNome: %s\t\tStatus: ", inicio->id, inicio->nome);
			if(inicio->status == RUN){
				printf("Executando\n\n");
			}else{
				printf("Suspenso\n\n");
			}
		}
		inicio = inicio->prox;
	}	
}

void init_Container(ImageList imgL){
	//listar tudo
	Image inicio = imgL->head;
	while(inicio){
		if(inicio->susp){
			divisa('=', 75);
			printf("Imagem -> ID: %i, Nome: %s, Size: %i\n\n", inicio->id, inicio->nome, inicio->size);
			listarContainerSuspenso(inicio);
		}
		inicio = inicio->prox;
	}
	divisa('=', 75);

	Image img = buscarImagem(imgL);
	Container con = buscarContainer(img);
	
	if(con){
		con->status = RUN;
		img->susp--;
		alert("Container iniciado.");
	}
	
}

void excluirImagem(ImageList imgL){
	Image img = buscarImagem(imgL);
	if(!img) return;
	if(img->size){
		alert("Imagem possui Container.");
		return;
	}
	
	if(img->ant){
		img->ant->prox = img->prox;
	}else{
		imgL->head = img->prox;
	}
	
	if(img->prox){
		img->prox->ant = img->ant;
	}else{
		imgL->tail = img->ant;
	}
	
	free(img->nome);
	free(img);
	imgL->size--;
	alert("Imagem excluida.");
}

void excluirContainer(ImageList imgL){
	//listar tudo
	Image inicio = imgL->head;
	while(inicio){
		divisa('=', 75);
		printf("Imagem -> ID: %i, Nome: %s, Size: %i\n\n", inicio->id, inicio->nome, inicio->size);
		listarContainer(inicio);
		inicio = inicio->prox;
	}
	divisa('=', 75);
	
	Image img = buscarImagem(imgL);
	if(!img) return;
	Container container = buscarContainer(img);
	if(!container) return;

	if(container->status == RUN){
		alert("Conteiner está em execução.");
		return;
	}
	
	if(container->ant){
		container->ant->prox = container->prox;
	}else{
		img->head = container->prox;
	}
	
	if(container->prox){
		container->prox->ant = container->ant;
	}else{
		img->tail = container->ant;
	}
	
	img->size--;
	img->susp--;
}
