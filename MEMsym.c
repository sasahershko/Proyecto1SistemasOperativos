#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------VGLOBALES---------------------------------------------------

#define TAM_LINEA 3
#define NUM_FILAS 8

//----------------------------------------------ESTRUCTURA---------------------------------------------------

typedef struct{
	unsigned char ETQ;
	unsigned char Data[TAM_LINEA];
}T_CACHE_LINE;

//----------------------------------------------FUNCIONES---------------------------------------------------

void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]);
void VolcarCACHE(T_CACHE_LINE *tbl);
void ParsearDireccion(unsigned int addr, int *ETQ, int*palabra, int *linea, int *bloque);
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ,int linea, int bloque);
void CerrarFicheros(FILE* f1, FILE* f2, FILE* f3);

//----------------------------------------------MAIN---------------------------------------------------

int main(){
	int globalTime = 0;
	int numFallos = 0;
	unsigned char Simul_RAM[4096];
	FILE* ficheroDirMemoria = fopen("dirs_memoria.txt", "r");
	FILE* ficheroContRAM = fopen("CONTENTS_RAM.bin", "r");
	FILE* ficheroAcessoMemoria = fopen("accesos_memoria.txt", "r");
	T_CACHE_LINE lineaCache;
	lineaCache.ETQ = 0xFF;
	for(int i = 0; i < TAM_LINEA; i++)
	{
			lineaCache.Data[i] = 0x23;
	}

<<<<<<< Updated upstream
=======
	//comprobación del fichero
	if((ficheroDirMemoria == NULL)  || (ficheroContRAM == NULL) || (ficheroAcessoMemoria == NULL))
	{
		printf("Error: algun fichero no existe");
		return(-1);
	}
	CerrarFicheros(ficheroAcessoMemoria, ficheroContRAM, ficheroDirMemoria);


	//ESTO SE TIENE QUE REPETIR
	//MIRAR DESPLAZAMIENTOS Y NUMEROS DE BITS EN C

	if(lineaCache.ETQ == TAM_LINEA)
	{

	}
	else
	{
		numFallos++;
		printf("T: %d, Fallo de CACHE %d, ADDR %04X Label %X linea %02Xpalabra %02X bloque %02X", globalTime, numFallos);
		globalTime += 20;
	}
	//HASTA AQUI


	return 0;

>>>>>>> Stashed changes
}

//----------------------------------------------FUNCIONES---------------------------------------------------

void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]){

}

void VolcarCACHE(T_CACHE_LINE *tbl){

}

void ParsearDireccion(unsigned int addr, int *ETQ, int*palabra, int *linea, int *bloque){

}

void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ,int linea, int bloque){

}

void CerrarFicheros(FILE* f1, FILE* f2, FILE* f3){
	fclose(f1);
	fclose(f2);
	fclose(f3);
}