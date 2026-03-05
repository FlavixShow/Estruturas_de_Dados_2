#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>



int resultado(int x, int y){
	if(y == 1) return x;
	return x*resultado(x , y--);
}


int main(){
	
	int x = 2, y = 3;
	printf("Resultado: %i", resultado(x, y));
	
	
}
