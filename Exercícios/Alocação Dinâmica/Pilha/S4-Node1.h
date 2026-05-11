typedef struct Veiculo{
	char* tipo;
	int ano;
	char* modelo;
	int km;
	float valor;
	struct Veiculo* proximo;
}Veiculo;

typedef struct{
	char* tipo;
	float valor;
}Media;

char* strInput(char* msg){
	char text[1000];
	printf("%s", msg);
	scanf(" %[^\n]s", text);
	char* pont = (char*)malloc(strlen(text)+1);
	strcpy(pont, text);
	return pont;
}

Veiculo* new_veiculo(Veiculo* veic){
	Veiculo* veiculo = (Veiculo*)malloc(sizeof(Veiculo));
	veiculo->tipo = strInput("Tipo do veículo: ");
	
	printf("Ano: ");
	scanf(" %i", &veiculo->ano);
	
	veiculo->modelo = strInput("Modelo do veículo: ");
	
	printf("Km: ");
	scanf(" %i", &veiculo->km);
	
	printf("Valor: ");
	scanf(" %f", &veiculo->valor);
	
	veiculo->proximo = veic;
	
	return veiculo;
}


void listarVeiculos(Veiculo* veic){
	while(veic){
		printf("Tipo: %s, Ano: %i, Modelo: %s, Km: %i, Valor: %f\n\n", veic->tipo, veic->ano, veic->modelo, veic->km, veic->valor);
		veic = veic->proximo;
	}
	
}


void buscarVeiculosTipo(Veiculo* veic){
	char* tipo = strInput("Tipo do veículo ser listado: ");
	
	while(veic){
		if(!strcmp(veic->tipo, tipo))
			printf("Tipo: %s, Ano: %i, Modelo: %s, Km: %i, Valor: %.2f\n\n", veic->tipo, veic->ano, veic->modelo, veic->km, veic->valor);
		veic = veic->proximo;
	}
	
}	

void meidiaValorVeiculosTipo(Veiculo* veic){

	
	while(veic){
		if(!strcmp(veic->tipo, tipo))
		
		veic = veic->proximo;
	}
	
}	
