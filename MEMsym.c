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
void MeterEnRAM(FILE* ficheroContRAM, unsigned char Simul_RAM[4096]);
int FicherosExisten(FILE* f1, FILE* f2, FILE* f3);
void CerrarFicheros(FILE* f1, FILE* f2, FILE* f3);

//----------------------------------------------MAIN---------------------------------------------------

int main(){
	int globalTime = 0;
	int numFallos = 0;
	
	//Aquí se guarda lo que hay dentro del fichero .bin

	FILE* ficheroDirMemoria = fopen("dirs_memoria.txt", "r");
	FILE* ficheroContRAM = fopen("CONTENTS_RAM.bin", "r");
	FILE* ficheroAcessoMemoria = fopen("accesos_memoria.txt", "r");
<<<<<<< Updated upstream
	T_CACHE_LINE lineaCache;
	lineaCache.ETQ = 0xFF;
	for(int i = 0; i < TAM_LINEA; i++)
	{
			lineaCache.Data[i] = 0x23;
	}
  
	//comprobación del fichero
	if((ficheroDirMemoria == NULL)  || (ficheroContRAM == NULL) || (ficheroAcessoMemoria == NULL))
	{
		printf("Error: algun fichero no existe");
=======
	T_CACHE_LINE lineaCache[NUM_FILAS];
	unsigned char Simul_RAM[4096];

	if(FicherosExisten(ficheroAcessoMemoria, ficheroContRAM, ficheroDirMemoria) == -1)
>>>>>>> Stashed changes
		return(-1);

	
	LimpiarCACHE(lineaCache);
	MeterEnRAM(ficheroContRAM, Simul_RAM);

	unsigned long numBin = 0;
	unsigned char TEMP = 0xff;
	unsigned char numHex[3];
	int contador = 0;
	//leo el fichero accesos memoria
	fopen("accesos_memoria.txt", "r");
	
	while((TEMP = getc(ficheroAcessoMemoria)) != '\n'){
		numHex[contador]= TEMP;
		contador++;
	}
	numBin = strtoul(numHex, NULL, 16);
	fclose(ficheroAcessoMemoria);
	/*
	- Cogemos la primera dirección : 22E

	- Lo convertimos a binario, los separamos por bits(palabra, linea y etiqueta)
			separamos los ultimos bits (5) de la etiqueta

	- lo comparamos con la estructura
	- Si da error se incremeta fallo +1 y tiempo +20, se copia el bloque de de Simul_RAM en la caché y se imprime lo que se esta cargando en la caché
	
	*/	
	
	//ESTO SE TIENE QUE REPETIR
	//MIRAR DESPLAZAMIENTOS Y NUMEROS DE BITS EN C

	/*if(lineaCache[0].ETQ == TAM_LINEA)
	{

	}
	else
	{
		numFallos++;
		printf("T: %d, Fallo de CACHE %d, ADDR %04X Label %X linea %02Xpalabra %02X bloque %02X", globalTime, numFallos);
		globalTime += 20;
	}*/
	//HASTA AQUÍ


	return 0;
}

//----------------------------------------------FUNCIONES---------------------------------------------------

// Esta función sirve para limpiar todas los valores de la cache, tanto de las etiquetas como de los datos.
void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]){

<<<<<<< Updated upstream
=======
	for(int i =0; i<NUM_FILAS;i++){

		tbl[i].ETQ = 0xFF;
		
		for(int j = 0; j < TAM_LINEA; j++)
		{
			tbl[i].Data[j] = 0x23;
		}
	}
>>>>>>> Stashed changes
}


//Antes de acabar el programa, vuelca los contenidos dentro del fichero .bin
void VolcarCACHE(T_CACHE_LINE *tbl){
}

void ParsearDireccion(unsigned int addr, int *ETQ, int*palabra, int *linea, int *bloque){
}

void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ,int linea, int bloque){
}


void MeterEnRAM(FILE* ficheroContRAM, unsigned char Simul_RAM[4096]){
	char input = '\0';
	int cont = 0;

	fopen("CONTENTS_RAM.bin", "rb");
	while((input = getc(ficheroContRAM)) != '\0' && !(feof(ficheroContRAM))){
		Simul_RAM[cont] = input;
		printf("%c", Simul_RAM[cont]);
		//printf("i: %d", cont);	
		cont++;
	}
	fclose(ficheroContRAM);
}

//Comprobación del ficheros
int FicherosExisten(FILE* f1, FILE* f2, FILE* f3){
	
	if((f1 == NULL)  || (f2 == NULL) || (f3 == NULL))
	{
		printf("Error: algun fichero no existe");
		return(-1);
	}
	return 0;
	CerrarFicheros(f1,f2,f3);
}

//Cierre de ficheros
void CerrarFicheros(FILE* f1, FILE* f2, FILE* f3){
	fclose(f1);
	fclose(f2);
	fclose(f3);
}