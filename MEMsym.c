#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned char ETQ;
	unsigned char Data[TAM_LINEA]
}T_CACHE_LINE;

void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]);
void VolcarCACHE(T_CACHE_LINE *tbl);
void ParsearDireccion(unsigned int addr, int *ETQ, int*palabra, int *linea, int *bloque);
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ,int linea, int bloque);

int main(){
	int num1 = 1;
	int num2 = 2;
	int suma = num1+num2;

	printf("Hola buenas soy saray %d", suma);
}

void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]){

}
void VolcarCACHE(T_CACHE_LINE *tbl){

}
void ParsearDireccion(unsigned int addr, int *ETQ, int*palabra, int *linea, int *bloque){

}
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ,int linea, int bloque){
	
}