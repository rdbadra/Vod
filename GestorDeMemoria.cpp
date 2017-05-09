//hay que crear el interfaz
//#include "GestorDeMemoria.h"
#include <stdio.h>  
#include <math.h>
#include <string.h>  

map<yytokentype, char> letra = {
	{INT, 'I'},
	{CHAR, 'U'},
	{TUPLE, 'I'}
};

map<yytokentye, int> tamano = {
	{INT, 4},
	{CHAR, 1},
	{TUPLE, 4}
};

map<int, char *> regNombres = {
	{RO, "RO"},
	{R1, "R1"},
	{R2, "R2"},
	{R3, "R3"},
	{R4, "R4"},
	{R5, "R5"},
	{R6, "R6"},
	{R7, "R7"}
};

char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int contenidoRegistros[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int tamanoDireccion = 7;
char* basePila = 0x13000;
char* stackCounter = basePila;

//metodos utiles


//vuelve el id de un registro libre
int GestorDeMemoria::devuelveRegistroLibre(){
	for (int i = 0; i< contenidoRegistros.size();i++){
		if (estaLibre(i)){
			return i;
		}
	}

	printf("ERROR: NO QUEDA NINGUN REGISTRO LIBRE");
}


//verifica si el registro está libre
bool GestorMemoria::estaLibre(int id){
	if (contenidoRegistros[id]==-1){
		return true;
	}

	return false;
}

//libera el registro numero *id
void GestorDeMemoria::liberaRegistro(int id){
	contenidoRegistros[id]=-1;
}


int convertEsadecimalADecimal(const char* hexa){
	
	char numero[6];
	int numeroDecimal=0;
	int potencia = 0;
	int i;
	
	for (i = 2; i<tamanoDireccion; i++){
		numero[i-2]=hexa[i];
	}
	numero[i-2]='\0';

	for(i=strlen(numero); i >= 0; i--) {		
		/*search currect character in hexDigits array */
		for(int j=0; j<16; j++){
		    if(numero[i] == hexDigits[j]){
		        numeroDecimal = numeroDecimal + (j)*pow(16, potencia);
		    }
		}
		if(i!=(strlen(numero)))potencia++;
    	}  
	
	return numeroDecimal;	
}



char* convertDecimalToHexadecimal(int decimal){
	char esadecimal[7];
	esadecimal[0]='0';
	esadecimal[1]='x';

	int cociente = decimal;
	int temp;
	int i =0;
	char numeroEsadecimal[5];

	while(cociente!=0){
	       	temp = cociente % 16;

		//To convert integer into character
	      	if(temp < 10)
			 temp =temp + 48;
	      	else
			 temp = temp + 55;

		numeroEsadecimal[i]= temp;
		i++;
		cociente = cociente / 16;
	}

	for (i=0; i<5;i++){
		esadecimal[i+2]=numeroEsadecimal[4-i];
	}

	return esadecimal;
}

void insertaNumero(int numero){
	int direccion = convertEsadecimalADecimal(stackCounter);
	direccion = direccion +4;
	char* direccionHexadecimal = convertDecimalToHexadecimal(direccion);

	//escribir el numero en la estructura de memoria
}

void insertaTupla(char* cadena){
	int tamano = strlen(cadena);

	int direccion = convertEsadecimalADecimal(stackCounter);
	direccion = direccion + tamano*1;
	char* direccionHexadecimal = convertDecimalToHexadecimal(direccion);

	//escribir la cadena en la estructura de memoria
}

int main(){
	int c;
	const char* direccion;
	direccion = "0x12000";

	convertDecimalToHexadecimal(73728);
}
